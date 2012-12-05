package glavni;

import javax.naming.InitialContext;
import javax.naming.NamingException;

import beans.UnosI;

public class Main 
{

	public static void main( String[] args ) throws NamingException
	{
		InitialContext ctx = new InitialContext();
		
		UnosI unos = (UnosI) ctx.lookup("java:global/Testiranje1/Unos!beans.UnosI");
		
		unos.ubaciStudenta("292/10", "igor", 2 );
		System.out.println( unos.iscitaj("292/10") );
		
	}
}
