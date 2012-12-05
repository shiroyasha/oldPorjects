

import java.io.Serializable;
import javax.persistence.*;
import javax.xml.crypto.Data;

/**
 * Entity implementation class for Entity: Ispit
 *
 */
@Entity
public class Ispit implements Serializable {
	private static final long serialVersionUID = 1L;

	@Id
	private int id;

	@ManyToOne
	private Student student;
	
	@ManyToOne
	private Predmet predmet;
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
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

	public Data getDatum() {
		return datum;
	}

	public void setDatum(Data datum) {
		this.datum = datum;
	}

	Data datum;
}
