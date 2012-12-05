using Gtk;
using Gee;

namespace Components
{
    class DirectoryModel : GLib.Object, Gtk.TreeModel
    {
        private Gee.ArrayList<FileInfo> file_list = null;
        
        construct
        {
            file_list = new Gee.ArrayList<FileInfo> ();
            
            try 
            {
                var directory = File.new_for_path ("/usr/bin");

                var enumerator = directory.enumerate_children ("standard::*", 0, null);

                FileInfo file_info;
                while ((file_info = enumerator.next_file (null)) != null) 
                {
                    file_list.add(  file_info );
                }

            } 
            catch (Error e) {
                stderr.printf ("Error: %s\n", e.message);
            }
        }
        
        public virtual Type get_column_type ( int index ) { }
        
        protected void reset_all()
        {
            int lenght;
            lenght = file_list.
            for( int i = 0; i < lenght; ++i)
            {
                TreeIter iter;
                get_iter(out iter, Gtk.TreePath.from_indices(i) );
                row_changed( Gtk.TreePath.from_indices(i) , iter );
            }
        }
        
        public TreeModelFlags get_flags ()
        {
            return Gtk.TreeModelFlags.LIST_ONLY;
        }
        
        public bool get_iter(out TreeIter iter, TreePath path)
        {
            int index = path.get_indices()[0];
            
            if ( index < file_list.size && index >= 0)
            {
                FileInfo* file = file_list.get(index);
                
                iter.stamp = 1723;
                iter.user_data = file;
                return true;
            }
            iter.stamp = 1723;
            iter.user_data = null;
            return false;
        }
        
        public int get_n_columns ()
        {
            return 1;
        }
        
        public TreePath get_path (TreeIter iter)
        {
            FileInfo file = (FileInfo*)iter.user_data;
            if ( file_list.contains( file ) )
            {
                int index = file_list.index_of( file ); 
                TreePath path = new TreePath.from_indices( index );
                return path; 
            }
            return new TreePath.from_indices(-1);
        }
        
        public virtual void get_value ( TreeIter iter, int column , out Value val)
        {
        }
        
        public bool iter_children ( out TreeIter iter, TreeIter? parent)
        {
            if( parent == null)
            {
                return get_iter( out iter, new TreePath.from_indices(0) );
            }
            
            return false;  
        }
        
        public bool iter_has_child (TreeIter iter)
        {
            return false;
        }
        
        public int iter_n_children ( TreeIter? iter)
        {
            if (iter == null)
            {
                return file_list.size;
            }
            return 0;
        }
        
        public bool iter_next ( ref TreeIter iter)
        {
            FileInfo name = (FileInfo*)iter.user_data;
            
            int index = file_list.index_of(name) + 1;
            return get_iter( out iter, new TreePath.from_indices(index) );
        }
        
        public bool iter_nth_child ( out TreeIter iter, TreeIter? parent, int n)
        {
            if (parent == null )
            {
                return get_iter( out iter, new TreePath.from_indices(n) );
            }
            return false;
        }
        
        public bool iter_parent (out TreeIter iter, TreeIter child)
        {
            return false;
        }
        
        public void ref_node(TreeIter iter)
        {
        }
        
        public void unref_node(TreeIter iter)
        {
        }
    }
}
