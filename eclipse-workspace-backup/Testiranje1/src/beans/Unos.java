package beans;

import javax.ejb.LocalBean;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import entities.Student;

/**
 * Session Bean implementation class Unos
 */
@Stateless
@LocalBean
public class Unos implements UnosI {

	@PersistenceContext( name = "Testiranje1")
	EntityManager manager;
    /**
     * Default constructor. 
     */
    public Unos() {
        // TODO Auto-generated constructor stub
    }
    
    /* (non-Javadoc)
	 * @see beans.UnosI#ubaciStudenta(java.lang.String, java.lang.String, int)
	 */
    @Override
	public void ubaciStudenta( String brIndexa, String ime, int godina)
    {
    	Student s = new Student();
    	
    	s.setBrIndexa( brIndexa );
    	s.setIme( ime );
    	s.setGodina( godina );
    	
    	manager.persist(s);
    }
    
    /* (non-Javadoc)
	 * @see beans.UnosI#iscitaj(java.lang.String)
	 */
    @Override
	public Student iscitaj( String brIndexa) 
    {
    	Student s = manager.find( Student.class, brIndexa );
    	
    	return s;
    }
    
}
