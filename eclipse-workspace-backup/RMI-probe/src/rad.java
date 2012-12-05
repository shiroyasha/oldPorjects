import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class rad 
{
	public static void main(String[] args)
	{
		MainServer server = new MainServer();
		
		server.start();
	}

}

class MainServer extends Thread 
{
	
	@Override
	public void run()
	{
		Registry registry;
		
		try 
		{
			registry = LocateRegistry.getRegistry("localhost", 1099);
			
			// vrati mi referencu na udaljeni objekat pod nazivom AgentServer
			AgentServerI server = (AgentServerI) registry.lookup("AgentServer");
			
			Agent a = new Agent();

			server.acceptAgent(a);
			
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}

	}
}
