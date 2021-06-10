#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 1000;
float tab[SIZE][2];


void zadanie65() {
  float minL = 1000, minM = 1000, minU = 1000;
  float ulamek;
  
  for (int i = 0; i < 1000; i++) {
    ulamek = tab[i][0] / tab[i][1];
    if (ulamek <= minU) {
      if (ulamek == minU && tab[i][1] > minM) continue;
      minU = ulamek;
      minL = tab[i][0];
      minM = tab[i][1];
    }
  }
  cout << "licznik " << minL << " mianownik ulamka: " << minM << endl;
}

int main() {
  ifstream in("dane_ulamki.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i][0] >> tab[i][1];
  }
  zadanie65();
}
