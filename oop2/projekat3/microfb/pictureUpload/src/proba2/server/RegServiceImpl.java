package proba2.server;

import java.util.Calendar;
import java.util.Properties;
import java.util.UUID;

import javax.mail.Message;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;

import proba2.client.RegService;
import proba2.server.entities.AppUser;
import proba2.shared.EMF;

import com.google.gwt.core.client.GWT;
import com.google.gwt.user.server.rpc.RemoteServiceServlet;

/**
 * Implementacija servisa za registraciju korisnika.
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
public class RegServiceImpl extends RemoteServiceServlet implements RegService
{
	private static final long serialVersionUID = 1L;

	@Override
	public boolean register(String email, String pass)
	{
		// kreiramo EntityManager objekat, i na kraju ga moramo unistiti
		// nema dependency injection-a :(
		EntityManager em = EMF.get(); 
		// moramo rucno voditi racuna o transakcijama :(
		EntityTransaction et = em.getTransaction();
		try
		{
			AppUser user = new AppUser();
			
			user.setEmail(email);
			user.setPass(pass);
			
			String actCode = UUID.randomUUID().toString(); 
			user.setActCode(actCode);
			
			Calendar c = Calendar.getInstance();
			long actDeadline = c.getTimeInMillis() + 24 * 60 * 60 * 1000;
			user.setActDeadline(actDeadline);
			
			et.begin(); // pocetak transakcije
			
			em.persist(user); 
			
			try
			{
				et.commit(); // upisi user-a u bazu
			} catch (Exception ex)
			{
				// poruke koje stampa GWT.log su vidljive iz "control panel"-a aplikacije na GAE-u
				GWT.log("Error while persisting user '" + email + "'", ex);
				et.rollback(); // moramo ponistiti zapocetu transakciju
				return false;
			}
			
			// posalji mail sa konfirmacionim linkom
			sendEmail(email, actCode);
			return true;
		} finally
		{
			em.close();
		}
	}
	
	// da bi slanje radilo, mail adresa postavljena kao "From" mora pripadati
	// administratoru aplikacije (postavlja se u "control panel"-u na GAE-u
	private void sendEmail(String email, String actCode)
	{
		try
		{
			Properties props = new Properties();
			Session session = Session.getDefaultInstance(props, null);
				
			Message msg = new MimeMessage(session);
			
			msg.setFrom(new InternetAddress("mitrovic.dejan@gmail.com", "Dejan Mitrovic"));
			msg.addRecipient(Message.RecipientType.TO, new InternetAddress(email, email));

			msg.setSubject("Your registration");
			
			// mail sadrzi aktivacioni link oblika
			// 		http://oop2dmi.appspot.com/activation?code=12345
			// u fajlu web.xml je definisano da zahteve "/activation" treba prosledjivati
			// objektu ActivationServlet. kada korisnik klikne na link, objektu ce biti 
			// prosledjena GET naredba
			
			String msgBody = "Dear User,\n\n" +
				"Thank you for registering with our service!\n\n" +
				"In order to complete the registration procedure, please visit the following link:\n\n" +
				"http://oop2dmi.appspot.com/activation?code=" + actCode + "\n\n" +
				"The link will expire in 24h. After that, you will have to repeat the registration procedure.\n\n" +
				"Thank you once again for choosing our service!";
			msg.setText(msgBody);
				
			Transport.send(msg);
		} catch (Exception ex)
		{
			GWT.log("Error while sending an e-mail to '" + email + "'", ex);
		}
	}

}
