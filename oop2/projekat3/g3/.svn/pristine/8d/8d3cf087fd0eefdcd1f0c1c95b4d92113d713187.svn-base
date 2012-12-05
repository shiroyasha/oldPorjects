package microfb.client.widgets;

import com.google.gwt.user.client.ui.Image;

public class VCheck extends Image {

	private boolean checked = false;
	private final String TICK = "/images/Tick.png";
	private final String CROSS = "/images/Cross.png";
	
	public VCheck(boolean checked) {
		super();
		this.checked = checked;
		if (this.checked)
			on();
		else
			off();
	}
	
	public void on() {
		this.setUrl(TICK);
		checked = true;
	}
	
	public void off() {
		this.setUrl(CROSS);
		checked = false;
	}
	
	public boolean isChecked() {
		return checked;
	}
	
	public void toggle() {
		if (isChecked())
			off();
		else
			on();
	}
	
}
