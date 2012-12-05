package gui.stranice;

import gui.GlavniGui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;
import javax.swing.table.DefaultTableCellRenderer;

import shared.ServerInfo;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *  
 * CellRenderer, kao sto mu ime kaze, se stara o crtanju sadrzaja u celijama
 * koristim ga da bih promenio pozadinsku boju u zelenu za agente koji su zavrsili
 * 
 */
@SuppressWarnings("serial") 
class RaceViewCellRenderer extends DefaultTableCellRenderer 
{
	@Override
    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
		RaceViewTableModel model = (RaceViewTableModel) table.getModel();
        Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
        c.setBackground( model.getRowColour(row) );
        return c;
    }
}


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */
@SuppressWarnings("serial")
class RaceViewTableModel extends AbstractTableModel
{
	String[] kolone = {"Agent", "Visited Servers", "Finished"};
	
	class AgentRaceInfo
	{
		String agentName;
		List<String> visitedServers = new ArrayList<String>();
		boolean finished = false;
		String time;
	}
	
	List<AgentRaceInfo> agentsInfo = new ArrayList<AgentRaceInfo>();
	
	public RaceViewTableModel() 
	{
	}
	
	public void init(List<String> agenti) 
	{
		for( String agent : agenti )
		{
			System.out.println( agent );
			AgentRaceInfo info = new AgentRaceInfo();
			info.agentName = agent;
			info.finished = false;
			
			agentsInfo.add(info);
		}
		
		fireTableDataChanged();
	}
	
	public void reset()
	{
		agentsInfo.clear();
		fireTableDataChanged();
	}
	
	public Color getRowColour(int row) 
	{
		return agentsInfo.get(row).finished ? Color.GREEN : Color.WHITE;
	}
	
	public int getColumnCount() {
		return kolone.length - 1;
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
		return agentsInfo.size();
	}
	
	public Object getValueAt(int rowIndex, int columnIndex) 
	{
		AgentRaceInfo item = agentsInfo.get(rowIndex);
		
		switch( columnIndex )
		{
		case 0: return item.agentName;
		case 1: return item.visitedServers;
		case 2: return item.finished ? "YES" : "";
		}
		return null;
	}
	
	public void addVisitedServer( int indexOfAgent, ServerInfo info , boolean finished )
	{
		System.out.println( info.name );
		agentsInfo.get(indexOfAgent).visitedServers.add( info.name );
		agentsInfo.get(indexOfAgent).finished = finished;
		
		fireTableRowsUpdated(indexOfAgent, indexOfAgent);
	}

}

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */
@SuppressWarnings("serial")
public class RaceViewPage extends JComponent
{
	private RaceViewTableModel model = new RaceViewTableModel();
	private JTable table;
	
	private JButton btnStart;
	
	private final GlavniGui parent;
	
	private boolean raceFinished = false;
	
	// argument je final da bi bio koristiv iz lokalne anonimne klase
	public RaceViewPage( final GlavniGui p ) 
	{
		parent = p;
		setLayout( new BorderLayout() );
		
		table = new JTable(model);
		table.setDefaultRenderer( String.class, new RaceViewCellRenderer() );
		table.setCellSelectionEnabled(false);
		
		
		JScrollPane scrollPane = new JScrollPane(table);
		add( scrollPane, BorderLayout.CENTER );
		
		
		//SOUTH
		JPanel panelZaDugmice = new JPanel( new BorderLayout() );
		
		btnStart = new JButton("START RACE");
		
		panelZaDugmice.add( btnStart );
		
		btnStart.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				if( ! RaceViewPage.this.raceFinished ) parent.startRace();
				else parent.nextPage();
			}
		});
		
		add(panelZaDugmice, BorderLayout.SOUTH);
		
	}
	
	public void addVisitedServer( int indexOfAgent, ServerInfo info, boolean finished)
	{
		model.addVisitedServer( indexOfAgent, info, finished);
	}

	public void raceStarted() 
	{
		btnStart.setEnabled(false);
	}
	
	public void raceFinished()
	{
		raceFinished = true;
		btnStart.setText("View race results");
		
		btnStart.setEnabled(true);
	}
	
	public void reset() 
	{
		raceFinished = false;
		model.reset();
		btnStart.setText("START RACE");
		btnStart.setEnabled(true);
	}

	public void setAgentList( List<String> agenti) 
	{
		model.init( agenti );
	}

	
}
