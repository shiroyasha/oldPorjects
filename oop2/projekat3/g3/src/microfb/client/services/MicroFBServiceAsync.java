package microfb.client.services;

import java.util.List;

import microfb.shared.IO.AktivnostIO;
import microfb.shared.IO.KorisnikIO;

import com.google.gwt.user.client.rpc.AsyncCallback;

public interface MicroFBServiceAsync {


	void getAllKorisnik(String sessionID,
			AsyncCallback<List<KorisnikIO>> callback);

	void getKorisnik(String sessionID, AsyncCallback<KorisnikIO> callback);

	void getWallItems(String sessionID, String email, long from, int to,
			AsyncCallback<List<AktivnostIO>> callback);

	void like(String sessionID, Long aktivnostID,
			AsyncCallback<Void> callback);

	void likeEnabled(String sessionID, Long aktivnostID,
			AsyncCallback<Boolean> callback);

	void login(String mail, String password, Boolean boolean1,
			AsyncCallback<String> callback);

	void logout(String sessionID, AsyncCallback<Void> callback);


	void register(String email, String password, String name, String birthdate,
			String city, String workplace, String quote, String sex,
			AsyncCallback<Void> callback);

	void searchForKorisnik(String sessionID, String queryString,
			AsyncCallback<KorisnikIO> callback);

	void unlike(String sessionID, Long aktivnostIO,
			AsyncCallback<Void> callback);

	void updateKorisnik(String sessionID, KorisnikIO korisnik,
			AsyncCallback<Void> callback);

	void getWallItemsCount(String sessionID, String email, long from, long to,
			AsyncCallback<Long> callback);

	void getKomentari(String sessionID, Long parent, long from, int to,
			AsyncCallback<List<AktivnostIO>> callback);

	void post(String sessionID, String emailTo, String value,
			AsyncCallback<Void> callback);

	void updatePost(String sessionID, Long aktivnostID, String value,
			 AsyncCallback<Void> callback);

	void deletePost(String sessionID, Long aktivnostID,
			AsyncCallback<Void> callback);

	void post(String sessionID, Long parent, String value,
			AsyncCallback<Void> callback);

	void getKorisnikByEmail(String sessionID, String email,
			AsyncCallback<KorisnikIO> callback);

}
