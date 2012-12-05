package proba2.server;

import java.io.IOException;
import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.Query;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import proba2.server.entities.AppUser;
import proba2.shared.EMF;

import com.google.gwt.core.client.GWT;

/**
 * Servlet kom se prosledjuju "klikovi" na aktivacione linkove. Veza izmedju
 * aktivacionih linkova i ovog objekta je data u fajlu web.xml
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
public class ActivationServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException
	{
		// link je oblika http://oop2dmi.appspot.com/activation?code=12345
		// deo nakon ? su parametri, oblika ime=vrednost
		// req.getParameter("code") vraca vrednost parametra "code"
		String code = req.getParameter("code");
		
		// kao i GlassFish, i GAE podrzava persistentne tajmere koje bismo ovde
		// mogli koristiti za "ciscenje" baze. u GAE sistemu se ovakav tajmer naziva "cron"
		// https://developers.google.com/appengine/docs/java/config/cron
		
		// update-ujemo odgovarajuci slog u bazi
		EntityManager em = EMF.get();
		EntityTransaction et = em.getTransaction();
		try
		{
			et.begin();
			Query q = em.createNamedQuery("AppUser.getByCode");
			q.setParameter("code", code);
			@SuppressWarnings("unchecked")
			List<AppUser> list = (List<AppUser>)q.getResultList();
			if (list.size() == 1)
			{
				AppUser user = list.get(0);
				// kada postavimo deadline na 0, to ce nam znaciti da je nalog aktiviran
				// (bolje nego da uvodimo jos jedno boolean polje)
				user.setActDeadline(0); 
				em.merge(user);
				
				try
				{
					et.commit();
					
					// saljemo odgovor korisniku (ovo je string koji ce on videti u web browser-u)
					resp.getWriter().println("Thank you, you have successfully activated your account!");
				} catch (Exception ex)
				{
					GWT.log("Error while merging users '" + user.getEmail() + "'", ex);
					et.rollback();
					resp.getWriter().println("There was an error on the server, please try again later");
				}
			}
		} finally
		{
			em.close();
		}
	}
}
