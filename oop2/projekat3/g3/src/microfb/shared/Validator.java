package microfb.shared;

import java.io.Serializable;


public class Validator implements Serializable{

	private static final long serialVersionUID = 1L;
	
	
	public Validator() {
		super();
	}

	public static final int MINIMUM_USERNAME_LENGTH = 4;
	public static final int MAXIMUM_USERNAME_LENGTH = 50;

	public static final int MINIMUM_PASSWORD_LENGTH = 4;
	public static final int MAXIMUM_PASSWORD_LENGTH = 30;

	public static final int MAXIMUM_FILESIZE = 1024 * 1024 * 10; // 10mb

	
	
	public static boolean username(String name) {
		return name.length() >= MINIMUM_USERNAME_LENGTH
				&& name.length() <= MAXIMUM_USERNAME_LENGTH;
	}

	public static boolean password(String pass) {
		return pass.length() >= MINIMUM_PASSWORD_LENGTH
				&& pass.length() <= MAXIMUM_PASSWORD_LENGTH;
	}

	public static boolean email(String mail) {
		return mail.matches("[_A-Za-z0-9-]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})");
	}

	public static boolean file(int size) {
		return size >= 0 && size <= MAXIMUM_FILESIZE;
	}
}
