package maze;

import java.awt.Point;

/**
 * 
 * @author Milos Marinkovic
 * @version 1.1
 * 
 */

public class Maze {

	/*
	 * U prvom delu klase implementirani su standardni metodi za ucitavanje i kreiranje lavirinta,
	 * konstruktori, pomocne promenljive i konstante.
	 * 
	 * U drugom delu implementirani su privatni metodi koji se koriste da bi se olaksao rad unutar
	 * glavnih metoda koji resavaju problem.
	 * 
	 * Korstante se koriste kao sigurnosne vrednosti pri kreiranju Objekta Maze.
	 * Promenljiva gustZidova koristi se da bi se odredila kolicina zidova unutar lavirinta,
	 * i izrazena je kao ceo broj. Predstavlja procentualnu popunjenost lavirinta zidovima.
	 * 
	 * Lavirint je predstavljen pomocu dvodimenzionalnog niza sa elementima tipa Cvor, dok je resenje
	 * problema (najkraci put) predstavljeno jednodimenzionalnim nizom ciji su elementi tipa Point. 
	 * 
	 * Unutrasnja klasa Cvor koristi se kako bi se olaksao rad sa poljima matrice koja predstavlja
	 * lavirint, i sadrzi neka standardna polja.
	 */
	
	private final int MAX_DIM = 10;
	private final int MIN_DIM = 3;
	private final int DEFAULT_GUSTINA = 20;
	private final int MIN_GUST = 5;
	private final int MAX_GUST = 50;
	private final String ZID = "#";
	private final String PRAZNO = " ";
	private final String PUTANJA = "O";

	private int sirina, visina;
	private int gustZidova;
	private Cvor[][] graf;
	private Point[] solution;

	public class Cvor {
		public int oznaka;
		public int vrednost;
		public Point mesto;

		public Cvor(int oznaka, int vrednost, Point mesto) {
			this.oznaka = oznaka;
			this.vrednost = vrednost;
			this.mesto = mesto;
		}
	}

	/*
	 * Standarna 3 konstruktora:
	 * 1. Bez parametara - uzima default gustinu zidova i postavlja dimenziju na najvecu mogucu
	 * 2. Uzima 2 parametra - dimenzija se koristi kao velicina matrice (dimenzija x dimenzija),
	 * 	  dobija se kvadratni lavirint
	 * 3. Uzima 3 parametra - visina, sirina i gustina zidova 
	 */
	
	public Maze() {
		super();
		sirina = visina = MAX_DIM;
		gustZidova = DEFAULT_GUSTINA;
	}

	public Maze(int dimenzija, int gustinaZidova) {
		super();
		if (valid(dimenzija))
			sirina = visina = dimenzija;
		else
			sirina = visina = MAX_DIM;
		if (validG(gustinaZidova))
			gustZidova = gustinaZidova;
		else
			gustZidova = DEFAULT_GUSTINA;
	}

	public Maze(int sir, int vis, int gustinaZidova) {
		super();
		if (valid(vis))
			sirina = vis;
		else
			sirina = MAX_DIM;
		if (valid(sir))
			visina = sir;
		else
			visina = MAX_DIM;
		if (validG(gustinaZidova))
			gustZidova = gustinaZidova;
		else
			gustZidova = DEFAULT_GUSTINA;
	}
	
	/*
	 * Get metodi za vracanje resenja i vracanje izgleda lavirinta
	 */

	public Cvor[][] getMazeLayout() {
		if (graf == null)
			makeMaze();
		return graf;
	}

	public Point[] getSolution() {
		if (solution == null)
			solve();
		return solution;
	}
	
	/*
	 * Ovaj metod koristi gustinu prosledjenu u konstruktoru kako bi generisao matricu,
	 * i to ako je nasumicno odabrani broj manji od te gustine, stavlja se zid.
	 * 
	 * Takodje, zidovi se stavljaju i oko cele matrice i na sva polja osim ulaza i izlaza.
	 * 
	 * Obezbedjeno je i da putanja u lavirintu bude bar 2 polja dugacka, tako sto je prvo
	 * polje pored ulaza i prvo polje pored izlaza postavljeno na prazno.
	 * 
	 * Kreirana matrica cuva se u promenljivoj graf
	 */
	
