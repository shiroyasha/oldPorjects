package entities;

import java.io.Serializable;
import javax.persistence.*;

/**
 * 
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: Kupljeno
 *
 * za detalje pogledati diagram u fajlu diagram.png
 */
@Entity
@NamedQueries ({
	@NamedQuery( name="Kupljeno.findByKorisnik", 
			 query = "SELECT k FROM Kupljeno k WHERE k.korisnik = :korisnik" ),
			 
	@NamedQuery( name="Kupljeno.findByArtikal", 
			     query = "SELECT k FROM Kupljeno k WHERE k.artikal = :artikal" ),

    @NamedQuery( name="Kupljeno.findBySessionID", 
			     query = "SELECT k FROM Kupljeno k, Korisnik k2 WHERE k2.sessionID = :sessionID AND k.korisnik = k2" )
})
public class Kupljeno implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	@ManyToOne
	private Korisnik korisnik;
	@ManyToOne
	private Artikal artikal;
	
	private int kolicina;
	
	private int ocena;
	private String komentar;
	
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//	
	private static final long serialVersionUID = 1L;

	public Kupljeno() {
		super();
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

	public int getOcena() {
		return ocena;
	}

	public void setOcena(int ocena) {
		this.ocena = ocena;
	}

	public String getKomentar() {
		return komentar;
	}

	public void setKomentar(String komentar) {
		this.komentar = komentar;
	}
}
