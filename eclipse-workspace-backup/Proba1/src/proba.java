import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class proba extends JApplet
{
	double mem = 0.0;
	boolean novi = true;
	
	public void init()
	{
		setLayout( new BorderLayout(5, 5) );
		
		JPanel gore = new JPanel();
		gore.setLayout( new GridLayout(1, 1) );
		final JTextField tf = new JTextField("0");
		
		gore.add(tf);
		tf.setHorizontalAlignment( JTextField.RIGHT );
		tf.setEditable( false );
		
		JPanel dole = new JPanel();
		
		dole.setLayout( new GridLayout( 4, 3, 5, 5) );
		
		for( int i = 1; i < 10; i++)
		{
			JButton b = new JButton(i + "");
			
			b.addActionListener( new ActionListener() {
				public void actionPerformed( ActionEvent e )
				{
					if ( !novi )
						tf.setText( tf.getText() + ((JButton)e.getSource()).getText() );
					else
						tf.setText( ((JButton)e.getSource()).getText() );
					
					novi = false;
				}
			});
			dole.add( b );
		}
		
		JButton b = new JButton(".");
		
		b.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e )
			{
				if( !novi )
					tf.setText( tf.getText() + ((JButton)e.getSource()).getText() );
				else
					tf.setText( "0." );
				
				novi = false;
			}
		});	
		dole.add( b );

		
		b = new JButton(0 + "");
		
		b.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e )
			{
				if ( !novi )
					tf.setText( tf.getText() + ((JButton)e.getSource()).getText() );
				else
					tf.setText( ((JButton)e.getSource()).getText() );
				
				novi = false;
			}
		});
		dole.add( b );
		
		b = new JButton("+");
		
		b.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e )
			{
				mem += Double.parseDouble( tf.getText() );
				tf.setText( mem + "" );
				novi = true;
			}
		});
		dole.add( b );		
		
		
		
		
		add( gore, BorderLayout.NORTH );
		add( dole, BorderLayout.CENTER );
	}
	
	public void start()
	{
		
	}
	
	
	public static void main( String[] args )
	{
		JFrame frame = new JFrame("naslov");
		
		frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		
		JApplet app = new proba();

		
		frame.getContentPane().add( app );
		
		
		app.init();
		app.start();
		frame.setSize( 300, 300 );
		frame.setVisible(true);
		
	}
}