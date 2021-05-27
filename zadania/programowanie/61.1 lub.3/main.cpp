#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 100;

void z1() {
  ifstream in("ciagi.txt");
  int tab[1000];
  int length, difference;
  int counter = 0, max = 0;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    flag = true;
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    difference = tab[1] - tab[0];
    for (int j = 1; j < length; j++) {
      if (tab[j] - tab[j - 1] != difference) flag = false;
    }
    if (flag) {
      counter++;
      if (difference > max) max = difference;
    }
  }
  in.close();
  ofstream out("wynik1.txt");
  out << "Liczba ciagow: " << counter << "\n";
  cout << "Liczba ciagow: " << counter << "\n";
  out << "Najwieksza roznica: " << max << "\n";
  cout << "Najwieksza roznica: " << max << "\n";
  out.close();
}





int main() {
  z1();

}
