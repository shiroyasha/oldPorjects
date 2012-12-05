package microfb.client;

import java.util.HashMap;

import microfb.client.pages.DialogPage;
import microfb.client.services.MicroFBService;
import microfb.client.services.MicroFBServiceAsync;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.core.client.GWT;
import com.google.gwt.user.client.ui.RootPanel;


public class FBEntryPoint implements EntryPoint {

	public static MicroFBServiceAsync service = GWT.create(MicroFBService.class);
	public static HashMap<String, RootPanel> panels;
	public static String sessionID = "";	
	
	@Override
	public void onModuleLoad() {
		try {
			panels = new HashMap<String, RootPanel>();
			panels.put("dialogPage", RootPanel.get("dialogPage"));
			panels.put("registerPage", RootPanel.get("registerPage"));
			panels.put("loginPage", RootPanel.get("loginPage"));
			panels.put("homePage", RootPanel.get("homePage"));
			panels.put("updateProfilePage", RootPanel.get("updateProfilePage"));
			
			new DialogPage(panels.get("dialogPage"), "dialogPage");
		} catch (Throwable e) {
			GWT.log("Entry point", e);
		}
	}

}
