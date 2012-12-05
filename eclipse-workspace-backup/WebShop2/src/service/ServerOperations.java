package service;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import javax.ejb.Schedule;
import javax.ejb.Stateless;
import javax.jws.WebService;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;
import javax.persistence.Transient;

import entities.Artikal;
import entities.Korisnik;
import entities.Korpa;
import entities.Kupljeno;
import entities.TipKorisnika;

/**
 * 
 * @author Milos Marinkovic
 * @version 1.2
 *
 */

@Stateless(mappedName = "ShopServiceLookup")
@WebService(endpointInterface = "service.SOI", serviceName = "ShopService")
public class ServerOperations implements SOI {

	private final int MIN_USER = 6;
	private final int MAX_USER = 20;
	private final int MIN_PASS = 6;
	private final int MAX_PASS = 20;
	private final int TIMEOUT = 5;
	
	@PersistenceContext(name = "ShopService")
	EntityManager em;
	
    public ServerOperations() {
        super();
    }

	@Override
	public boolean validUsername(String user) {
		int l = user.length();
		if (MIN_USER <= l && l <= MAX_USER && !user.contains(" "))
			return true;
		return false;
	}

	@Override
	public boolean validPassword(String pass) {
		int l = pass.length();
		if (MIN_PASS <= l && l <= MAX_PASS && !pass.contains(" "))
			return true;
		return false;
	}

	@Override
	public String testConnection() {
		return "Success!";
	}

	@Override
	public String login(String user, String pass) {
		try {
			Query q = em.createNamedQuery("Korisnik.findByUsername", Korisnik.class);
			q.setParameter("username", user);
			
			@SuppressWarnings("unchecked")
			List<Korisnik> list = q.getResultList();
			Korisnik found = null;
			if (list.size() != 0)
				found = list.get(0);
			if (found != null)
				if (found.getPassword().equals(md5(pass))) {
					String sessionId = UUID.randomUUID().toString();
					found.setSessionID(sessionId);
					found.setTimeSinceLastActivity(0);
					em.merge(found);
					return sessionId;
				}
		} catch (Exception e) {
			return e.getMessage();
		}
		return "";
	}

	@Override
	public boolean logout(String sessionId) {
		try {
			if (!leave(sessionId))
				return false;
			Query q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			@SuppressWarnings("unchecked")
			List<Korisnik> list = q.getResultList();
			Korisnik found = null;
			if (list.size() != 0)
				found = list.get(0);
			if (found != null) {
				found.setSessionID("");
				found.setTimeSinceLastActivity(TIMEOUT + 1);
				em.merge(found);
				return true;
			}
		} catch (Exception e) { return false; }
		return false;
	}

	@Override
	public int register(String ime, String username, String password, int idTipaKorisnika) {
		try {
			TipKorisnika foundTip = em.find(TipKorisnika.class, idTipaKorisnika);
			if (foundTip == null)
				return 3;
			if (!validUsername(username) || !validPassword(password))
				return 2;
			Query q = em.createNamedQuery("Korisnik.findByUsername", Korisnik.class);
			q.setParameter("username", username);
			
			@SuppressWarnings("unchecked")
			List<Korisnik> list = q.getResultList();
			if (list.size() != 0)
				return 1;
			
			Korisnik e = new Korisnik(ime, username, md5(password), foundTip);
			e.setTimeSinceLastActivity(0);
			e.setBanned(false);
			em.persist(e);

			return 0;
		} catch (Exception e) {
			return 4;
		}
	}

	@Override
	public boolean loggedIn(String sessionId) {
		List<Korisnik> list = em.createNamedQuery("Korisnik.findLoggedInUsers", Korisnik.class).getResultList();
		if (list.size() != 0) {
			for (Korisnik k : list)
				if (k.getSessionID().equals(sessionId))
					return true;
		}
		return false;
	}

	@Override
	public String[] getItems(String type, boolean all) {
		try {
			Query q;
			if (type == null || type.isEmpty()) {
				q = em.createNamedQuery("Artikal.all", Artikal.class);
			} else {
				q = em.createNamedQuery("Artikal.findByTipArtikla", Artikal.class);
				q.setParameter("naziv", type);
			}
			@SuppressWarnings("unchecked")
			List<Artikal> list = q.getResultList();
			List<Artikal> returnList = new ArrayList<Artikal>();
			
			for (Artikal a : list)
				if (all)
					returnList.add(a);
				else 
					if (a.getKolicinaNaLageru() > 0)
						returnList.add(a);
			
			int i = 0;
			String[] returnArray = new String[returnList.size()]; 
			for (Artikal a : returnList)
				returnArray[i++] = a.getId() + ";" + a.getNaziv() + ";" +
								   a.getCena() + ";" + a.getTipArtikla().getNaziv() + ";" +
								   a.getKolicinaNaLageru();
			
			return returnArray;
		} catch (Exception e) { return null; }
	}

