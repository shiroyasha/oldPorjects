import java.util.concurrent.locks.ReentrantLock;



public class ddd {

	static class Kolac
	{
		int velicina;
		Kolac( int kol )
		{
			velicina = kol;
		}
		
		public boolean imaKolaca()
		{
			return velicina > 0;
		}
		
	    public int jedi()
		{
			int staraVelicina = velicina;
			velicina -= Math.min( 5, velicina );
			return staraVelicina - velicina;
		}
	}
	static class Covek extends Thread
	{
		public int pojedeno = 0;
		static Kolac kolac = new Kolac( 279 );
		
		static ReentrantLock lock = new ReentrantLock();
		static ReentrantLock lock2 = new ReentrantLock();
		
		public void run()
		{

			while( true )
			{
				lock.lock();
				try
				{
					if (!kolac.imaKolaca()) break; 
				}
			    finally
			    {
			    	lock.unlock();
			    }
				try
				{
					lock2.lock();
					try
					{
						pojedeno += kolac.jedi();
					}
					finally
					{
						lock2.unlock();
					}
					
					System.out.println( this.getName() + " pojeo zasad " + pojedeno );
					Thread.sleep( 2000 );
					
				}catch(InterruptedException e )
				{
					
				}
				
			}
		}
	}
	
	public static void main( String[] args ) throws InterruptedException
	{
		Covek[] niz = new Covek[10];
		
		for( int i = 0; i < niz.length ; i++)
			niz[i] = new Covek();
		
		for( Covek c : niz )
			c.start();
		
		for( Covek c : niz )
			c.join();
		
		
		for( Covek c : niz )
			System.out.println( c.getName() + " " + c.pojedeno );
		
	}
}
