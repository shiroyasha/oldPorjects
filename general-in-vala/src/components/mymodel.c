/* mymodel.c generated by valac 0.9.8, the Vala compiler
 * generated from mymodel.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <gio/gio.h>
#include <float.h>
#include <math.h>


#define COMPONENTS_TYPE_DIRECTORY_MODEL (components_directory_model_get_type ())
#define COMPONENTS_DIRECTORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModel))
#define COMPONENTS_DIRECTORY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModelClass))
#define COMPONENTS_IS_DIRECTORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL))
#define COMPONENTS_IS_DIRECTORY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPONENTS_TYPE_DIRECTORY_MODEL))
#define COMPONENTS_DIRECTORY_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModelClass))

typedef struct _ComponentsDirectoryModel ComponentsDirectoryModel;
typedef struct _ComponentsDirectoryModelClass ComponentsDirectoryModelClass;
typedef struct _ComponentsDirectoryModelPrivate ComponentsDirectoryModelPrivate;

#define COMPONENTS_TYPE_MY_MODEL (components_my_model_get_type ())
#define COMPONENTS_MY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPONENTS_TYPE_MY_MODEL, ComponentsMyModel))
#define COMPONENTS_MY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), COMPONENTS_TYPE_MY_MODEL, ComponentsMyModelClass))
#define COMPONENTS_IS_MY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPONENTS_TYPE_MY_MODEL))
#define COMPONENTS_IS_MY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPONENTS_TYPE_MY_MODEL))
#define COMPONENTS_MY_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPONENTS_TYPE_MY_MODEL, ComponentsMyModelClass))

typedef struct _ComponentsMyModel ComponentsMyModel;
typedef struct _ComponentsMyModelClass ComponentsMyModelClass;
typedef struct _ComponentsMyModelPrivate ComponentsMyModelPrivate;
#define _gtk_icon_info_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_info_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ComponentsDirectoryModel {
	GObject parent_instance;
	ComponentsDirectoryModelPrivate * priv;
};

struct _ComponentsDirectoryModelClass {
	GObjectClass parent_class;
	GType (*get_column_type) (ComponentsDirectoryModel* self, gint index);
	void (*get_value) (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val);
};

struct _ComponentsMyModel {
	ComponentsDirectoryModel parent_instance;
	ComponentsMyModelPrivate * priv;
};

struct _ComponentsMyModelClass {
	ComponentsDirectoryModelClass parent_class;
};

struct _ComponentsMyModelPrivate {
	char** size_names;
	gint size_names_length1;
	gint _size_names_size_;
};


static gpointer components_my_model_parent_class = NULL;

GType components_directory_model_get_type (void) G_GNUC_CONST;
GType components_my_model_get_type (void) G_GNUC_CONST;
#define COMPONENTS_MY_MODEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), COMPONENTS_TYPE_MY_MODEL, ComponentsMyModelPrivate))
enum  {
	COMPONENTS_MY_MODEL_DUMMY_PROPERTY
};
static GType components_my_model_real_get_column_type (ComponentsDirectoryModel* base, gint index);
static void components_my_model_real_get_value (ComponentsDirectoryModel* base, GtkTreeIter* iter, gint column, GValue* val);
static char* components_my_model_get_formated_size (ComponentsMyModel* self, gint64 size);
static char* components_my_model_with_two_decimals (ComponentsMyModel* self, double i);
ComponentsMyModel* components_my_model_new (void);
ComponentsMyModel* components_my_model_construct (GType object_type);
ComponentsDirectoryModel* components_directory_model_new (void);
ComponentsDirectoryModel* components_directory_model_construct (GType object_type);
static GObject * components_my_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void components_my_model_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



static GType components_my_model_real_get_column_type (ComponentsDirectoryModel* base, gint index) {
	ComponentsMyModel * self;
	GType result = 0UL;
	self = (ComponentsMyModel*) base;
	if (index == 0) {
		result = GDK_TYPE_PIXBUF;
		return result;
	}
	result = G_TYPE_STRING;
	return result;
}


static void components_my_model_real_get_value (ComponentsDirectoryModel* base, GtkTreeIter* iter, gint column, GValue* val) {
	ComponentsMyModel * self;
	GFileInfo* info;
	GError * _inner_error_ = NULL;
	self = (ComponentsMyModel*) base;
	info = (GFileInfo*) (*iter).user_data;
	switch (column) {
		case 0:
		{
			{
				GtkIconTheme* theme;
				GtkIconInfo* icon_info;
				g_value_init (val, GDK_TYPE_PIXBUF);
				theme = gtk_icon_theme_new ();
				icon_info = gtk_icon_theme_lookup_by_gicon (gtk_icon_theme_get_default (), g_file_info_get_icon (info), 16, 0);
				if (icon_info != NULL) {
					GdkPixbuf* _tmp0_;
					GdkPixbuf* _tmp1_;
					_tmp0_ = gtk_icon_info_load_icon (icon_info, &_inner_error_);
					if (_inner_error_ != NULL) {
						_gtk_icon_info_free0 (icon_info);
						_g_object_unref0 (theme);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return;
					}
					g_value_set_object (val, (GObject*) (_tmp1_ = _tmp0_));
					_g_object_unref0 (_tmp1_);
				}
				_gtk_icon_info_free0 (icon_info);
				_g_object_unref0 (theme);
				break;
			}
		}
		case 1:
		{
			{
				g_value_init (val, G_TYPE_STRING);
				g_value_set_string (val, g_file_info_get_display_name (info));
				break;
			}
		}
		case 2:
		{
			{
				char* _tmp2_;
				g_value_init (val, G_TYPE_STRING);
				g_value_set_string (val, _tmp2_ = components_my_model_get_formated_size (self, g_file_info_get_size (info)));
				_g_free0 (_tmp2_);
				break;
			}
		}
	}
}


static char* components_my_model_get_formated_size (ComponentsMyModel* self, gint64 size) {
	char* result = NULL;
	double helper;
	gint i;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	helper = (double) size;
	i = 0;
	{
		gboolean _tmp0_;
		i = 0;
		_tmp0_ = TRUE;
		while (TRUE) {
			if (!_tmp0_) {
				i = i + 1;
			}
			_tmp0_ = FALSE;
			if (!(helper > 2048.0)) {
				break;
			}
			helper = helper / 2048.0;
		}
	}
	result = (_tmp3_ = g_strconcat (_tmp2_ = g_strconcat (_tmp1_ = components_my_model_with_two_decimals (self, helper), " ", NULL), self->priv->size_names[i], NULL), _g_free0 (_tmp2_), _g_free0 (_tmp1_), _tmp3_);
	return result;
}


static char* components_my_model_with_two_decimals (ComponentsMyModel* self, double i) {
	char* result = NULL;
	gint whole;
	gint bdot;
	gint adot;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	char* _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	whole = (gint) (i * 100.0);
	bdot = whole / 100;
	adot = whole - (bdot * 100);
	result = (_tmp3_ = g_strconcat (_tmp1_ = g_strconcat (_tmp0_ = g_strdup_printf ("%i", bdot), ".", NULL), _tmp2_ = g_strdup_printf ("%i", adot), NULL), _g_free0 (_tmp2_), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp3_);
	return result;
}


ComponentsMyModel* components_my_model_construct (GType object_type) {
	ComponentsMyModel * self;
	self = (ComponentsMyModel*) components_directory_model_construct (object_type);
	return self;
}


ComponentsMyModel* components_my_model_new (void) {
	return components_my_model_construct (COMPONENTS_TYPE_MY_MODEL);
}


static GObject * components_my_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	ComponentsMyModel * self;
	parent_class = G_OBJECT_CLASS (components_my_model_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = COMPONENTS_MY_MODEL (obj);
	{
	}
	return obj;
}


static void components_my_model_class_init (ComponentsMyModelClass * klass) {
	components_my_model_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ComponentsMyModelPrivate));
	COMPONENTS_DIRECTORY_MODEL_CLASS (klass)->get_column_type = components_my_model_real_get_column_type;
	COMPONENTS_DIRECTORY_MODEL_CLASS (klass)->get_value = components_my_model_real_get_value;
	G_OBJECT_CLASS (klass)->constructor = components_my_model_constructor;
	G_OBJECT_CLASS (klass)->finalize = components_my_model_finalize;
}


static void components_my_model_instance_init (ComponentsMyModel * self) {
	char** _tmp0_ = NULL;
	self->priv = COMPONENTS_MY_MODEL_GET_PRIVATE (self);
	self->priv->size_names = (_tmp0_ = g_new0 (char*, 9 + 1), _tmp0_[0] = g_strdup ("B"), _tmp0_[1] = g_strdup ("KiB"), _tmp0_[2] = g_strdup ("MiB"), _tmp0_[3] = g_strdup ("GiB"), _tmp0_[4] = g_strdup ("TiB"), _tmp0_[5] = g_strdup ("PiT"), _tmp0_[6] = g_strdup ("EiB"), _tmp0_[7] = g_strdup ("ZiB"), _tmp0_[8] = g_strdup ("YiB"), _tmp0_);
	self->priv->size_names_length1 = 9;
	self->priv->_size_names_size_ = self->priv->size_names_length1;
}


static void components_my_model_finalize (GObject* obj) {
	ComponentsMyModel * self;
	self = COMPONENTS_MY_MODEL (obj);
	self->priv->size_names = (_vala_array_free (self->priv->size_names, self->priv->size_names_length1, (GDestroyNotify) g_free), NULL);
	G_OBJECT_CLASS (components_my_model_parent_class)->finalize (obj);
}


GType components_my_model_get_type (void) {
	static volatile gsize components_my_model_type_id__volatile = 0;
	if (g_once_init_enter (&components_my_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ComponentsMyModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) components_my_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ComponentsMyModel), 0, (GInstanceInitFunc) components_my_model_instance_init, NULL };
		GType components_my_model_type_id;
		components_my_model_type_id = g_type_register_static (COMPONENTS_TYPE_DIRECTORY_MODEL, "ComponentsMyModel", &g_define_type_info, 0);
		g_once_init_leave (&components_my_model_type_id__volatile, components_my_model_type_id);
	}
	return components_my_model_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}




