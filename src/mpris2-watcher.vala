/*
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

[DBus (name = "org.freedesktop.DBus")]
public interface FreeDesktopObject: Object {
    public abstract signal void name_owner_changed (string name,
                                                    string old_owner,
                                                    string new_owner);
}

public class Mpris2Watcher : GLib.Object
{
  private const string FREEDESKTOP_SERVICE = "org.freedesktop.DBus";
  private const string FREEDESKTOP_OBJECT = "/org/freedesktop/DBus";
  private const string MPRIS_PREFIX = "org.mpris.MediaPlayer2.";
  private const string MPRIS_MEDIA_PLAYER_PATH = "/org/mpris/MediaPlayer2";

  FreeDesktopObject fdesktop_obj;
  
  public signal void client_appeared ( string desktop_name );
  public signal void client_disappeared ( string desktop_name );

  public Mpris2Watcher ()
  {
  }
  
  construct
  {  
    try {
      this.fdesktop_obj = Bus.get_proxy_sync ( BusType.SESSION,
                                               FREEDESKTOP_SERVICE,
                                               FREEDESKTOP_OBJECT,
                                               DBusProxyFlags.DO_NOT_LOAD_PROPERTIES );      
      this.fdesktop_obj.name_owner_changed.connect (this.name_changes_detected);      
    }
    catch ( IOError e ){
      warning( "Mpris2watcher could not set up a watch for mpris clients appearing on the bus: %s",
                e.message );
    }
  }

  private void name_changes_detected ( FreeDesktopObject dbus_obj,
                                       string     name,
                                       string     previous_owner,
                                       string     current_owner ) {
    MprisRoot mpris2_root;                                         
    if ( name.has_prefix (MPRIS_PREFIX) ){
      try {
        mpris2_root = Bus.get_proxy_sync (  BusType.SESSION,
                                             name,
                                             MPRIS_MEDIA_PLAYER_PATH );
      }
      catch (IOError e){
        warning( "Mpris2watcher could not create a root interface: %s",
                  e.message );
        return;
      }
      if (previous_owner != "" && current_owner == "") {
        debug ("Service '%s' going down", name);
        client_disappeared (mpris2_root.DesktopEntry);
      }
      else if (previous_owner == "" && current_owner != "") {
        debug ("Service '%s' has appeared", name);
        client_appeared (mpris2_root.DesktopEntry);
      }
    }
  }
}