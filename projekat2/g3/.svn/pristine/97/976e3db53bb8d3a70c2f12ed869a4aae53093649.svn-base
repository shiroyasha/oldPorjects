package ShopClient;

import javax.swing.table.AbstractTableModel;
import java.util.List;
import java.util.ArrayList;

/**
 * 
 * @author Nikola Bosic (nikolabosic91@gmail.com)
 *
 *	klasa koja predstavlja model za korpu 
 *
 */

@SuppressWarnings("serial")
public class TableModelCart extends AbstractTableModel{
	List<Article> articles;
	
	public TableModelCart(){
		articles=new ArrayList<Article>();
	}
	@Override
	public int getRowCount(){
		return articles.size();
	}
	@Override
	public int getColumnCount(){
		return 5;
	}
	@Override
	public Object getValueAt(int row, int column){
		switch(column){
		case 0: return articles.get(row).getId();
		case 1: return articles.get(row).getNaziv();
		case 2: return articles.get(row).getCijena();
		case 3: return articles.get(row).getTip();
		default: return articles.get(row).getKolicinaKupljena();
		}
	}
	@Override
	public String getColumnName(int column){
		switch(column){
		case 0: return "id";
		case 1: return "Naziv";
		case 2: return "Cijena";
		case 3: return "tip";
		default: return "Kolicna kupljena";
		}
	}
	
	// ukoliko ubacujemo u korpu artikal koji se vec nalazi tamo
	// samo povecamo polje brojKupljenih, ne gomilamo ih u tabeli
	public void addArticle(Article a){
		if(articles.contains(a)){
			articles.get(articles.indexOf(a)).incKupljeno();
		} else{
			a.resetKupljeno();
			articles.add(a);
		}
		fireTableDataChanged();
	}
	
	// ukoliko izbacujemo artikal iz korpe
	// moramo provjeriti da li se nalazi samo jedan, 
	// tada ga skroz uklanjamo, ili samo smanjujemo broj kupljenih
	public void removeArticle(int index){
		if(articles.get(index).getKolicinaKupljena()>1){
			articles.get(index).decKupljeno();
		} else{
			articles.remove(index);
		}
		fireTableRowsDeleted(index,index);
	}
	public void removeAll(){
		articles.clear();
		fireTableDataChanged();
	}
	public boolean isEmptu(){
		return articles.isEmpty();
	}
	public Article getArticle(int index){
		return articles.get(index);
	}
}
