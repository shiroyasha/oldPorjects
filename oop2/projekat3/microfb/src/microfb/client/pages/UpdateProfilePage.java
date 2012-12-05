package microfb.client.pages;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import microfb.client.FBEntryPoint;
import microfb.client.widgets.ButtonFB;
import microfb.client.widgets.PassBoxFB;
import microfb.client.widgets.TextBoxFB;
import microfb.client.widgets.VCheck;
import microfb.client.widgets.WallPost;
import microfb.shared.Utilities;
import microfb.shared.Validator;
import microfb.shared.IO.AktivnostIO;
import microfb.shared.IO.KorisnikIO;
import microfb.shared.exceptions.LogedOutException;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.event.dom.client.KeyUpEvent;
import com.google.gwt.event.dom.client.KeyUpHandler;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.FileUpload;
import com.google.gwt.user.client.ui.FlowPanel;
import com.google.gwt.user.client.ui.FormPanel;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.google.gwt.user.client.ui.FormPanel.SubmitCompleteEvent;
import com.google.gwt.user.client.ui.FormPanel.SubmitCompleteHandler;

public class UpdateProfilePage extends AbstractPage {

	protected HashMap<String, RootPanel> homepage;
	private FlowPanel top, wall, left, right;
	
	protected KorisnikIO kor, thiskor;
	
	public UpdateProfilePage(RootPanel page, String style) {
		super(page, style);
		
		if (loggedIn() == null) {
			new LoginPage(panels.get("loginPage"), "loginPage");
			System.out.println("Redirect - not logged in!");
		}
	}

