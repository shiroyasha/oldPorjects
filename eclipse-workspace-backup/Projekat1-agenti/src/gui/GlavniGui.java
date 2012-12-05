package gui;

import gui.stranice.AgentSetupPage;
import gui.stranice.RaceResultsPage;
import gui.stranice.RaceViewPage;
import gui.stranice.ServerSetupPage;
import gui.stranice.StartPage;

import java.awt.BorderLayout;
import java.awt.CardLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */

@SuppressWarnings("serial")
public class GlavniGui extends JFrame
{
	StartPage startPage;
	ServerSetupPage serverSetupPage;
	AgentSetupPage agentSetupPage;
	RaceViewPage raceViewPage;
	RaceResultsPage raceResultsPage;
	
	JPanel centralPanel;

	JButton btnNext;
	
	ServerInfo[] serveri;
	
	public GlavniGui( ServerInfo[] serveri ) 
	{
		this.serveri = serveri;
		
		setTitle("Agent Race Game");
		setSize(551, 461);
		setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		
		centralPanel = new JPanel( new CardLayout() );
		
		startPage = new StartPage(this);
		agentSetupPage = new AgentSetupPage(this);
		serverSetupPage = new ServerSetupPage(this);
		raceViewPage = new RaceViewPage(this);
		raceResultsPage = new RaceResultsPage(this);
		
		centralPanel.add( startPage, "startPage" );
		centralPanel.add( serverSetupPage, "serverSetupPage" );
		centralPanel.add( agentSetupPage , "agentSetupPage");
		centralPanel.add( raceViewPage , "raceViewPage");
		centralPanel.add( raceResultsPage, "raceResultPage" );
		
		add( centralPanel, BorderLayout.CENTER );
		
		this.setVisible(true);
	}
	

	public void reset() 
	{	
		startPage.reset();
		agentSetupPage.reset();
		serverSetupPage.reset();
		raceViewPage.reset();
		raceResultsPage.reset();
		
		nextPage();
	}
	
	
	public void nextPage()
	{
		( (CardLayout)centralPanel.getLayout() ).next( centralPanel );
	}
	
	
	
	
	/*
	 * 
	 * metode koje poziva server koji nadgleda agente
	 *
	*/
	
	public void raceStarted()
	{
		raceViewPage.raceStarted();
	}
	
	public void addVisitedServer( int indexOfAgent, ServerInfo info )
	{
		raceViewPage.addVisitedServer( indexOfAgent, info );
	}
	
	public void raceFinished()
	{
		nextPage();
	}
	
	
	
	
	

	// metode koje pozivaju metode koje pruza servera
	public void startRace() 
	{
		//TODO implementiraj
		
		//samo za testiranje, start odmah poziva prikaz rezultata
		raceFinished();
	}

	
}


