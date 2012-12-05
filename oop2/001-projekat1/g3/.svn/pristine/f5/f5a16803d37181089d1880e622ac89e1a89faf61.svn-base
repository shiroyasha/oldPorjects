package gui.stranice;

import gui.GlavniGui;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */

@SuppressWarnings("serial")
class RaceResultsTableModel extends AbstractTableModel
{
	private String[] kolone = {"Agent", "Time needed", "Place"};
	
	class RaceResultInfo
	{
		public RaceResultInfo(String ime, Integer vreme) 
		{
			agentName = ime;
			time = vreme;
		}
		String agentName;
		int time;
	}
	
	private List<RaceResultInfo> raceInfo = new ArrayList<RaceResultInfo>();
	
	public RaceResultsTableModel() 
	{

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
		return String.class;
	}
	
	public int getRowCount() {
		return raceInfo.size();
	}
	
	public Object getValueAt(int rowIndex, int columnIndex) 
	{
		RaceResultInfo item = raceInfo.get(rowIndex);
		
		switch( columnIndex )
		{
		case 0: return item.agentName;
		case 1: return item.time + " ms";
		case 2: return (rowIndex + 1) + ".";
		}
		return null;
	}

	public void setResults(String[] imena, Integer[] vreme) 
	{
		raceInfo.clear();
		
		for( int i = 0; i < imena.length; i++)
		{
			RaceResultInfo info = new RaceResultInfo( imena[i], vreme[i] );
			
			raceInfo.add( info );
		}
		
		Collections.sort( raceInfo, new Comparator<RaceResultInfo>() 
		{
			@Override
			public int compare(RaceResultInfo o1, RaceResultInfo o2) {
				return  o1.time - o2.time;
			}
		});
		
		fireTableDataChanged();
	}
}

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */

@SuppressWarnings("serial")
public class RaceResultsPage extends JComponent
{
	private RaceResultsTableModel model = new RaceResultsTableModel();
	private JTable table;
	
	// argument je final da bi bio koristiv iz lokalne anonimne klase
	public RaceResultsPage( final GlavniGui parent ) 
	{
		setLayout( new BorderLayout() );
		
		table = new JTable(model);
		JScrollPane scrollPane = new JScrollPane(table);
		add( scrollPane, BorderLayout.CENTER );
		
		
		//SOUTH
		JPanel panelZaDugmice = new JPanel( new BorderLayout() );
		
		JButton btnNewGame = new JButton("New Game");
		
		panelZaDugmice.add( btnNewGame );
		
		btnNewGame.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				parent.reset();
			}
		});
		
		add(panelZaDugmice, BorderLayout.SOUTH);
		
	}
	
	public void reset() 
	{
		// TODO
	}

	public void setResults( String[] imena, Integer[] vreme ) 
	{
		model.setResults( imena, vreme );
	}
	
}
