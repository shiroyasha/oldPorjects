package entities;

import java.io.Serializable;
import java.util.List;

import javax.persistence.*;

/**
 * @author Igor Sarcevic(igisar@gmail.com)
 * Entity implementation class for Entity: TipArtikla
 * 
 * za detalje pogledati diagram u fajlu diagram.png
 */

@Entity
@NamedQueries ({
	@NamedQuery( name="TipArtikla.all", 
			     query = "SELECT ta FROM TipArtikla ta" )
})
public class TipArtikla implements Serializable {

	@Id
	@GeneratedValue
	private int id;
	
	private String naziv;
	
	// artikli ovog tipa artikla
	@OneToMany(mappedBy = "tipArtikla")
	private List<Artikal> artikli;
	
	//
	//
	// generisani getteri i setteri, konstruktori i ostalo ^_^
	//
	//
	private static final long serialVersionUID = 1L;

	public TipArtikla() {
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

	public List<Artikal> getArtikli() {
		return artikli;
	}

	public void setArtikli(List<Artikal> artikli) {
		this.artikli = artikli;
	}
   
	
}
