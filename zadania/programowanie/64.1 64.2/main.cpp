#include <iostream>
#include <fstream>
using namespace std;

//200 czarno-bia³ych obrazków o rozmiarze20 × 20 pikseli

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tablica[21][21];
void wczytaj_obraz() {
	for (int i = 0; i < 21; i++) {
	for (int j = 0; j < 21; j++) {
    	if (i == 20 && j == 20) return;
		in >> tablica[i][j];
    }
  }
}


bool isrewersy() {
  int czrny = 0, bialy = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tablica[i][j] == '0') bialy++;
      if (tablica[i][j] == '1') czrny++;
    }
  }
  return czrny > bialy;
}

int ileczarnych() {
  int czarne = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tablica[i][j] == '1') czarne++;
    }
  }
  return czarne;
}


int main() {
	int rewersyczarne = 0,
	maxczarne = 0;
	
  for (int n = 0; n < SIZE; n++) {wczytaj_obraz();
    if (isrewersy()) rewersyczarne++;
    if (ileczarnych() > maxczarne) maxczarne = ileczarnych();
    
  }
  
  cout << "Liczba rewersów: " << rewersyczarne << endl;
  cout << "Najwiêksza liczba pikseli czarnych: " << maxczarne << endl << endl;
}
