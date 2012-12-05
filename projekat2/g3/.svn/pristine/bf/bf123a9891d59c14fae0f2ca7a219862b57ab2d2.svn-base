package entities;

import java.io.Serializable;
import java.util.List;

import javax.persistence.*;

/**
 * 
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: TipKorisnika
 * 
 * za detalje pogledati diagram u fajlu diagram.png
 */
@Entity
@NamedQueries ({
	@NamedQuery( name="TipKorisnika.all", 
			     query = "SELECT tk FROM TipKorisnika tk" ),

	@NamedQuery( name="TipKorisnika.findByNaziv", 
			     query = "SELECT tk FROM TipKorisnika tk WHERE tk.naziv = :naziv" )
})
public class TipKorisnika implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	private String naziv;

	// korisnici ovog tipa korisnika
	@OneToMany(mappedBy = "tipKorisnika")
	private List<Korisnik> korisnici;	
	
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//	
	private static final long serialVersionUID = 1L;

	public TipKorisnika() {
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

	public List<Korisnik> getKorisnici() {
		return korisnici;
	}

	public void setKorisnici(List<Korisnik> korisnici) {
		this.korisnici = korisnici;
	}

}