	@Override
	public double getCurrentCost(String sessionId) {
		try {
			Query q = em.createNamedQuery("Korpa.findBySessionID", Korpa.class);
			q.setParameter("sessionID", sessionId);
			@SuppressWarnings("unchecked")
			List<Korpa> korpe = q.getResultList();
			
			double sum = 0;
			if (korpe.size() != 0)
				for (Korpa k : korpe)
					sum += k.getArtikal().getCena() * k.getKolicina();
			return sum;
		} catch (Exception e) { return -1; }
	}

	@Override
	public double getCurrentCostPlus(String sessionId, int discount) {
		try {	
			double sum = getCurrentCost(sessionId);
			sum -= sum * discount/100;
			return sum;
		} catch (Exception e) { return -1; }
	}

	@SuppressWarnings("unchecked")
	@Override
	public double addToCart(String sessionId, String itemName) {
		try {
			Query q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			if (art == null || kor == null)
				return 0;
			kor.setTimeSinceLastActivity(0);
			em.merge(kor);
			q = em.createNamedQuery("Korpa.findByKorisnik", Korpa.class);
			q.setParameter("korisnik", kor);
			List<Korpa> listKorpa = q.getResultList();
			Korpa found = null;
			for (Korpa k : listKorpa)
				if (k.getArtikal().equals(art) && k.getKorisnik().equals(kor))
					found = k;
			if (found != null) {
				found.setKolicina(found.getKolicina() + 1);
				em.merge(found);
			} else {
				found = new Korpa(kor, art, 1);
				em.persist(found);
			}
			return getCurrentCost(sessionId);
		} catch (Exception e) { return 0; }
	}

