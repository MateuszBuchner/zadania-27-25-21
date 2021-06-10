#include <iostream>
#include <fstream>
using namespace std;


const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

void wczytajobraz() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 20 && j == 20) return;
      in >> tab[i][j];
    }
  }
}

int col2() {
  int sum = 0, korek = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (tab[i][j] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[i][j] == '1') korek++;
      }
    }
    sum = 0;
  }
  return korek;
}

int col3() {
  int sum = 0, korek = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
      if (tab[j][i] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[j][i] == '1') korek++;
        if (sum % 2 == 1 && tab[j][i] == '0') korek++; 
      }
    }
    sum = 0;
  }
  return korek;
}

int showerror() {
  return col2() + col3();
}

bool nextconnect () {
  if (showerror() == 0) return true;
}

bool przekazdal() {
  if (nextconnect()) return false;
  if (col3() < 2 && col2() < 2)
    return true;
}


int main() {
  int zdjecie = 0, SUMA, line, column;
  
  for (int n = 0; n < SIZE; n++) {
    wczytajobraz();
	zdjecie++;
    if (przekazdal()) {
      column = 0;
      line = 0;
      cout << "(" << zdjecie << ", ";
      if (col2() == 1) {
        SUMA = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[i][j] == '1' && j != 20) SUMA++;
            if (j == 20) {
              if ((SUMA % 2 == 0 && tab[i][j] == '1') ||
                  (SUMA % 2 == 1 && tab[i][j] == '0')) {
                line = i + 1; 
              }
            }
          }
          SUMA = 0;
        }
      }
      if (col3() == 1) {
        SUMA = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[j][i] == '1' && j != 20) SUMA++;
            if (j == 20) {
              if ((SUMA % 2 == 0 && tab[j][i] == '1') ||
                  (SUMA % 2 == 1 && tab[j][i] == '0')) {
                column = i + 1; 
              }
            }
          }
          SUMA = 0;
        }
      }
      if (line == 0) line = 21;
      if (column == 0) column = 21;
      cout << line << ", " << column << ")" << endl;
    }
  }
  
}
