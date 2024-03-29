/* directorymodel.c generated by valac 0.9.8, the Vala compiler
 * generated from directorymodel.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gee.h>
#include <gio/gio.h>
#include <gdk-pixbuf/gdk-pixdata.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define COMPONENTS_TYPE_DIRECTORY_MODEL (components_directory_model_get_type ())
#define COMPONENTS_DIRECTORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModel))
#define COMPONENTS_DIRECTORY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModelClass))
#define COMPONENTS_IS_DIRECTORY_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL))
#define COMPONENTS_IS_DIRECTORY_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), COMPONENTS_TYPE_DIRECTORY_MODEL))
#define COMPONENTS_DIRECTORY_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModelClass))

typedef struct _ComponentsDirectoryModel ComponentsDirectoryModel;
typedef struct _ComponentsDirectoryModelClass ComponentsDirectoryModelClass;
typedef struct _ComponentsDirectoryModelPrivate ComponentsDirectoryModelPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _gtk_tree_path_free0(var) ((var == NULL) ? NULL : (var = (gtk_tree_path_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _ComponentsDirectoryModel {
	GObject parent_instance;
	ComponentsDirectoryModelPrivate * priv;
};

struct _ComponentsDirectoryModelClass {
	GObjectClass parent_class;
	GType (*get_column_type) (ComponentsDirectoryModel* self, gint index);
	void (*get_value) (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val);
};

struct _ComponentsDirectoryModelPrivate {
	GeeArrayList* file_list;
};


static gpointer components_directory_model_parent_class = NULL;
static GtkTreeModelIface* components_directory_model_gtk_tree_model_parent_iface = NULL;

GType components_directory_model_get_type (void) G_GNUC_CONST;
#define COMPONENTS_DIRECTORY_MODEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), COMPONENTS_TYPE_DIRECTORY_MODEL, ComponentsDirectoryModelPrivate))
enum  {
	COMPONENTS_DIRECTORY_MODEL_DUMMY_PROPERTY
};
GType components_directory_model_get_column_type (ComponentsDirectoryModel* self, gint index);
static GType components_directory_model_real_get_column_type (ComponentsDirectoryModel* self, gint index);
static GtkTreeModelFlags components_directory_model_real_get_flags (GtkTreeModel* base);
static gboolean components_directory_model_real_get_iter (GtkTreeModel* base, GtkTreeIter* iter, GtkTreePath* path);
static gint components_directory_model_real_get_n_columns (GtkTreeModel* base);
static GtkTreePath* components_directory_model_real_get_path (GtkTreeModel* base, GtkTreeIter* iter);
void components_directory_model_get_value (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val);
static void components_directory_model_real_get_value (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val);
static gboolean components_directory_model_real_iter_children (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* parent);
static gboolean components_directory_model_real_iter_has_child (GtkTreeModel* base, GtkTreeIter* iter);
static gint components_directory_model_real_iter_n_children (GtkTreeModel* base, GtkTreeIter* iter);
static gboolean components_directory_model_real_iter_next (GtkTreeModel* base, GtkTreeIter* iter);
static gboolean components_directory_model_real_iter_nth_child (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* parent, gint n);
static gboolean components_directory_model_real_iter_parent (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* child);
static void components_directory_model_real_ref_node (GtkTreeModel* base, GtkTreeIter* iter);
static void components_directory_model_real_unref_node (GtkTreeModel* base, GtkTreeIter* iter);
ComponentsDirectoryModel* components_directory_model_new (void);
ComponentsDirectoryModel* components_directory_model_construct (GType object_type);
static GObject * components_directory_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void components_directory_model_finalize (GObject* obj);



static GType components_directory_model_real_get_column_type (ComponentsDirectoryModel* self, gint index) {
	GType result = 0UL;
	g_return_val_if_fail (self != NULL, 0UL);
	if (index == 0) {
		result = GDK_TYPE_PIXBUF;
		return result;
	}
	result = G_TYPE_STRING;
	return result;
}


GType components_directory_model_get_column_type (ComponentsDirectoryModel* self, gint index) {
	return COMPONENTS_DIRECTORY_MODEL_GET_CLASS (self)->get_column_type (self, index);
}


static GtkTreeModelFlags components_directory_model_real_get_flags (GtkTreeModel* base) {
	ComponentsDirectoryModel * self;
	GtkTreeModelFlags result = 0;
	self = (ComponentsDirectoryModel*) base;
	result = GTK_TREE_MODEL_LIST_ONLY;
	return result;
}


static gboolean components_directory_model_real_get_iter (GtkTreeModel* base, GtkTreeIter* iter, GtkTreePath* path) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	gint index;
	gboolean _tmp0_ = FALSE;
	self = (ComponentsDirectoryModel*) base;
	g_return_val_if_fail (path != NULL, FALSE);
	index = gtk_tree_path_get_indices (path)[0];
	if (index < gee_collection_get_size ((GeeCollection*) self->priv->file_list)) {
		_tmp0_ = index >= 0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GFileInfo* file;
		file = (GFileInfo*) gee_abstract_list_get ((GeeAbstractList*) self->priv->file_list, index);
		(*iter).stamp = 1723;
		(*iter).user_data = file;
		result = TRUE;
		return result;
	}
	(*iter).stamp = 1723;
	(*iter).user_data = NULL;
	result = FALSE;
	return result;
}


static gint components_directory_model_real_get_n_columns (GtkTreeModel* base) {
	ComponentsDirectoryModel * self;
	gint result = 0;
	self = (ComponentsDirectoryModel*) base;
	result = 1;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GtkTreePath* components_directory_model_real_get_path (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	GtkTreePath* result = NULL;
	GFileInfo* file;
	self = (ComponentsDirectoryModel*) base;
	file = _g_object_ref0 ((GFileInfo*) (*iter).user_data);
	if (gee_abstract_collection_contains ((GeeAbstractCollection*) self->priv->file_list, file)) {
		gint index;
		GtkTreePath* path;
		index = gee_abstract_list_index_of ((GeeAbstractList*) self->priv->file_list, file);
		path = gtk_tree_path_new_from_indices (index, -1);
		result = path;
		_g_object_unref0 (file);
		return result;
	}
	result = gtk_tree_path_new_from_indices (-1, -1);
	_g_object_unref0 (file);
	return result;
}


static void components_directory_model_real_get_value (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val) {
	g_return_if_fail (self != NULL);
}


void components_directory_model_get_value (ComponentsDirectoryModel* self, GtkTreeIter* iter, gint column, GValue* val) {
	COMPONENTS_DIRECTORY_MODEL_GET_CLASS (self)->get_value (self, iter, column, val);
}


static gboolean components_directory_model_real_iter_children (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* parent) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	self = (ComponentsDirectoryModel*) base;
	if (parent == NULL) {
		GtkTreePath* _tmp0_;
		gboolean _tmp1_;
		result = (_tmp1_ = gtk_tree_model_get_iter ((GtkTreeModel*) self, iter, _tmp0_ = gtk_tree_path_new_from_indices (0, -1)), _gtk_tree_path_free0 (_tmp0_), _tmp1_);
		return result;
	}
	result = FALSE;
	return result;
}


static gboolean components_directory_model_real_iter_has_child (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	self = (ComponentsDirectoryModel*) base;
	result = FALSE;
	return result;
}


static gint components_directory_model_real_iter_n_children (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	gint result = 0;
	self = (ComponentsDirectoryModel*) base;
	if (iter == NULL) {
		result = gee_collection_get_size ((GeeCollection*) self->priv->file_list);
		return result;
	}
	result = 0;
	return result;
}


static gboolean components_directory_model_real_iter_next (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	GFileInfo* name;
	gint index;
	GtkTreePath* _tmp0_;
	gboolean _tmp1_;
	self = (ComponentsDirectoryModel*) base;
	name = _g_object_ref0 ((GFileInfo*) (*iter).user_data);
	index = gee_abstract_list_index_of ((GeeAbstractList*) self->priv->file_list, name) + 1;
	result = (_tmp1_ = gtk_tree_model_get_iter ((GtkTreeModel*) self, iter, _tmp0_ = gtk_tree_path_new_from_indices (index, -1)), _gtk_tree_path_free0 (_tmp0_), _tmp1_);
	_g_object_unref0 (name);
	return result;
	_g_object_unref0 (name);
}


static gboolean components_directory_model_real_iter_nth_child (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* parent, gint n) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	self = (ComponentsDirectoryModel*) base;
	if (parent == NULL) {
		GtkTreePath* _tmp0_;
		gboolean _tmp1_;
		result = (_tmp1_ = gtk_tree_model_get_iter ((GtkTreeModel*) self, iter, _tmp0_ = gtk_tree_path_new_from_indices (n, -1)), _gtk_tree_path_free0 (_tmp0_), _tmp1_);
		return result;
	}
	result = FALSE;
	return result;
}


static gboolean components_directory_model_real_iter_parent (GtkTreeModel* base, GtkTreeIter* iter, GtkTreeIter* child) {
	ComponentsDirectoryModel * self;
	gboolean result = FALSE;
	self = (ComponentsDirectoryModel*) base;
	result = FALSE;
	return result;
}


static void components_directory_model_real_ref_node (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	self = (ComponentsDirectoryModel*) base;
}


static void components_directory_model_real_unref_node (GtkTreeModel* base, GtkTreeIter* iter) {
	ComponentsDirectoryModel * self;
	self = (ComponentsDirectoryModel*) base;
}


ComponentsDirectoryModel* components_directory_model_construct (GType object_type) {
	ComponentsDirectoryModel * self;
	self = (ComponentsDirectoryModel*) g_object_new (object_type, NULL);
	return self;
}


ComponentsDirectoryModel* components_directory_model_new (void) {
	return components_directory_model_construct (COMPONENTS_TYPE_DIRECTORY_MODEL);
}


static GObject * components_directory_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	ComponentsDirectoryModel * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (components_directory_model_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = COMPONENTS_DIRECTORY_MODEL (obj);
	_inner_error_ = NULL;
	{
		GeeArrayList* _tmp0_;
		self->priv->file_list = (_tmp0_ = gee_array_list_new (G_TYPE_FILE_INFO, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->file_list), _tmp0_);
		{
			GFile* directory;
			GFileEnumerator* enumerator;
			GFileInfo* file_info;
			directory = g_file_new_for_path ("/usr/bin");
			enumerator = g_file_enumerate_children (directory, "standard::*", 0, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (directory);
				goto __catch0_g_error;
			}
			file_info = NULL;
			while (TRUE) {
				GFileInfo* _tmp1_;
				GFileInfo* _tmp2_;
				_tmp1_ = g_file_enumerator_next_file (enumerator, NULL, &_inner_error_);
				if (_inner_error_ != NULL) {
					_g_object_unref0 (file_info);
					_g_object_unref0 (enumerator);
					_g_object_unref0 (directory);
					goto __catch0_g_error;
				}
				if (!((file_info = (_tmp2_ = _tmp1_, _g_object_unref0 (file_info), _tmp2_)) != NULL)) {
					break;
				}
				gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->file_list, file_info);
			}
			_g_object_unref0 (file_info);
			_g_object_unref0 (enumerator);
			_g_object_unref0 (directory);
		}
		goto __finally0;
		__catch0_g_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				fprintf (stderr, "Error: %s\n", e->message);
				_g_error_free0 (e);
			}
		}
		__finally0:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
	}
	return obj;
}


static void components_directory_model_class_init (ComponentsDirectoryModelClass * klass) {
	components_directory_model_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ComponentsDirectoryModelPrivate));
	COMPONENTS_DIRECTORY_MODEL_CLASS (klass)->get_column_type = components_directory_model_real_get_column_type;
	COMPONENTS_DIRECTORY_MODEL_CLASS (klass)->get_value = components_directory_model_real_get_value;
	G_OBJECT_CLASS (klass)->constructor = components_directory_model_constructor;
	G_OBJECT_CLASS (klass)->finalize = components_directory_model_finalize;
}


static void components_directory_model_gtk_tree_model_interface_init (GtkTreeModelIface * iface) {
	components_directory_model_gtk_tree_model_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_column_type = (GType (*)(GtkTreeModel* ,gint)) components_directory_model_get_column_type;
	iface->get_flags = components_directory_model_real_get_flags;
	iface->get_iter = components_directory_model_real_get_iter;
	iface->get_n_columns = components_directory_model_real_get_n_columns;
	iface->get_path = components_directory_model_real_get_path;
	iface->get_value = (void (*)(GtkTreeModel* ,GtkTreeIter* ,gint ,GValue*)) components_directory_model_get_value;
	iface->iter_children = components_directory_model_real_iter_children;
	iface->iter_has_child = components_directory_model_real_iter_has_child;
	iface->iter_n_children = components_directory_model_real_iter_n_children;
	iface->iter_next = components_directory_model_real_iter_next;
	iface->iter_nth_child = components_directory_model_real_iter_nth_child;
	iface->iter_parent = components_directory_model_real_iter_parent;
	iface->ref_node = components_directory_model_real_ref_node;
	iface->unref_node = components_directory_model_real_unref_node;
}


static void components_directory_model_instance_init (ComponentsDirectoryModel * self) {
	self->priv = COMPONENTS_DIRECTORY_MODEL_GET_PRIVATE (self);
	self->priv->file_list = NULL;
}


static void components_directory_model_finalize (GObject* obj) {
	ComponentsDirectoryModel * self;
	self = COMPONENTS_DIRECTORY_MODEL (obj);
	_g_object_unref0 (self->priv->file_list);
	G_OBJECT_CLASS (components_directory_model_parent_class)->finalize (obj);
}


GType components_directory_model_get_type (void) {
	static volatile gsize components_directory_model_type_id__volatile = 0;
	if (g_once_init_enter (&components_directory_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ComponentsDirectoryModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) components_directory_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ComponentsDirectoryModel), 0, (GInstanceInitFunc) components_directory_model_instance_init, NULL };
		static const GInterfaceInfo gtk_tree_model_info = { (GInterfaceInitFunc) components_directory_model_gtk_tree_model_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType components_directory_model_type_id;
		components_directory_model_type_id = g_type_register_static (G_TYPE_OBJECT, "ComponentsDirectoryModel", &g_define_type_info, 0);
		g_type_add_interface_static (components_directory_model_type_id, GTK_TYPE_TREE_MODEL, &gtk_tree_model_info);
		g_once_init_leave (&components_directory_model_type_id__volatile, components_directory_model_type_id);
	}
	return components_directory_model_type_id__volatile;
}




