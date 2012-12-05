package proba2.client;

import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;

@RemoteServiceRelativePath("regService")
public interface RegService extends RemoteService
{
	// vraca true ukoliko je registracija uspesna (jedinstven e-mail)
	public boolean register(String email, String pass);
}
