import java.rmi.RemoteException;

import javax.swing.JOptionPane;
import javax.swing.UIManager;

import server.Server;

import maze.gui.Starter;
import maze.maze.Maze;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 * 
 */
public class AgentServerMain
{
	public static void main( String[] args ) throws RemoteException
	{
		Maze maze = null;
		String port = "";
		
		
		//pokretanje sa gui-em
		if(args.length == 0)
		{
			try {
				UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
			} catch (Exception e) {}
			
			//smaraj dok nije uneta pravilna vrednost
			int p;
			do
			{
				try 
				{ p = Integer.parseInt(new String(JOptionPane.showInputDialog("Server Port( 0 - 65535 )")));
				} catch( Exception e ) { p = -1; }
			}while( p < 0 || p > 65535 );
			
			port = p + "";
			
			Starter window = new Starter();
			
			maze = window.getMaze();
		}
		//pokretanje bez gui-a
		else if( args.length == 3 )
		{
			port = args[0];
			
			int velicina, gustina;
			try { velicina = Integer.parseInt( args[1] ); } catch(Exception e) { velicina = 5; };
			try { gustina = Integer.parseInt( args[2] ); } catch(Exception e) { gustina = 20; };
			
			if( velicina < 5 || velicina > 20 || gustina < 5 || gustina > 50 )
			{
				System.out.println("FATAL ERROR : velicina ili gustina matrice su izvan granica");
				System.exit(0);
			}
		
			maze = new Maze(velicina, gustina);
		}
		
		try
		{
			int p = Integer.parseInt(port);
			
			if ( p > 65535 ) 
			{
				System.out.println("FATAL ERROR : Port number is invalid");
				System.exit(0);
			}
		}catch(Exception e)
		{
			System.out.println("FATAL ERROR : Something went terribly wrong");
			System.exit(0);
		}
		
		Server server = new Server("", port, maze);
	}
}