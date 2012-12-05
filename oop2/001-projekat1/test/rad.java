import maze.Maze;

public class rad
{
    public static void main( String[] args )
    {
        Maze m = new Maze();
        m.makeMaze();

        m.getSolution();

        m.printToConsole();
    }
}
