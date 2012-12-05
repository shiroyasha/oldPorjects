package entities;

import java.io.Serializable;
import javax.persistence.*;

/**
 * 
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: Korpa
 * 
 * za detalje pogledati diagram u fajlu diagram.png
 */
@Entity
@NamedQueries ({
	@NamedQuery( name="Korpa.findByKorisnik", 
			 query = "SELECT k FROM Korpa k WHERE k.korisnik = :korisnik" ),
			 
	@NamedQuery( name="Korpa.findByArtikal", 
			     query = "SELECT k FROM Korpa k WHERE k.artikal = :artikal" ),
	
	@NamedQuery( name="Korpa.findBySessionID", 
    			 query = "SELECT k FROM Korpa k WHERE k.korisnik.sessionID = :sessionID" )
})
public class Korpa implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	@ManyToOne
	private Korisnik korisnik;
	@ManyToOne
	private Artikal artikal;
	
	private int kolicina;
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//
	private static final long serialVersionUID = 1L;

	public Korpa() {
		super();
	}
	
	public Korpa(Korisnik korisnik, Artikal artikal, int kolicina) {
		this();
		this.korisnik = korisnik;
		this.artikal = artikal;
		this.kolicina = kolicina;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public Korisnik getKorisnik() {
		return korisnik;
	}

	public void setKorisnik(Korisnik korisnik) {
		this.korisnik = korisnik;
	}

	public Artikal getArtikal() {
		return artikal;
	}

	public void setArtikal(Artikal artikal) {
		this.artikal = artikal;
	}

	public int getKolicina() {
		return kolicina;
	}

	public void setKolicina(int kolicina) {
		this.kolicina = kolicina;
	}
   
}
