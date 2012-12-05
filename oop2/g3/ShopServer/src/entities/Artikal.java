package entities;

import java.io.Serializable;
import java.util.List;

import javax.persistence.*;

/**
 * 
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: Artikal
 * 
 * za detalje pogledati diagram u fajlu diagram.png
 *
 */
@Entity
@NamedQueries ({

	@NamedQuery( name="Artikal.all", 
				 query = "SELECT a FROM Artikal a" ),
	
	@NamedQuery( name="Artikal.findByNaziv", 
			     query = "SELECT a FROM Artikal a WHERE a.naziv = :naziv" ),
    
    @NamedQuery( name="Artikal.findByTipArtikla", 
    			 query = "SELECT a FROM Artikal a WHERE a.tipArtikla.naziv = :naziv" )
})
public class Artikal implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	private String naziv;
	private int kolicinaNaLageru;
	private double cena;
	
	@ManyToOne
	private TipArtikla tipArtikla;
	
	// artikli u korpi
	@OneToMany(mappedBy = "artikal")
	private List<Korpa> artikliUKorpi;
	
	// artikli koji se nalaze u korpi
	@OneToMany(mappedBy = "artikal")
	private List<Kupljeno> kupljeneStvari;	
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//
	private static final long serialVersionUID = 1L;

	public Artikal() {
		super();
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNaziv() {
		return naziv;
	}

	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}

	public int getKolicinaNaLageru() {
		return kolicinaNaLageru;
	}

	public void setKolicinaNaLageru(int kolicinaNaLageru) {
		this.kolicinaNaLageru = kolicinaNaLageru;
	}

	public TipArtikla getTipArtikla() {
		return tipArtikla;
	}

	public void setTipArtikla(TipArtikla tipArtikla) {
		this.tipArtikla = tipArtikla;
	}

	public List<Korpa> getArtikliUKorpi() {
		return artikliUKorpi;
	}

	public void setArtikliUKorpi(List<Korpa> artikliUKorpi) {
		this.artikliUKorpi = artikliUKorpi;
	}

	public List<Kupljeno> getKupljeneStvari() {
		return kupljeneStvari;
	}

	public void setKupljeneStvari(List<Kupljeno> kupljeneStvari) {
		this.kupljeneStvari = kupljeneStvari;
	}

	public double getCena() {
		return cena;
	}

	public void setCena(double cena) {
		this.cena = cena;
	}
	
	
   
}
