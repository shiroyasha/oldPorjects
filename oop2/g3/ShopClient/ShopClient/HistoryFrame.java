package ShopClient;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.table.AbstractTableModel;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.JTextArea;
import javax.swing.JComboBox;

/**
 * 
 * @author Nikola Bosic (nikolabosic@gmail.com)
 *
 *
 *
 *model za prikazivanje svih artikala koje je korisnik kupio
 */
@SuppressWarnings("serial")
class HistoryTableModel extends AbstractTableModel{
	List<Article> articles;
	public HistoryTableModel(Article[] articles){
		this.articles=new ArrayList<Article>();
		if(articles!=null){
			for(Article a:articles){
				this.articles.add(a);
			}
		}
	}
	@Override
	public int getRowCount(){
		return articles.size();
	}
	@Override
	public int getColumnCount(){
		return 3;
	}
	@Override
	public Object getValueAt(int row, int column){
		switch(column){
		case 0: return articles.get(row).getId();
		case 1: return articles.get(row).getNaziv();
		default: return articles.get(row).getTip();
		}
	}
	@Override
	public String getColumnName(int column){
		switch(column){
		case 0: return "id";
		case 1: return "Naziv";
		default: return "tip";
		}
	}
	public Article getArticle(int index){
		return articles.get(index);
	}
	
}

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 *
 *Ovaj frejm se kreira kada korisnik zeli da vidi listu svih
 *artikala koje je kupio. Dobija niz artikala, i prikazuje ih u tabeli
 *
 *takodje moze da ocjeni ili da komentar na bilo koji od tih artikala
 */
@SuppressWarnings("serial")
public class HistoryFrame extends JFrame{
	JButton addCom;
	JButton addRat;
	JTable table;
	HistoryTableModel model;
	public HistoryFrame(Article[] articles){
		try {
			UIManager.setLookAndFeel(
            UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e){}
		setTitle("LoseLose WebService");
		setSize(280,340);
		setDefaultCloseOperation( JFrame.HIDE_ON_CLOSE );
		model=new HistoryTableModel(articles);
		table=new JTable(model);
		table.getSelectionModel().addListSelectionListener(new ListSelectionListener(){
			@Override public void valueChanged(ListSelectionEvent e){
				btnUpdate();
			}
		});
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane scp=new JScrollPane(table);
		add(scp,BorderLayout.CENTER);
		
		JPanel panel=new JPanel();
		add(panel,BorderLayout.SOUTH);
		
		addCom=new JButton("Dodajte komentar");
		addCom.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO salje WebServisu informaciju da je korisnik dao komentar na odredjeni artikal
				
				String input=JOptionPane.showInputDialog("Ostavite Vas Komentar");
				if (input!=null && input.length()>0){
					JOptionPane.showMessageDialog(null, " uspjesno ste ostavili komentar na artikal "+model.getArticle(table.getSelectedColumn()).getNaziv());
				}
			}
		});
		addCom.setEnabled(false);
		addRat=new JButton("Dodajte ocjenu");
		addRat.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				// TODO salje WebServisu informaciju da je korisnik ocjenio odredjeni artikal
				
				JPanel panel = new JPanel( new GridLayout(2, 2, 5, 5) );
				
				panel.add( new JLabel("Unesite Ocjenu") );
				
				JComboBox cbox=new JComboBox();
				for(int i=1 ; i<6; i++){
					cbox.addItem(i);
				}	
				panel.add( cbox ); 
				
				int value = JOptionPane.showConfirmDialog( null, panel, "Ocjenjivanje", JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE );   
				if (value == JOptionPane.OK_OPTION)  
				{  
					
					// TODO salje Web Servisu zahtjev za login, i vrsi sledece korake u zavisnosti od odgovora

					JOptionPane.showMessageDialog(null, " uspjesno ste ocjenili artikal "+model.getArticle(table.getSelectedColumn()).getNaziv());
				}
				
			}
		});
		addRat.setEnabled(false);
		
		panel.add(addCom);
		panel.add(addRat);
		setVisible(true);
	}
	private void btnUpdate(){
		addCom.setEnabled(table.getSelectedRow()!=-1);
		addRat.setEnabled(table.getSelectedRow()!=-1);
	}
}
