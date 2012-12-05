import java.awt.Color;

import javax.naming.InitialContext;
import javax.naming.NamingException;


public class Main {
	
	
	public static void main(String[] args) throws NamingException {
		InitialContext ctx = new InitialContext();
		// naziv bean-a generise GlassFish prilikom publish-ovanja serverskog projekta
		UnosI bean = (UnosI) ctx.lookup("java:global/Testiranje1/Unos!beans.UnosI");
		
		Student vrednost = bean.iscitaj("292/10");
		
		System.out.println( vrednost.getIme() );
		
	}
}