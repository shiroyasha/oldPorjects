package maze.gui;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import maze.maze.Cvor;
import maze.maze.Maze;
import maze.maze.MazeSolver;

/**
 * 
 * @author Milos Marinkovic
 * 
 */

public class Starter {

	private JFrame frmMazeSolver;
	private Point[] sol;
	private int dim;
	private int dens;
	private Maze mat;
	private Cvor[][] maze;
	private JLabel[][] all;
	

	/**
	 * Create the application.
	 */
	public Starter() {
		initialize();
		frmMazeSolver.setVisible(true);
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() 
	{
		//smaraj dok nije uneta pravilna vrednost
		do
		{
			try 
			{ dim = Integer.parseInt(new String(JOptionPane.showInputDialog("Matrix dimension( 5 - 20 )")));
			} catch( Exception e ) { dim = 0; }
		}while( dim < 5 || dim > 20 );
		
		//smaraj dok nije uneta pravilna vrednost
		do
		{
			try 
			{ dens = Integer.parseInt(new String(JOptionPane.showInputDialog("Wall density( 5 - 50 )")));
			} catch( Exception e ) { dens = 0; }
		}while( dens < 5 || dens >= 50);
		
		do {
			mat = new Maze(dim, dens);
			mat.makeMaze();
			maze = mat.getMazeLayout();
			sol = MazeSolver.getSolution(mat.getMazeLayout());
		} while(sol == null);
		
		frmMazeSolver = new JFrame();
		//frmMazeSolver.setIconImage( new ImageIcon( Starter.class.getResource("wall.png") ));
		frmMazeSolver.setTitle("Maze Solver");
		frmMazeSolver.setResizable(false);
		frmMazeSolver.setLocationRelativeTo(null);
		frmMazeSolver.setSize(dim * 50 + 100, dim * 50);
		frmMazeSolver.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmMazeSolver.setLayout(new BorderLayout());
		JPanel left = new JPanel();
		left.setLayout(new GridLayout(dim, dim, 0, 0));
		frmMazeSolver.getContentPane().add(left, BorderLayout.CENTER);
		JPanel right = new JPanel();
		
		
		//　suvise bi komplikovao projekat, posto bi pri svakoj promeni trebao javiti serveru,
		// i neznam sta bi radili ako bi se lavirint promenio dok agent radi na njemu   
		
		JButton rand = new JButton("Random");
		rand.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent a) {
				sol = null;
				do {
					mat = new Maze(dim, dens);
					mat.makeMaze();
					maze = mat.getMazeLayout();
					sol = MazeSolver.getSolution(mat.getMazeLayout());
				} while(sol == null);
				for (int i = 1; i < dim + 1; i++)
					for (int j = 1; j < dim + 1; j ++)
						if (maze[i][j].vrednost == 1)
							all[i][j].setIcon(new ImageIcon( Starter.class.getResource("wall.png") ));
						else
							all[i][j].setIcon(new ImageIcon( Starter.class.getResource("ground.png") ));
				for (int i = 1; i < dim + 1; i ++) 
					for (int j = 1; j < dim + 1; j++)
						if (inSolution(i, j))
							all[i][j].setIcon( new ImageIcon( Starter.class.getResource("path.png") ) );
				frmMazeSolver.validate();
				frmMazeSolver.repaint();
			}
		});

		Container cp = left;
		all = new JLabel[dim + 2][dim + 2];
		for (int i = 1; i < dim + 1; i++)
			for (int j = 1; j < dim + 1; j ++)
				if (maze[i][j].vrednost == 1) {
					all[i][j] = new JLabel(new ImageIcon( Starter.class.getResource("wall.png") ));
					cp.add(all[i][j]);
				} else {
					all[i][j] = new JLabel(new ImageIcon(Starter.class.getResource("ground.png")));
					cp.add(all[i][j]);
				}
		for (int i = 1; i < dim + 1; i ++) 
			for (int j = 1; j < dim + 1; j++)
				if (inSolution(i, j))
					all[i][j].setIcon(new ImageIcon( Starter.class.getResource("path.png") ));
		
		frmMazeSolver.getContentPane().add(left, BorderLayout.CENTER);
	}

	private boolean inSolution(int x, int y) {
		if (sol == null)
			return false;
		for (int i = 0; i < sol.length; i++)
			if (sol[i].x == x && sol[i].y == y)
				return true;
		return false;
	}

	public Maze getMaze() 
	{
		return mat;
	}
	
}
