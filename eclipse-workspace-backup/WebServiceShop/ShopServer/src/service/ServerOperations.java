package service;

import javax.ejb.Stateless;
import javax.jws.WebService;

@Stateless(mappedName = "ShopServiceLookup")
@WebService(endpointInterface = "service.SOI", serviceName = "ShopService")
public class ServerOperations implements SOI {

	private final int MIN_USER = 6;
	private final int MAX_USER = 20;
	private final int MIN_PASS = 6;
	private final int MAX_PASS = 20;
	
    public ServerOperations() {
        super();
    }

	@Override
	public boolean validUsername(String user) {
		int l = user.length();
		if (MIN_USER <= l && l <= MAX_USER)
			return true;
		return false;
	}

	@Override
	public boolean validPassword(String pass) {
		int l = pass.length();
		if (MIN_PASS <= l && l <= MAX_PASS)
			return true;
		return false;
	}

	@Override
	public String testConnection() {
		return "Success!";
	}

	@Override
	public String login(String user, String pass) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean logout() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String register(String[] data) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean loggedIn(String sessionId) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String[] getAllItems() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String[] getAllAvailableItems() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String[] getAllItemsOf(String type) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int getCurrentCost(String sessionId) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int getCurrentCostPlus(String sessionId) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int addToCart(String sessionId, Object item) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int removeFromCart(String sessionId, Object item) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public boolean checkout(String sessionId) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String[] getCommentsFor(Object item) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int getRatingFor(Object item) {
		// TODO Auto-generated method stub
		return 0;
	}    

}
