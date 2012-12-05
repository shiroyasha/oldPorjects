package microfb.server;

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CleanRegistrationServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException
	{
		try {
			EntityHelper.refreshKorisnik();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
