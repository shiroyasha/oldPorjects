package microfb.server;

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LogoutInactiveUsersServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException
	{
		try {
			EntityHelper.refreshLoggedin();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
