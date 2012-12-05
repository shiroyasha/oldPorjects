package maze.maze;

import java.awt.Point;
import java.io.Serializable;

/**
 * 
 * @author Milos Marinkovic
 * @version 1.2
 * 
 */

public class MazeSolver implements Serializable{
	
	/*
	 * Klasa koja se koristi staticki za resavanje lavirinta, sadrzi
	 * samo metode iz klase Maze koji resavaju problem.
	 */
	
	private static int sirina;
	private static int visina;
	private static Cvor[][] graf;
	private static Point[] solution;
	private static int[] iviceX;
	private static int[] iviceY;

	public static Point[] getSolution(Cvor[][] maze) {
		solution = null;
		resetMaze(maze);
		
		if (solution == null)
			solve();
		sirina = visina = 0;
		graf = null;
		iviceX = iviceY = null;
		return solution;
	}
	
	private static void resetMaze(Cvor[][] maze) {
		graf = new Cvor[maze.length][maze[0].length];
		for (int i = 0; i < maze.length; i++)
			for (int j = 0; j < maze[0].length; j++)
				graf[i][j] = new Cvor(maze[i][j].oznaka, maze[i][j].vrednost, maze[i][j].mesto);
		sirina = maze.length - 2;
		visina = maze[0].length - 2;
		
		iviceX = new int[2];
		iviceX[0] = graf.length;
		iviceX[1] = 0;
		iviceY = new int[2];
		iviceY[0] = graf[0].length;
		iviceY[1] = 0;
		
	}
	
	private static void solve() {	
		Cvor next = new Cvor(0, 0, new Point(2, 1));
		boolean type = true;
		int counter = 1;
		
		graf[2][1].oznaka = 0;
		oznaci(2, 1, 0, type);
		
		while (graf[sirina - 1][visina].oznaka == -1 && next != null && ++counter <= (graf.length * graf[0].length) / 2) {
			next = getNextUnmarked();
			if (next != null) {
				type = !type;
				oznaci(next.mesto.x, next.mesto.y, next.oznaka, type);
			}
		}
		solution = getPath();
	}
	
	private static void oznaci(int x, int y, int oznaka, boolean primarno) {
		if (x == sirina - 1 && y == visina)
			return;
		if (graf[x][y].vrednost == 1)
			return;
		
		Cvor desni, levi, gornji, donji;
		desni = levi = gornji = donji = null;
		oznaka++;
		
		if (primarno) {
			
			if (!edgeX(x) && !edgeY(y + 1)) {
				desni = graf[x][y + 1];
				if (desni.oznaka == -1 && desni.vrednost != 1)
						desni.oznaka = oznaka;
			}
			if (!edgeX(x + 1) && !edgeY(y)) {
				donji = graf[x + 1][y];
				if (donji.oznaka == -1 && donji.vrednost != 1) 
					donji.oznaka = oznaka;
			}
			if (desni != null && desni.vrednost != 1 && desni.oznaka != -1)
				oznaci(desni.mesto.x, desni.mesto.y, oznaka, primarno);
			if (donji != null && donji.vrednost != 1 && donji.oznaka != -1)
				oznaci(donji.mesto.x, donji.mesto.y, oznaka, primarno);
			
		} else {
			
			if (!edgeX(x) && !edgeY(y - 1)) {
				levi = graf[x][y - 1];
				if (levi.oznaka == -1 && levi.vrednost != 1)
					levi.oznaka = oznaka;
			}
			if (!edgeX(x - 1) && !edgeY(y)) {
				gornji = graf[x - 1][y];
				if (gornji.oznaka == -1 && gornji.vrednost != 1)
					gornji.oznaka = oznaka;
			}
			if (levi != null && levi.vrednost != 1 && levi.oznaka != -1)
				oznaci(levi.mesto.x, levi.mesto.y, oznaka, primarno);
			if (gornji != null && gornji.vrednost != 1 && gornji.oznaka != -1)
				oznaci(gornji.mesto.x, gornji.mesto.y, oznaka, primarno);
		}
	}
	
	private static Point[] getPath() {
		if (graf == null)
			solve();
		int duzina = graf[sirina - 1][visina - 1].oznaka;
		if (duzina == -1)
			return null;
		Point node = new Point(sirina - 1, visina - 1);
		Point[] sol = new Point[duzina + 2];
		int i = 0;
		do {
			sol[i++] = node;
			node = getNextNode(node);
		} while (node != null);
		sol[i] = new Point(sirina - 1, visina);
		return sol;
	}
	
	private static Point getNextNode(Point p) {
		int x = p.x;
		int y = p.y;
		Cvor centar = graf[x][y];
		Cvor desno = graf[x + 1][y];
		Cvor levo = graf[x - 1][y];
		Cvor gore = graf[x][y - 1];
		Cvor dole = graf[x][y + 1];
		if (x == 2 && y == 1)
			return null;
		if (centar.oznaka - 1 == levo.oznaka)
			return levo.mesto;
		if (centar.oznaka - 1 == desno.oznaka)
			return desno.mesto;
		if (centar.oznaka - 1 == gore.oznaka)
			return gore.mesto;
		if (centar.oznaka - 1 == dole.oznaka)
			return dole.mesto;
		return null;
	}
	
	private static Cvor getNextUnmarked() {
		Point start = new Point(2, 1);
		Point end = new Point(sirina - 1, visina);
		Cvor exit = null;
		for (int i = 1; i < graf.length - 1; i++) {
			for (int j = 1; j < graf[i].length - 1; j++) {
				exit = graf[i][j];
				if (!exit.mesto.equals(end) && !exit.mesto.equals(start) &&
					exit.vrednost != 1 && exit.oznaka == -1)
				{
					Cvor newStart = smallestNeighbour(exit.mesto);
					if (newStart != null)
						return newStart;
				}
			}
		}
		return null;
	}
	
	private static Cvor smallestNeighbour(Point p) {
		final int MAX_OZ = graf.length * graf[0].length;
		Cvor min = new Cvor(MAX_OZ, 0, new Point(0, 0));
		
		Cvor levi = graf[p.x][p.y - 1];
		Cvor desni = graf[p.x][p.y + 1];
		Cvor gornji = graf[p.x - 1][p.y];
		Cvor donji = graf[p.x + 1][p.y];
		
		if (levi.vrednost != 1 && levi.oznaka != -1 && levi.oznaka < min.oznaka) {
			min = levi;
		}
		if (desni.vrednost != 1 && desni.oznaka != -1 && desni.oznaka < min.oznaka) {
			min = desni;
		}
		if (gornji.vrednost != 1 && gornji.oznaka != -1 && gornji.oznaka < min.oznaka) {
			min = gornji;
		}
		if (donji.vrednost != 1 && donji.oznaka != -1 && donji.oznaka < min.oznaka) {
			min = donji;
		}
		return (min.oznaka == MAX_OZ) ? null : min;
	}
	
	private static boolean edgeX(int x) {
		return (x == iviceX[0] || x == iviceX[1]);
	}
	
	private static boolean edgeY(int y) {
		return (y == iviceY[0] || y == iviceY[1]);
	}

}