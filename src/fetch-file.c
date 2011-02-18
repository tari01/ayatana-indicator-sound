/* fetch-file.c generated by valac 0.11.6, the Vala compiler
 * generated from fetch-file.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors
 *      Gordon Allott <gord.allott@canonical.com>
 *      Conor Curran <conor.curran@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define TYPE_FETCH_FILE (fetch_file_get_type ())
#define FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FETCH_FILE, FetchFile))
#define FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FETCH_FILE, FetchFileClass))
#define IS_FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FETCH_FILE))
#define IS_FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FETCH_FILE))
#define FETCH_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FETCH_FILE, FetchFileClass))

typedef struct _FetchFile FetchFile;
typedef struct _FetchFileClass FetchFileClass;
typedef struct _FetchFilePrivate FetchFilePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_byte_array_free0(var) ((var == NULL) ? NULL : (var = (g_byte_array_free (var, TRUE), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _FetchFileFetchDataData FetchFileFetchDataData;
typedef struct _FetchFileReadSomethingAsyncData FetchFileReadSomethingAsyncData;

struct _FetchFile {
	GObject parent_instance;
	FetchFilePrivate * priv;
};

struct _FetchFileClass {
	GObjectClass parent_class;
};

struct _FetchFilePrivate {
	gchar* _uri;
	gchar* _intended_property;
	GDataInputStream* stream;
	GFile* file;
	GByteArray* data;
};

struct _FetchFileFetchDataData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FetchFile* self;
	GFileInputStream* _tmp0_;
	GFileInputStream* _tmp1_;
	GFileInputStream* _tmp2_;
	GDataInputStream* _tmp3_;
	GDataInputStream* _tmp4_;
	GError * e;
	GError * _inner_error_;
};

struct _FetchFileReadSomethingAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	FetchFile* self;
	gssize size;
	guint8* _tmp0_;
	guint8* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	gssize bufsize;
	gboolean _tmp1_;
	gssize _tmp2_;
	gssize _tmp3_;
	guint8* _tmp4_;
	guint8* cpybuf;
	gint cpybuf_length1;
	gint _cpybuf_size_;
	GError * e;
	GError * _inner_error_;
};


static gpointer fetch_file_parent_class = NULL;

GType fetch_file_get_type (void) G_GNUC_CONST;
#define FETCH_FILE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_FETCH_FILE, FetchFilePrivate))
enum  {
	FETCH_FILE_DUMMY_PROPERTY,
	FETCH_FILE_URI,
	FETCH_FILE_INTENDED_PROPERTY
};
FetchFile* fetch_file_new (const gchar* uri, const gchar* prop);
FetchFile* fetch_file_construct (GType object_type, const gchar* uri, const gchar* prop);
static void fetch_file_fetch_data_data_free (gpointer _data);
void fetch_file_fetch_data (FetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fetch_file_fetch_data_finish (FetchFile* self, GAsyncResult* _res_);
static gboolean fetch_file_fetch_data_co (FetchFileFetchDataData* data);
static void fetch_file_read_something_async (FetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void fetch_file_read_something_finish (FetchFile* self, GAsyncResult* _res_);
static void fetch_file_read_something_async_data_free (gpointer _data);
static gboolean fetch_file_read_something_async_co (FetchFileReadSomethingAsyncData* data);
static void fetch_file_read_something_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
const gchar* fetch_file_get_intended_property (FetchFile* self);
const gchar* fetch_file_get_uri (FetchFile* self);
static void fetch_file_set_uri (FetchFile* self, const gchar* value);
static void fetch_file_set_intended_property (FetchFile* self, const gchar* value);
static void g_cclosure_user_marshal_VOID__POINTER_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static GObject * fetch_file_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void fetch_file_finalize (GObject* obj);
static void _vala_fetch_file_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_fetch_file_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


FetchFile* fetch_file_construct (GType object_type, const gchar* uri, const gchar* prop) {
	FetchFile * self = NULL;
	g_return_val_if_fail (uri != NULL, NULL);
	g_return_val_if_fail (prop != NULL, NULL);
	self = (FetchFile*) g_object_new (object_type, "uri", uri, "intended-property", prop, NULL);
	return self;
}


FetchFile* fetch_file_new (const gchar* uri, const gchar* prop) {
	return fetch_file_construct (TYPE_FETCH_FILE, uri, prop);
}


static void fetch_file_fetch_data_data_free (gpointer _data) {
	FetchFileFetchDataData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (FetchFileFetchDataData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void fetch_file_fetch_data (FetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FetchFileFetchDataData* _data_;
	_data_ = g_slice_new0 (FetchFileFetchDataData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fetch_file_fetch_data);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fetch_file_fetch_data_data_free);
	_data_->self = _g_object_ref0 (self);
	fetch_file_fetch_data_co (_data_);
}


void fetch_file_fetch_data_finish (FetchFile* self, GAsyncResult* _res_) {
	FetchFileFetchDataData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean fetch_file_fetch_data_co (FetchFileFetchDataData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	data->_tmp0_ = NULL;
	data->_tmp0_ = g_file_read (data->self->priv->file, NULL, &data->_inner_error_);
	data->_tmp1_ = data->_tmp0_;
	if (data->_inner_error_ != NULL) {
		goto __catch14_g_error;
	}
	data->_tmp2_ = data->_tmp1_;
	data->_tmp3_ = NULL;
	data->_tmp3_ = g_data_input_stream_new ((GInputStream*) data->_tmp2_);
	data->_tmp4_ = data->_tmp3_;
	_g_object_unref0 (data->self->priv->stream);
	data->self->priv->stream = data->_tmp4_;
	_g_object_unref0 (data->_tmp2_);
	g_data_input_stream_set_byte_order (data->self->priv->stream, G_DATA_STREAM_BYTE_ORDER_LITTLE_ENDIAN);
	goto __finally14;
	__catch14_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		g_signal_emit_by_name (data->self, "failed");
		_g_error_free0 (data->e);
	}
	__finally14:
	if (data->_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	fetch_file_read_something_async (data->self, NULL, NULL);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


static void fetch_file_read_something_async_data_free (gpointer _data) {
	FetchFileReadSomethingAsyncData* data;
	data = _data;
	_g_object_unref0 (data->self);
	g_slice_free (FetchFileReadSomethingAsyncData, data);
}


static void fetch_file_read_something_async (FetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	FetchFileReadSomethingAsyncData* _data_;
	_data_ = g_slice_new0 (FetchFileReadSomethingAsyncData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, fetch_file_read_something_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, fetch_file_read_something_async_data_free);
	_data_->self = _g_object_ref0 (self);
	fetch_file_read_something_async_co (_data_);
}


static void fetch_file_read_something_finish (FetchFile* self, GAsyncResult* _res_) {
	FetchFileReadSomethingAsyncData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void fetch_file_read_something_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	FetchFileReadSomethingAsyncData* data;
	data = _user_data_;
	data->_source_object_ = source_object;
	data->_res_ = _res_;
	fetch_file_read_something_async_co (data);
}


static gboolean fetch_file_read_something_async_co (FetchFileReadSomethingAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	data->size = (gssize) 1024;
	data->_tmp0_ = NULL;
	data->_tmp0_ = g_new0 (guint8, data->size);
	data->buffer = data->_tmp0_;
	data->buffer_length1 = data->size;
	data->_buffer_size_ = data->size;
	data->bufsize = (gssize) 1;
	{
		data->_tmp1_ = TRUE;
		while (TRUE) {
			if (!data->_tmp1_) {
				if (!(data->bufsize > 0)) {
					break;
				}
			}
			data->_tmp1_ = FALSE;
			data->_state_ = 1;
			g_input_stream_read_async ((GInputStream*) data->self->priv->stream, data->buffer, (gsize) data->buffer_length1, G_PRIORITY_DEFAULT, NULL, fetch_file_read_something_async_ready, data);
			return FALSE;
			_state_1:
			data->_tmp2_ = g_input_stream_read_finish ((GInputStream*) data->self->priv->stream, data->_res_, &data->_inner_error_);
			data->_tmp3_ = data->_tmp2_;
			if (data->_inner_error_ != NULL) {
				goto __catch15_g_error;
			}
			data->bufsize = data->_tmp3_;
			if (data->bufsize < 1) {
				break;
			}
			if (data->bufsize != data->size) {
				data->_tmp4_ = NULL;
				data->_tmp4_ = g_new0 (guint8, data->bufsize);
				data->cpybuf = data->_tmp4_;
				data->cpybuf_length1 = data->bufsize;
				data->_cpybuf_size_ = data->bufsize;
				memcpy (data->cpybuf, data->buffer, (gsize) data->bufsize);
				g_byte_array_append (data->self->priv->data, data->cpybuf, data->cpybuf_length1);
				data->cpybuf = (g_free (data->cpybuf), NULL);
			} else {
				g_byte_array_append (data->self->priv->data, data->buffer, data->buffer_length1);
			}
			goto __finally15;
			__catch15_g_error:
			{
				data->e = data->_inner_error_;
				data->_inner_error_ = NULL;
				g_signal_emit_by_name (data->self, "failed");
				_g_error_free0 (data->e);
			}
			__finally15:
			if (data->_inner_error_ != NULL) {
				data->buffer = (g_free (data->buffer), NULL);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
				g_clear_error (&data->_inner_error_);
				return FALSE;
			}
		}
	}
	g_signal_emit_by_name (data->self, "completed", data->self->priv->data, data->self->priv->_intended_property);
	data->buffer = (g_free (data->buffer), NULL);
	if (data->_state_ == 0) {
		g_simple_async_result_complete_in_idle (data->_async_result);
	} else {
		g_simple_async_result_complete (data->_async_result);
	}
	g_object_unref (data->_async_result);
	return FALSE;
}


const gchar* fetch_file_get_uri (FetchFile* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_uri;
	return result;
}


static void fetch_file_set_uri (FetchFile* self, const gchar* value) {
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_tmp1_ = _tmp0_;
	_g_free0 (self->priv->_uri);
	self->priv->_uri = _tmp1_;
	g_object_notify ((GObject *) self, "uri");
}


const gchar* fetch_file_get_intended_property (FetchFile* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_intended_property;
	return result;
}


static void fetch_file_set_intended_property (FetchFile* self, const gchar* value) {
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_tmp1_ = _tmp0_;
	_g_free0 (self->priv->_intended_property);
	self->priv->_intended_property = _tmp1_;
	g_object_notify ((GObject *) self, "intended-property");
}


static void g_cclosure_user_marshal_VOID__POINTER_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__POINTER_STRING) (gpointer data1, gpointer arg_1, const char* arg_2, gpointer data2);
	register GMarshalFunc_VOID__POINTER_STRING callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__POINTER_STRING) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_pointer (param_values + 1), g_value_get_string (param_values + 2), data2);
}


static GObject * fetch_file_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	FetchFile * self;
	GFile* _tmp0_ = NULL;
	GFile* _tmp1_;
	GByteArray* _tmp2_ = NULL;
	GByteArray* _tmp3_;
	parent_class = G_OBJECT_CLASS (fetch_file_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = FETCH_FILE (obj);
	_tmp0_ = g_file_new_for_uri (self->priv->_uri);
	_tmp1_ = _tmp0_;
	_g_object_unref0 (self->priv->file);
	self->priv->file = _tmp1_;
	_tmp2_ = g_byte_array_new ();
	_tmp3_ = _tmp2_;
	_g_byte_array_free0 (self->priv->data);
	self->priv->data = _tmp3_;
	return obj;
}


static void fetch_file_class_init (FetchFileClass * klass) {
	fetch_file_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FetchFilePrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_fetch_file_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_fetch_file_set_property;
	G_OBJECT_CLASS (klass)->constructor = fetch_file_constructor;
	G_OBJECT_CLASS (klass)->finalize = fetch_file_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FETCH_FILE_URI, g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FETCH_FILE_INTENDED_PROPERTY, g_param_spec_string ("intended-property", "intended-property", "intended-property", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("failed", TYPE_FETCH_FILE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("completed", TYPE_FETCH_FILE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__POINTER_STRING, G_TYPE_NONE, 2, G_TYPE_POINTER, G_TYPE_STRING);
}


static void fetch_file_instance_init (FetchFile * self) {
	self->priv = FETCH_FILE_GET_PRIVATE (self);
}


static void fetch_file_finalize (GObject* obj) {
	FetchFile * self;
	self = FETCH_FILE (obj);
	_g_free0 (self->priv->_uri);
	_g_free0 (self->priv->_intended_property);
	_g_object_unref0 (self->priv->stream);
	_g_object_unref0 (self->priv->file);
	_g_byte_array_free0 (self->priv->data);
	G_OBJECT_CLASS (fetch_file_parent_class)->finalize (obj);
}


GType fetch_file_get_type (void) {
	static volatile gsize fetch_file_type_id__volatile = 0;
	if (g_once_init_enter (&fetch_file_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FetchFileClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fetch_file_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FetchFile), 0, (GInstanceInitFunc) fetch_file_instance_init, NULL };
		GType fetch_file_type_id;
		fetch_file_type_id = g_type_register_static (G_TYPE_OBJECT, "FetchFile", &g_define_type_info, 0);
		g_once_init_leave (&fetch_file_type_id__volatile, fetch_file_type_id);
	}
	return fetch_file_type_id__volatile;
}


static void _vala_fetch_file_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	FetchFile * self;
	self = FETCH_FILE (object);
	switch (property_id) {
		case FETCH_FILE_URI:
		g_value_set_string (value, fetch_file_get_uri (self));
		break;
		case FETCH_FILE_INTENDED_PROPERTY:
		g_value_set_string (value, fetch_file_get_intended_property (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_fetch_file_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	FetchFile * self;
	self = FETCH_FILE (object);
	switch (property_id) {
		case FETCH_FILE_URI:
		fetch_file_set_uri (self, g_value_get_string (value));
		break;
		case FETCH_FILE_INTENDED_PROPERTY:
		fetch_file_set_intended_property (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



