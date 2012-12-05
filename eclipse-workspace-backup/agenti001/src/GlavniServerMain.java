import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import shared.ServerInfo;

import gui.GlavniGui;


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 * 
 */
public class GlavniServerMain
{
	
	public static List<ServerInfo> ucitaj(String filename)
	{

		List<ServerInfo> infoList = new ArrayList<ServerInfo>();
		
	    try
	    {
	        System.out.println("Working Directory = " +
	                System.getProperty("user.dir"));
	    	File f = new File(filename);
	    	System.out.println( filename + " " +f.exists() );
			BufferedReader ulaz = new BufferedReader(new InputStreamReader( new FileInputStream(filename) ));
			  
			String strLine;
			  
			while ((strLine = ulaz.readLine()) != null)   
			{
				System.out.println("tu sam" + strLine);
				String[] red = strLine.split(";");
				
				ServerInfo info = new ServerInfo( red[0], red[2], red[1] );
				
				infoList.add( info );
				
			}
			
			ulaz.close();
			
	    }
	    catch (Exception e)
	    {
	    	infoList = new ArrayList<ServerInfo>();
	    }

	    return infoList;
	}
	
	
	
	public static void main( String[] args )
	{
		String configFile = "";
		
		if( args.length == 0 )
		{
			configFile = "bin/mainServer.conf";
		}
		else if( args.length == 2 && args[0].equals("--config") )
		{
			File config = new File( args[1] );
			
			if( config.exists() && !config.isDirectory() )
			{
				configFile = args[1]; 
			}
		}
		
		List<ServerInfo> infoList = ucitaj( configFile );
		
		GlavniGui g = new GlavniGui( infoList );
	}
	
	
}