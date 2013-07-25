/*
 * Copyright 2013 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Lars Uebernickel <lars.uebernickel@canonical.com>
 */

/* Icon.serialize() is not yet in gio-2.0.vapi; remove this when it is */
extern Variant? g_icon_serialize (Icon icon);

public class IndicatorSound.Service {
	public Service () {
		this.settings = new Settings ("com.canonical.indicator.sound");

		this.volume_control = new VolumeControl ();

		this.players = new MediaPlayerList ();
		this.players.player_added.connect (this.player_added);
		this.players.player_removed.connect (this.player_removed);

		this.actions = new SimpleActionGroup ();
		this.actions.add_entries (action_entries, this);
		this.actions.add_action (this.create_mute_action ());
		this.actions.add_action (this.create_volume_action ());
		this.actions.add_action (this.create_mic_volume_action ());

		this.menu = new SoundMenu ();
		this.volume_control.bind_property ("active-mic", this.menu, "show-mic-volume", BindingFlags.SYNC_CREATE);

		this.players.sync (settings.get_strv ("interested-media-players"));
		this.settings.changed["interested-media-players"].connect ( () => {
			this.players.sync (settings.get_strv ("interested-media-players"));
		});
	}

	public int run () {
		if (this.loop != null) {
			warning ("service is already running");
			return 1;
		}

		Bus.own_name (BusType.SESSION, "com.canonical.indicator.sound", BusNameOwnerFlags.NONE,
			this.bus_acquired, null, this.name_lost);

		this.loop = new MainLoop (null, false);
		this.loop.run ();

		return 0;
	}

	const ActionEntry[] action_entries = {
		{ "root", null, null, "@a{sv} {}", null },
		{ "settings", activate_settings, null, null, null },
	};

	MainLoop loop;
	SimpleActionGroup actions;
	SoundMenu menu;
	Settings settings;
	VolumeControl volume_control;
	MediaPlayerList players;
	uint player_action_update_id;

	void activate_settings (SimpleAction action, Variant? param) {
		var env = Environment.get_variable ("DESKTOP_SESSION");
		string cmd;
		if (env == "unity")
			cmd = "gnome-control-center sound-nua";
		else if (env == "xubuntu" || env == "ubuntustudio")
			cmd = "pavucontrol";
		else
			cmd = "gnome-control-center sound";

		try {
			Process.spawn_command_line_async (cmd);
		} catch (Error e) {
			warning ("unable to launch sound settings: %s", e.message);
		}
	}

	/* Returns a serialized version of @icon_name suited for the panel */
	static Variant serialize_themed_icon (string icon_name)
	{
		var icon = new ThemedIcon.with_default_fallbacks (icon_name);
		return g_icon_serialize (icon);
	}

	void update_root_icon () {
		double volume = this.volume_control.get_volume ();
		string icon;
		if (this.volume_control.mute)
			icon = "audio-volume-muted-panel";
		else if (volume <= 0.0)
			icon = "audio-volume-low-zero-panel";
		else if (volume <= 0.3)
			icon = "audio-volume-low-panel";
		else if (volume <= 0.7)
			icon = "audio-volume-medium-panel";
		else
			icon  = "audio-volume-high-panel";

		var root_action = this.actions.lookup ("root") as SimpleAction;
		root_action.set_state (new Variant.parsed ("{ 'icon': %v }", serialize_themed_icon (icon)));
	}

	Action create_mute_action () {
		var mute_action = new SimpleAction.stateful ("mute", null, this.volume_control.mute);

		mute_action.activate.connect ( (action, param) => {
			action.change_state (!action.get_state ().get_boolean ());
		});

		mute_action.change_state.connect ( (action, val) => {
			volume_control.set_mute (val.get_boolean ());
		});

		this.volume_control.notify["mute"].connect ( () => {
			mute_action.set_state (this.volume_control.mute);
			this.update_root_icon ();
		});

		return mute_action;
	}

	void volume_changed (double volume) {
		var volume_action = this.actions.lookup ("volume") as SimpleAction;
		volume_action.set_state (volume);

		this.update_root_icon ();
	}

