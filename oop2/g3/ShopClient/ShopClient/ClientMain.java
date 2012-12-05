package ShopClient;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.UIManager;
import javax.swing.JSplitPane;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 * 
 * 	Osnovna klasa klijenta. Klijenat se pokrece tako sto se napravi instanca
 * 	ove klase
 * 
 * 	Klasa komunicira sa WebServisom, i pruza korisniku informacije dostupne na WebServisu
 *
 */
@SuppressWarnings("serial")
public class ClientMain extends JFrame {
	
	// koristimo dvije tabele, jednu osnovu za pregled i pretragu, a drugu kao korpu
	// tabelu korpa mozemo koristiti samo ako smo ulogovani
	private JTable tableView;
	private TableModelView model;
	private JTable tableCart;
	private TableModelCart tableModelCart;
	
	// radi lakseg rada u klijentskoj aplikaciji dodata meni traka sa nekim opcijama
	private JMenuBar menuBar;
	private JMenu mnOptions;
	private JMenu mnHistory;
	private JMenuItem menuLogin;
	private JMenuItem menuRegister;
	private JMenuItem menuLogout;
	private JMenuItem menuHistory;
	
	private JSplitPane splitPane;
	
	private JPanel panelUp;
	private JPanel panelDown;
	private JPanel panelDownNorth;
	private JPanel panelUpNorth;
	private JPanel panelDownMiddle;
	private JPanel panelUpSouth;
	
	private JButton loginDugme;
	private JButton registerDugme;
	private JButton show;
	private JButton comments;
	private JButton remove;
	private JButton checkout;
	private JButton insert;
	private JButton buy;
	private JButton ratings;
	
	// dva comboBoxa koristimo za filtriranje podataka
	// prvi kombobox sluzi da saopstimo aplikaciji da li zelimo da dobijemo
	// sve artikle, ili samo one koji su trenutno na lageru,
	// drugi sluzi da pretrazujemo po tipu artikla
	private JComboBox comboBoxMain;
	private JComboBox comboBoxType;
	
	// u ovoj promjenjivoj cuvamo da li smo ulogovani ili ne
	private boolean loggedin;
	
	// Dovoljno je napraviti objekat pomocu ovog konstruktora 
	// da bi pokrenuli prozor klijenta
	public ClientMain(){
		try {
			UIManager.setLookAndFeel(
            UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e){}
		loggedin=false;
		setTitle("LoseLose WebService");
		setSize(800, 600);
		setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
	
		initialiseCentral();
		initialiseBtm();
		initialiseMenu();
		
		setVisible(true);
	}
	
	
	// pomocna metoda za inicijalizaciju
	// inicijalizuje osnovnu tabelu i dugmice za rad sa njom
	private void initialiseCentral(){
		
		// osnovni split panel, koji odvaja tabelu sa artiklima od korisnicke korpe
		splitPane = new JSplitPane();
		splitPane.setResizeWeight(1.0);
		splitPane.setOrientation(JSplitPane.VERTICAL_SPLIT);
		splitPane.setContinuousLayout(true);
		add(splitPane, BorderLayout.CENTER);
		
		
		// pomocni paneli
		panelUp = new JPanel();
		panelDown = new JPanel();
		panelDownNorth = new JPanel();
		panelUpNorth= new JPanel();
		panelDownMiddle=new JPanel();
		panelUpSouth=new JPanel();
		
		
		panelDown.setLayout(new BorderLayout());
		panelDownMiddle.setLayout(new BorderLayout());
		panelUp.setLayout(new BorderLayout());
		
		panelDown.add(panelDownNorth,BorderLayout.NORTH);
		panelDown.add(panelDownMiddle,BorderLayout.CENTER);
		panelUp.add(panelUpNorth,BorderLayout.NORTH);
		panelUp.add(panelUpSouth,BorderLayout.SOUTH);
		
		// model osnovne tabele, ne prikazuje nista dok korisnik ne zatrazi
		model=new TableModelView(null);
		tableView = new JTable(model);
		tableView.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
			@Override public void valueChanged(ListSelectionEvent e){
				comments.setEnabled(tableView.getSelectedRow()!=-1);
				ratings.setEnabled(tableView.getSelectedRow()!=-1);
				if (loggedin){
					btnUpdate();
				}
			}
		});
		tableView.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane scp=new JScrollPane(tableView);
		panelUp.add( scp, BorderLayout.CENTER );
		
		
		comboBoxMain=new JComboBox();
		comboBoxMain.setToolTipText("Izaberite da li zelite da pregledate sve komponente koje nudimo, ili samo one koje trenutno imamo na lageru!");
		comboBoxMain.addItem("Sve komponente u ponudi");
		comboBoxMain.addItem("Trenutno dostupne komponente");
		panelUpNorth.add(comboBoxMain);
		
