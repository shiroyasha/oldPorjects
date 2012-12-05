#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int prvi = 1;

    cout << "Unesi prvi broj : ";
    cin >> prvi;

    cout << endl;

    ifstream ulaz("brojevi.txt");

    int niz[1000];

    for( int i =0; i < 1000; ++i)
    {
        ulaz >> niz[i];
    }

    ulaz.close();
/*
    for( int i =0; i < 1000; ++i)
    {
        cout << niz[i] << endl;
    }
*/
    int poslednji = 0;

    for( int i =0; i < 1000; ++i)
    {
        int pomocni = prvi + i*( 2 + ( i-1 ));

        for( int y = poslednji; y < 1001; ++y)
        {
            if( niz[y] == pomocni)
            {
                cout << "y -> " << pomocni << endl;
                poslednji =  y;
                break;
            }
            if( y == 1000)
            {
                cout << "greshka -> " << pomocni << endl;
                return 0;

            }
        }
    }

    return 0;
}
