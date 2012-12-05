package entities;

import javax.ejb.Remote;
import javax.persistence.ManyToOne;


@Remote
public class Ispiti {
	
	@ManyToOne
	private Student student;
	@ManyToOne
	private Predmet predmet;
	
	
	public Student getStudent() {
		return student;
	}
	public void setStudent(Student student) {
		this.student = student;
	}
	public Predmet getPredmet() {
		return predmet;
	}
	public void setPredmet(Predmet predmet) {
		this.predmet = predmet;
	}

}
