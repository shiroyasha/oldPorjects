package service;

import java.util.List;
import java.util.UUID;

import javax.ejb.Stateless;
import javax.jws.WebService;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.TypedQuery;

import entities.Artikal;
import entities.Korisnik;
import entities.Korpa;
import entities.Kupljeno;
import entities.TipArtikla;
import entities.TipKorisnika;


/**
 * Session Bean implementation class AdminOperations
 * @author Igor Sarcevic ( igisar@gmail.com )
 */

@Stateless(mappedName = "AdminServiceLookup")
@WebService(endpointInterface = "service.AdminOperationsI", serviceName = "AdminService")
public class AdminOperations implements AdminOperationsI {

	@PersistenceContext(name = "AdminService")
	EntityManager em;
	
    public AdminOperations() {
    	super();
    	
    	//createAdmin();
    }

	private boolean loggedIn(String sessionID) 
	{
		TypedQuery<Korisnik> korisnici = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class );
		korisnici.setParameter("sessionID", sessionID);
		
		System.out.println( korisnici.getResultList() );
		return korisnici.getResultList().size() > 0;
	}
	
	private boolean createAdmin()
	{
    	TypedQuery<TipKorisnika> foundTip = em.createNamedQuery("TipKorisnika.findByNaziv", TipKorisnika.class);
    	foundTip.setParameter("naziv", "administrator");
    	List<TipKorisnika> tipovi = foundTip.getResultList();
    	
    	if( tipovi.size() == 0 ) 
    	{
    		TipKorisnika tip = new TipKorisnika();
    		tip.setNaziv("administrator");
    		em.persist(tip);
    	}
    	
    	TypedQuery<TipKorisnika> foundTip2 = em.createNamedQuery("TipKorisnika.findByNaziv", TipKorisnika.class);
    	foundTip2.setParameter("naziv", "administrator");
    	List<TipKorisnika> tipovi2 = foundTip2.getResultList();
    	

    	if( tipovi2.size() == 0 ) return false;
    	TipKorisnika tip = tipovi2.get(0);
    	
    	TypedQuery<Korisnik> korisnici = em.createNamedQuery("Korisnik.findByUsername", Korisnik.class );
    	korisnici.setParameter("username", "admin");
    	List<Korisnik> lista = korisnici.getResultList();
    	
    	if( lista.size() == 0 )
    	{
    		Korisnik k = new Korisnik("admin","admin", "mojSuperTajniKljuc", tip );
    		em.persist(k);
    	}
    	
    	TypedQuery<Korisnik> korisnici2 = em.createNamedQuery("Korisnik.findByUsername", Korisnik.class );
    	korisnici2.setParameter("username", "admin");
    	List<Korisnik> lista2 = korisnici2.getResultList();

    	//System.out.println(lista2.size());
    	if( lista2.size() == 0 ) return false;
    	
    	tipovi2.get(0).getKorisnici().add( lista2.get(0) );
    	
    	return true;
	}

    public String login(String username, String password) {
    	
    	if( createAdmin() == false ) System.out.println("nesto nije u redu !");
    	
    	TypedQuery<Korisnik> korisnici = em.createNamedQuery("Korisnik.findByUsername", Korisnik.class );
    	korisnici.setParameter("username", username);
    	List<Korisnik> lista = korisnici.getResultList();
    			
    	System.out.println("tu sam");
    	if( lista.size() == 0 || !lista.get(0).getPassword().equals(password) ) return "";
    	
    	Korisnik k = lista.get(0);
    	k.setSessionID( UUID.randomUUID().toString() );
    	
    	em.merge( k );
    	
    	return k.getSessionID();
    }
    
    public boolean logout(String sessionID) {
    	
    	if( !loggedIn(sessionID) ) return false;
		TypedQuery<Korisnik> korisnici = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class );
		korisnici.setParameter("sessionID", sessionID + "");
		
		List<Korisnik> k= korisnici.getResultList();
		
		if( k.size() == 0 ) return false;
		
		k.get(0).setSessionID("");
		em.merge( k.get(0) );
		return true;
    }

    
    /*
     * 
     * 
     * TipKorisnika
     * 
     * 
     * 
     */
    
    public String[][] getTipKorisnikaTable(String sessionID) {
    	
    	if( !loggedIn(sessionID) ) return null;
    	
    	TypedQuery<TipKorisnika> korisnici = em.createNamedQuery("TipKorisnika.all", TipKorisnika.class );
    	
    	List<TipKorisnika> tipovi = korisnici.getResultList();
    	
    	String[][] ret = new String[tipovi.size()][2];
    	
    	for( int i = 0; i < tipovi.size(); i++ )
    	{
    		ret[i][0] = tipovi.get(i).getId() + "";
    		ret[i][1] = tipovi.get(i).getNaziv();
    	}
    	  
    	return ret;
    }
    
    public boolean addToTipKorisnikaTable(String sessionID, String naziv) {
        
    	if( !loggedIn(sessionID) ) return false;
    	
    	TypedQuery<TipKorisnika> tipoviQuery = em.createNamedQuery("TipKorisnika.findByNaziv", TipKorisnika.class );
    	tipoviQuery.setParameter("naziv", naziv);
    	
    	if( tipoviQuery.getResultList().size() != 0 ) return false;
    	
    	TipKorisnika tip = new TipKorisnika();
    	tip.setNaziv(naziv);
    	
    	em.persist(tip);
    	
    	return true;
    }
    
    public boolean editTipKorisnikaTableItem(String sessionID, int id, String noviNaziv) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TipKorisnika a = em.find( TipKorisnika.class , id );
	    if( a == null ) return false;
		
		a.setNaziv( noviNaziv );	
		em.merge( a );
		
		return true;
    }
    
    
    
    
    
    
    
    /*
     * 
     * 
     * TipArtikla
     * 
     * 
     */
    
    public String[][] getTipArtiklaTable(String sessionID) {
    	
    	if( !loggedIn(sessionID) ) return null;
    	TypedQuery<TipArtikla> tipovi = em.createNamedQuery("TipArtikla.all", TipArtikla.class );
    	List<TipArtikla> lista = tipovi.getResultList();
    	
    	if( lista.size() == 0 ) return null;
    	
    	String[][] ret = new String[lista.size()][2];
    	for( int i = 0; i < lista.size(); i++)
    	{
    		ret[i][0] = lista.get(i).getId() + "";
    		ret[i][1] = lista.get(i).getNaziv();
    	}
    	
    	System.out.println( ret[0][0] + " " + ret[0][1] );
    	
    	return ret;
    }
    
    public boolean addToTipArtiklaTable(String sessionID, String naziv) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TypedQuery<TipArtikla> a = em.createNamedQuery("TipArtikla.findByNaziv", TipArtikla.class);
    	a.setParameter("naziv", naziv);
    	
    	System.out.println(naziv);
		if( a.getResultList().size() != 0 ) return false;
		
		TipArtikla ta = new TipArtikla();
		ta.setNaziv( naziv );
		
		em.persist( ta );
		
		return true;
    }
    
    public boolean editTipArtiklaTableItem(String sessionID, int id, String noviNaziv) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TipArtikla a = em.find( TipArtikla.class , id );
		if( a == null ) return false;
		
		a.setNaziv( noviNaziv );	
		em.merge( a );
		
		return true;
    }
    
    
    
    
    /*
     * 
     * 
     * Artikli
     * 
     * 
     */
    public String[][] getArtikliTable(String sessionID) {
    	if( !loggedIn(sessionID) ) return null;
    	
    	TypedQuery<Artikal> artikli = em.createNamedQuery("Artikal.all", Artikal.class );
    	List<Artikal> lista = artikli.getResultList();
    	
    	
    	if( lista.size() == 0 ) return null;
    	
    	// "id" "naziv" "kolicinaNaLageru" "TipArtikla" "Cena"
    	String[][] ret = new String[lista.size()][5];
    	
    	for( int i = 0; i < lista.size(); i++ )
    	{
    		ret[i][0] = lista.get(i).getId() + "";
    		ret[i][1] = lista.get(i).getNaziv();
    		ret[i][2] = lista.get(i).getKolicinaNaLageru() + "";
    		ret[i][3] = lista.get(i).getTipArtikla().getNaziv();
    		ret[i][4] = lista.get(i).getCena() + "";
    	}
    	System.out.println(lista.size() + " tu sam");
    	return ret;
    }
    
    public boolean addToArtikliTable(String sessionID, String naziv, double cena, int kolicina_na_lageru, int tip_artikla) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TypedQuery<Artikal> a = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
    	a.setParameter("naziv", naziv);
    	
    	TipArtikla tip = em.find( TipArtikla.class, tip_artikla );
    	
    	System.out.println(tip.getNaziv());
    	
		if( a.getResultList().size() != 0 || tip == null ) return false;
		
		Artikal artikal = new Artikal();
		artikal.setNaziv( naziv );
		artikal.setCena( cena );
		artikal.setKolicinaNaLageru( kolicina_na_lageru );
		artikal.setTipArtikla(tip);
		
		em.persist( artikal );
		
		tip.getArtikli().add( artikal );
		em.merge(tip);
		
		return true;
    }
    
    public boolean editArtikliTableItem(String sessionID, int id, String naziv, double cena, int kolicina_na_lageru, int tip_artikla ) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TipArtikla tip = em.find(TipArtikla.class, tip_artikla);
    	Artikal a = em.find( Artikal.class , id );
		if( a == null || tip == null ) return false;
		
		a.setNaziv( naziv );
		a.setCena( cena );
		a.setKolicinaNaLageru( kolicina_na_lageru );
		
		a.getTipArtikla().getArtikli().remove( a );
		a.setTipArtikla(tip);
		
		em.merge( a );
		
		a = em.find( Artikal.class, id );
		tip.getArtikli().add(a);
		
		em.merge( tip );
		
		return true;
    }  
    
    
    
    
    
    
    
    /*
     * 
     * 
     * Korisnici
     * 
     * 
     */    
    public String[][] getKorisniciTable(String sessionID) {
    	
    	if( !loggedIn(sessionID) ) return null;
    	TypedQuery<Korisnik> korisnici = em.createNamedQuery("Korisnik.all", Korisnik.class );
    	List<Korisnik> lista = korisnici.getResultList();
    	
    	// "id" "username" "password" "banned" "TipKorisnika" "SessionID" "timeSinceLastActive"
    	if( lista.size() == 0 ) return null;
    	
    	String[][] ret = new String[lista.size()][8];
    	
    	for( int i = 0; i < lista.size(); i++)
    	{
    		ret[i][0] = lista.get(i).getId() + "";
    		ret[i][1] = lista.get(i).getIme();
    		ret[i][2] = lista.get(i).getUsername();
    		ret[i][3] = lista.get(i).getPassword();
    		ret[i][4] = lista.get(i).getBanned() + "";
    		ret[i][5] = lista.get(i).getTipKorisnika().getNaziv();
    		ret[i][6] = lista.get(i).getSessionID();
    		ret[i][7] = lista.get(i).getTimeSinceLastActivity() + "";
    	}
    	
    	return ret;
    }
    
    
    public boolean editKorisniciTableItem(String sessionID, int id, String ime, String username, boolean banned, int tipKorisnika) {
    	if( !loggedIn(sessionID) ) return false;
    	
    	TipKorisnika tip = em.find( TipKorisnika.class, tipKorisnika);
    	
    	Korisnik k = em.find( Korisnik.class , id );
		if( k == null || tip == null ) return false;
		
		k.setIme( ime );
		k.setUsername( username );
		k.setBanned( banned );
		k.getTipKorisnika().getKorisnici().remove(k);
		k.setTipKorisnika( tip );
		em.merge( k );
		
		k = em.find( Korisnik.class, id );
		tip.getKorisnici().add( k );
		em.merge(tip);
		return true;
    }
    
    
    
    
    
    /*
     * 
     * 
     * Korpa
     * 
     * 
     */
    
    public String[][] getKorpaTable(String sessionID) {
        
    	if( !loggedIn(sessionID) ) return null;
    	TypedQuery<Korpa> korpa = em.createNamedQuery("Korpa.all", Korpa.class );
    	List<Korpa> lista = korpa.getResultList();
    	
    	// "id" "Korisnik" "Artikal" "Kolicina"
    	if( lista.size() == 0 ) return null;
    	
    	String[][] ret = new String[lista.size()][];
    	
    	for( int i = 0; i < lista.size(); i++)
    	{
    		ret[i] = new String[]{ lista.get(i).getId() + "", lista.get(i).getKorisnik().getUsername(), lista.get(i).getArtikal().getNaziv(), lista.get(i).getKolicina() + "" };
    	}
    	
    	return ret;
    }
    
    
    /*
     * 
     * 
     * Kupljeno
     * 
     * 
     */

    public String[][] getKupljenoTable(String sessionID) {
    	if( !loggedIn(sessionID) ) return null;
    	TypedQuery<Kupljeno> kupljeno = em.createNamedQuery("Kupjeno.all", Kupljeno.class );
    	List<Kupljeno> lista = kupljeno.getResultList();
    	
    	// "id" "Korisnik" "Artikal" "Kolicina" "Ocena" "Komentar"
    	if( lista.size() == 0 ) return null;
    	
    	String[][] ret = new String[lista.size()][];
    	
    	for( int i = 0; i < lista.size(); i++)
    	{
    		ret[i] = new String[]{ lista.get(i).getId() + "", lista.get(i).getKorisnik().getUsername(), lista.get(i).getArtikal().getNaziv(), 
    				               lista.get(i).getKolicina() + "", lista.get(i).getOcena() + "", lista.get(i).getKomentar() };
    	}
    	
    	return ret;
    }

}
