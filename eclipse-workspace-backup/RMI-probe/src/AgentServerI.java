import java.rmi.Remote;
import java.rmi.RemoteException;


public interface AgentServerI extends Remote
{
	public void acceptAgent(Agent agent) throws RemoteException;
}
