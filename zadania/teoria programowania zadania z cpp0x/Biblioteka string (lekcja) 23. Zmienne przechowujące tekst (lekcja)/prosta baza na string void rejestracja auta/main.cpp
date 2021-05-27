#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
int i;

struct baza
{
	string marka;
	string model;
	string silnik;
	string pojemnosc;
	string rocznik;
	string imie;
	string nazwisko;
	string data_urodzenia;
	string adres;
};
baza dane[500];

void Dodaj();
void Zapisz();
void edycja();
void Baza();
void Usun();

int main()
{
int k;
short x;

cout<<"\n 1.Wczytanie istniejacej bazy";
cout<<"\n 2.Utwoz nowa baze danych";
cout<<"\n Wybierz opcje: ";
cin>>x;
if(x==1)
{

ifstream plik("baza.txt", ios::in);
plik >> i;
if (!plik)
        {
         cout << "\n Brak pliku w bazie";
         cout<<"\n";
         system("pause");
         return 0; 
         }
   else
   {
  int j = 0;
  do
  {
	plik >>dane[j].marka;
	plik >>dane[j].model;
	plik >>dane[j].silnik;
	plik >>dane[j].pojemnosc;
	plik >>dane[j].rocznik;
	plik >>dane[j].imie;
	plik >>dane[j].imie;
	plik >>dane[j].nazwisko;
	plik >>dane[j].data_urodzenia;
	plik >>dane[j].adres;
    j++;
  }
  while( !plik.eof() );
  cout <<"\n Dane zostaly wczytane.";
  getchar();
  getchar();
  } }

  system("cls");
  cout << "\n";

  do
  {
    cout <<"\n   W bazie znajduje sie "<<i<<" rekordow\n";
    cout <<"\n 1. Zarejestruj pojazd \n";
    cout <<"\n 2. Zapis bazy danych do pliku\n";
    cout <<"\n 3. Edycja danych\n";
    cout <<"\n 4. Odtworz baze danych\n";
    cout <<"\n 5. Usun wpis z bazy danych\n";
    cout <<"\n 0. Wylacz program ";

    cout<<"\n Opcja nr: ";
    cin>>k;
    if(k>5 || k<0)
    {
      system("cls");
      cout<<"\n Blad danych !!";
      cout<<"\n Dzialanie END \n";
      system ("pause");
      return 0;
    };

    switch (k)
    {
      case 0: cout<<"Dzialanie END \n ";
              system("pause");
              return 0;
              break;

            case 1: Dodaj();break;
            case 2: Zapisz();break;
            case 3: edycja();break;
            case 4: Baza();break;
            case 5: Usun();break;

    }

    system("cls");
  }
  while (k!= 0);

   cin.ignore();
   getchar();
   return 0;
}

void Wczytaj()
{
ifstream plik("baza.txt", ios::in);
plik >> i;
if (!plik)
        {
         cout << "\n Brak pliku";
         cout<<"\n";
         system("pause");
         }
   else
   {
  int j = 0;
  do
  {
	plik >>dane[j].marka;
	plik >>dane[j].model;
	plik >>dane[j].silnik;
	plik >>dane[j].pojemnosc;
	plik >>dane[j].rocznik;
	plik >>dane[j].imie;
	plik >>dane[j].nazwisko;
	plik >>dane[j].data_urodzenia;
	plik >>dane[j].adres;
    j++;
  }
  while( !plik.eof() );
  cout <<"\n Wczytano dane. Nacisnij ENTER!";
  getchar();
  getchar();
  } }

void Dodaj()
{
  system("cls");
	cout <<"\n Wpisz marke : ";
	cin >>dane[i].marka;
	cout <<"\n Wpisz model : ";
	cin >>dane[i].model;
	cout <<"\n Wpisz silnik : ";
	cin >>dane[i].silnik;
	cout <<"\n Wpisz pojemnosc : ";
	cin >>dane[i].pojemnosc;
	cout <<"\n Wpisz rocznik: ";
	cin >>dane[i].rocznik;  
	cout <<"\n Wpisz imie : ";
	cin >>dane[i].imie;
	cout <<"\n Wpisz nazwisko : ";
	cin >>dane[i].nazwisko;
	cout <<"\n Wpisz data urodzenia : ";
	cin >>dane[i].data_urodzenia;
	cout <<"\n Wpisz adres: ";
	cin >>dane[i].adres;
  i++;
  cin.ignore();
  cout <<"\n Nacisnij enter";
  getchar();
}

