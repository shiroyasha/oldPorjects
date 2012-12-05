package entities;

import java.util.List;

import javax.ejb.Remote;
import javax.persistence.OneToMany;

@Remote
public class Student {

	private String brIndexa;
	private int godina;
	private String ime;
	
	@OneToMany(mappedBy = "predmet")
	private List<Ispiti> ispiti;
	
	public List<Ispiti> getIspiti() {
		return ispiti;
	}
	public void setIspiti(List<Ispiti> ispiti) {
		this.ispiti = ispiti;
	}
	
	public String getBrIndexa() {
		return brIndexa;
	}
	public void setBrIndexa(String brIndexa) {
		this.brIndexa = brIndexa;
	}
	public int getGodina() {
		return godina;
	}
	public void setGodina(int godina) {
		this.godina = godina;
	}
	public String getIme() {
		return ime;
	}
	public void setIme(String ime) {
		this.ime = ime;
	}
	
	
}
