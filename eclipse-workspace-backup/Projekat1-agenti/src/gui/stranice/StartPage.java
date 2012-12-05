package gui.stranice;

import gui.GlavniGui;

import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JPanel;


/**
 * 
 * @author Igor Sarcevic ( igisar@gmail.com )
 *
 */
@SuppressWarnings("serial")
public class StartPage extends JComponent 
{
	JPanel centralniPanel;
	
	// argument je final da bi bio koristiv iz lokalne anonimne klase
	public StartPage(final GlavniGui parent) 
	{
		//izgled - centralni panel se namesta na sredinu
		setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
		Component glue = Box.createGlue();
		add(glue);
		
		JPanel panel = new JPanel();
		panel.setLayout( new BoxLayout(panel, BoxLayout.Y_AXIS) );
		add(panel);
		
		Component verticalGlue = Box.createVerticalGlue();
		panel.add(verticalGlue);
		
		centralniPanel = new JPanel();
		panel.add(centralniPanel);
	
		Component verticalGlue_1 = Box.createVerticalGlue();
		panel.add(verticalGlue_1);
		
		Component glue2 = Box.createGlue();
		add(glue2);
		
		
		//komponente
		centralniPanel.setLayout( new GridLayout(2, 1, 5, 5) );
		
		
		JButton btnStart = new JButton("Start new race");
		JButton btnQuit = new JButton("Quit");
		
		centralniPanel.add(btnStart);
		centralniPanel.add(btnQuit);
		
		btnStart.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				( (GlavniGui) parent).nextPage();
				
			}
		});
		
		btnQuit.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				parent.dispose();
			}
		});
			
	}

	public void reset() 
	{
		// do nothing, cisto se nalazi ovde posto se nalazi u svakom drugom ^_^
		
	}
}
