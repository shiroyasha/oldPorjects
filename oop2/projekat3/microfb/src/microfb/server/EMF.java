package microfb.server;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class EMF
{
	private static EntityManagerFactory factory;
	
	public static EntityManager get()
	{
		if (factory == null)
			factory = Persistence.createEntityManagerFactory("transactions-optional");
		return factory.createEntityManager();
	}
	
}