package ShopClient;


/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 *	Pomocna klasa, koristi se za baratanje tabelama. 
 *	Korisnik od WebServisa dobija informacije o artiklu u formi stringa,
 *	kojeg parsira, i na osnovu dobijenih informacija pravi objekat tipa
 *	Article kojeg koristi u daljem radu
 *
 */

public class Article {
	private int id;
	private String naziv;
	private int kolicinaNaLageru;
	private String tipArtikla;
	private int kolicinaKupljena;
	
	public Article(int id,String naziv, int kolicinaNaLageru,String tipArtikla){
		this.id=id;
		this.kolicinaNaLageru=kolicinaNaLageru;
		this.naziv=naziv;
		this.tipArtikla=tipArtikla;
		kolicinaKupljena=1;
	}
	public int getId(){
		return id;
	}
	public String getNaziv(){
		return naziv;
	}
	public int getKolicinaNaLageru(){
		return kolicinaNaLageru;
	}
	public String getTip(){
		return tipArtikla;
	}
	public int getKolicinaKupljena(){
		return kolicinaKupljena;
	}
	// ovaj metod se koristi ukoliko ubacimo u korpu
	// artikal koji se vec nalazi tamo,  pa da se ne gomilaju isti
	// artikli u tabeli, informaciju cuvamo u polju kolicinaKupljena
	public void incKupljeno(){
		kolicinaKupljena++;
	}

	public void decKupljeno(){
		kolicinaKupljena--;
	}
}
