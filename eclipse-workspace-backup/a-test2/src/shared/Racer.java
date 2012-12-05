package shared;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import maze.maze.MazeSolver;
import maze.maze.Cvor;


  /**
   * 
   *  @author Nikola Bosic ( nikolabosic91@gmail.com )
		v 1.1  (Klasa Racer od sada sadrzi samo implementaciju metoda za resavanje matrice, i neke get/set metode
				Serveri vode racuna o transportu Agenata i slanja trenutnih pozicija)



   *  Racer (Agent) je objekat koji treba da obidje zadate servere 
   *  i da rijesi zadate probleme na svakom serveru
   */
	
/*
 */
public class Racer implements Serializable{
	
	/* mainServer je server na kome se nalazi glavna aplikacija, 
	 * bitno da ga posebno cuvamo radi slanja informacija o trenutnoj poziciji trkaca
	 * 
	 * serverList je lista svih servera koje trkac treba da obidje
	 * 
	 * koristimo metod shuffle da bi "izmjesali" redoslijed lokacija koje trkac treba posjetiti
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private ServerInfo mainServer;
	private long starttime;
	private List<ServerInfo> serverList;
	private String racerName;
	private int racerId;
	
	private ServerInfo currentServer;
	
	public Racer(String racerName,int racerId,ServerInfo mainServer,List<ServerInfo> servers){
		this.racerName=racerName;
		this.racerId=racerId;
		this.mainServer=mainServer;
		serverList=new ArrayList<ServerInfo>();
		this.serverList.addAll(servers);
		Collections.shuffle(serverList);
		serverList.add(mainServer);
		
		System.out.println("Agent "+racerName+" created");
	}
	public void setStartTime(long start){
		starttime=start;
	}
	public String getRacerName(){
		return racerName;
	}
	public int getRacerId(){
		return racerId;
	}
	public List<ServerInfo> getServerList(){
		return serverList;
	}
	public ServerInfo getMainServer(){
		return mainServer;
	}
	public void removeServer(){
		currentServer = serverList.get(0); // sacuva na kom smo sad serveru
		serverList.remove(0);
	}
	public ServerInfo getCurrentServer() {
		return currentServer;
	}
	public ServerInfo getNextServer(){
		return serverList.get(0);
	}
	public String getName(){
		return racerName;
	}
	public Integer getFinishTime(long finish){
		return new Integer((int)(finish-starttime));
	}
	
	// metod doJob rjesava prosledjenu matricu
	public void doJob(Cvor[][] cvor){	
		System.out.println(getName()+" resava lavirint");
		MazeSolver.getSolution(cvor);
	}
}
