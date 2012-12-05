package service;

import javax.ejb.Remote;
import javax.jws.WebService;

@Remote
@WebService
public interface SOI {
	
	public String testConnection();
	
	public boolean validUsername(String user);
	public boolean validPassword(String pass);
	
	public String login(String user, String pass);
	public boolean logout();
	public String register(String[] data);
	public boolean loggedIn(String sessionId);
	
	public String[] getAllItems();
	public String[] getAllAvailableItems();
	public String[] getAllItemsOf(String type);
	
	public int getCurrentCost(String sessionId);
	public int getCurrentCostPlus(String sessionId);
	public int addToCart(String sessionId, Object item);
	public int removeFromCart(String sessionId, Object item);
	public boolean checkout(String sessionId); 
	
	public String[] getCommentsFor(Object item);
	public int getRatingFor(Object item);
	
}