		// dugme kojim korisnik saopstava da zeli da pregleda komponente, i to onakve
		// kako je naveo u combobox-ovima
		show = new JButton("Prikazi definisane komponente");
		show.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				
				// TODO salje Web Servisu zahtjev, i dobija niz definisanih komponenti
				// koje zatim ubacuje preko tableModelView u osnovnu tabelu
				
				// za testiranje, ubacujemo 5 artikala koji nemaju bas smisla
				Article[] a=new Article[5];
				for(int i=0;i<5;i++){
					a[i]=new Article(i," artikl "+i,100+i," tip "+i);
				}
				model.setArticles(a);
				
			}
		});
		show.setToolTipText("Klikom na ovo dugme dobicete tabelu komponenata prema podesenim filterima(padajuce liste lijevo i desno)!");
		panelUpNorth.add(show);
		
		
		comboBoxType=new JComboBox();
		comboBoxType.setToolTipText("Mozete izabrati tacno koji tip komponente zelite da pregledate!");
		
		// TODO salje Web Serveru zahtjev, i dobija niz svih tipova, zatim ubacuje u combobox metodom comboBoxAdd
		
		panelUpNorth.add(comboBoxType);
		
		
		comments=new JButton("komentari");
		comments.setToolTipText("Pritiskom na ovo dugme vidicete komentare kupaca za datu komponentu");
		comments.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO salje servisu zahtjev, a dobija niz svih komentara i ocjena odredjenog artikla
				new CommentsFrame(null);
				
			}
		});
		comments.setEnabled(false);
		
		panelUpSouth.add(comments,BorderLayout.SOUTH);
		
		ratings=new JButton("ocene");
		ratings.setToolTipText("Pritiskom na ovo dugme vidicete ocene kupaca za datu komponentu");
		ratings.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO salje servisu zahtjev, a dobija niz svih komentara i ocjena odredjenog artikla
				new CommentsFrame(null);
				
			}
		});
		ratings.setEnabled(false);
		
		panelUpSouth.add(ratings,BorderLayout.SOUTH);
		
		
		splitPane.setRightComponent(panelDown);
		splitPane.setLeftComponent(panelUp);
		
		// kada se pokrene aplikacija, korisnik nije ulogovan, pa ne moze da pristupi djelu prozora sa korpom
		splitPane.setEnabled(false);
	}
	
	
	// inicijalizacija donjeg djela aplikacije
	private void initialiseBtm(){
		
		// dugme za prijavu
		loginDugme=new JButton("Prijavi se");
		loginDugme.setToolTipText("Pritiskom na ovo dugme mozete se prijaviti za kupovinu!");
		loginDugme.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				JPanel panel = new JPanel( new GridLayout(2, 2, 5, 5) );
				
				panel.add( new JLabel("Unesite korisnicko ime") );
				JTextField field1 = new JTextField(10); 
				panel.add(field1);
				
				panel.add( new JLabel("Unesite lozinku") );
				JTextField field2 = new JTextField(10);  
				panel.add(field2);  
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Prijavljivanje", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					
					// TODO salje Web Servisu zahtjev za login, i vrsi sledece korake u zavisnosti od odgovora
					
					JOptionPane.showMessageDialog(null, " uspjesno ste se prijavili. Uzivajte u kupovini! ");
				    windowLogin();
				}
			}
		});
		panelDownNorth.add(loginDugme);
		
		
		// dugme za registraciju
		registerDugme=new JButton("Registruj se");
		registerDugme.setToolTipText("Registrujte se ukoliko vec niste registrovani, dovoljno je registrovati se samo jednom!");
		registerDugme.addActionListener(new ActionListener(){
			@Override
				public void actionPerformed(ActionEvent e){
				JPanel panel = new JPanel( new GridLayout(3, 2, 5, 5) );
					
				panel.add( new JLabel("Unesite vase ime i prezime") );					
				JTextField field1 = new JTextField(10); 
				panel.add(field1);
					
				panel.add( new JLabel("Unesite zeljeno korisnicko ime") );
				JTextField field2 = new JTextField(10);  
				panel.add(field2);  
					
				panel.add( new JLabel("Unesite lozinku"));
				JTextField field3 = new JTextField(10);
				panel.add(field3);
					
				int value = JOptionPane.showConfirmDialog( null, panel, "Registracija", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					
					//TODO salje Web Servisu zahtjev za registraciju, i u zavisnosti od odgovora, vrsi sledece korake
					
				    JOptionPane.showMessageDialog(null, " uspjesno ste izvrsili registraciju, sada se mozete prijaviti za kupovinu ");
				}
			}
			
		});
		panelDownNorth.add(registerDugme);
		
	}
	
	// inicijalizacija menija
	private void initialiseMenu(){
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		mnOptions = new JMenu("Opcije");
		menuBar.add(mnOptions);
		
		
		menuLogin=new JMenuItem("Prijavi se");
		menuLogin.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				JPanel panel = new JPanel( new GridLayout(2, 2, 5, 5) );
				
				panel.add( new JLabel("Unesite korisnicko ime") );
				JTextField field1 = new JTextField(10); 
				panel.add(field1);
				
				panel.add( new JLabel("Unesite lozinku") );
				JTextField field2 = new JTextField(10);  
				panel.add(field2);  
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Prijavljivanje", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					// TODO analogno dugmetu prijavi se
					
				    windowLogin();
				    JOptionPane.showMessageDialog(null, " uspjesno ste se prijavili. Uzivajte u kupovini! ");
				}
			}
			
		});
		mnOptions.add(menuLogin);
		
		menuRegister=new JMenuItem("Registruj se");
		menuRegister.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				JPanel panel = new JPanel( new GridLayout(3, 2, 5, 5) );
				
				panel.add( new JLabel("Unesite vase ime i prezime") );
				JTextField field1 = new JTextField(10); 
				panel.add(field1);
				
				panel.add( new JLabel("Unesite zeljeno korisnicko ime") );
				JTextField field2 = new JTextField(10);  
				panel.add(field2);  
				
				panel.add( new JLabel("Unesite lozinku"));
				JTextField field3 = new JTextField(10);
				panel.add(field3);
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Registracija", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					// TODO analogno dugmetu register
					
				    JOptionPane.showMessageDialog(null, " uspjesno ste izvrsili registraciju, sada se mozete prijaviti za kupovinu ");
				}
			}
			
		});
		mnOptions.add(menuRegister);
		
		menuLogout=new JMenuItem("Odjavi se");
		menuLogout.setEnabled(false);
		menuLogout.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				
				// TODO salje informaciju da se korisnik odjavljuje
				// i prilagodjava prozor "ne prijavljenom" rezimu
				windowLogout();
				btnUpdate();
				JOptionPane.showMessageDialog(null, " uspjesno ste se odjavili ");
				
			}
			
		});
		mnOptions.add(menuLogout);
		
		
		mnHistory = new JMenu("Istorija");
		mnHistory.setEnabled(false);
		menuBar.add(mnHistory);
	
		
		menuHistory=new JMenuItem("Istorija vasih kupovina");
		menuHistory.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO salje Web Servisu zahtjev za listu svih kupovina, nakon toga
				// dobija novi prozor sa tabelom, i mogucnosti da naknadno ocjeni
				// i ostavi komentar za kupljene proizvode
				Article[] a=new Article[5];
				for(int i=0;i<5;i++){
					a[i]=new Article(i," artikl "+i,100+i," tip "+i);
				}
				new HistoryFrame(a);
			}
			
		});
		mnHistory.add(menuHistory);
	}
	
	// ponasanje prozora nakon sto se korisnik uspjesno uloguje
	private void windowLogin(){
		loggedin=true;
		panelDownNorth.remove(loginDugme);
		panelDownNorth.remove(registerDugme);
		
		// dugme kojim se selektovani artikal iz osnovne tabele prebacuje u korpu
		insert=new JButton("ubaci u korpu");
		insert.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				//TODO javlja servisu da zeli da ubaci artikl u korpu,
				// ukoliko dobije pozitivan odgovor, ubacuje artikl u korpu i vizuelno
				
				tableModelCart.addArticle(model.getArticle(tableView.getSelectedRow()));
				btnUpdate();
				JOptionPane.showMessageDialog(null, " uspjesno ste ubacili "+model.getArticle(tableView.getSelectedRow()).getNaziv()+" u korpu");
			}
		});
		
		// dugme kojim se selektovani artikal izbacuje iz korpe
		remove=new JButton("izbaci iz korpe");
		remove.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				//TODO javlja servisu da zeli da izbaci artikl iz korpe, ukoliko
				// dobije pozitivan odgovor i vizuelno ga izbacuje
				String name=tableModelCart.getArticle(tableCart.getSelectedRow()).getNaziv();
				tableModelCart.removeArticle(tableCart.getSelectedRow());
				btnUpdate();
				JOptionPane.showMessageDialog(null, " uspjesno ste izbacili "+name+" iz korpe");
			}
		});
		
		// dugme za kupovinu, nakon izvrsene kupovine, korpa se prazni
		buy=new JButton("izvrsi kupovinu");
		buy.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO javlja servisu da zeli da kupi odabrane proizvode,
				
				tableModelCart.removeAll();
				btnUpdate();
				JOptionPane.showMessageDialog(null, " uspjesno ste izvrsili kupovinu");
				
			}
		});
		
		// odustajanje od kupovine, korpa se prazni
		checkout=new JButton("odustani od kupovine");
		checkout.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				//TODO javlja servisu da zeli da odustane od kupovine,
				// analogno izbacivanju svih proizvoda iz korpe
				
				tableModelCart.removeAll();
				btnUpdate();
				JOptionPane.showMessageDialog(null, " uspjesno ste odustali od kupovine");
			}
		});
		
		panelDownNorth.add(insert);
		panelDownNorth.add(remove);
		panelDownNorth.add(buy);
		panelDownNorth.add(checkout);
		
		
		// tabela korpe
		tableModelCart=new TableModelCart();
		tableCart=new JTable(tableModelCart);
		tableCart.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
			@Override public void valueChanged(ListSelectionEvent e){
				btnUpdate();
			}
		});
		JScrollPane scp2=new JScrollPane(tableCart);
		panelDownMiddle.add( new JLabel("\t korpa za kupovinu"),BorderLayout.NORTH);
		tableCart.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		panelDownMiddle.add(scp2,BorderLayout.CENTER);
		btnUpdate();
		
		// sredjivanje izgleda prozora
		splitPane.setDividerLocation(280);
		panelDownNorth.repaint();
		panelDown.repaint();
		splitPane.repaint();
		
		splitPane.setEnabled(true);
	}
	
	// ponasanje prozora nakon sto se korisnik izloguje
	private void windowLogout(){
		loggedin=false;
		panelDownNorth.removeAll();
		panelDownMiddle.removeAll();
		
		panelDownNorth.add(loginDugme,BorderLayout.NORTH);
		panelDownNorth.add(registerDugme,BorderLayout.NORTH);
		
		splitPane.resetToPreferredSizes();
		
		panelDownNorth.repaint();
		panelDown.repaint();
		splitPane.setEnabled(false);
	}
	
	// metod koji govori dugmicima da li da budu aktivna ili ne
	private void btnUpdate(){
		remove.setEnabled(tableCart.getSelectedRow()!=-1);
		insert.setEnabled(tableView.getSelectedRow()!=-1);
		checkout.setEnabled(!tableModelCart.isEmptu());
		buy.setEnabled(!tableModelCart.isEmptu());
		comments.setEnabled(tableView.getSelectedRow()!=-1);
		ratings.setEnabled(tableView.getSelectedRow()!=-1);
		mnHistory.setEnabled(loggedin);
		menuLogout.setEnabled(loggedin);
		menuLogin.setEnabled(!loggedin);
		menuRegister.setEnabled(!loggedin);
		
	}
	
	// kako ce se informacije od Web Servisa dobijati preko stringova,
	// ovaj metod ce parsovati dobijeni niz stringova, i vracati niz Artikala
	// koji se koriste dalje u programu
	private Article[] parseStringToArticles(String[] data){
		// TODO parsuje dobijeni string, i vraca niz artikala
		
		return null;
	}
	
	
	// metod koji ubacuje niz stringova kao komponente comboboxa
	// vjerovatno nece biti potreban
	private void comboBoxAdd(JComboBox cb,String[] niz){
		for(String s:niz){
			cb.addItem(s);
		}
	}
	
	
	public static void main(String[] args){
		// za pokretanje aplikacije dovoljno je napraviti novi objekat
		// tipa ClientMain
		new ClientMain();
	}
}