	@SuppressWarnings("unchecked")
	@Override
	public double removeFromCart(String sessionId, String itemName) {
		try {
			Query q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			if (art == null || kor == null)
				return -1;
			kor.setTimeSinceLastActivity(0);
			em.merge(kor);
			q = em.createNamedQuery("Korpa.findByKorisnik", Korpa.class);
			q.setParameter("korisnik", kor);
			List<Korpa> listKorpa = q.getResultList();
			Korpa found = null;
			for (Korpa k : listKorpa)
				if (k.getArtikal().equals(art) && k.getKorisnik().equals(kor))
					found = k;
			if (found != null) {
				int rezKolicina = found.getKolicina() - 1;
				if (rezKolicina < 1)
					em.remove(found);
				else {
					found.setKolicina(rezKolicina);
					em.merge(found);
				}
			} else {
				return -1;
			}
			return getCurrentCost(sessionId);
		} catch (Exception e) { return -1; }
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean checkout(String sessionId) {
		try {
			Query q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			if (kor == null) return false;
			kor.setTimeSinceLastActivity(0);
			em.merge(kor);
			q = em.createNamedQuery("Korpa.findByKorisnik", Korpa.class);
			q.setParameter("korisnik", kor);
			List<Korpa> listKorpa = q.getResultList();
			q = em.createNamedQuery("Kupljeno.findByKorisnik", Kupljeno.class);
			q.setParameter("korisnik", kor);
			List<Kupljeno> listKupljeno = q.getResultList();
			boolean nemaNaLageru = false;
			for (Korpa k : listKorpa) {
				Artikal a = k.getArtikal();
				int kolicina = k.getKolicina();
				if (a.getKolicinaNaLageru() >= kolicina) {
					a.setKolicinaNaLageru(a.getKolicinaNaLageru() - kolicina);
					em.merge(a);
					boolean found = false;
					for (Kupljeno kup : listKupljeno)
						if (!found && kup.getArtikal().equals(a)) {
							kup.setKolicina(kup.getKolicina() + kolicina);
							found = true;
							em.merge(kup);
						}
					if (!found) {
						Kupljeno kup = new Kupljeno();
						kup.setArtikal(a);
						kup.setKolicina(kolicina);
						kup.setKomentar("");
						kup.setKorisnik(kor);
						kup.setOcena(0);
						em.persist(kup);
					}
				} else {
					nemaNaLageru = true;
				}
				em.remove(k);
			}
			return !nemaNaLageru;
		} catch (Exception e) { return false; }
	}
	
	@SuppressWarnings("unchecked")
	@Override
	public boolean leave(String sessionId) {
		try {
			Query q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			if (kor == null) return false;
			kor.setTimeSinceLastActivity(0);
			em.merge(kor);
			q = em.createNamedQuery("Korpa.findByKorisnik", Korpa.class);
			q.setParameter("korisnik", kor);
			List<Korpa> listKorpa = q.getResultList();
			for (Korpa k : listKorpa) {
				em.remove(k);
			}
			return true;
		} catch (Exception e) { return false; }
	}

	@SuppressWarnings("unchecked")
	@Override
	public String[] getCommentsFor(String itemName) {
		try {
			Query q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			if (art == null) return null;
			q = em.createNamedQuery("Kupljeno.findByArtikal", Kupljeno.class);
			q.setParameter("artikal", art);
			List<Kupljeno> listKupljeno = q.getResultList();
			if (listKupljeno.size() > 0) {
				int i = 0;
				String[] data = new String[listKupljeno.size()];
				for (Kupljeno k : listKupljeno) {
					data[i++] = "[" + k.getKorisnik().getUsername() + "]: " + k.getKomentar();
				}
				return data;
			}
		} catch (Exception e) { return null; }
		return null;
	}

	@SuppressWarnings("unchecked")
	@Override
	public int[] getRatingsFor(String itemName) {
		try {
			Query q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			if (art == null) return null;
			q = em.createNamedQuery("Kupljeno.findByArtikal", Kupljeno.class);
			q.setParameter("artikal", art);
			List<Kupljeno> listKupljeno = q.getResultList();
			if (listKupljeno.size() > 0) {
				int i = 0;
				int[] data = new int[listKupljeno.size()];
				for (Kupljeno k : listKupljeno)
					data[i++] = k.getOcena();
				return data;
			}
		} catch (Exception e) { return null; }
		return null;
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean setCommentFor(String itemName, String sessionId, String comment) {
		try {	
			Query q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			if (art == null || kor == null)
				return false;
			q = em.createNamedQuery("Kupljeno.findByArtikal", Kupljeno.class);
			q.setParameter("artikal", art);
			List<Kupljeno> listKupljeno = q.getResultList();
			boolean found = false;
			for (Kupljeno k : listKupljeno)
				if (!found && k.getKorisnik().equals(kor)) {
					found = true;
					k.setKomentar(comment);
					em.merge(k);
				}
			return true;
		} catch (Exception e) { return false; }
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean setRatingFor(String itemName, String sessionId, int rating) {
		try {	
			Query q = em.createNamedQuery("Artikal.findByNaziv", Artikal.class);
			q.setParameter("naziv", itemName);
			List<Artikal> artList = q.getResultList();
			Artikal art = artList.get(0);
			q = em.createNamedQuery("Korisnik.findBySessionID", Korisnik.class);
			q.setParameter("sessionID", sessionId);
			List<Korisnik> korList = q.getResultList();
			Korisnik kor = korList.get(0);
			if (art == null || kor == null)
				return false;
			q = em.createNamedQuery("Kupljeno.findByArtikal", Kupljeno.class);
			q.setParameter("artikal", art);
			List<Kupljeno> listKupljeno = q.getResultList();
			boolean found = false;
			for (Kupljeno k : listKupljeno)
				if (!found && k.getKorisnik().equals(kor)) {
					found = true;
					k.setOcena(rating);
					em.merge(k);
				}
			return true;
		} catch (Exception e) { return false; }
	}

	@Override
	public String[] getBuyListFor(String sessionId) {
		try {
			Query q = em.createNamedQuery("Kupljeno.findBySessionID", Kupljeno.class);
			q.setParameter("sessionID", sessionId);
			@SuppressWarnings("unchecked")
			List<Kupljeno> list = q.getResultList();
			if (list.size() > 0) {
				int i = 0;
				String[] data = new String[list.size()];
				for (Kupljeno k : list)
					data[i++] = k.getArtikal().getId() + ";" + k.getArtikal().getNaziv() + ";" + 
								k.getKolicina() + ";" + k.getOcena();
				return data;
			}
		} catch (Exception e) { return null; }
		return null;
	}

	@Schedule(hour = "0-23", minute = "*/2")
	public void cleanup() {
		List<Korisnik> logged = em.createNamedQuery("Korisnik.findLoggedInUsers", Korisnik.class).getResultList();
		for (Korisnik k : logged) {
			k.setTimeSinceLastActivity(k.getTimeSinceLastActivity() + 2);
			em.merge(k);
		}
		Query q = em.createNamedQuery("Korisnik.findBytimeSinceLastActivity", Korisnik.class);
		q.setParameter("vreme", TIMEOUT);
		@SuppressWarnings("unchecked")
		List<Korisnik> awayList = q.getResultList();
		for (Korisnik k : awayList) {
			k.setSessionID("");
			em.merge(k);
		}
	}
	
	@Transient
	private String md5(String s) {
		try {
			MessageDigest m = MessageDigest.getInstance("MD5");
			m.reset();
			m.update(s.getBytes());
			byte[] digest = m.digest();
			BigInteger bigInt = new BigInteger(1,digest);
			return bigInt.toString(16);
		} catch (Exception e) { return null; }
		
	}
	
}
