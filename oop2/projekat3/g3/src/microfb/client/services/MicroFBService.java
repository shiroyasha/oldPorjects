package microfb.client.services;

import java.util.List;

import microfb.shared.IO.AktivnostIO;
import microfb.shared.IO.KorisnikIO;

import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;

@RemoteServiceRelativePath("usersService")
public interface MicroFBService extends RemoteService
{
	String login(String mail, String password, Boolean boolean1) throws IllegalArgumentException;;
	void logout( String sessionID ) throws IllegalArgumentException;
	void register( String email, String password, String name, String birthdate, 
            String city, String workplace, String quote, String sex  ) throws Exception;
	
	
	
	KorisnikIO getKorisnik( String sessionID ) throws IllegalArgumentException;
	List<KorisnikIO> getAllKorisnik( String sessionID ) throws IllegalArgumentException;
	KorisnikIO searchForKorisnik( String sessionID, String queryString ) throws IllegalArgumentException;
	
	void updateKorisnik( String sessionID, KorisnikIO korisnik ) throws IllegalArgumentException;
	

	
	long getWallItemsCount(String sessionID, String email, long from, long to) throws IllegalArgumentException;
	List<AktivnostIO> getWallItems(String sessionID,String email, long from, int to ) throws IllegalArgumentException;
	List<AktivnostIO> getKomentari(String sessionID, Long parent, long from,int to) throws IllegalArgumentException;

	
	

	boolean likeEnabled(String sessionID, Long aktivnostID ) throws IllegalArgumentException;
	void like(String sessionID, Long aktivnostID ) throws IllegalArgumentException;
	void unlike(String sessionID, Long aktivnostIO) throws IllegalArgumentException;
	

	void post(String sessionID, Long parent, String value)
			throws IllegalArgumentException;
	void post(String sessionID, String emailTo, String value)
			throws IllegalArgumentException;
	void updatePost(String sessionID, Long aktivnostID, String value)
			throws IllegalArgumentException;
	void deletePost(String sessionID, Long aktivnostID)
			throws IllegalArgumentException;
	KorisnikIO getKorisnikByEmail(String sessionID, String email)
			throws IllegalArgumentException;



	
	
}

