import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 * 
 */
public class Tester 
{
	public static void main( String[] args ) throws IOException, InterruptedException
	{
		final int START_PORT = 2000;
		final int NUM_PORTS = 15;
		final int VELICINA = 20;
		final int GUSTINA = 30;
		
		PrintWriter izlaz = new PrintWriter( new File("mainServer.conf") );

		Process[] procesi = new Process[NUM_PORTS];
		for( int i = 0; i < NUM_PORTS; i++)
		{
			ProcessBuilder pb = new ProcessBuilder( new String[] { "java", "-jar", "Server.jar", (i+ START_PORT) + "", VELICINA + "", GUSTINA + ""} );
			
			procesi[i] = pb.start();
			
			System.out.println("Server started on port " + (i+ START_PORT));
			
			izlaz.println("Server" + i + ";localhost;" + (i + START_PORT) );
		}
		izlaz.close();

		
		System.out.println("Unesi bilo sta i serveri ce se ugasiti.");
		System.in.read();
		
		for( Process p: procesi)
			p.destroy();
	}
}
