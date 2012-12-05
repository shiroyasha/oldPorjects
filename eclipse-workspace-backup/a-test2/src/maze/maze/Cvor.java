package maze.maze;

import java.awt.Point;

/**
 * 
 * @author Milos Marinkovic
 * @version 1.1
 * 
 */

public class Cvor {
	
	/*
	 * Pomocna klasa za cuvanje dodatnih informacija o polju lavirinta.
	 */
	
	public int oznaka;
	public int vrednost;
	public Point mesto;

	public Cvor(int oznaka, int vrednost, Point mesto) {
		this.oznaka = oznaka;
		this.vrednost = vrednost;
		this.mesto = mesto;
	}
}