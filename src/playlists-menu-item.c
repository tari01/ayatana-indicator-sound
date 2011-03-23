/* playlists-menu-item.c generated by valac 0.11.7, the Vala compiler
 * generated from playlists-menu-item.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/dbusmenu-glib.h>
#include <libdbusmenu-glib/enum-types.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/types.h>
#include <gee.h>
#include <common-defs.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>


#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;

#define TYPE_PLAYLISTS_MENUITEM (playlists_menuitem_get_type ())
#define PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitem))
#define PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))
#define IS_PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYLISTS_MENUITEM))
#define IS_PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYLISTS_MENUITEM))
#define PLAYLISTS_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))

typedef struct _PlaylistsMenuitem PlaylistsMenuitem;
typedef struct _PlaylistsMenuitemClass PlaylistsMenuitemClass;
typedef struct _PlaylistsMenuitemPrivate PlaylistsMenuitemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;

#define TYPE_PLAYLIST_DETAILS (playlist_details_get_type ())
typedef struct _PlaylistDetails PlaylistDetails;
typedef struct _Block1Data Block1Data;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _PlayerControllerPrivate PlayerControllerPrivate;

#define TYPE_MPRIS2_CONTROLLER (mpris2_controller_get_type ())
#define MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2Controller))
#define MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))
#define IS_MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS2_CONTROLLER))
#define IS_MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MPRIS2_CONTROLLER))
#define MPRIS2_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))

typedef struct _Mpris2Controller Mpris2Controller;
typedef struct _Mpris2ControllerClass Mpris2ControllerClass;

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _PlaylistsMenuitem {
	PlayerItem parent_instance;
	PlaylistsMenuitemPrivate * priv;
	DbusmenuMenuitem* root_item;
};

struct _PlaylistsMenuitemClass {
	PlayerItemClass parent_class;
};

struct _PlaylistsMenuitemPrivate {
	GeeHashMap* current_playlists;
};

struct _PlaylistDetails {
	char* path;
	gchar* name;
	gchar* icon_path;
};

struct _Block1Data {
	int _ref_count_;
	PlaylistsMenuitem * self;
	DbusmenuMenuitem* menuitem;
};

struct _PlayerController {
	GObject parent_instance;
	PlayerControllerPrivate * priv;
	gint current_state;
	GeeArrayList* custom_items;
	Mpris2Controller* mpris_bridge;
	gboolean* use_playlists;
};

struct _PlayerControllerClass {
	GObjectClass parent_class;
};


static gpointer playlists_menuitem_parent_class = NULL;

GType player_item_get_type (void) G_GNUC_CONST;
GType playlists_menuitem_get_type (void) G_GNUC_CONST;
#define PLAYLISTS_MENUITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemPrivate))
enum  {
	PLAYLISTS_MENUITEM_DUMMY_PROPERTY
};
GType player_controller_get_type (void) G_GNUC_CONST;
PlaylistsMenuitem* playlists_menuitem_new (PlayerController* parent);
PlaylistsMenuitem* playlists_menuitem_construct (GType object_type, PlayerController* parent);
GType playlist_details_get_type (void) G_GNUC_CONST;
PlaylistDetails* playlist_details_dup (const PlaylistDetails* self);
void playlist_details_free (PlaylistDetails* self);
void playlist_details_copy (const PlaylistDetails* self, PlaylistDetails* dest);
void playlist_details_destroy (PlaylistDetails* self);
void playlists_menuitem_update (PlaylistsMenuitem* self, PlaylistDetails* playlists, int playlists_length1);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (Block1Data* _data1_);
static gboolean playlists_menuitem_already_observed (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
static gboolean playlists_menuitem_is_video_related (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
static void _lambda1_ (Block1Data* _data1_);
static void playlists_menuitem_submenu_item_activated (PlaylistsMenuitem* self, gint menu_item_id);
static void __lambda1__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint timestamp, gpointer self);
void playlists_menuitem_update_individual_playlist (PlaylistsMenuitem* self, PlaylistDetails* new_detail);
void playlists_menuitem_active_playlist_update (PlaylistsMenuitem* self, PlaylistDetails* detail);
PlayerController* player_item_get_owner (PlayerItem* self);
GType mpris2_controller_get_type (void) G_GNUC_CONST;
void mpris2_controller_activate_playlist (Mpris2Controller* self, const char* path);
GeeHashSet* playlists_menuitem_attributes_format (void);
static GObject * playlists_menuitem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void playlists_menuitem_finalize (GObject* obj);


PlaylistsMenuitem* playlists_menuitem_construct (GType object_type, PlayerController* parent) {
	PlaylistsMenuitem * self = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	self = (PlaylistsMenuitem*) g_object_new (object_type, "item-type", DBUSMENU_PLAYLISTS_MENUITEM_TYPE, "owner", parent, NULL);
	return self;
}


PlaylistsMenuitem* playlists_menuitem_new (PlayerController* parent) {
	return playlists_menuitem_construct (TYPE_PLAYLISTS_MENUITEM, parent);
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (Block1Data* _data1_) {
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->self);
		_g_object_unref0 (_data1_->menuitem);
		g_slice_free (Block1Data, _data1_);
	}
}


static void _lambda1_ (Block1Data* _data1_) {
	PlaylistsMenuitem * self;
	gint _tmp0_;
	self = _data1_->self;
	_tmp0_ = dbusmenu_menuitem_get_id (_data1_->menuitem);
	playlists_menuitem_submenu_item_activated (self, _tmp0_);
}


static void __lambda1__dbusmenu_menuitem_item_activated (DbusmenuMenuitem* _sender, guint timestamp, gpointer self) {
	_lambda1_ (self);
}


void playlists_menuitem_update (PlaylistsMenuitem* self, PlaylistDetails* playlists, int playlists_length1) {
	g_return_if_fail (self != NULL);
	{
		PlaylistDetails* detail_collection;
		int detail_collection_length1;
		int detail_it;
		detail_collection = playlists;
		detail_collection_length1 = playlists_length1;
		for (detail_it = 0; detail_it < playlists_length1; detail_it = detail_it + 1) {
			PlaylistDetails _tmp0_;
			PlaylistDetails _tmp1_ = {0};
			PlaylistDetails detail;
			playlist_details_copy (&detail_collection[detail_it], &_tmp1_);
			_tmp0_ = _tmp1_;
			detail = _tmp0_;
			{
				Block1Data* _data1_;
				gboolean _tmp2_ = FALSE;
				gboolean _tmp3_;
				DbusmenuMenuitem* _tmp5_ = NULL;
				gint _tmp6_;
				_data1_ = g_slice_new0 (Block1Data);
				_data1_->_ref_count_ = 1;
				_data1_->self = g_object_ref (self);
				_tmp3_ = playlists_menuitem_already_observed (self, &detail);
				if (_tmp3_) {
					_tmp2_ = TRUE;
				} else {
					gboolean _tmp4_;
					_tmp4_ = playlists_menuitem_is_video_related (self, &detail);
					_tmp2_ = _tmp4_;
				}
				if (_tmp2_) {
					playlist_details_destroy (&detail);
					block1_data_unref (_data1_);
					_data1_ = NULL;
					continue;
				}
				_tmp5_ = dbusmenu_menuitem_new ();
				_data1_->menuitem = _tmp5_;
				dbusmenu_menuitem_property_set (_data1_->menuitem, DBUSMENU_MENUITEM_PROP_LABEL, detail.name);
				dbusmenu_menuitem_property_set (_data1_->menuitem, DBUSMENU_MENUITEM_PROP_ICON_NAME, "playlist-symbolic");
				dbusmenu_menuitem_property_set (_data1_->menuitem, DBUSMENU_PLAYLIST_MENUITEM_PATH, (const gchar*) detail.path);
				dbusmenu_menuitem_property_set_bool (_data1_->menuitem, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
				dbusmenu_menuitem_property_set_bool (_data1_->menuitem, DBUSMENU_MENUITEM_PROP_ENABLED, TRUE);
				g_signal_connect_data (_data1_->menuitem, "item-activated", (GCallback) __lambda1__dbusmenu_menuitem_item_activated, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
				_tmp6_ = dbusmenu_menuitem_get_id (_data1_->menuitem);
				gee_abstract_map_set ((GeeAbstractMap*) self->priv->current_playlists, GINT_TO_POINTER (_tmp6_), _data1_->menuitem);
				dbusmenu_menuitem_child_append (self->root_item, _data1_->menuitem);
				playlist_details_destroy (&detail);
				block1_data_unref (_data1_);
				_data1_ = NULL;
			}
		}
	}
	{
		GeeCollection* _tmp7_ = NULL;
		GeeCollection* _tmp8_;
		GeeIterator* _tmp9_ = NULL;
		GeeIterator* _tmp10_;
		GeeIterator* _item_it;
		_tmp7_ = gee_map_get_values ((GeeMap*) self->priv->current_playlists);
		_tmp8_ = _tmp7_;
		_tmp9_ = gee_iterable_iterator ((GeeIterable*) _tmp8_);
		_tmp10_ = _tmp9_;
		_g_object_unref0 (_tmp8_);
		_item_it = _tmp10_;
		while (TRUE) {
			gboolean _tmp11_;
			gpointer _tmp12_ = NULL;
			DbusmenuMenuitem* item;
			gboolean within;
			_tmp11_ = gee_iterator_next (_item_it);
			if (!_tmp11_) {
				break;
			}
			_tmp12_ = gee_iterator_get (_item_it);
			item = (DbusmenuMenuitem*) _tmp12_;
			within = FALSE;
			{
				PlaylistDetails* detail_collection;
				int detail_collection_length1;
				int detail_it;
				detail_collection = playlists;
				detail_collection_length1 = playlists_length1;
				for (detail_it = 0; detail_it < playlists_length1; detail_it = detail_it + 1) {
					PlaylistDetails _tmp13_;
					PlaylistDetails _tmp14_ = {0};
					PlaylistDetails detail;
					playlist_details_copy (&detail_collection[detail_it], &_tmp14_);
					_tmp13_ = _tmp14_;
					detail = _tmp13_;
					{
						const gchar* _tmp15_ = NULL;
						_tmp15_ = dbusmenu_menuitem_property_get (item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
						if (g_strcmp0 (detail.path, _tmp15_) == 0) {
							within = TRUE;
							playlist_details_destroy (&detail);
							break;
						}
						playlist_details_destroy (&detail);
					}
				}
			}
			if (within == FALSE) {
				const gchar* _tmp16_ = NULL;
				const gchar* _tmp17_ = NULL;
				_tmp16_ = dbusmenu_menuitem_property_get (self->root_item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
				_tmp17_ = dbusmenu_menuitem_property_get (item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
				if (g_strcmp0 (_tmp16_, _tmp17_) == 0) {
					const gchar* _tmp18_ = NULL;
					_tmp18_ = _ ("Choose Playlist");
					dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_MENUITEM_PROP_LABEL, _tmp18_);
				}
				dbusmenu_menuitem_child_delete (self->root_item, item);
			}
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
}


void playlists_menuitem_update_individual_playlist (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	const gchar* _tmp7_ = NULL;
	g_return_if_fail (self != NULL);
	{
		GeeCollection* _tmp0_ = NULL;
		GeeCollection* _tmp1_;
		GeeIterator* _tmp2_ = NULL;
		GeeIterator* _tmp3_;
		GeeIterator* _item_it;
		_tmp0_ = gee_map_get_values ((GeeMap*) self->priv->current_playlists);
		_tmp1_ = _tmp0_;
		_tmp2_ = gee_iterable_iterator ((GeeIterable*) _tmp1_);
		_tmp3_ = _tmp2_;
		_g_object_unref0 (_tmp1_);
		_item_it = _tmp3_;
		while (TRUE) {
			gboolean _tmp4_;
			gpointer _tmp5_ = NULL;
			DbusmenuMenuitem* item;
			const gchar* _tmp6_ = NULL;
			_tmp4_ = gee_iterator_next (_item_it);
			if (!_tmp4_) {
				break;
			}
			_tmp5_ = gee_iterator_get (_item_it);
			item = (DbusmenuMenuitem*) _tmp5_;
			_tmp6_ = dbusmenu_menuitem_property_get (item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
			if (g_strcmp0 ((*new_detail).path, _tmp6_) == 0) {
				dbusmenu_menuitem_property_set (item, DBUSMENU_MENUITEM_PROP_LABEL, (*new_detail).name);
			}
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
	_tmp7_ = dbusmenu_menuitem_property_get (self->root_item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
	if (g_strcmp0 (_tmp7_, (*new_detail).path) == 0) {
		dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_MENUITEM_PROP_LABEL, (*new_detail).name);
	}
}


static gboolean playlists_menuitem_already_observed (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	{
		GeeCollection* _tmp0_ = NULL;
		GeeCollection* _tmp1_;
		GeeIterator* _tmp2_ = NULL;
		GeeIterator* _tmp3_;
		GeeIterator* _item_it;
		_tmp0_ = gee_map_get_values ((GeeMap*) self->priv->current_playlists);
		_tmp1_ = _tmp0_;
		_tmp2_ = gee_iterable_iterator ((GeeIterable*) _tmp1_);
		_tmp3_ = _tmp2_;
		_g_object_unref0 (_tmp1_);
		_item_it = _tmp3_;
		while (TRUE) {
			gboolean _tmp4_;
			gpointer _tmp5_ = NULL;
			DbusmenuMenuitem* item;
			const gchar* _tmp6_ = NULL;
			gchar* _tmp7_;
			gchar* path;
			_tmp4_ = gee_iterator_next (_item_it);
			if (!_tmp4_) {
				break;
			}
			_tmp5_ = gee_iterator_get (_item_it);
			item = (DbusmenuMenuitem*) _tmp5_;
			_tmp6_ = dbusmenu_menuitem_property_get (item, DBUSMENU_PLAYLIST_MENUITEM_PATH);
			_tmp7_ = g_strdup (_tmp6_);
			path = _tmp7_;
			if (g_strcmp0 ((*new_detail).path, path) == 0) {
				result = TRUE;
				_g_free0 (path);
				_g_object_unref0 (item);
				_g_object_unref0 (_item_it);
				return result;
			}
			_g_free0 (path);
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_it);
	}
	result = FALSE;
	return result;
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = strstr ((gchar*) self, (gchar*) needle);
	result = _tmp0_ != NULL;
	return result;
}


static gboolean playlists_menuitem_is_video_related (PlaylistsMenuitem* self, PlaylistDetails* new_detail) {
	gboolean result = FALSE;
	gchar* _tmp0_;
	gchar* location;
	gboolean _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = g_strdup ((const gchar*) (*new_detail).path);
	location = _tmp0_;
	_tmp1_ = string_contains (location, "/VideoLibrarySource/");
	if (_tmp1_) {
		result = TRUE;
		_g_free0 (location);
		return result;
	}
	result = FALSE;
	_g_free0 (location);
	return result;
}


void playlists_menuitem_active_playlist_update (PlaylistsMenuitem* self, PlaylistDetails* detail) {
	gchar* _tmp0_;
	gchar* update;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup ((*detail).name);
	update = _tmp0_;
	if (g_strcmp0 (update, "") == 0) {
		const gchar* _tmp1_ = NULL;
		gchar* _tmp2_;
		_tmp1_ = _ ("Choose Playlist");
		_tmp2_ = g_strdup (_tmp1_);
		_g_free0 (update);
		update = _tmp2_;
	}
	dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_MENUITEM_PROP_LABEL, update);
	dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_PLAYLIST_MENUITEM_PATH, (const gchar*) (*detail).path);
	_g_free0 (update);
}


static void playlists_menuitem_submenu_item_activated (PlaylistsMenuitem* self, gint menu_item_id) {
	gboolean _tmp0_;
	PlayerController* _tmp1_ = NULL;
	gpointer _tmp2_ = NULL;
	DbusmenuMenuitem* _tmp3_;
	const gchar* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = gee_abstract_map_has_key ((GeeAbstractMap*) self->priv->current_playlists, GINT_TO_POINTER (menu_item_id));
	if (!_tmp0_) {
		g_warning ("playlists-menu-item.vala:126: item %i was activated but we don't have " \
"a corresponding playlist", menu_item_id);
		return;
	}
	_tmp1_ = player_item_get_owner ((PlayerItem*) self);
	_tmp2_ = gee_abstract_map_get ((GeeAbstractMap*) self->priv->current_playlists, GINT_TO_POINTER (menu_item_id));
	_tmp3_ = (DbusmenuMenuitem*) _tmp2_;
	_tmp4_ = dbusmenu_menuitem_property_get (_tmp3_, DBUSMENU_PLAYLIST_MENUITEM_PATH);
	mpris2_controller_activate_playlist (_tmp1_->mpris_bridge, (const char*) _tmp4_);
	_g_object_unref0 (_tmp3_);
}


GeeHashSet* playlists_menuitem_attributes_format (void) {
	GeeHashSet* result = NULL;
	GeeHashSet* _tmp0_ = NULL;
	GeeHashSet* attrs;
	_tmp0_ = gee_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL);
	attrs = _tmp0_;
	gee_abstract_collection_add ((GeeAbstractCollection*) attrs, DBUSMENU_PLAYLISTS_MENUITEM_TITLE);
	gee_abstract_collection_add ((GeeAbstractCollection*) attrs, DBUSMENU_PLAYLISTS_MENUITEM_PLAYLISTS);
	result = attrs;
	return result;
}


static GObject * playlists_menuitem_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PlaylistsMenuitem * self;
	GeeHashMap* _tmp0_ = NULL;
	DbusmenuMenuitem* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	parent_class = G_OBJECT_CLASS (playlists_menuitem_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = PLAYLISTS_MENUITEM (obj);
	_tmp0_ = gee_hash_map_new (G_TYPE_INT, NULL, NULL, DBUSMENU_TYPE_MENUITEM, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->current_playlists);
	self->priv->current_playlists = _tmp0_;
	_tmp1_ = dbusmenu_menuitem_new ();
	_g_object_unref0 (self->root_item);
	self->root_item = _tmp1_;
	_tmp2_ = _ ("Choose Playlist");
	dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_MENUITEM_PROP_LABEL, _tmp2_);
	dbusmenu_menuitem_property_set (self->root_item, DBUSMENU_PLAYLIST_MENUITEM_PATH, "");
	return obj;
}


static void playlists_menuitem_class_init (PlaylistsMenuitemClass * klass) {
	playlists_menuitem_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PlaylistsMenuitemPrivate));
	G_OBJECT_CLASS (klass)->constructor = playlists_menuitem_constructor;
	G_OBJECT_CLASS (klass)->finalize = playlists_menuitem_finalize;
}


static void playlists_menuitem_instance_init (PlaylistsMenuitem * self) {
	self->priv = PLAYLISTS_MENUITEM_GET_PRIVATE (self);
}


static void playlists_menuitem_finalize (GObject* obj) {
	PlaylistsMenuitem * self;
	self = PLAYLISTS_MENUITEM (obj);
	_g_object_unref0 (self->priv->current_playlists);
	_g_object_unref0 (self->root_item);
	G_OBJECT_CLASS (playlists_menuitem_parent_class)->finalize (obj);
}


GType playlists_menuitem_get_type (void) {
	static volatile gsize playlists_menuitem_type_id__volatile = 0;
	if (g_once_init_enter (&playlists_menuitem_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PlaylistsMenuitemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) playlists_menuitem_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PlaylistsMenuitem), 0, (GInstanceInitFunc) playlists_menuitem_instance_init, NULL };
		GType playlists_menuitem_type_id;
		playlists_menuitem_type_id = g_type_register_static (TYPE_PLAYER_ITEM, "PlaylistsMenuitem", &g_define_type_info, 0);
		g_once_init_leave (&playlists_menuitem_type_id__volatile, playlists_menuitem_type_id);
	}
	return playlists_menuitem_type_id__volatile;
}



