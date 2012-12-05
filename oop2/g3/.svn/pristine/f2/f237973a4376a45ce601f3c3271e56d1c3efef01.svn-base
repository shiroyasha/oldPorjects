package ShopClient;
import java.awt.BorderLayout;
import java.util.List;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.JFrame;
import javax.swing.ListSelectionModel;
import javax.swing.UIManager;
import javax.swing.table.AbstractTableModel;
import javax.swing.JScrollPane;

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 *jednostavni model za prikaz informacija u obliku tabele
 */
@SuppressWarnings("serial")
class CommentTableModel extends AbstractTableModel{
	List<String> commsrates;
	public CommentTableModel(Object[] commsrates){
		this.commsrates=new ArrayList<String>();
		if(commsrates!=null){
			for(int i=0;i<commsrates.length;i++){
				this.commsrates.add(commsrates[i].toString());
			}
		}
	}
	@Override
	public int getRowCount(){
		return commsrates.size();
	}
	@Override
	public int getColumnCount(){
		return 1;
	}
	@Override
	public String getColumnName(int colum){
		return " Sta korisnici misle o ovom proizvodu ";
	}
	@Override
	public Object getValueAt(int row, int colum){
		return commsrates.get(row);
	}	
}

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 ** Frejm za komentare i ocjene,
 * kada korisnik zeli da vidi listu ocjena ili komentara
 * nekog artikla poziva se ovaj frejm
 *
 *
 */
@SuppressWarnings("serial")
public class CommentsFrame extends JFrame{
	public CommentsFrame(Object[] commsrates){
		try {
			UIManager.setLookAndFeel(
            UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e){}
		setTitle("LoseLose WebService");
		setSize(280,340);
		setDefaultCloseOperation( JFrame.HIDE_ON_CLOSE );
		CommentTableModel model=new CommentTableModel(commsrates);
		JTable table=new JTable(model);
		table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane scp=new JScrollPane(table);
		add(scp,BorderLayout.CENTER);
		setVisible(true);
	}
}
