package proba2.client;

import java.util.ArrayList;
import java.util.List;
import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.core.client.GWT;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.VerticalPanel;

/**
 * Entry point class.
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
public class UserActivation implements EntryPoint, ClickHandler
{
	private RegServiceAsync service = GWT.create(RegService.class);
	private VerticalPanel pnlFields; // cuva polja za unos (InputField instance)
	private List<InputField> fields;
	private Button submit;
	private Image ajax;
	private InputField email;
	private InputField pass;
	private RootPanel root;
	
	@Override
	public void onModuleLoad()
	{
		pnlFields = new VerticalPanel();
		fields = new ArrayList<InputField>();
		
		// polje za unos e-mail adrese
		// regulari izrazi: http://docs.oracle.com/javase/7/docs/api/java/util/regex/Pattern.html
		fields.add( email = new InputField(this, "E-mail:", "[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}", false) );
		fields.add( pass = new InputField(this, "Password: ", ".{6,}", true) );
		// dodaj u GUI
		pnlFields.add(email);
		pnlFields.add(pass);
		
		HorizontalPanel hp = new HorizontalPanel();
		hp.setSpacing(4);
		hp.setVerticalAlignment(HorizontalPanel.ALIGN_MIDDLE);
		
		// submit dugme...
		submit = new Button("Submit");
		submit.addClickHandler(this);
		submit.setEnabled(false);
		hp.add(submit);
		// ... i AJAX ikonica pored njega
		ajax = new Image("img/ajax-loader.gif");
		ajax.setVisible(false);
		hp.add(ajax);
		
		pnlFields.add(hp);
		
		root = RootPanel.get("main");
		root.add(pnlFields);
	}
	
	// korisnik je menjao neko polje
	public void onFieldChange()
	{
		boolean ok = true;
		// proveravamo da li su sva polja ok
		for (InputField f : fields)
			if (!f.isOk())
			{
				ok = false;
				break;
			}
		submit.setEnabled(ok);
	}

	@Override
	public void onClick(ClickEvent event)
	{
		// disable-ujemo dugme i prikazujemo AJAX animaciju
		submit.setEnabled(false);
		ajax.setVisible(true);
		
		// asinhroni poziv
		service.register(email.getText(), pass.getText(), new AsyncCallback<Boolean>() {
			@Override
			public void onFailure(Throwable caught)
			{
				// prikazi gresku u prozoru
				HTML res = new HTML("Error: " + caught.getMessage());
				root.remove(0); // ukloni 0. widget
				root.add(res);
			}

			@Override
			public void onSuccess(Boolean result)
			{
				HTML res;
				if (result)
					res = new HTML("Success! A confirmation e-mail has been sent to your e-mail address.");
				else
					res = new HTML("Error, the specified e-mail address already exists.");
				root.remove(0);
				root.add(res);
			}
		});
	}
}
