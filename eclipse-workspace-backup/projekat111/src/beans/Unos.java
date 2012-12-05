package beans;

import javax.ejb.DependsOn;
import javax.ejb.LocalBean;
import javax.ejb.Stateless;
import javax.enterprise.context.Dependent;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

/**
 * Session Bean implementation class Unos
 */

@Stateless
public class Unos {

	@PersistenceContext(name = "OOP2_2011-2012_EE")
	private EntityManager entityManager;
    /**
     * Default constructor. 
     */
    public Unos() {
        // TODO Auto-generated constructor stub
    }

}
