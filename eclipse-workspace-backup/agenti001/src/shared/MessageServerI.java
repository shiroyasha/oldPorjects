package shared;
import java.rmi.Remote;
import java.rmi.RemoteException;
/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 * 
 * 
 * 
 * jednostavan interfejs koji nasledjuje Remote
 * 
 * sadrzi jedan metod - sta da uradi server kada primi objekat tipa RacerPositionInfo
 * objekat RacerPosition info sadrzi sve bitne informacije o poziciji agenta
 *
 */
public interface MessageServerI extends Remote{
	public void messageRecieved(RacerPositionInfo racerpi) throws RemoteException;
}
