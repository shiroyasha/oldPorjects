package proba2.client;

import com.google.gwt.event.dom.client.KeyUpEvent;
import com.google.gwt.event.dom.client.KeyUpHandler;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.PasswordTextBox;
import com.google.gwt.user.client.ui.TextBox;

/**
 * Polje za unos podatka (e-mail ili sifra). Sastoji se iz statickog
 * teksta i TextBox widget-a.
 * 
 * @author <a href="mitrovic.dejan@gmail.com">Dejan Mitrovic</a>
 * @version 1.0
 */
public class InputField extends HorizontalPanel
{
	private String pattern; 
	private TextBox box;
	private Image image;
	private boolean ok;
	private UserActivation userActivation;
	
	/**
	 * Konstruktor komponente. 
	 * 
	 * @param userActivation Referenca na glavnu aplikaciju.
	 * @param caption Staticki tekst.
	 * @param pattern Regularni izraz koji unos mora zadovoljiti.
	 * @param isPassword Da li treba maskirati sadrzaj TextBox-a?
	 */
	public InputField(UserActivation userActivation, String caption, String pattern, boolean isPassword)
	{
		this.userActivation = userActivation;
		this.pattern = pattern;
		setSpacing(4);
		setVerticalAlignment(HorizontalPanel.ALIGN_MIDDLE);
		
		HTML h = new HTML(caption);
		h.setWidth("70px");
		add(h);
		
		if (isPassword)
			box = new PasswordTextBox();
		else
			box = new TextBox();
		
		// kako korisnik menja unos, proveravamo da li su podaci ok
		box.addKeyUpHandler(new KeyUpHandler()
		{
			@Override
			public void onKeyUp(KeyUpEvent event)
			{
				TextBox box = (TextBox) event.getSource();
				updateControls(box);
			}
		});
		box.setWidth("200px");
		add(box);
		
		ok = false;
		// zvezdica
		image = new Image("img/reqfield.png"); 
		add(image);
	}
	
	private void updateControls(TextBox box)
	{
		// da li unos zadovoljava regularni izraz?
		if (box.getText().matches(pattern))
		{
			if (!ok)
			{
				ok = true;
				image.setUrl("img/okfield.png");
			}
		}
		else
		{
			if (ok)
			{
				ok = false;
				image.setUrl("img/reqfield.png");
			}
		}
		// javi glavnoj aplikaciji da je doslo do izmene unosa
		userActivation.onFieldChange();
	}

	public boolean isOk()
	{
		return ok;
	}
	
	public String getText()
	{
		return box.getText();
	}
}
