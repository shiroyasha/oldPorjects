package shared;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.NotBoundException;
/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 *
 *
 *
 * jednostavan interfejs koji nasledjuje Remote 
 * sadrzi jedan metod - sta da radi server kad mu stigne trkac(Racer - agent)
 */
public interface AgentServerI extends Remote {
	public void recieveRacer(Racer racer) throws RemoteException,NotBoundException,InterruptedException;
}
