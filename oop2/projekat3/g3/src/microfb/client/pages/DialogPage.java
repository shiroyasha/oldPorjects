package microfb.client.pages;

import microfb.client.widgets.ButtonFB;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.Cookies;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.RootPanel;


public class DialogPage extends AbstractPage {

	public DialogPage(RootPanel page, String style) {
		super(page, style);
	}

	@Override
	protected void defineElements() {			
		HTML title = new HTML();
		title.setHTML("<h1>Menu</h1><hr/>");
		addElement(title);

		Image logo = new Image("/images/Logo.png");
		addElement(logo);
		
		if (!Cookies.isCookieEnabled())
			title.setText("<h1>Cookies are disabled!</h1><hr/>");
		else {
			if (loggedIn() == null) {
				ButtonFB log = new ButtonFB("Login");
				addElement(log);
				ButtonFB reg = new ButtonFB("Register");
				addElement(reg);
				log.addClickHandler(new ClickHandler() {
					@Override
					public void onClick(ClickEvent event) {
						new LoginPage(panels.get("loginPage"), "loginPage");
					}
				});
				reg.addClickHandler(new ClickHandler() {
					@Override
					public void onClick(ClickEvent event) {
						new RegisterPage(panels.get("loginPage"), "registerPage");
					}
				});
			} else {
				ButtonFB log = new ButtonFB("Logout");
				addElement(log);
				log.addClickHandler(new ClickHandler() {
					@Override
					public void onClick(ClickEvent event) {
						logOut();
					}
				});
			}
		}
		
	}
	
}