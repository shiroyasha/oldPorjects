package microfb.server.entities;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import java.io.Serializable;

import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;

@Entity
@NamedQueries({
		@NamedQuery(name = "Korisnik.findByEmail", query = "SELECT k FROM Korisnik k WHERE k.email = :email"),

		@NamedQuery(name = "Korisnik.all", query = "SELECT k FROM Korisnik k"),

		@NamedQuery(name = "Korisnik.findByName", query = "SELECT k FROM Korisnik k WHERE k.name = :name"),

		@NamedQuery(name = "Korisnik.findByRCode", query = "SELECT k FROM Korisnik k WHERE k.actCode = :actCode"),

		@NamedQuery(name = "Korisnik.findBySessionID", query = "SELECT k FROM Korisnik k WHERE k.sessionID = :sessionID"),

		@NamedQuery(name = "Korisnik.findById", query = "SELECT k FROM Korisnik k WHERE k.id = :id") })
public class Korisnik implements Serializable {
	public static final long serialVersionUID = 1L;
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;
	private String name;
	private String email;
	private String password;
	private String birthdate;
	private String city;
	private String workplace;
	private String quote;
	private String sex;
	private String sessionID;
	private long registrationTime;
	private long lastActive;
	private String actCode;
	private boolean activated;
	private boolean stayLoggedIn;

	public Korisnik() {
		super();
	}

	public Korisnik(String email, String password, String name,
			String birthdate, String city, String workplace, String quote,
			String sex, String actCode) {
		this.email = email;
		this.password = password;
		this.name = name;
		this.birthdate = birthdate;
		this.city = city;
		this.workplace = workplace;
		this.quote = quote;
		this.sex = sex;
		this.actCode = actCode;
		sessionID = "";
		activated = false;
		registrationTime = System.currentTimeMillis();
		stayLoggedIn = false;
		lastActive = System.currentTimeMillis();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getWorkplace() {
		return workplace;
	}

	public void setWorkplace(String workplace) {
		this.workplace = workplace;
	}

	public String getQuote() {
		return quote;
	}

	public void setQuote(String quote) {
		this.quote = quote;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public boolean isActivated() {
		return activated;
	}

	public void setActivated(boolean activated) {
		this.activated = activated;
	}

	public String getSessionID() {
		return sessionID;
	}

	public void setSessionID(String sessionID) {
		this.sessionID = sessionID;
	}

	public String getActCode() {
		return actCode;
	}

	public void setActCode(String actCode) {
		this.actCode = actCode;
	}

	public long getRegistrationTime() {
		return registrationTime;
	}

	public void setRegistrationTime(long registrationTime) {
		this.registrationTime = registrationTime;
	}

	public String getBirthdate() {
		return birthdate;
	}

	public void setBirthdate(String birthdate) {
		this.birthdate = birthdate;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public long getLastActive() {
		return lastActive;
	}

	public void setLastActive(long lastActive) {
		this.lastActive = lastActive;
	}

	public boolean isStayLoggedIn() {
		return stayLoggedIn;
	}

	public void setStayLoggedIn(boolean stayLoggedIn) {
		this.stayLoggedIn = stayLoggedIn;
	}

}
