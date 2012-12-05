
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.font.NumericShaper.Range;
import java.awt.CardLayout;

@SuppressWarnings("serial")
public class SpisakMakerGui extends JFrame implements ActionListener {
	private JTable table;
	
	public SpisakMakerGui()
	{
		
		JScrollPane scrollPane = new JScrollPane();
		getContentPane().add(scrollPane, BorderLayout.CENTER);
		
		table = new JTable();
		table.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) {
				if( e.getKeyCode() == KeyEvent.VK_DELETE )
				{
					int i = table.getSelectedRow();
					model1.delete( i );
					table.getSelectionModel().setSelectionInterval( i, i );
				}
			}
		});
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		scrollPane.setViewportView(table);
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.NORTH);
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));
		
		textField = new JTextField();
		textField.setMaximumSize(new Dimension(200, 2147483647));
		panel.add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setMaximumSize(new Dimension(200, 2147483647));
		panel.add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setMaximumSize(new Dimension(200, 2147483647));
		panel.add(textField_2);
		textField_2.setColumns(10);
		
		Component horizontalGlue = Box.createHorizontalGlue();
		panel.add(horizontalGlue);
		
		JButton btnNewButton = new JButton("Submit");
		panel.add(btnNewButton);
		
		
		JPanel panel_1 = new JPanel();
		getContentPane().add(panel_1, BorderLayout.SOUTH);
		
		JButton btnDelete = new JButton("Delete");
		
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) 
			{
				model1.delete( table.getSelectedRow() );
			}
		});
		panel_1.setLayout(new CardLayout(0, 0));
		
		panel_1.add(btnDelete, "name_455652100483");
		
		JButton btnMoveup = new JButton("MoveUp");
		btnMoveup.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				if( !model1.moveUp( table.getSelectedRow() ) ) return;
				table.getSelectionModel().setSelectionInterval(table.getSelectedRow() - 1, table.getSelectedRow() - 1 );
			}
		});
		
		panel_1.add(btnMoveup, "name_455797175797");
		
		JButton btnMovedown = new JButton("MoveDown");
		btnMovedown.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				if( !model1.moveDown( table.getSelectedRow() ) ) return;
				table.getSelectionModel().setSelectionInterval(table.getSelectedRow() + 1, table.getSelectedRow() + 1 );				
			}
		});
		panel_1.add(btnMovedown, "name_455942688930");
		btnNewButton.addActionListener( this );
		
		
		
	}
	private ModelPodataka model1 = new ModelPodataka();
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	
	public void init()
	{
		
		table.setModel( model1 );
		
		setSize(300, 300);
		setVisible( true );
		
		new Range(1, 5);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// On Submit button clicked
		
		model1.addRed( textField.getText(), textField_1.getText(), textField_2.getText() );
	}
	
	
	
}
