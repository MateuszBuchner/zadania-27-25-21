#include <iostream>
#include <fstream>
using namespace std;
int Rozm_tablica = 1000;


void osemkowe() {
  ifstream in("liczby1.txt");
  int tablica[Rozm_tablica];
  int y = 0;
  int x = 0;
  int min = 1000000;
  int max = 0;
  
  for (y; y < Rozm_tablica; y++) in >> tablica[y];
  for (x; x< Rozm_tablica; x++) {
    if (tablica[x] < min) min = tablica[x];
    if (tablica[x] > max) max = tablica[x];
  }
  cout << "najmn " << min << endl;
  cout << "najw " << max << endl;
}




int main() {
  osemkowe();

}