	public void makeMaze() {
		graf = new Cvor[sirina + 2][visina + 2];
		for (int i = 0; i < sirina + 2; i++)
			for (int j = 0; j < visina + 2; j++)
				if (i == 0 || i == 1 || j == 0 || j == 1 || i == sirina + 1
						|| i == sirina || j == visina + 1 || j == visina
						|| randomNum(1, 99) <= gustZidova) {
					graf[i][j] = new Cvor(-1, 1, new Point(i, j));
				} else {
					graf[i][j] = new Cvor(-1, 0, new Point(i, j));
				}
		graf[2][1].vrednost = graf[sirina - 1][visina].vrednost = 0;
		graf[2][2].vrednost = graf[sirina - 1][visina - 1].vrednost = 0;
	}
	
	/*
	 * Kontrolni metod printToConsole() koristi se iskljucivo da bi se odstampala matrica u konzolu.
	 * U finalnoj verziji aplikacije, bice najverovatnije onemogucen.
	 */
	
	@Deprecated
	public void printToConsole() {
		if (graf == null)
			makeMaze();
		if (solution == null)
			solve();
		for (int i = 1; i < graf.length - 1; i++) {
			for (int j = 1; j < graf[i].length - 1; j++)
				System.out.print((graf[i][j].vrednost == 1 ? ZID : (inSolution(i, j) ? PUTANJA : PRAZNO)) + " ");
			System.out.println();
		}
	}
	
	/*
	 * Ideja resavanja lavirinta je pronalazenje dva najkraca puta:
	 * 1. Kretanje primarno DESNO, sekundarno DOLE. U slucaju nailaska na prepreku,
	 * 	  prepreka se obilazi, cime se dobija produzen put.
	 * 2. Kretanje primarno DOLE, sekundarno DESNO. Obilazak prepreke je analogan.
	 * 
	 * U oba slucaja je put produzen za (povrsina prepreke + broj strana prepreke) DIV 2.
	 * Ovo nije tako velik obilazak, ali najverovatnije ne daje najkraci moguci put do izlaza.
	 * Kao resenje problema produzenja puta, traze se obe putanje - i putanja (1) i putanja(2).
	 * 
	 * Koriscenjem pomocnog metoda getPath() dobija se niz tacaka zeljene putanje, a zatim se
	 * uporedjuju putanja dobijena na prvi nacin sa putanjom drugog nacina. Ona koja ima kraci
	 * niz, ima i manje tacaka, odnosno kraca je. Ukoliko jedna od putanja ne daje dobre rezultate,
	 * ona uzima vrednost null, cime se skracuje provera duzina i automatski dodeljuje druga putanja
	 * resenju lavirinta.
	 * 
	 * Koristi se pomocni metod oznaci(int, int, int, int) za oznacavanje tacaka u matrici, cime se
	 * omogucuje pronalazenje najkrace putanje.
	 */
	
	private void solve() {
		oznaci(2, 1, 0, 1);
		Point[] path1 = getPath();
		resetMaze();
		oznaci(2, 1, 0, 2);
		Point[] path2 = getPath();
		if (path1 == null && path2 != null)
			solution = path2;
		else if (path2 == null && path1 != null)
			solution = path1;
		else if (path1 == null && path2 == null)
			solution = null;
		else
			solution = (path1.length < path2.length) ? path1 : path2;
	}
	
	/*
	 * Metod oznaci(x, y, oznaka, tip) oslanja se delimicno na BFS algoritam pretrazivanja
	 * nekog grafa. Promenljive x i y sluze za oznacavanje pozicije na kojoj je nalazi posmatrani
	 * cvor.
	 * 
	 * Kako su elementi dvodimenzionalnog niza "graf" tipa Cvor, sadrse i korisna javna polja, cije
	 * se vrednosti lako uzimaju i menjaju.
	 * 
	 * Ideja je da se, pocevsi od prvog cvora (ulaza), obelezavaju cvorovi na sledeci nacin:
	 *  - Ako je cvor zid ili vec obelezen, prelazi se na sledeci.
	 *  - Ako je cvor poslednji cvor u lavirintu, oznacava se sa 0, i prekida se nastavak na tu stranu.
	 *  - Ako je cvor neobelezen, obelezava se trenutnom oznakom (parametar "oznaka"), a vrednost te
	 *	  oznake se povecava za jedan.
	 *  - Na ovaj nacin, posecuju se jos preostala 3 cvora sve dok svi moguci cvorovi ne postanu obelezeni.
	 *  
	 * Prelazak na sledeci cvor je modifikacija bektreka, cime se osigurava da svi cvorovi budu poseceni i
	 * obelezeni.
	 * 
	 * Parametar "tip" sluzi za odredjivanje nacina trazenja, ako je tip = 1, primarno je DESNO, inace DOLE.
	 */
	
