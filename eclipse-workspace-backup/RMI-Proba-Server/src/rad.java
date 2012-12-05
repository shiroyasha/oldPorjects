import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;


public class rad extends UnicastRemoteObject implements  AgentServerI
{
	protected rad() throws RemoteException
	{
		super();
	}
	
	public static void main(String[] args)
	{
		rad server;
		try 
		{
			server = new rad();

		
			// kreiraj lokalni RMI registar na portu 1099
			Registry registry = LocateRegistry.createRegistry(1099);
			// registruj server objekat pod imenom AgentServer
			registry.rebind("AgentServer", server);
		
			System.out.println("AgentServer started");
		
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}

	@Override
	public void acceptAgent(Agent agent) throws RemoteException 
	{
		agent.resiMatricu();
	}
}
