#include <iostream>
#include <fstream>
using namespace std;


const int SIZE = 1000;
string tab[SIZE];

void z1() {
  cout << "Zadanie 1:" << endl;
  int length;
  string w1, w2;
  for (int i = 0; i < SIZE; i++) {
    length = tab[i].length();
    if (length % 2 != 0) continue;
    w1 = tab[i].substr(0, length / 2);
    w2 = tab[i].substr(length / 2, length / 2);
    if (w1 == w2) {
      cout << tab[i] << endl;
    }
  }
}



int main() {
  ifstream in("ciagi.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  z1();
}
