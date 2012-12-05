
import javax.swing.*;

public class SpisakMaker {
	
	public static void main( String[] args )
	{
		
		try
		{
			UIManager.setLookAndFeel( UIManager.getSystemLookAndFeelClassName() );
		}catch(Exception e)
		{
			
		}
	    SpisakMakerGui g = new SpisakMakerGui();
	    g.init();
	}
}
