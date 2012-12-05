package shared; import java.io.Serializable; 


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 * 
 * Klasa sluzi kao alat za prosledjivanje informacija o serverima
 * bilo u trenutku ucitavanja, ili u toku same igre. Polje su ostavljena
 * da budu public radi lakog i efikasnog pristupa istima.
 *
 * Napravljen je i konstruktor koji dodatno olaksava kreiranje instanca. 
 */

public class ServerInfo implements Serializable
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
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
