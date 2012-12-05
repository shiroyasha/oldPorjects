/* main.vala
 *
 * Copyright (C) 2010  Igor Sarcevic
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author:
 * 	Igor Sarcevic <igisar@gmail.com>
 */

using GLib;
using Gtk;
using Components;

public class ApplicationWindow : Window {
	private TextBuffer text_buffer;
	private string filename;

	public ApplicationWindow () 
	{
		title = "general-in-vala";
        
	}

	construct {
		set_default_size (600, 400);

		destroy.connect( Gtk.main_quit );

		var vbox = new VBox (false, 0);
		add (vbox);
		vbox.show ();

		var toolbar = new Toolbar ();
		vbox.pack_start (toolbar, false, false, 0);
		toolbar.show ();

		var scrolled_window = new ScrolledWindow (null, null);
		vbox.pack_start (scrolled_window, true, true, 0);
		scrolled_window.hscrollbar_policy = PolicyType.AUTOMATIC;
		scrolled_window.vscrollbar_policy = PolicyType.AUTOMATIC;
		scrolled_window.show ();

        Components.ListView view = new Components.ListView();
		scrolled_window.add ( view );
		view.show ();
	}

	public void run () {
		show ();

		Gtk.main ();
	}

	static int main (string[] args) {
		Gtk.init (ref args);

		var window = new ApplicationWindow ();
		window.run ();
		return 0;
	}

}
