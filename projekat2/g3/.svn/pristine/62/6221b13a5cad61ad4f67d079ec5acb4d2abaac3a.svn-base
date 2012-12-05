package service;

import javax.ejb.Remote;
import javax.jws.WebService;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */

@Remote
@WebService(serviceName = "AdminService")
public interface AdminOperationsI 
{

    public String login( String username, String password );
    public boolean logout( String sessionID );

    //tip korisnika
    public String[][] getTipKorisnikaTable( String sessionID );
    public boolean addToTipKorisnikaTable( String sessionID, String naziv );
    public boolean editTipKorisnikaTableItem( String sessionID, int id, String noviNaziv );

    //tip artikla
    public String[][] getTipArtiklaTable( String sessionID );
    public boolean addToTipArtiklaTable( String sessionID, String naziv );
    public boolean editTipArtiklaTableItem( String sessionID, int id, String noviNaziv );

    // artikli
    public String[][] getArtikliTable( String sessionID );
    public boolean addToArtikliTable( String sessionID, String naziv, double cena, int kolicina_na_lageru, int tip_artikla );
    public boolean editArtikliTableItem( String sessionID, int id, String naziv, double cena, int kolicina_na_lageru, int tip_artikla );

    // korisnici - mogu samo da menjam, ne mogu da dodajem
    public String[][] getKorisniciTable( String sessionID );
    public boolean editKorisniciTableItem( String sessionID, int id, String ime, String username, boolean banned , int tipKorisnika );

    // korpa - mogu samo da izlistam
    public String[][] getKorpaTable( String sessionID );

    // kupljeno - mogu samo da izlistam
    public String[][] getKupljenoTable( String sessionID );

}