	private void oznaci(int x, int y, int oznaka, int tip) {
		if (graf[x][y].vrednost == 1)
			return;
		if (graf[x][y].oznaka != -1)
			return;
		if (x == sirina - 1 && y == visina) {
			graf[x][y].oznaka = 0;
			return;
		}
		graf[x][y].oznaka = oznaka++;
		if (tip == 1) {
			oznaci(x + 1, y, oznaka, 1);
			oznaci(x, y + 1, oznaka, 1);
		} else {
			oznaci(x, y + 1, oznaka, 2);
			oznaci(x + 1, y, oznaka, 2);
		}
		oznaci(x - 1, y, oznaka, tip);
		oznaci(x, y - 1, oznaka, tip);
	}
	
	
	/*
	 * Pomocni metod koji vraca tacno ako se unete koordinate nalaze u nizu resenja "solution" 
	 */
	
	private boolean inSolution(int x, int y) {
		if (solution == null)
			return false;
		for (int i = 0; i < solution.length; i++)
			if (solution[i].x == x && solution[i].y == y)
				return true;
		return false;
	}
	
	/*
	 * Pomocni metod koji ponovo inicijalizuje lavirint, kako bi se omogucilo ponovno obelezavanje svih
	 * cvorova unutar matrice. Takodje, sve vrednosti koje su mozda bile izmenjene se ponovo
	 * vracaju na pocetne.
	 */
	
	private void resetMaze() {
		if (graf != null)
			for (int i = 0; i < sirina + 2; i++)
				for (int j = 0; j < visina + 2; j++) {
					graf[i][j].oznaka = -1;
					if (graf[i][j].vrednost != 1)
						graf[i][j].vrednost = 0;
				}
		else
			makeMaze();
	}
	
	/*
	 * Pomocni metod koji vraca najkracu putanju obelezenog lavirinta.
	 * 
	 * Ideja je sledeca:
	 * Posto ce se u procesu obelezavanja kreiraju neke dvostruke vrednosti za oznaku cvora,
	 * na primer kada se udje u slepi put i slicno, nije bezbedno osloniti se na upisivanje
	 * cvorova od najmanjeg do najveceg obelezja.
	 * Kao resenje ovog problema, cvorovi se u resenje upisuju obrnutim redosledom, od najvece
	 * vrednosti oznake ka najmanjoj. Ovako se osigurava da ce putanja biti bez racvastih delova,
	 * koji bi mogli da nastanu ukoliko bi se islo prvim redosledom.
	 * 
	 * Kreira se novi niz tacaka (Point[]) duzine za 2 vece od najblize oznake pri izlazu. U njega
	 * se upisuju redom sve tacke sa oznakom za 1 manjom od prethodne. Pronalazak sledece tacke koja
	 * se upisuje omogucuje pomocni metod getNextNode(Point).
	 * 
	 * Kada se dodje do pocetne tacke, niz se zavrsava, ali on jos uvek ima jedan element manje nego
	 * sto bi trebalo, jer se upis putanje pocinje od obelezja najblizeg izlazu, a ne od samog izlaza.
	 * Ovaj problem je resen tako sto se u niz resenja dodaje i izlaz, cime je niz resenja kompletiran.
	 * 
	 * Razlog zbog kojeg se ne krece od samog izlaza je taj sto je vrednost oznake na izlazu (ako je
	 * lavirint resiv) uvek 0, pa bi trazenje manjeg obelezja od 0 bilo nemoguce. Ako je lavitint neresiv,
	 * to znaci da je obelezje na izlazu ostalo nepromenjeno (-1), i kao resenje se vraca "null".
	 */
	
	private Point[] getPath() {
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

	/*
	 * Pomocni metod za pronalazenje koordinata susednog cvora koji ima obelezje za 1 manje.
	 */
	
	private Point getNextNode(Point p) {
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
	
	/*
	 * Metodi valid(int) i validG(int) koriste se da bi se proverio opseg unetih vrednosti
	 * za visinu, sirinu, dimenziju i gustinu. U slucaju loseg opsega, vrednosti uzimaju
	 * default konstante, odnosno maksimalne vrednosti za dimenziju.
	 * 
	 * Metod randomNum vraca jedan ceo broj iz opsega u konstrukroru.
	 */
	
	private boolean valid(int dim) {
		return (dim <= MAX_DIM && dim >= MIN_DIM) ? true : false;
	}

	private boolean validG(int gust) {
		return (gust <= MAX_GUST && gust >= MIN_GUST) ? true : false;
	}

	private int randomNum(int min, int max) {
		java.util.Random r = new java.util.Random();
		return r.nextInt((max - min + 1)) + min;
	}

}
