package entities;

import java.io.Serializable;
import java.util.List;

import javax.persistence.*;

/**
 * Entity implementation class for Entity: Predmet
 *
 */
@Entity

public class Predmet implements Serializable {

	
	private static final long serialVersionUID = 1L;

	private String naziv;
	
	@Id
	@GeneratedValue
	private int id;
	
	@OneToMany(mappedBy = "predmet")
	private List<Ispit> ispiti;

	
	public String getNaziv() {
		return naziv;
	}

	public void setNaziv(String naziv) {
		this.naziv = naziv;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public List<Ispit> getIspiti() {
		return ispiti;
	}

	public void setIspiti(List<Ispit> ispiti) {
		this.ispiti = ispiti;
	}
	
	
}
