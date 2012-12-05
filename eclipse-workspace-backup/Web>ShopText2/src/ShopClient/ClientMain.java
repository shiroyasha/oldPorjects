package ShopClient;

import javax.swing.JPasswordField;
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


import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.util.List;
import java.util.ArrayList;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import service.SOI;
import service.ShopService;
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
	
	// koristimo dvije tabele, jednu osnovu za pregled i pretragu, a drugu kao korpu.
	// tabelu-korpu mozemo koristiti samo ako smo ulogovani
	private JTable tableView;
	private TableModelView model;
	private JTable tableCart;
	private TableModelCart tableModelCart;
	
	// radi lakseg rada u klijentskoj aplikaciji dodata menu traka sa nekim opcijama
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
	private JPanel infoPanel;
	private JLabel price;
	private JLabel priceDisc;
	
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
	
	// interfejs web servisa preko koga radimo
	private SOI service;
	
	// id koji se dobija nakon sto se korisnik uloguje
	private String sessionID; 
	
	
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
		setLocationRelativeTo(null);
		
		// prije nego sto zatvorimo prozor, trebamo se izlogovati
		this.addWindowListener(new WindowAdapter() {
			  public void windowClosing(WindowEvent we) {
			    service.logout(sessionID);
			    System.exit(0);
			  }
			});
		try{
			ShopService ss=new ShopService();
			service=ss.getServerOperationsPort();
		} catch (Exception e){System.exit(0);}
		
		initialiseCentral();
		initialiseBtm();
		initialiseMenu();
		
		setVisible(true);
	}
	
	
	
	// pomocna metoda za inicijalizaciju.
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
				
				// alje Web Servisu zahtjev, i dobija niz definisanih komponenti
				// koje zatim ubacuje preko tableModelView u osnovnu tabelu.
				// Komunikacija sa serverom se obavlja preko metoda refreshMain()
				List<String> list=refreshMain();
				Article[] article=deCrypterUltra(list);
				model.setArticles(article);
				
			}
		});
		show.setToolTipText("Klikom na ovo dugme dobicete tabelu komponenata prema podesenim filterima(padajuce liste lijevo i desno)!");
		panelUpNorth.add(show);
		
		
		comboBoxType=new JComboBox();
		comboBoxType.addItem("svi tipovi");
		comboBoxType.setToolTipText("Mozete izabrati tacno koji tip komponente zelite da pregledate!");
		
		// punimo combobox tipova
		ArrayList<String> cboxList=new ArrayList<String>();
		ArrayList<String> elementi=new ArrayList<String>();
		cboxList.addAll(service.getItems("", true));
		for(String s:cboxList){
			String[] element=s.split(";");
			if(!elementi.contains(element[3])){
				elementi.add(element[3]);
			}
		}
		for(String e:elementi){
			comboBoxType.addItem(e);
		}
		
		panelUpNorth.add(comboBoxType);
		
		
		// ovim dugmetom pristupamo listi komentara proizvoda kojeg smo selektovali
		// u osnovnoj tabeli
		comments=new JButton("Komentari");
		comments.setToolTipText("Pritiskom na ovo dugme vidicete komentare kupaca za datu komponentu");
		comments.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// salje servisu zahtjev, a dobija listu svih komentara odredjenog artikla
				String name=model.getArticle(tableView.getSelectedRow()).getNaziv();
				List<String> comms=new ArrayList<String>();
				List<String> filterComms=new ArrayList<String>();
				comms.addAll(service.getCommentsFor(name));
				for(String s:comms){
					if(!s.split(":")[1].trim().equals("")){
						filterComms.add(s);
					}
				}
				new CommentsFrame(filterComms,"Komentari");
				
			}
		});
		comments.setEnabled(false);
		
		panelUpSouth.add(comments,BorderLayout.SOUTH);
		
		// prikaz ocjena selektovanog artikla
		ratings=new JButton("Ocjene");
		ratings.setToolTipText("Pritiskom na ovo dugme vidicete ocene kupaca za datu komponentu");
		ratings.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// salje servisu zahtjev, a dobija listu ocjena
				String name=model.getArticle(tableView.getSelectedRow()).getNaziv();
				List<Integer> list=new ArrayList<Integer>();
				list.addAll(service.getRatingsFor(name));
				List<String> list2=new ArrayList<String>();
				for(Integer i:list){
					if(i.intValue()!=0){
						list2.add(i.toString());
					}
				}
				new CommentsFrame(list2,"Ocjene");
				
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
				JPasswordField field2 = new JPasswordField(10);  
				panel.add(field2);  
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Prijavljivanje", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					
					// salje Web Servisu zahtjev za login, i vrsi sledece korake u zavisnosti od odgovora
					String pw=new String(field2.getPassword());
					sessionID=service.login(field1.getText(), pw);
					if(sessionID!=null && !sessionID.equals("")){
						JOptionPane.showMessageDialog(null, " Uspjesno ste se prijavili. Uzivajte u kupovini! ");
						windowLogin();
					} else {
						JOptionPane.showMessageDialog(null, " Prijavljivanje nije uspjelo ");
					}
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
					
					//salje Web Servisu zahtjev za registraciju, i u zavisnosti od odgovora, vrsi sledece korake
					
					int control=service.register(field1.getText(), field2.getText(), field3.getText(), 1);
					switch(control){
					case 0: {
						JOptionPane.showMessageDialog(null, " Uspjesno ste se registrovali. Mozete se prijaviti za kupovinu! ");
						break;
					}
					case 1: {
						JOptionPane.showMessageDialog(null, " Korisnicko ime zauzeto, izaberite neko drugo ");
						break;
					}
					case 2: {
						JOptionPane.showMessageDialog(null, " Korisnicko ime ili lozinka nisu validni, pokusajte ponovo ");
						break;
					}
					default :JOptionPane.showMessageDialog(null, " Greska pri registraciji , pokusajte ponovo ");
					}
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
				JPasswordField field2 = new JPasswordField(10);  
				panel.add(field2);  
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Prijavljivanje", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					// salje Web Servisu zahtjev za login, i vrsi sledece korake u zavisnosti od odgovora
					String pw=new String(field2.getPassword());
					sessionID=service.login(field1.getText(), pw);
					
					if(sessionID!=null && !sessionID.equals("")){
						JOptionPane.showMessageDialog(null, " Uspjesno ste se prijavili. Uzivajte u kupovini! ");
						windowLogin();
					} else {
						JOptionPane.showMessageDialog(null, " Prijavljivanje nije uspjelo ");
					}
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
					//salje Web Servisu zahtjev za registraciju, i u zavisnosti od odgovora, vrsi sledece korake
					
					int control=service.register(field1.getText(), field2.getText(), field3.getText(), 1);
					switch(control){
					case 0: {
						JOptionPane.showMessageDialog(null, " Uspjesno ste se registrovali. Mozete se prijaviti za kupovinu! ");
						break;
					}
					case 1: {
						JOptionPane.showMessageDialog(null, " Korisnicko ime zauzeto, izaberite neko drugo ");
						break;
					}
					case 2: {
						JOptionPane.showMessageDialog(null, " Korisnicko ime ili lozinka nisu validni, pokusajte ponovo ");
						break;
					}
					default :JOptionPane.showMessageDialog(null, " Greska pri registraciji, pokusajte ponovo ");
					}
				}
			}
			
		});
		mnOptions.add(menuRegister);
		
		menuLogout=new JMenuItem("Odjavi se");
		menuLogout.setEnabled(false);
		menuLogout.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				
				// salje informaciju da se korisnik odjavljuje
				// i prilagodjava prozor "ne prijavljenom" rezimu
				if(service.logout(sessionID)){
					windowLogout();
					btnUpdate();
					JOptionPane.showMessageDialog(null, " Uspjesno ste se odjavili ");
				} else {
					JOptionPane.showMessageDialog(null, " Greska pri odjavljivanju. Pokusajte ponovo");
				}
				
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
				// salje Web Servisu zahtjev za listu svih kupovina, nakon toga
				// dobija novi prozor sa tabelom, i mogucnosti da naknadno ocjeni
				// i ostavi komentar za kupljene proizvode
				List<String> list=new ArrayList<String>();
				list.addAll(service.getBuyListFor(sessionID));
				Article[] a=deCrypterGiga(list);
				new HistoryFrame(a,service,sessionID);
			}
			
		});
		mnHistory.add(menuHistory);
	}
	
	// ponasanje prozora nakon sto se korisnik uspjesno uloguje
	private void windowLogin(){
		loggedin=true;
		panelDownNorth.remove(loginDugme);
		panelDownNorth.remove(registerDugme);
		
		price=new JLabel("\t      Maloprodajna vrijednost korpe :  0  ;");
		priceDisc=new JLabel("\t        Vrijednost korpe sa popustom :  0 ;");
		
		// dugme kojim se selektovani artikal iz osnovne tabele prebacuje u korpu
		insert=new JButton("Ubaci u korpu");
		insert.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// javlja servisu da zeli da ubaci artikl u korpu,
				// ukoliko dobije pozitivan odgovor, ubacuje artikl u korpu i vizuelno
				double priceArt = service.addToCart(sessionID, model.getArticle(tableView.getSelectedRow()).getNaziv());
				if(priceArt>0){
					tableModelCart.addArticle(model.getArticle(tableView.getSelectedRow()));
					btnUpdate();
					price.setText("\t      Maloprodajna vrijednost korpe :  "+priceArt+" ;");
					priceDisc.setText("\t        Vrijednost korpe sa popustom : "+service.getCurrentCostPlus(sessionID, 10)+" ;");
				} else {
					JOptionPane.showMessageDialog(null, " Greska pri ubacivanju artikla u korpu, pokusajte ponovo");
					btnUpdate();
				}
			}
		});
		
		// dugme kojim se selektovani artikal izbacuje iz korpe
		remove=new JButton("Izbaci iz korpe");
		remove.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// javlja servisu da zeli da izbaci artikl iz korpe, ukoliko
				// dobije pozitivan odgovor i vizuelno ga izbacuje
				String name=tableModelCart.getArticle(tableCart.getSelectedRow()).getNaziv();
				double priceArt=service.removeFromCart(sessionID, name);
				if(priceArt>-1){
					tableModelCart.removeArticle(tableCart.getSelectedRow());
					btnUpdate();
					price.setText("\t      Maloprodajna vrijednost korpe :  "+priceArt+" ;");
					priceDisc.setText("\t        Vrijednost korpe sa popustom : "+service.getCurrentCostPlus(sessionID, 10)+" ;");
				} else {
					JOptionPane.showMessageDialog(null, " Problem pri izbacivanju iz korpe, pokusajte ponovo");
					btnUpdate();
				}
			}
		});
		
		// dugme za kupovinu, nakon izvrsene kupovine, korpa se prazni
		buy=new JButton("Izvrsi kupovinu");
		buy.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// javlja servisu da zeli da kupi odabrane proizvode
				if(service.checkout(sessionID)){
					tableModelCart.removeAll();
					btnUpdate();
					JOptionPane.showMessageDialog(null, " Uspjesno ste izvrsili kupovinu");
					price.setText("\t      Maloprodajna vrijednost korpe :  0  ;");
					priceDisc.setText("\t        Vrijednost korpe sa popustom :  0 ;");
					List<String> list = refreshMain();
					model.setArticles(deCrypterUltra(list));
				} else {
					JOptionPane.showMessageDialog(null," Neki od odabranih artikala se trenutno ne nalaze na lageru. Probajte kasnije! ");
					tableModelCart.removeAll();
					btnUpdate();
					List<String> list=refreshMain();
					model.setArticles(deCrypterUltra(list));
					price.setText("\t      Maloprodajna vrijednost korpe :  0  ;");
					priceDisc.setText("\t        Vrijednost korpe sa popustom :  0 ;");
				}
				
			}
		});
		
		// odustajanje od kupovine, korpa se prazni
		checkout=new JButton("Odustani od kupovine");
		checkout.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// javlja servisu da zeli da odustane od kupovine,
				// analogno izbacivanju svih proizvoda iz korpe
				if(service.leave(sessionID)){
					tableModelCart.removeAll();
					btnUpdate();
					JOptionPane.showMessageDialog(null, " Uspjesno ste odustali od kupovine");
					price.setText("\t      Maloprodajna vrijednost korpe :  0  ;");
					priceDisc.setText("\t        Vrijednost korpe sa popustom :  0 ;");
				} else{
					JOptionPane.showMessageDialog(null, " Problem pri odustajanju od kupovine, pokusajte ponovo");
					btnUpdate();
				}
			}
		});
		
		panelDownNorth.add(insert);
		panelDownNorth.add(remove);
		panelDownNorth.add(buy);
		panelDownNorth.add(checkout);
		
		
		// model tabele korpe
		tableModelCart=new TableModelCart();
		tableCart=new JTable(tableModelCart);
		tableCart.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
			@Override public void valueChanged(ListSelectionEvent e){
				btnUpdate();
			}
		});
		JScrollPane scp2=new JScrollPane(tableCart);
		
		infoPanel=new JPanel();
		panelDownMiddle.add(infoPanel,BorderLayout.NORTH);
	
		infoPanel.add(price);
		infoPanel.add(priceDisc);
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
	private Article[] deCrypterUltra(List<String> data){
		// parsuje dobijeni string, i vraca niz artikala
		if(!data.isEmpty()){	
			Article[] articles = new Article[data.size()];
			int i=0;
			for(String s:data){
				String[] elements=s.split(";");
				articles[i]=new Article(Integer.parseInt(elements[0]),elements[1],Double.parseDouble(elements[2]),elements[3],Integer.parseInt(elements[4]));
				i++;
			}
			return articles;
		}
		return null;
	}
	// druga verzija dekriptera, radi na istom principu, a razlikuje se
	// po tome sto parsira informacije u drugom redoslijedu
	public static Article[] deCrypterGiga(List<String> data){
		// parsuje dobijeni string, i vraca niz artikala
				if(!data.isEmpty()){	
					Article[] articles = new Article[data.size()];
					int i=0;
					for(String s:data){
						String[] elements=s.split(";");
						articles[i]=new Article(Integer.parseInt(elements[0]),elements[1],Integer.parseInt(elements[2]),Integer.parseInt(elements[3]));
						i++;
					}
					return articles;
				}
				return null;	
	}
	
	// metod za punjenje osnovne tabele
	private List<String> refreshMain(){
		String type;
		if(comboBoxType.getSelectedIndex()==0){
			type="";
		} else{
			type=comboBoxType.getSelectedItem().toString();
		}
		List<String> list = new ArrayList<String>();
		list.addAll(service.getItems(type, comboBoxMain.getSelectedIndex()==0));
		return list;
	}
}
