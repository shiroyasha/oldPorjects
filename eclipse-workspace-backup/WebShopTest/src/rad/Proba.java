package rad;

import javax.ejb.LocalBean;
import javax.ejb.Stateless;
import javax.jws.WebService;

/**
 * Session Bean implementation class Proba
 */
@Stateless
@LocalBean
@WebService
public class Proba {

    /**
     * Default constructor. 
     */
    public Proba() {
        // TODO Auto-generated constructor stub
    }
    
    public String vratiString()
    {
    	return "bucbucbuc";
    }

}