void Zapisz()
{
  ofstream plik("baza.txt",ios::trunc);
  plik <<i<<"\n";

  for (int j = 0; j < i; j++)
  {
	plik <<dane[j].marka<<"\n";
	plik <<dane[j].model<<"\n";
	plik <<dane[j].silnik<<"\n";
	plik <<dane[j].pojemnosc<<"\n";
	plik <<dane[j].rocznik<<"\n";
	plik <<dane[j].imie<<"\n";
	plik <<dane[j].nazwisko<<"\n";
	plik <<dane[j].data_urodzenia<<"\n";
	plik <<dane[j].adres<<"\n";
  }
  system("cls");
  cout <<"\n Dane zostaly zapisane!";
  system("pause");

}

void Baza()
{
  int j;
  system("cls");
  if ( i != 0)
  {
    cout<<"\n\n\n";
    for (j = 0; j < i; j++)
    {
      cout
      <<"----------------------------------------------------------------------------"<<endl;
      cout <<"     Rekord nr "<<j+1<<": \n";
      cout <<"     Marka: "<<dane[j].marka<<"\n";
      cout <<"     Model: "<<dane[j].model<<"\n";
      cout <<"     Silnik: "<<dane[j].silnik<<"\n";
      cout <<"     Pojemnosc: "<<dane[j].pojemnosc<<"\n";
      cout <<"     Rocznik: "<<dane[j].rocznik<<"\n";
      cout <<"     Imie: "<<dane[j].imie<<"\n";
      cout <<"     Nazwisko: "<<dane[j].nazwisko<<"\n";
      cout <<"     Data urodzniea: "<<dane[j].data_urodzenia<<"\n";
      cout <<"     Adres: "<<dane[j].adres<<"\n";
      cout <<"";
      cout
      <<"----------------------------------------------------------------------------"<<endl;
    }
  }
  else
  cout <<"\n Nie ma wybrnaego rekordu w bazie\n";
  system("pause");
}

void edycja()
{

  int nr;
  if (i != 0)
  {
    system("cls");
    cout <<"\n Podaj numer rekordu przeznaczonego do edycji: ";
    cin >>nr;
    nr=nr - 1;
    cin.ignore();

    if (nr<0 || nr > i)
    {
     system("cls");
     cout <<"\n Nie mozna wykonac operacji - brak danych\n";
     system("pause");
    }
    else
    {
     system("cls");
     cout <<"\n Podaj Marka :";
     cin>>dane[nr].marka;
     cout <<"\n Podaj model :";
     cin>>dane[nr].model;
     cout <<"\n Podaj silnik :";
     cin>>dane[nr].silnik;
     cout <<"\n Podaj pojemnosc :";
     cin>>dane[nr].pojemnosc;
     cout <<"\n Podaj rocznik :";
     cin>>dane[nr].rocznik;
     cout <<"\n Podaj imie :";
     cin>>dane[nr].imie;
     cout <<"\n Podaj nazwisko :";
     cin>>dane[nr].nazwisko;
     cout <<"\n Podaj data urodzniea :";
     cin>>dane[nr].data_urodzenia;
     cout <<"\n Podaj adres : ";
     cin>>dane[nr].adres;
     cout <<"\n Zmiane danych wykonano - rekord "<<nr +1 <<" zostal zmieniony!\n";
     cin.ignore();
     cout <<"\n  Wcisnij ENTER!";
     getchar();
     Zapisz();
      }
     }
  else
  {
    system("cls");
    cout <<"\n Nie ma rekordow w bazie. Nacisnij dowolny klawisz";
    system("pause");
  }
}

void Usun()
{
  int nr;

    cout <<"\n Podaj numer rekordu ktory chcesz usunac: ";
    cin >>nr;
    cin.ignore();

     if (i != 0)
     {
    if (nr > i)
    {
    cout <<"\n Operacja nie moze byc wykonana brak rekordu o takim numerze";
    cout <<"\n Wcisnij ENTER!";
    getchar();
    }
    else
    {
      for (short k = nr; k < i; k++)
      {
    	dane[k-1].marka = dane[k].marka;
    	dane[k-1].model = dane[k].model;
    	dane[k-1].silnik = dane[k].silnik;
    	dane[k-1].pojemnosc = dane[k].pojemnosc;
    	dane[k-1].rocznik = dane[k].rocznik;
        dane[k-1].imie = dane[k].imie;
        dane[k-1].nazwisko = dane[k].nazwisko;
        dane[k-1].data_urodzenia = dane[k].data_urodzenia;
        dane[k-1].adres = dane[k].adres;
      }
      i--;

      system("cls");
      cout <<"\n Operacja zakonczyla sie sukcesem! rekord o numerze "<<nr<<" zostal usuniety!\n";
      getchar();
      Zapisz();
    }
  }
  else
  {
    cout <<"\n Nie ma rekordu w bazie!! Wcisnij ENTER!";
    getchar();

  }
}
