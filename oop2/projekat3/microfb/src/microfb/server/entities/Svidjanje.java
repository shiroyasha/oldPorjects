package microfb.server.entities;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;

@NamedQueries({
		@NamedQuery(name = "Svidjanje.findByAktivnostIdentifier", query = "SELECT s FROM Svidjanje s WHERE s.father = :identifier"),
		@NamedQuery(name = "Svidjanje.findByAktivnostFrom", query = "SELECT s FROM Svidjanje s WHERE s.father = :identifier AND s.from = :from"),
		@NamedQuery(name = "Svidjanje.countSvidjanjeByType", query = "SELECT COUNT(s) FROM Svidjanje s WHERE s.father = :identifier AND s.type = :type") })
@Entity
public class Svidjanje implements Serializable {
	private static final long serialVersionUID = 1L;
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;
	private int type;
	private Long from;
	private Long father;

	public Svidjanje() {
		super();
	}

	public Svidjanje(long from, long father, int type) {
		this.from = from;
		this.father = father;
		this.type = type;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public long getFather() {
		return father;
	}

	public void setFather(long father) {
		this.father = father;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public long getFrom() {
		return from;
	}

	public void setFrom(long from) {
		this.from = from;
	}

}
