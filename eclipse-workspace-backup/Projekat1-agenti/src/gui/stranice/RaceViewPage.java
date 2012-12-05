package gui.stranice;

import gui.GlavniGui;
import gui.ServerInfo;

import java.awt.BorderLayout;
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
		AgentRaceInfo info = new AgentRaceInfo();
		info.agentName = "Agent Smith";
		
		agentsInfo.add( info );
		
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
	
	public void addVisitedServer( int indexOfAgent, ServerInfo info )
	{
		agentsInfo.get(indexOfAgent).visitedServers.add( info.name );
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
	RaceViewTableModel model = new RaceViewTableModel();
	JTable table;
	
	JButton btnStart;
	
	// argument je final da bi bio koristiv iz lokalne anonimne klase
	public RaceViewPage( final GlavniGui parent ) 
	{
		setLayout( new BorderLayout() );
		
		table = new JTable(model);
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
				parent.startRace();
			}
		});
		
		add(panelZaDugmice, BorderLayout.SOUTH);
		
	}
	
	public void addVisitedServer( int indexOfAgent, ServerInfo info )
	{
		model.addVisitedServer( indexOfAgent, info );
	}

	public void raceStarted() 
	{
		btnStart.setEnabled(false);
	}
	
	public void reset() 
	{
		//TODO
	}
	
}
