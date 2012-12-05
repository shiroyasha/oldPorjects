package beans;

import javax.ejb.Remote;

import entities.Student;

@Remote
public interface UnosI {

	public abstract void ubaciStudenta(String brIndexa, String ime, int godina);

	public abstract Student iscitaj(String brIndexa);

}