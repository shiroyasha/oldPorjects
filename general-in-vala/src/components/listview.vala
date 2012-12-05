using Gtk;

namespace Components
{
    class ListView : Gtk.TreeView
    {
        construct
        {
            MyModel store = new MyModel();
            Gtk.TreeModelFilter filter = new Gtk.TreeModelFilter( store , null);
            set_model( filter );
            this.append_column( this.create_name_column("Name", 0, 1) );
            this.append_column( this.create_text_column("Size",  2, 1.0f) );
            this.append_column( this.create_text_column("Modified", 2) );
        }
        
        
        
        private TreeViewColumn create_text_column( string name ,  int model_index, float xalign = 1.0)
        {
            Gtk.CellRendererText renderer_text = new Gtk.CellRendererText();
            renderer_text.set_property("xalign", xalign);
            
            Gtk.TreeViewColumn column = new Gtk.TreeViewColumn();
            column.set_property("alignment", xalign );
            column.set_title( name );
            
            column.pack_start(renderer_text, true);
            
            column.add_attribute( renderer_text, "text", model_index );
            return column;
        }
        
        private TreeViewColumn create_name_column(string name, int model_index_icon, int model_index_name )
        {
            Gtk.CellRendererText renderer_text = new Gtk.CellRendererText();
            Gtk.CellRendererPixbuf renderer_icon = new Gtk.CellRendererPixbuf();
            
            Gtk.TreeViewColumn column = new Gtk.TreeViewColumn();
            column.set_expand(true);
            column.set_title( name );
            
            column.pack_start(renderer_icon, false);
            column.pack_start(renderer_text, true);
            
            column.add_attribute( renderer_text, "text", model_index_name );
            column.add_attribute( renderer_icon, "pixbuf", model_index_icon );
            return column;
        }
        
    }
}