	@Override
	protected void defineElements() {
		top = new FlowPanel();
		top.addStyleName("top");
		left = new FlowPanel();
		left.addStyleName("left");
		right = new FlowPanel();
		right.addStyleName("right");
		wall = new FlowPanel();
		wall.addStyleName("wall");
		
		addElement(top);
		addElement(left);
		addElement(right);
		addElement(wall);
		
		final HTML title = new HTML();
		title.setHTML("<h1>Update information</h1>");
		top.add(title);
		
		
		ButtonFB nazad = new ButtonFB("Home Page");
		nazad.setWidth("150px");
		nazad.addClickHandler( new ClickHandler() {
			
			@Override
			public void onClick(ClickEvent event) {
				new HomePage(panels.get("homePage"), "homePage");
			}
		});
		
		top.add( nazad );

		
		service.getKorisnik(FBEntryPoint.sessionID, new AsyncCallback<KorisnikIO>() {
			@Override
			public void onSuccess(final KorisnikIO result) {
				

				
				HTML imei = new HTML();
				imei.setHTML("First and Last Name:");
				final TextBoxFB ime = new TextBoxFB();
				ime.setText( result.getIme());
				wall.add(imei);
				wall.add(ime);
				final VCheck imec = new VCheck(true);
				wall.add(imec);
				ime.addKeyUpHandler(new KeyUpHandler() {
					@Override
					public void onKeyUp(KeyUpEvent event) {
						if (!ime.getText().trim().isEmpty())
							imec.on();
						else
							imec.off();
					}
				});
				
				wall.add(new HTML("<hr style='width:300px;margin:10px auto 10px auto;' />"));
				
				
				HTML passi = new HTML();
				passi.setHTML("Password:");
				final PassBoxFB pass = new PassBoxFB();
				wall.add(passi);
				wall.add(pass);
				final VCheck passc = new VCheck(true);
				wall.add(passc);

				HTML passi2 = new HTML();
				passi2.setHTML("Repeat password:");
				final PassBoxFB pass2 = new PassBoxFB();
				wall.add(passi2);
				wall.add(pass2);
				final VCheck passc2 = new VCheck(true);
				wall.add(passc2);
				
				final HTML passStrength = new HTML();
				passStrength.setHTML("strenth: " + "<div style='font-weight:900;display:inline;color:" + Utilities.passwordStrength(pass.getText()).getColor() + ";' >" 
									 + Utilities.passwordStrength(pass.getText()).toString().replace("_", " ").toLowerCase() + "</div>");
				wall.add(passStrength);
				
				wall.add( new HTML("<br/>"));
				
				pass.addKeyUpHandler(new KeyUpHandler() {
					@Override
					public void onKeyUp(KeyUpEvent event) {
						passStrength.setHTML("strenth: " + "<div style='font-weight:900;display:inline;color:" + Utilities.passwordStrength(pass.getText()).getColor() + ";' >" 
											+ Utilities.passwordStrength(pass.getText()).toString().replace("_", " ").toLowerCase() + "</div>");
						if( pass.getText().isEmpty() || Validator.password(pass.getText()) )
							passc.on();
						else
							passc.off();
					}
				});
				pass2.addKeyUpHandler(new KeyUpHandler() {
					@Override
					public void onKeyUp(KeyUpEvent event) {
						if ( ( pass2.getText().isEmpty() && pass.getText().isEmpty() ) || 
						     ( Validator.password(pass2.getText()) && pass2.getText().equals(pass.getText())) )
							passc2.on();
						else
							passc2.off();
					}
				});
				
				
				wall.add(new HTML("<hr style='width:300px;margin:10px auto 10px auto;' />"));				
				
				
				HTML datei = new HTML();
				datei.setHTML("Birthdate:");
				final TextBoxFB date = new TextBoxFB();
				date.setText( result.getBirthdate() );
				wall.add(datei);
				wall.add(date);
				final VCheck datec = new VCheck(true);
				wall.add(datec);
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
				city.setText( result.getCurrentCity() );
				wall.add(cityi);
				wall.add(city);
				wall.add(new VCheck(true));
				
				HTML worki = new HTML();
				worki.setHTML("Workplace:");
				final TextBoxFB work = new TextBoxFB();
				work.setText( result.getWorkplace() );
				wall.add(worki);
				wall.add(work);
				wall.add(new VCheck(true));
				
				HTML quotei = new HTML();
				quotei.setHTML("Quote:");
				final TextBoxFB quote = new TextBoxFB();
				quote.setText( result.getQuote() );
				wall.add(quotei);
				wall.add(quote);
				wall.add(new VCheck(true));
				
				HTML sexi = new HTML();
				sexi.setHTML("Sex:");
				final TextBoxFB sex = new TextBoxFB();
				sex.setText( result.getSex() );
				wall.add(sexi);
				wall.add(sex);
				wall.add(new VCheck(true));
					
				
				wall.add(new HTML("<hr style='width:300px;margin:10px auto 10px auto;' />"));	
				
				
				
				
				HTML profilei = new HTML();
				profilei.setHTML("Profile photo:");
				wall.add(profilei);
				
				
				final FormPanel form = new FormPanel();
				form.setEncoding(FormPanel.ENCODING_MULTIPART);
				form.setMethod(FormPanel.METHOD_POST); // koristi POST
				form.setAction("/uploadService?sessionID=" + FBEntryPoint.sessionID + 
								"&email=" + result.getEmail() + "&type=profile");
				
				final FileUpload fu = new FileUpload();
				fu.setName("Upload");

				form.add(fu);
				
				wall.add(form);
				
				
				
				
				
				
				HTML coveri = new HTML();
				coveri.setHTML("Cover Photo:");
				wall.add(coveri);
				
				final FormPanel form1 = new FormPanel();
				form1.setEncoding(FormPanel.ENCODING_MULTIPART);
				form1.setMethod(FormPanel.METHOD_POST); // koristi POST
				form1.setAction("/uploadService?sessionID=" + FBEntryPoint.sessionID + 
						"&email=" + result.getEmail() + "&type=cover");
				
				final FileUpload fu1 = new FileUpload();
				fu1.setName("Upload");

				form1.add(fu1);
				
				wall.add(form1);				
				
				
				
				
				
				
				ButtonFB b = new ButtonFB("Update");
				b.setWidth("150px");
				wall.add(b);
				
				b.addClickHandler( new ClickHandler() {
					
					@Override
					public void onClick(ClickEvent event) {
						
						result.setIme( ime.getText() );
						if( Validator.password(pass.getText()) && pass.getText().equals(pass2.getText()) ) result.setPassword(pass.getText());
						result.setBirthdate( date.getText() );
						result.setWorkplace( work.getText() );
						result.setQuote( quote.getText() );
						result.setSex( sex.getText() );
						
						//profile
						if( fu.isAttached() )
							form.submit();
						
						form.addSubmitCompleteHandler( new SubmitCompleteHandler() {
							
							@Override
							public void onSubmitComplete(SubmitCompleteEvent event) {
								title.setText("Succes");
								
							}
						});
						
						form1.addSubmitCompleteHandler( new SubmitCompleteHandler() {
							
							@Override
							public void onSubmitComplete(SubmitCompleteEvent event) {
								title.setText("Succes");
								
							}
						});
						
						//cover
						if( fu1.isAttached() )
							form1.submit();
						
						service.updateKorisnik( FBEntryPoint.sessionID, result, new AsyncCallback<Void>() {
							
							@Override
							public void onSuccess(Void result) {
								//title.setText("Succes");
							}
							
							@Override
							public void onFailure(Throwable caught) {
								if( caught instanceof LogedOutException) {
									logOut();	
								}
								
								title.setText("Check your data!");
								
							}
						});
					}
				});
		
			}
			
			
			@Override
			public void onFailure(Throwable caught) {
				if (caught instanceof LogedOutException)
				{
					logOut();
				}
			}
		});
		

		
	}
}