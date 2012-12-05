
import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.AbstractTableModel;

import java.awt.BorderLayout;

public class glavni extends JFrame {
	private JTable table;
	
	class Model extends AbstractTableModel
	{

		@Override
		public int getColumnCount() {
			
			return 3;
		}

		@Override
		public int getRowCount() {
			// TODO Auto-generated method stub
			return 3;
		}

		@Override
		public Object getValueAt(int arg0, int arg1) {
			// TODO Auto-generated method stub
			return null;
		}
		
		
		
	}
	
	public glavni() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		table = new JTable();
		getContentPane().add(table, BorderLayout.CENTER);
		table.setModel( new Model() );
		
		table.getSelectionModel().addListSelectionListener( new ListSelectionListener()
		{

			@Override
			public void valueChanged(ListSelectionEvent arg0) {
				// TODO Auto-generated method stub
				System.out.println("dasdasdas");
			}
			
		}); 
		
		JButton btnNewButton = new JButton("New button");
		getContentPane().add(btnNewButton, BorderLayout.NORTH);
		
		init();
	}
	
	public void init()
	{
		
	}
	
	public static void main( String[] args )
	{
		
		glavni g = new glavni();
		
		g.setSize( 300, 300 );
		g.setVisible(true);
	}
}
