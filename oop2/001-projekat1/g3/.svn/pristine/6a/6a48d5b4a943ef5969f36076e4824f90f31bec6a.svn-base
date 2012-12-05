package server;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.NotBoundException;
import shared.AgentServerI;
import shared.MessageServerI;
import shared.Racer;
import shared.RacerPositionInfo;
import shared.ServerInfo;
import maze.maze.Maze;

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 * 
 * Nit koja opsluzuje trkaca:
 * salje poruku glavnom serveru o trenutnoj poziciji trkaca,
 * prosledjuje trkacu lavirint koji treba da rijesi
 * salje trkaca na sledeci server
 *
 */

class AgentService extends Thread{
	Racer racer;
	Maze maze;
	ServerInfo serverInfo;
	public AgentService(Racer racer,Maze maze,ServerInfo serverInfo){
		this.racer=racer;
		this.maze=maze;
		this.serverInfo=serverInfo;
	}
	@Override
	public void run(){
		try{
			sendMessage(racer);
			racer.doJob(maze);
			
			Thread.sleep(2000);
			
		} catch (RemoteException re){	
		} catch (InterruptedException ie){
		} catch (Exception e){
			System.out.println("greska");
		} finally {
			sendRacer(racer);
		}
	}
	/*
	 * objekat tipa RacerPositionInfo sakuplja sve potrebne informacije o trenutnoj poziciji servera,
	 * te informacije se pakuju i salju glavnom serveru
	 */
	public void sendMessage(Racer racer) throws RemoteException{
		try{
			Registry registry = LocateRegistry.getRegistry(racer.getMainServer().host, Integer.parseInt(racer.getMainServer().port));
	   	 	MessageServerI serverMSG = (MessageServerI) registry.lookup("AgentServer");
	   	 	serverMSG.messageRecieved(new RacerPositionInfo(racer.getRacerId(),racer.getCurrentServer(),racer.getServerList().isEmpty()));
	   	 	
		 } catch (NotBoundException nbe){
			 System.out.println(" lookup error ");
		 }
	}
	
	// metod koji salje trkaca na sledeci server, ukoliko ga posalje na "neispravan" server, izbacuje ga sa liste
	// i salje ga na sledeci. Posto je poslednji server na listi svakog trkaca Main Server, mozemo biti sigurni
	// da postoji barem jedan ispravan server
	public void sendRacer(Racer racer){
		if (!racer.getServerList().isEmpty()){
			try{
				ServerInfo nextServer=racer.getNextServer();
				racer.removeServer();
				Registry registry = LocateRegistry.getRegistry(nextServer.host, Integer.parseInt(nextServer.port));
				AgentServerI serverCP = (AgentServerI) registry.lookup("AgentServer");
				serverCP.recieveRacer(racer);	
			} catch (Exception e){
				sendRacer(racer);
			}
		}
	}
	
}
/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 * 	v1.1 
 * 
 * 
 * Klasa Server predstavlja server koji moze da primi agenta 
 * Svaki server se registruje na RMI registar i generise svoj lavirint (vise info maze.Maze)
 * 
 * kada primi trkaca, pravi novu nit koja opsluzuje trkaca
 * 
 */

public class Server extends UnicastRemoteObject implements AgentServerI{
	private static final long serialVersionUID = 1L;
	private Maze maze;
	
	// ServerInfo je tip koji sadrzi sve bitne osobine servera (ime, host i port), vise info u (gui.ServerInfo)
	private ServerInfo serverInfo;
	
	protected Server() throws RemoteException{
		super();
	}
	
	//konstruktor prima ime , port i host servera, i registruje ga na RMI registry.
	//Generise sam svoj lavirint
	public Server(String serverName,String port) throws RemoteException{
		
		
		registerServer(serverName,port);
		
		// TODO Server treba da generise svoj lavirint , maze= Maze.generateMaze();
		maze=new Maze();
		maze.makeMaze();
		
		System.out.println("Server "+serverName+" on port "+port+" created");
	}	
	
	//drugi konstruktor koji prima lavirint(ne generise ga)
	public Server(String serverName,String port,Maze maze) throws RemoteException{
		registerServer(serverName,port);
		this.maze=maze;
		
		System.out.println("Server "+serverName+" on port "+port+" created");
	}
	
	//treci konstruktor, prima samo port servera i lavirint
	public Server(String port,Maze maze) throws RemoteException{
		registerServer("AgentServer",port);
		this.maze=maze;
		
		System.out.println("Server on port "+port+" created");
	}
	
	public void registerServer(String serverName,String port) throws RemoteException{
		serverInfo=new ServerInfo(serverName,port,"localhost");
		Registry registry = LocateRegistry.createRegistry(Integer.parseInt(port));
		registry.rebind("AgentServer", this);
	}
	// kada server primi trkaca(Racer), pravi i pokrece novu nit koja opsluzuje trkaca
	@Override
	public void recieveRacer(Racer racer) throws RemoteException,NotBoundException,InterruptedException{
		System.out.println("Racer "+racer.getName()+" stigao");
		new AgentService(racer,maze,serverInfo).start();
	}	
}
