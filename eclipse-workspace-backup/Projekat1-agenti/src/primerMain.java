
import gui.GlavniGui;

import javax.swing.UIManager;

/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */
public class primerMain
{
	public static void main(String[] args)
	{
		try {
			UIManager.setLookAndFeel( UIManager.getSystemLookAndFeelClassName() );
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		GlavniGui gui = new GlavniGui(null);
	}
}
