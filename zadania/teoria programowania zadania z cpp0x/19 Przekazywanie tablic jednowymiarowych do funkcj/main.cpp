#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct osoba
{
        string imie, nazwisko, adres, pesel;
        int numer;
};


void menu()
    {
    	cout<<"\n1.Wprowadz\n";
    	cout<<"2.Wypisz dane\n";
    	cout<<"3.Zapisz do pliku \n";
}

class dane
{
                vector <struct osoba> spis;
       
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);                
};

void dane::wprowadz()
{
        int iloscUczniow;
        struct osoba wprowadzany;
        cout << "Ilosc osob: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Imie Nazwisko Adres Pesel: ";
                cin >> wprowadzany.numer
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko
                        >> wprowadzany.adres
                        >> wprowadzany.pesel;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}

void dane::wypisz()
{
        for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout
						 << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
						 << it->adres << " "
						 << it->pesel << "\n";
        }
}

void dane::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik
						 << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
						 << it->adres << " "
						 << it->pesel << "\n";
        }
        plik.close();  
}

int main(int argc, char** argv) {
	
        dane TI;
        int wybor;
        do
        {
            menu();
            cin >> wybor;
            switch(wybor)
            {
                case 1:
        			TI.wprowadz();
                break;
                case 2:
        			TI.wypisz();
                break;
                case 3:
        			TI.zapiszDoPliku("plik.txt");
                    break;
                case 0:
                    return 0;
                break;
            }
        }while(wybor!=0);
        
        
        return 0;
	
	
}


