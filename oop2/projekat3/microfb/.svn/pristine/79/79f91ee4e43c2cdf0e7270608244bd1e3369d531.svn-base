package microfb.client.widgets;

import java.util.ArrayList;
import java.util.List;

import microfb.client.FBEntryPoint;
import microfb.client.pages.HomePage;
import microfb.client.services.MicroFBServiceAsync;
import microfb.shared.Utilities;
import microfb.shared.IO.AktivnostIO;
import microfb.shared.exceptions.LogedOutException;

import com.google.gwt.core.client.GWT;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.Timer;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.FlowPanel;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.Widget;

public class WallPost extends Widget {

	private AktivnostIO a;
	private FlowPanel c, cpan;
	private boolean showingComments = false;
	private MicroFBServiceAsync service;
	private ArrayList<WallChild> children;
	private HomePage page;
	
	public WallPost(AktivnostIO a, MicroFBServiceAsync service, HomePage page) {
		super();
		this.a = a;
		this.page = page;
		this.service = service;
		c = new FlowPanel();
		cpan = new FlowPanel();
		children = new ArrayList<WallChild>();
		c.addStyleName("wallPostContainer");
		loadContainer();
	}
	
	private void loadContainer() {
		c.clear();
		
		final String picture = Utilities.nadjiSliku(a.getValue());
		String video = Utilities.nadjiVideo(a.getValue());
		String text = Utilities.nadjiUrlove(a.getValue());
		
		c.add(new HTML("<strong>" + a.getFrom() + "</strong>: " +
					   "<span style=\"color: orange; margin-top: 10px;\">" + text + "</span><br/>"));
		c.add(new HTML("<span style\"color: #808080; font-size: 12px;\">" + Utilities.generateFuzzyTime(System.currentTimeMillis(), a.getTime()) + "</span>"));
		
		/***************************** EMBED *****************************/
		if(!video.equals(""))
			c.add(new HTML("<div style='display:inline-block;'>" + video + "</div>"));
        else if (!picture.equals("")) {
        	final Image slika = new Image(picture);
        	slika.setVisible(false);
    		final NewBool resized = new NewBool(false);
    		final Timer tester = new Timer() {
    			@Override
    			public void run() {
    				if (slika.getWidth() < 20 || slika.getHeight() < 20)
    					slika.setUrl(picture);
    				else
    					if (!resized.get()) {
    						int h = slika.getHeight();
    						int w = slika.getWidth();
    						slika.addStyleName("postPicture");
    						int newW = slika.getWidth();
    						int newH = slika.getHeight();
    						try {
    							newH = h * newW / w;
    						} catch (Exception e) {}
    						slika.setHeight(newH + "px");
    						slika.setVisible(true);
    						resized.set(true);
    						this.cancel();
    					}
    			}
    		};
    		tester.scheduleRepeating(2000);
    		c.add(slika);
			c.add(new HTML("<br/>"));
        }
		/*************************** EMBED END *****************************/
		
		final ButtonFB like = new ButtonFB("Like (" + a.getLikes() + ")");
		like.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				service.like(FBEntryPoint.sessionID, a.getId(), new AsyncCallback<Void>() {
					@Override
					public void onFailure(Throwable caught) {
						if (caught instanceof LogedOutException)
							page.logOut();
						else {
							caught.printStackTrace();
							GWT.log("Like", caught);
						}
					}
					@Override
					public void onSuccess(Void result) {
						like.setVisible(false);
						page.reloadWall();
					}
				});
			}
		});
		c.add(like);
		
		final ButtonFB dislike = new ButtonFB("Dislike (" + a.getDislikes() + ")");
		dislike.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				service.unlike(FBEntryPoint.sessionID, a.getId(), new AsyncCallback<Void>() {
					@Override
					public void onFailure(Throwable caught) {
						if (caught instanceof LogedOutException)
							page.logOut();
						else {
							caught.printStackTrace();
							GWT.log("Unlike", caught);
						}
					}
					@Override
					public void onSuccess(Void result) {
						dislike.setVisible(false);
						page.reloadWall();
					}
				});
			}
		});
		c.add(dislike);
		
		final Image loading = new Image("/images/AJAXanim.gif");
		loading.setVisible(false);
		c.add(loading);
		
		final ButtonFB comments = new ButtonFB("Comments (" + a.getKomentariCount() + ")");
		comments.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				if (!showingComments) {
					loading.setVisible(true);
					comments.setVisible(false);
					System.out.println("IDa: " + a.getId());
					service.getKomentari(FBEntryPoint.sessionID, a.getId(), -1, -1, new AsyncCallback<List<AktivnostIO>>() {
						@Override
						public void onFailure(Throwable caught) {
							if (caught instanceof LogedOutException)
								page.logOut();
							else {
								comments.setText("Error! Please reload page.");
								caught.printStackTrace();
								GWT.log("Get comments", caught);
								
								showingComments = false;
								comments.setVisible(true);
								loading.setVisible(false);
							}
						}
	
						@Override
						public void onSuccess(List<AktivnostIO> result) {
							children.clear();
							for (AktivnostIO ak : result)
								children.add(new WallChild(ak, service, page));
							loadChildren();
							
							loading.setVisible(false);
							comments.setText("Collapse");
							comments.setVisible(true);
							showingComments = true;
							cpan.setVisible(true);
						}
					});
				} else {
					showingComments = false;
					comments.setText("Comments (" + a.getKomentariCount() + ")");
					cpan.setVisible(false);
					comments.setVisible(true);
					loading.setVisible(false);
				}
				
			}
		});
		c.add(comments);
		
		final ButtonFB remove = new ButtonFB("Remove post");
		remove.setVisible(false);
		Timer refresh = new Timer() {
			@Override
			public void run() {
				if (page.thiskor != null) {
					makeDeleteBtn(remove, like, dislike, comments, loading);
					this.cancel();
				}
			}
		};
		refresh.scheduleRepeating(1000);
		
		c.add(cpan);
		loadChildren();
		cpan.setVisible(false);
	}
	
	private void loadChildren() {
		cpan.clear();
		
		if (children.size() > 0)
			for (WallChild wc : children)
				cpan.add(wc.getData());
		
		cpan.add(makePostForm());		
	}
	
	private void refreshChildren() {
		service.getKomentari(FBEntryPoint.sessionID, a.getId(), -1, -1, new AsyncCallback<List<AktivnostIO>>() {
			@Override
			public void onFailure(Throwable caught) {
				if (caught instanceof LogedOutException)
					page.logOut();
				else {
					caught.printStackTrace();
					GWT.log("Refreshing children", caught);
				}
			}

			@Override
			public void onSuccess(List<AktivnostIO> result) {
				children.clear();
				for (AktivnostIO ak : result)
					children.add(new WallChild(ak, service, page));
			}
		});
	}
	
	private FlowPanel makePostForm() {
		FlowPanel wall = new FlowPanel();
		
		final MemoFB postText = new MemoFB();
		wall.add(postText);
		final Image miniLoad = new Image("/images/AJAXanim.gif");
		miniLoad.setVisible(false);
		wall.add(miniLoad);
		final ButtonFB postBtn = new ButtonFB("Comment");
		wall.add(postBtn);
		postBtn.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				postBtn.setVisible(false);
				miniLoad.setVisible(true);
				String post = postText.getText();
				
				if (!post.trim().isEmpty())
					service.post(FBEntryPoint.sessionID, a.getId(), post, new AsyncCallback<Void>() {
						@Override
						public void onSuccess(Void result) {
							refreshChildren();
							loadChildren();
							a.setKomentariCount(a.getKomentariCount() + 1);
						}
						
						@Override
						public void onFailure(Throwable caught) {
							if (caught instanceof LogedOutException)
								page.logOut();
							else {
								postText.setText("Error commenting: " + caught.getMessage());
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
		return wall;
	}
	
	private void makeDeleteBtn(final ButtonFB remove, final ButtonFB like,
							   final ButtonFB dislike, final ButtonFB comments,
							   final Image loading) {
		if (page.thiskor == null)
			System.out.println("Still null");
		
		if (page.thiskor.getEmail().equalsIgnoreCase(a.getOwner()))
			remove.setVisible(true);
		
		remove.addClickHandler(new ClickHandler() {
			@Override
			public void onClick(ClickEvent event) {
				remove.setVisible(false);
				like.setVisible(false);
				dislike.setVisible(false);
				comments.setVisible(false);
				loading.setVisible(true);
				service.deletePost(FBEntryPoint.sessionID, a.getId(), new AsyncCallback<Void>() {

					@Override
					public void onFailure(Throwable caught) {
						if (caught instanceof LogedOutException)
							page.logOut();
						else {
							caught.printStackTrace();
							GWT.log("Deleting post", caught);
							remove.setVisible(true);
							like.setVisible(true);
							dislike.setVisible(true);
							comments.setVisible(true);
							loading.setVisible(false);
						}
					}

					@Override
					public void onSuccess(Void result) {
						page.reloadWall();
					}
					
				});
			}
		});
	}
	
	public FlowPanel getData() {
		return c;
	}
	
}
