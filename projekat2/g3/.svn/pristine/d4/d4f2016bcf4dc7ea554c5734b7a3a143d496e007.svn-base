package entities;

import java.io.Serializable;
import java.util.List;

import javax.persistence.*;

/**
 * 
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: Korisnik
 *
 * za detalje pogledati diagram u fajlu diagram.png
 */
@Entity
@NamedQueries ({
	@NamedQuery( name="Korisnik.all", 
			     query = "SELECT k FROM Korisnik k" ),
			 
	@NamedQuery( name="Korisnik.findBySessionID", 
			     query = "SELECT k FROM Korisnik k WHERE k.sessionID = :sessionID" ),
			     
	@NamedQuery( name="Korisnik.findByName", 
			     query = "SELECT k FROM Korisnik k WHERE k.ime = :ime" ),
	
    @NamedQuery( name="Korisnik.findByUsername", 
                 query = "SELECT k FROM Korisnik k WHERE k.username = :username" ),
    
    @NamedQuery( name="Korisnik.findByTipKorisnika", 
    			 query = "SELECT k FROM Korisnik k WHERE k.tipKorisnika.naziv = :naziv" ),
    
    @NamedQuery( name="Korisnik.findBytimeSinceLastActivity", 
    		     query = "SELECT k FROM Korisnik k WHERE k.timeSinceLastActivity > :vreme" ),  //uoci '>' umesto '='
    		     
	@NamedQuery( name="Korisnik.findLoggedInUsers",
	             query = "SELECT k FROM Korisnik k WHERE k.sessionID <> ''") // vraca one koji imaju postavljen sessionID
})
public class Korisnik implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	// ime prezime srednje ime i sve ostalo ide na isto mesto, svakako je polje prakticno beskorisno za pretrazivanje
	private String ime; 
	
	private String username;
	private String password;
	
	private Boolean banned;
	private String sessionID;
	private int timeSinceLastActivity;
	
	@ManyToOne
    private TipKorisnika tipKorisnika;
	
	
	// artikli koji se nalaze u korpi
	@OneToMany(mappedBy = "korisnik")
	private List<Korpa> stvariUKorpi;
	
	// artikli koji se nalaze u korpi
	@OneToMany(mappedBy = "korisnik")
	private List<Kupljeno> kupljeneStvari;	
	
	
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//
	
	private static final long serialVersionUID = 1L;

	public Korisnik() {
		super();
	}
	
	public Korisnik(String ime, String username, String password, TipKorisnika tipKorisnika) {
		this();
		this.ime = ime;
		this.username = username;
		this.password = password;
		this.tipKorisnika = tipKorisnika;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getIme() {
		return ime;
	}

	public void setIme(String ime) {
		this.ime = ime;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Boolean getBanned() {
		return banned;
	}

	public void setBanned(Boolean banned) {
		this.banned = banned;
	}

	public String getSessionID() {
		return sessionID;
	}

	public void setSessionID(String sessionID) {
		this.sessionID = sessionID;
	}

	public TipKorisnika getTipKorisnika() {
		return tipKorisnika;
	}

	public void setTipKorisnika(TipKorisnika tipKorisnika) {
		this.tipKorisnika = tipKorisnika;
	}

	public int getTimeSinceLastActivity() {
		return timeSinceLastActivity;
	}

	public void setTimeSinceLastActivity(int timeSinceLastActivity) {
		this.timeSinceLastActivity = timeSinceLastActivity;
	}

	public List<Korpa> getStvariUKorpi() {
		return stvariUKorpi;
	}

	public void setStvariUKorpi(List<Korpa> stvariUKorpi) {
		this.stvariUKorpi = stvariUKorpi;
	}

	public List<Kupljeno> getKupljeneStvari() {
		return kupljeneStvari;
	}

	public void setKupljeneStvari(List<Kupljeno> kupljeneStvari) {
		this.kupljeneStvari = kupljeneStvari;
	}
	
}
