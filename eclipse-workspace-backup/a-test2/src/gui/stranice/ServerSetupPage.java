package gui.stranice;

import gui.GlavniGui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.AbstractTableModel;

import shared.ServerInfo;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 * source sadrzi gomile koda, mada je sustinski veoma prost
 *
 * Kreiram TableModel koji nudi informacije o serverima, ali u isto
 * vreme nudi korisniku kao mogucnost da doda i menja postojece servere
 *
 * Pomocu dva klika na dato polje ono postaje spremno za menjanje, sto je
 * postignuto sa isCellEditable i setCellValue metodom.
 *
 * Ostatak TableModela bi trebao da je lak za svatiti.
 *
 */
@SuppressWarnings("serial")
class ServerSetupTableModel extends AbstractTableModel
{
	String[] kolone = {"Name", "Host", "Port", "To use"};
	List<ServerInfo> serveri = new ArrayList<ServerInfo>();
	List<Boolean> serverKoriscen = new ArrayList<Boolean>();
	
	public ServerSetupTableModel() 
	{
	}
	
	public void init( List<ServerInfo> infoList )
	{
		serveri = infoList;
		serverKoriscen = new ArrayList<Boolean>(infoList.size());
		
		for( int i = 0; i < serveri.size(); i++ ) serverKoriscen.add(true);
		fireTableDataChanged();
	}
	
	public int getColumnCount() {
		return kolone.length;
	}
	
	@Override
	public String getColumnName(int column) {
		return kolone[column];
	}
	
	@Override
	public Class<?> getColumnClass( int column )
	{
		if( column < 3) return String.class;
		else return Boolean.class;
	}
	
	public int getRowCount() {
		return serveri.size();
	}
	
	public Object getValueAt(int rowIndex, int columnIndex) 
	{
		ServerInfo item = serveri.get(rowIndex);
		switch( columnIndex )
		{
		case 0: return item.name;
		case 1: return item.host;
		case 2: return item.port;
		case 3: return serverKoriscen.get(rowIndex);
		}
		return null;
	}
	
	@Override
	public boolean isCellEditable( int rowIndex, int columnIndex)
	{
		if( columnIndex <= 3 ) return true;
		else return false;
	}
	
	@Override
	public void setValueAt(Object aValue, int rowIndex, int columnIndex) 
	{
		switch( columnIndex )
		{
		case 0:
			serveri.get(rowIndex).name = (String) aValue;
			break;
		case 1:
			serveri.get(rowIndex).host = (String) aValue;
			break;			
		case 2:
			serveri.get(rowIndex).port = (String) aValue;
			break;			
	    case 3: 
	    	serverKoriscen.set(rowIndex, (Boolean) aValue);
	    	break;
		}
	};
	
	public void addItem( ServerInfo item )
	{
		serveri.add(item);
		serverKoriscen.add(true);
		
		fireTableRowsInserted( serveri.size(), serveri.size());
	}
	
	public void removeItem( int rowIndex )
	{
		serveri.remove( rowIndex );
		serverKoriscen.remove( rowIndex );
		
		fireTableRowsDeleted( rowIndex, rowIndex );
	}

	public List<ServerInfo> getServerList() 
	{
		List<ServerInfo> lista = new ArrayList<ServerInfo>();
		
		for( int i = 0; i < serveri.size(); i++ )
		{
			if( serverKoriscen.get(i) ) lista.add( serveri.get(i) );
		}
		return lista;
	}
}

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 * Izgled same stranice je implementiran u ovoj klasi. Ona pravi
 * JTable i koristi gore navedeni TableModel, pri tom ima jos nekoliko
 * dugmica za dodavanje i brisanje stavki iz tabele.
 *
 */
@SuppressWarnings("serial")
public class ServerSetupPage extends JComponent
{
	ServerSetupTableModel model = new ServerSetupTableModel();
	JTable table;

	// argument je final da bi bio koristiv iz lokalne anonimne klase
	public ServerSetupPage( final GlavniGui parent, List<ServerInfo> serverInfoList ) 
	{
		setLayout( new BorderLayout() );
		
		table = new JTable(model);
		model.init( serverInfoList );
		
		JScrollPane scrollPane = new JScrollPane(table);
		add( scrollPane, BorderLayout.CENTER );
		
		JButton btnAddServer = new JButton("Add Server");
		btnAddServer.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				JPanel panel = new JPanel( new GridLayout(3, 2, 5, 5) );
				
				panel.add( new JLabel("Server name") );
				JTextField field1 = new JTextField(10); 
				panel.add(field1);
				
				panel.add( new JLabel("Host name") );
				JTextField field2 = new JTextField(10);  
				panel.add(field2);  
				
				panel.add( new JLabel("Port number") );
				JTextField field3 = new JTextField(10);  
				panel.add(field3);
				
				int value = JOptionPane.showConfirmDialog(parent, panel, "Enter Server info", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
				    // OK was pressed
					ServerInfo info = new ServerInfo(field1.getText(), field3.getText(), field2.getText() );
	
				    model.addItem( info );
				}
				
			}
		});
		
		JButton btnRemoveServer = new JButton("Remove Server");
		btnRemoveServer.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				int red = table.getSelectedRow();
				if( red >= 0 && red <= model.getRowCount() )
					model.removeItem( red );
				
				if( red != 0 ) table.getSelectionModel().setSelectionInterval(red, red);
			}
		});
		
		//NORTH
		
		JPanel panelZaObjasnjenje = new JPanel();
		panelZaObjasnjenje.add( new JLabel("Please fill the table with servers you want to use in the race") );
		
		add(panelZaObjasnjenje, BorderLayout.NORTH);
		
		//SOUTH
		JPanel panelZaDugmice = new JPanel();
		panelZaDugmice.setLayout( new BoxLayout(panelZaDugmice, BoxLayout.X_AXIS ) );
		
		panelZaDugmice.add(btnAddServer);
		
		panelZaDugmice.add( Box.createRigidArea( new Dimension(5, 0) ) );
		panelZaDugmice.add(btnRemoveServer);
		panelZaDugmice.add( Box.createRigidArea( new Dimension(5, 0) ) );
		
		panelZaDugmice.add( Box.createHorizontalGlue() );
		
		JButton btnNext = new JButton("Next");
		panelZaDugmice.add( btnNext );
		
		btnNext.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				parent.nextPage() ;
				
			}
		});
		
		add(panelZaDugmice, BorderLayout.SOUTH);
		
	}
	
	public List<ServerInfo> getServerList()
	{
		return model.getServerList();
	}

	public void reset() 
	{
		// do nothing, koristi prethodne servere
	}
}