	Action create_volume_action () {
		var volume_action = new SimpleAction.stateful ("volume", null, this.volume_control.get_volume ());

		volume_action.change_state.connect ( (action, val) => {
			volume_control.set_volume (val.get_double ());
		});

		this.volume_control.volume_changed.connect (volume_changed);

		this.volume_control.bind_property ("ready", volume_action, "enabled", BindingFlags.SYNC_CREATE);

		return volume_action;
	}

	Action create_mic_volume_action () {
		var volume_action = new SimpleAction.stateful ("mic-volume", null, this.volume_control.get_mic_volume ());

		volume_action.change_state.connect ( (action, val) => {
			volume_control.set_mic_volume (val.get_double ());
		});

		this.volume_control.mic_volume_changed.connect ( (volume) => {
			volume_action.set_state (volume);
		});

		this.volume_control.bind_property ("ready", volume_action, "enabled", BindingFlags.SYNC_CREATE);

		return volume_action;
	}

	void bus_acquired (DBusConnection connection, string name) {
		try {
			connection.export_action_group ("/com/canonical/indicator/sound", this.actions);
			this.menu.export (connection, "/com/canonical/indicator/sound/desktop");
		} catch (Error e) {
			critical ("%s", e.message);
		}
	}

	void name_lost (DBusConnection connection, string name) {
		this.loop.quit ();
	}

	Variant action_state_for_player (MediaPlayer player) {
		var builder = new VariantBuilder (new VariantType ("a{sv}"));
		builder.add ("{sv}", "running", new Variant ("b", player.is_running));
		builder.add ("{sv}", "state", new Variant ("s", player.state));
		if (player.current_track != null) {
			builder.add ("{sv}", "title", new Variant ("s", player.current_track.title));
			builder.add ("{sv}", "artist", new Variant ("s", player.current_track.artist));
			builder.add ("{sv}", "album", new Variant ("s", player.current_track.album));
			builder.add ("{sv}", "art-url", new Variant ("s", player.current_track.art_url));
		}
		return builder.end ();
	}

	bool update_player_actions () {
		foreach (var player in this.players) {
			SimpleAction? action = this.actions.lookup (player.id) as SimpleAction;
			if (action != null)
				action.set_state (this.action_state_for_player (player));
		}

		this.player_action_update_id = 0;
		return false;
	}

	void eventually_update_player_actions () {
		if (player_action_update_id == 0)
			this.player_action_update_id = Idle.add (this.update_player_actions);
	}

	void update_preferred_players () {
		var builder = new VariantBuilder (VariantType.STRING_ARRAY);
		foreach (var player in this.players)
			builder.add ("s", player.id);
		this.settings.set_value ("interested-media-players", builder.end ());
	}

	void player_added (MediaPlayer player) {
		this.menu.add_player (player);

		SimpleAction action = new SimpleAction.stateful (player.id, null, this.action_state_for_player (player));
		action.activate.connect ( () => { player.launch (); });
		this.actions.insert (action);

		var play_action = new SimpleAction.stateful ("play." + player.id, null, player.state);
		play_action.activate.connect ( () => player.play_pause () );
		this.actions.insert (play_action);
		player.notify.connect ( (object, pspec) => {
			if (pspec.name == "state")
				play_action.set_state (player.state);
		});

		var next_action = new SimpleAction ("next." + player.id, null);
		next_action.activate.connect ( () => player.next () );
		this.actions.insert (next_action);

		var prev_action = new SimpleAction ("previous." + player.id, null);
		prev_action.activate.connect ( () => player.previous () );
		this.actions.insert (prev_action);

		var playlist_action = new SimpleAction ("play-playlist." + player.id, VariantType.STRING);
		playlist_action.activate.connect ( (parameter) => player.activate_playlist_by_name (parameter.get_string ()) );
		this.actions.insert (playlist_action);

		player.notify.connect (this.eventually_update_player_actions);

		this.update_preferred_players ();
	}

	void player_removed (MediaPlayer player) {
		this.actions.remove (player.id);
		this.actions.remove ("play." + player.id);
		this.actions.remove ("next." + player.id);
		this.actions.remove ("previous." + player.id);
		this.actions.remove ("play-playlist." + player.id);

		this.menu.remove_player (player);

		this.update_preferred_players ();
	}
}
