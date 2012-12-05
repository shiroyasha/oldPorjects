

import javax.ejb.Remote;


@Remote
public interface UnosI {

	public abstract void ubaciStudenta(String brIndexa, String ime, int godina);

	public abstract Student iscitaj(String brIndexa);

}