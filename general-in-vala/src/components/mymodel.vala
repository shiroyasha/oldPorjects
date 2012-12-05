using Gtk;

namespace Components
{
    class MyModel : DirectoryModel
    {
        private string[] size_names = { "B", "KiB", "MiB", "GiB", "TiB", "PiT", "EiB", "ZiB", "YiB"};
        construct
        {
        }
        
        public override Type get_column_type( int index )
        {
            if (index == 0 ) return typeof(Gdk.Pixbuf);
            return typeof(string);
        }
        
        public override void get_value ( TreeIter iter, int column , out Value val)
        {
            FileInfo* info =  (FileInfo*) iter.user_data;
            
            switch( column )
            {
                case 0:
                {
                    val.init( typeof(Gdk.Pixbuf) );
                    Gtk.IconTheme theme = new Gtk.IconTheme();
                    
                    Gtk.IconInfo? icon_info = theme.get_default().lookup_by_gicon( info->get_icon(), 16, 0 );
                    
                    if( icon_info != null ) val.set_object( icon_info.load_icon() );
                    
                    break;
                }
                case 1:
                {
                    val.init( typeof(string) );
                    val.set_string( info->get_display_name() );   
                    break; 
                }
                case 2:
                {
                    val.init( typeof(string) );
                    val.set_string( this.get_formated_size( info->get_size() ) );
                    break;
                }
            }
        }
        
        private string get_formated_size( int64 size )
        {
            double helper = (double)size;
            int i = 0;
            
            for( i = 0; helper > 2048.0 ; ++i)
            {
                helper = helper / 2048.0;
            }
            
            return with_two_decimals( helper ) + " " + size_names[i];
        }
        
        private string with_two_decimals( double i )
        {
            int whole = (int)( i * 100.0);
            int bdot = whole / 100;
            int adot = whole - bdot * 100;
            
            return bdot.to_string() + "." + adot.to_string();
        }
        
    } 
}

