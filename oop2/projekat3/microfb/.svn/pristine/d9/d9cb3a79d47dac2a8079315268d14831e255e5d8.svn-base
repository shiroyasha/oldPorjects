package microfb.client.pages;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import microfb.client.FBEntryPoint;
import microfb.client.widgets.ButtonFB;
import microfb.client.widgets.MemoFB;
import microfb.client.widgets.NewBool;
import microfb.client.widgets.TextBoxFB;
import microfb.client.widgets.WallPost;
import microfb.shared.IO.AktivnostIO;
import microfb.shared.IO.KorisnikIO;
import microfb.shared.exceptions.LogedOutException;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.Timer;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.FlowPanel;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.RootPanel;

public class HomePage extends AbstractPage {

	protected HashMap<String, RootPanel> homepage;
	private FlowPanel top, wall, left, right;
	
	private TextBoxFB search;
	public KorisnikIO kor, thiskor;
	
	public HomePage(RootPanel page, String style) {
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
		
		loadTop();
		loadLeft(null);
		// loadRight(); - LOADING FROM LEFT
		// loadWall(null); - LOADING FROM LEFT
		
		FlowPanel logoPanel = new FlowPanel();
		Image logoutImage = new Image("/images/LogoMini.png");
		logoPanel.add(logoutImage);
		logoutImage.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				logOut();
			}
		});
		logoPanel.addStyleName("logo");
		addElement(logoPanel);
	}

	
	
	private void loadTop() {
		top.clear();
		
		search = new TextBoxFB();
		search.setWidth("150px");
		top.add(search);
		
		final Image loading = new Image("/images/AJAXanim.gif");
		top.add(loading);
		loading.setVisible(false);
		
		final ButtonFB find = new ButtonFB("Find user");
		find.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				String user = search.getText().trim();
				loading.setVisible(true);
				search.setVisible(false);
				find.setVisible(false);
				
				service.searchForKorisnik(FBEntryPoint.sessionID, user, new AsyncCallback<KorisnikIO>() {
					@Override
					public void onSuccess(KorisnikIO result) {
						search.setVisible(true);
						find.setVisible(true);
						loading.setVisible(false);
						
						if (result != null) {
							loadLeft(result.getEmail());
							search.setText("");
						} else {
							search.setText("User not found!");
							search.setFocus(true);
						}
					}
					
					@Override
					public void onFailure(Throwable caught) {
						if (caught instanceof LogedOutException)
							logOut();
						else {
							search.setVisible(true);
							find.setVisible(true);
							loading.setVisible(false);
							search.setText("Error: " + caught.getMessage());
							search.setFocus(true);
						}
					}					
				});
			}
		});
		top.add(find);
	}
	
	
	
	private void loadLeft(final String username) {
		left.clear();
		
		final Image loading = new Image("/images/AJAXanim.gif");
		loading.setVisible(true);
		left.add(loading);
		
		ButtonFB updateProfile = new ButtonFB("Profile Settings");
		updateProfile.addClickHandler(new ClickHandler() {
			
			@Override
			public void onClick(ClickEvent event) {
				new UpdateProfilePage(panels.get("updateProfilePage"), "homePage");
			}
		});
		
		left.add(updateProfile);

		final HTML info = new HTML();
		info.setHTML("Error retrieving info.<br/>");
		info.setVisible(false);
		left.add(info);
		
		AsyncCallback<KorisnikIO> response = new AsyncCallback<KorisnikIO>() {
			@Override
			public void onSuccess(KorisnikIO result) {
				kor = result;
				loading.setVisible(false);
				left.add(new HTML("<h1>Personal data</h1><hr/><br/>"));
				left.add(new HTML("<h1 style=\"display: inline-block;\">" + result.getIme() + "</h1><br />"));
				left.add(new HTML("[ " + result.getSex() + " ]"));
				left.add(new HTML("<a href=\"mailto:" + result.getEmail() + "\">" + result.getEmail() + "</a>"));
				left.add(new HTML(result.getBirthdate()));
				left.add(new HTML(result.getCurrentCity()));
				left.add(new HTML(result.getWorkplace()));
				if (kor.getEmail().equals(username)) thiskor = kor;
				loadRight(kor);
				loadWall(kor);
			}
			
			@Override
			public void onFailure(Throwable caught) {
				if (caught instanceof LogedOutException)
					logOut();
				else {
					loading.setVisible(false);
					info.setVisible(true);
					ButtonFB reload = new ButtonFB("Reload");
					reload.addClickHandler(new ClickHandler() {
						@Override
						public void onClick(ClickEvent event) {
							String user = username;
							loadLeft(user);
						}
					});
				}
			}
		};
		
		if (username == null || username.isEmpty())
			service.getKorisnik(FBEntryPoint.sessionID, response);
		else
			service.getKorisnikByEmail(FBEntryPoint.sessionID, username, response);
	}
	
	
	
	private void loadRight(final KorisnikIO kor) {
		right.clear();
		
		if (kor == null) {
			loadLeft(null);
			return;
		}
		
		final Image profile = new Image("/uploadService?sessionID=" + FBEntryPoint.sessionID +"&email=" + kor.getEmail() + "&type=profile");
		profile.setVisible(false);
		final NewBool resized = new NewBool(false);
		final Timer tester = new Timer() {
			@Override
			public void run() {
				if (profile.getWidth() < 20 || profile.getHeight() < 20)
					profile.setUrl("/uploadService?sessionID=" + FBEntryPoint.sessionID +"&email=" + kor.getEmail() + "&type=profile");
				else
					if (!resized.get()) {
						int h = profile.getHeight();
						int w = profile.getWidth();
						profile.addStyleName("profile");
						int newW = profile.getWidth();
						int newH = profile.getHeight();
						try {
							newH = h * newW / w;
						} catch (Exception e) {}
						profile.setHeight(newH + "px");
						profile.setVisible(true);
						resized.set(true);
						this.cancel();
					}
			}
		};
		tester.scheduleRepeating(2000);
		right.add(profile);
		
		right.add(new HTML("<hr/><br/>"));
		right.add(new HTML("<h1>" + kor.getQuote() + "</h1>"));
	}
	
	
	
	private void loadWall(final KorisnikIO kor) {
		wall.clear();
		final String username = (kor == null) ? thiskor.getEmail() : this.kor.getEmail();

		final Image cover = new Image("/uploadService?sessionID=" + FBEntryPoint.sessionID +"&email=" + kor.getEmail() + "&type=cover");
		cover.setVisible(false);
		final NewBool resized = new NewBool(false);
		final Timer tester = new Timer() {
			@Override
			public void run() {
				if (cover.getWidth() < 20 || cover.getHeight() < 20)
					cover.setUrl("/uploadService?sessionID=" + FBEntryPoint.sessionID +"&email=" + kor.getEmail() + "&type=profile");
				else
					if (!resized.get()) {
						int h = cover.getHeight();
						int w = cover.getWidth();
						cover.addStyleName("cover");
						int newW = cover.getWidth();
						int newH = cover.getHeight();
						try {
							newH = h * newW / w;
						} catch (Exception e) {}
						cover.setHeight(newH + "px");
						cover.setVisible(true);
						resized.set(true);
						this.cancel();
					}
			}
		};
		tester.scheduleRepeating(2000);
		wall.add(cover);
		
		final MemoFB postText = new MemoFB();
		wall.add(postText);
		final Image miniLoad = new Image("/images/AJAXanim.gif");
		miniLoad.setVisible(false);
		wall.add(miniLoad);
		final ButtonFB postBtn = new ButtonFB("Post");
		wall.add(postBtn);
		postBtn.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				postBtn.setVisible(false);
				miniLoad.setVisible(true);
				String post = postText.getText();
				if (!post.trim().isEmpty())
					service.post(FBEntryPoint.sessionID, kor.getEmail(), post, new AsyncCallback<Void>() {
						@Override
						public void onSuccess(Void result) {
							KorisnikIO kori = kor;
							loadWall(kori);
						}
						
						@Override
						public void onFailure(Throwable caught) {
							if (caught instanceof LogedOutException)
								logOut();
							else {
								postText.setText("Error posting to wall: " + caught.getMessage());
								miniLoad.setVisible(false);
								postBtn.setVisible(true);
							}
						}
					});
				else {
					postText.setText("Please enter some text...");
					miniLoad.setVisible(false);
					postBtn.setVisible(true);
				}
			}
		});
		wall.add(new HTML("<hr/>"));
		
		final ArrayList<WallPost> posts = new ArrayList<WallPost>();

		final Image loading = new Image("/images/AJAXanim.gif");
		loading.setVisible(true);
		wall.add(loading);
		
		final HTML info = new HTML("<h1>Error getting wall posts!</h1><br/>");
		wall.add(info);
		info.setVisible(false);
		
		final HomePage homePage = this;
		
		service.getWallItems(FBEntryPoint.sessionID, username, -1, -1, new AsyncCallback<List<AktivnostIO>>() {
			@Override
			public void onSuccess(List<AktivnostIO> result) {
				for (AktivnostIO a : result)
					posts.add(new WallPost(a, service, homePage));
				if (posts.size() > 0)
					for (WallPost wp : posts)
						wall.add(wp.getData());
				else
					wall.add(new HTML("<h1>No wall posts</h1><br/>"));
				loading.setVisible(false);
			}
			
			@Override
			public void onFailure(Throwable caught) {
				if (caught instanceof LogedOutException)
					logOut();
				else {
					info.setVisible(true);
					// info.setHTML("<h1>Error: " + caught.getMessage() + "</h1><br/>");
					loading.setVisible(false);
					ButtonFB reload = new ButtonFB("Reload posts");
					reload.addClickHandler(new ClickHandler() {
						@Override
						public void onClick(ClickEvent event) {
							KorisnikIO kori = kor;
							loadWall(kori);
						}
					});
				}
			}
		});
		
	}
	
	public void reloadWall() {
		loadWall(kor);
	}
	public void reloadLeft() {
		loadLeft(kor == null ? null : kor.getEmail());
	}
	public void reloadRight() {
		loadRight(kor);
	}
}