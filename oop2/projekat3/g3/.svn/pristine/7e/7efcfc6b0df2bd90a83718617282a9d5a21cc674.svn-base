package microfb.client.widgets;

import microfb.client.FBEntryPoint;
import microfb.client.pages.HomePage;
import microfb.client.services.MicroFBServiceAsync;
import microfb.shared.Utilities;
import microfb.shared.IO.AktivnostIO;
import microfb.shared.exceptions.LogedOutException;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.Timer;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.FlowPanel;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.Widget;

public class WallChild extends Widget {
	
	private AktivnostIO a;
	private FlowPanel c;
	private MicroFBServiceAsync service;
	private HomePage page;
	
	public WallChild(AktivnostIO a, MicroFBServiceAsync service, HomePage page) {
		super();
		this.a = a;
		this.page = page;
		this.service = service;
		c = new FlowPanel();
		c.addStyleName("wallChildContainer");
		loadContainer();
	}
	
	private void loadContainer() {
		c.clear();
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
					}
					@Override
					public void onSuccess(Void result) {
						like.setVisible(false);
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
					}
					@Override
					public void onSuccess(Void result) {
						dislike.setVisible(false);
					}
				});
			}
		});
		c.add(dislike);
	}
	
	public FlowPanel getData() {
		return c;
	}	
}
