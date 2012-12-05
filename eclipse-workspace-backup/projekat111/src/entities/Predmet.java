package entities;

import java.util.List;

import javax.ejb.Remote;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.OneToMany;

@Remote
public class Predmet {

	private String imePredmeta;
	
	@OneToMany(mappedBy = "predmet")
	List<Ispiti> ispiti;
	
	@Id
	@GeneratedValue
	private int id;
	
	public List<Ispiti> getIspiti() {
		return ispiti;
	}

	public void setIspiti(List<Ispiti> ispiti) {
		this.ispiti = ispiti;
	}

	public String getImePredmeta() {
		return imePredmeta;
	}

	public void setImePredmeta(String imePredmeta) {
		this.imePredmeta = imePredmeta;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
}
