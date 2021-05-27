#include <iostream>
#include <windows.h>

using namespace std;

int dane[5];
int rozmiar,pierw_liczba,wolne;

void wyswietl_kolejke()
{
    system("CLS");
    if (rozmiar==0)
    {
        cout<<"empty";
    }
    else
    {
        int indeks;
        for (int i=0; i<rozmiar; i++)
        {
            indeks=pierw_liczba+i;
            if (pierw_liczba+i>=5) ;
            cout<<dane[indeks]<<" ";
        }
    }
}

void dodaj()
{
    if (rozmiar>=5)
    {
    }
    else
    {
        cout<<endl<< "Wstaw liczbe: ";
        cin>>dane[wolne];
        wolne=(wolne+1)%5;
        rozmiar=rozmiar+1;
    }
}

void usun()
{
    if (rozmiar==0)
    {
    }
    else
    {
        cout<<endl<<"Usun"<<dane[pierw_liczba];
        pierw_liczba=(pierw_liczba+1)%5;
        rozmiar=rozmiar-1;
    }
}

int main()
{
    int wybor;
    do
    {
        wyswietl_kolejke();
        cout << ""<<endl<<endl;
        cout << "1. Wstaw "<<endl;
        cout << "2. Usun "<<endl;
        cout << ">: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            dodaj();
            break;

        case 2:
            usun();
            break;
        }
    }
    while(wybor != 3);
    return 0;
}

