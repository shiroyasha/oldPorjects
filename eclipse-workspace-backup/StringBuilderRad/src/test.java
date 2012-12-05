

import javax.swing.*;
import java.awt.BorderLayout;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.ListSelectionEvent;
import java.awt.GridLayout;
import java.awt.Dimension;
import javax.swing.tree.DefaultMutableTreeNode;

@SuppressWarnings("serial")
public class test extends JFrame
{
	private JTextField textField;
	private JTextField textField_1;
	private JTree tree;
	private DefaultMutableTreeNode root;
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public test() {
		setTitle("Nesto");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.NORTH);
		panel.setLayout(new GridLayout(2, 0, 0, 0));
		
		JPanel panel_1 = new JPanel();
		panel.add(panel_1);
		panel_1.setLayout(new BoxLayout(panel_1, BoxLayout.X_AXIS));
		
		JButton btnPrev = new JButton("Prev");
		panel_1.add(btnPrev);
		
		JButton btnForv = new JButton("Forv");
		panel_1.add(btnForv);
		
		textField = new JTextField();
		panel_1.add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setMaximumSize(new Dimension(300, 2147483647));
		panel_1.add(textField_1);
		textField_1.setColumns(10);
		
		JPanel panel_2 = new JPanel();
		panel.add(panel_2);
		panel_2.setLayout(new BoxLayout(panel_2, BoxLayout.X_AXIS));
		
		JButton btnNewButton = new JButton("New button");
		panel_2.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("New button");
		panel_2.add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("New button");
		panel_2.add(btnNewButton_2);
		
		JSplitPane splitPane = new JSplitPane();
		splitPane.setOrientation(JSplitPane.VERTICAL_SPLIT);
		splitPane.setContinuousLayout(true);
		getContentPane().add(splitPane, BorderLayout.CENTER);
		
		JPanel panel_3 = new JPanel();
		splitPane.setLeftComponent(panel_3);
		
		root = new DefaultMutableTreeNode("straasdas");
		
		tree = new JTree( root );
		
		root.add( new DefaultMutableTreeNode("ispod") );
		root.add( new DefaultMutableTreeNode("ispod1") );
		root.add( new DefaultMutableTreeNode("ispod2") );
		
		panel_3.add(tree);
		JPanel panel_4 = new JPanel();
		splitPane.setRightComponent(panel_4);
		
		JLabel lblasdfasdfasdfasdfasdfasdfasdfasd = new JLabel("<html><b>asdfasdfasdfasdfasdfasdfasdfasd</b>");
		panel_4.add(lblasdfasdfasdfasdfasdfasdfasdfasd);
	}
	
	public static void main( String[] args )
	{
		
		
		test t  = new test();
		t.setVisible(true);
		
		
		
	}

}
