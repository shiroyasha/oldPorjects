package microfb.server.entities;

import java.io.Serializable;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;

import com.google.appengine.api.datastore.Blob;

@Entity
@NamedQueries({
 @NamedQuery(name = "Slike.findByKorisnikId", query = "SELECT s FROM Slike s WHERE s.korisnik = :korisnikId")
})
public class Slike implements Serializable {
	private final static long serialVersionUID = 1L;
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;
	private Long korisnik;
	private Blob Image;
	private Blob Cover;

	public Slike(){
		super();
	}
	
	public Slike(long korisnik,Blob Image,Blob Cover){
		this.setKorisnik(korisnik);
		this.Image=Image;
		this.Cover=Cover;
	}

	public Blob getImage() {
		return Image;
	}

	public void setImage(Blob image) {
		Image = image;
	}

	public Blob getCover() {
		return Cover;
	}

	public void setCover(Blob cover) {
		Cover = cover;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public long getKorisnik() {
		return korisnik;
	}

	public void setKorisnik(long korisnik) {
		this.korisnik = korisnik;
	}

}
