package oop2.useract.server.entities;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQuery;

/**
 * Opis korisnika sistema.
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
@Entity
@NamedQuery(name = "AppUser.getByCode", query = "SELECT a FROM AppUser a WHERE a.actCode = :code")
public class AppUser
{
	@Id
	private String email;
	private String pass;
	private String actCode; // activacioni kod
	private long actDeadline; // rok za aktivaciju
	
	public String getEmail()
	{
		return email;
	}

	public void setEmail(String email)
	{
		this.email = email;
	}

	public String getPass()
	{
		return pass;
	}

	public void setPass(String pass)
	{
		this.pass = pass;
	}

	public String getActCode()
	{
		return actCode;
	}

	public void setActCode(String actCode)
	{
		this.actCode = actCode;
	}

	public long getActDeadline()
	{
		return actDeadline;
	}

	public void setActDeadline(long actDeadline)
	{
		this.actDeadline = actDeadline;
	}
}
