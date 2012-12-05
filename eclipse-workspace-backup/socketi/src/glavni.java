import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;


public class glavni {
	
	public static void main( String[] args )
	{
		try
		{
			Socket s = new Socket("www.google.com", 80 );
			
			BufferedReader b = new BufferedReader( new InputStreamReader( s.getInputStream() ) );
			
			PrintWriter p = new PrintWriter( s.getOutputStream(), true );
			
			p.println("GET" );
			
			String red;
			while( (red = b.readLine()) != null )
				System.out.println( red );
	
		}
		catch(UnknownHostException e)
		{
			e.printStackTrace();
		}
		catch( IOException e )
		{
			e.printStackTrace();
		}
	}
}
