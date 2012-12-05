
import java.util.ArrayList;
import java.util.List;

import javax.swing.table.AbstractTableModel;

@SuppressWarnings("serial")
public class ModelPodataka extends AbstractTableModel {
	
	class Red
	{
		Red( String p, String d, String t) { prvi = p; drugi = d; treci = t; }
		public String prvi;
		public String drugi;
		public String treci;
	}
	
	private List<Red> lista = new ArrayList<Red>();
	
	public ModelPodataka()
	{
		lista.add( new Red( "test1", "test2", "test3") );
	}

	@Override
	public int getColumnCount() {
		// TODO Auto-generated method stub
		return 4;
	}

	@Override
	public int getRowCount() {
		// TODO Auto-generated method stub
		return lista.size();
	}
	
	@Override
	public String getColumnName( int i )
	{
		if( i < 0 || i > 2 ) return null;
		
		if( i == 0 ) return "prvi";
		if( i == 1 ) return "drugi";
		if( i == 2 ) return "treci";
		if( i == 3 ) return "4";
		return null;
	}
	
	@Override
	public Class<?> getColumnClass( int i )
	{
		
		return i < 3 ? String.class : Boolean.class;
		
	}

	@Override
	public Object getValueAt(int arg0, int arg1) {
		
		if( arg0 < 0 || arg0 >= lista.size() ) return null;

		Red r = lista.get( arg0 );
		switch( arg1 )
		{
			case 0 : return r.prvi;
			case 1 : return r.drugi;
			case 2 : return r.treci;
			case 3 : return Math.random() > 0.5;
			default : return null;
		}

	}

	public void addRed(String text, String text2, String text3) {
		// TODO Auto-generated method stub
		lista.add( new Red( text, text2, text3 ) );
		
		this.fireTableDataChanged();
	}

	public void delete(int e) {
		if( e < 0 || e >= lista.size() ) return;
		
		lista.remove(e);
		
		this.fireTableRowsDeleted(e, e);

	}

	public boolean moveUp(int e) 
	{
		if( e < 1 || e >= lista.size() ) return false;
		
		Red r = lista.get(e);
		lista.set( e, lista.get(e - 1) );
		lista.set( e-1, r );
		
		this.fireTableRowsUpdated(e-1, e );		
		return true;
		
	}
	
	public boolean moveDown(int e) 
	{
		if( e < 0 || e >= lista.size() - 1 ) return false;
		
		Red r = lista.get(e);
		lista.set( e, lista.get(e + 1) );
		lista.set( e+1, r );
		
		this.fireTableRowsUpdated(e+1, e );		
		return true;
		
	}
	
}
