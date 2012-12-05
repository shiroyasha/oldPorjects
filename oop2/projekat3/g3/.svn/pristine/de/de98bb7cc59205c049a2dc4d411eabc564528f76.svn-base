package proba2.shared;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

/**
 * Objekat koji cuva staticku referencu na "fabriku" EntityManager objekata.
 * GAE specifikacija navodi da inicijalizacija ovog objekta traje dosta dugo,
 * te da je potrebno cuvati jednu instancu za celu aplikaciju.
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
public class EMF
{
	private static EntityManagerFactory emf;
	
	public static EntityManager get()
	{
		if (emf == null) // "transactions-optional" je naziv u fajlu "persistence.xml"
			emf = Persistence.createEntityManagerFactory("transactions-optional");
		return emf.createEntityManager();
	}
}
