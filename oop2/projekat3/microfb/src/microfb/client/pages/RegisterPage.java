package microfb.client.pages;

import microfb.client.widgets.ButtonFB;
import microfb.client.widgets.PassBoxFB;
import microfb.client.widgets.TextBoxFB;
import microfb.client.widgets.VCheck;
import microfb.shared.Validator;

import com.google.gwt.core.client.GWT;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.event.dom.client.KeyUpEvent;
import com.google.gwt.event.dom.client.KeyUpHandler;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.RootPanel;


public class RegisterPage extends AbstractPage {
	
	public RegisterPage(RootPanel page, String style) {
		super(page, style);
	}

	@Override
	protected void defineElements() {
		if (loggedIn() != null)	new HomePage(panels.get("homePage"), "homePage");
		
		final HTML title = new HTML();
		title.setHTML("<h1>Register</h1><hr/>");
		addElement(title);
		
		HTML imei = new HTML();
		imei.setHTML("First and Last Name:");
		final TextBoxFB ime = new TextBoxFB();
		addElement(imei);
		addElement(ime);
		final VCheck imec = new VCheck(false);
		addElement(imec);
		ime.addKeyUpHandler(new KeyUpHandler() {
			@Override
			public void onKeyUp(KeyUpEvent event) {
				if (!ime.getText().trim().isEmpty())
					imec.on();
				else
					imec.off();
			}
		});
		
		HTML maili = new HTML();
		maili.setHTML("E-Mail:");
		final TextBoxFB mail = new TextBoxFB();
		addElement(maili);
		addElement(mail);
		final VCheck mailc = new VCheck(false);
		addElement(mailc);
		mail.addKeyUpHandler(new KeyUpHandler() {
			@Override
			public void onKeyUp(KeyUpEvent event) {
				if (Validator.email(mail.getText()))
					mailc.on();
				else
					mailc.off();
			}
		});
		
		HTML passi = new HTML();
		passi.setHTML("Password:");
		final PassBoxFB pass = new PassBoxFB();
		addElement(passi);
		addElement(pass);
		final VCheck passc = new VCheck(false);
		addElement(passc);

		HTML passi2 = new HTML();
		passi2.setHTML("Repeat password:");
		final PassBoxFB pass2 = new PassBoxFB();
		addElement(passi2);
		addElement(pass2);
		final VCheck passc2 = new VCheck(false);
		addElement(passc2);
		
		pass.addKeyUpHandler(new KeyUpHandler() {
			@Override
			public void onKeyUp(KeyUpEvent event) {
				if (
						Validator.password(pass.getText()) &&
						( (!pass2.getText().trim().isEmpty() && pass.getText().equals(pass2.getText()) || pass2.getText().trim().isEmpty()) )
					)
					passc.on();
				else
					passc.off();
			}
		});
		pass2.addKeyUpHandler(new KeyUpHandler() {
			@Override
			public void onKeyUp(KeyUpEvent event) {
				if (Validator.password(pass2.getText()) 
						&& pass2.getText().equals(pass.getText()))
					passc2.on();
				else
					passc2.off();
			}
		});
		
		HTML datei = new HTML();
		datei.setHTML("Birthdate:");
		final TextBoxFB date = new TextBoxFB();
		addElement(datei);
		addElement(date);
		final VCheck datec = new VCheck(false);
		addElement(datec);
		date.addKeyUpHandler(new KeyUpHandler() {
			@Override
			public void onKeyUp(KeyUpEvent event) {
				if (!date.getText().trim().isEmpty())
					datec.on();
				else
					datec.off();
			}
		});
		
		HTML cityi = new HTML();
		cityi.setHTML("Current city:");
		final TextBoxFB city = new TextBoxFB();
		addElement(cityi);
		addElement(city);
		addElement(new VCheck(true));
		
		HTML worki = new HTML();
		worki.setHTML("Workplace:");
		final TextBoxFB work = new TextBoxFB();
		addElement(worki);
		addElement(work);
		addElement(new VCheck(true));
		
		HTML quotei = new HTML();
		quotei.setHTML("Quote:");
		final TextBoxFB quote = new TextBoxFB();
		addElement(quotei);
		addElement(quote);
		addElement(new VCheck(true));
		
		HTML sexi = new HTML();
		sexi.setHTML("Sex:");
		final TextBoxFB sex = new TextBoxFB();
		addElement(sexi);
		addElement(sex);
		addElement(new VCheck(true));
		
		HTML br = new HTML();
		br.setHTML("<br/>");
		addElement(br);
		
		final ButtonFB reg = new ButtonFB("Register");
		final ButtonFB back = new ButtonFB("Menu");
		addElement(reg);
		addElement(back);

		final Image loading = new Image("/images/AJAXanim.gif");
		loading.setVisible(false);
		addElement(loading);
		
		back.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				new DialogPage(panels.get("dialogPage"), "dialogPage");
			}
		});
		
		reg.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				if (imec.isChecked() && mailc.isChecked() && passc.isChecked() &&
					passc2.isChecked() && datec.isChecked()) {
					
					reg.setVisible(false);
					back.setVisible(false);
					loading.setVisible(true);
					
					service.register(mail.getText(), pass.getText(), ime.getText(), date.getText(),
									 city.getText(), work.getText(), quote.getText(), sex.getText(),
						new AsyncCallback<Void>() {
							
							@Override
							public void onSuccess(Void result) {
								title.setHTML("<h1 style=\"color: green;\">Registered!</h1><hr/>");
								reg.setVisible(false);
								back.setVisible(true);
								loading.setVisible(false);
							}
							
							@Override
							public void onFailure(Throwable caught) {
								title.setHTML("<h1 style=\"color: red; font-size: 12px;\">Error: " + caught.getMessage() + "</h1><hr/>");
								reg.setVisible(true);
								back.setVisible(true);
								loading.setVisible(false);
								GWT.log("Registration", caught);
							}
						});
				} else {
					title.setHTML("<h1 style=\"color: red;\">Check your data!</h1><hr/>");
				}
			}
		});
	}

}
