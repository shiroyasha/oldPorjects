package gui;


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */

public class ServerInfo 
{
	public String name;
	public String port;
	public String host;
	
	public ServerInfo( String serverName, String serverPort, String serverHost ) 
	{
		name = serverName;
		port = serverPort;
		host = serverHost;
	}
}
