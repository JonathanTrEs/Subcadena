
#include "Subcadena.h"
#include <vector>

Subcadena::Subcadena(char* cad1, char* cad2) {
  cadena1_ = cad1;
  cadena2_ = cad2;
  dimcadena1_ = strlen(cad1);
  dimcadena2_ = strlen(cad2);
}

Subcadena::~Subcadena() {
  
}

int max(int a, int b, int c) {
  int resultado;
  if (a > b)
    if (a > c)
      resultado = a;
    else
      resultado = c;
  else
    if (b > c)
      resultado = b;
    else
      resultado = c;
  return resultado;
}

void Subcadena::calcularSubcadena() {
  int** matriz;
  matriz = new int* [dimcadena1_ + 1];
  
  //Iniciamos matriz
  for (int i = 0; i <= dimcadena1_; i++) {
    matriz[i] = new int [dimcadena2_ + 1];
    for (int j = 0; j <= dimcadena2_; j++)
      matriz[i][j] = 0;
  }
  
  //Calculamos matriz
  for (int i = 1; i <= dimcadena1_; i++) {
    for (int j = 1; j <= dimcadena2_; j++) {
      if (cadena1_[i - 1] == cadena2_[j - 1])
        matriz[i][j] = 1 + matriz[i - 1][j - 1];
      else
        matriz[i][j] = max(matriz[i - 1][j], matriz[i][j - 1], matriz[i - 1][j - 1]);
    }
  }
  
  //Mostramos matriz
  for (int i = 0; i <= dimcadena1_; i++) { 
    for (int j = 0; j <= dimcadena2_; j++) { 
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  
  //calculamos resultado
  int i = dimcadena1_;
  int j = dimcadena2_;
  vector<char> subcadena;
  int actual = matriz[i][j];
  int dim = actual;
  while(actual > 0) {
    //si los 3 son iguales avanzamos a la celda diagonal
    if((matriz[i - 1][j] == matriz[i][j - 1]) &&  matriz[i - 1][j] == matriz[i - 1][j - 1]) {
      i = i - 1;
      j = j - 1;
      //Si el valor actual es menor cogemos la letra de dicha posicion
      if (matriz[i][j] == actual - 1) {
        actual = actual - 1;
        subcadena.push_back(cadena1_[i]);
      }
    }
    // avanzamos al mayor
    else {
      if (matriz[i - 1][j] > matriz[i - 1][j - 1]) 
        if (matriz[i - 1][j] > matriz[i][j - 1]) 
          i = i - 1;
        else
          j = j - 1;
      else
        if (matriz[i - 1][j - 1] > matriz[i][j - 1]) {
          i = i - 1;
          j = j - 1;
        }
        else
          j = j - 1;
    }
    
  }
  cout << "Subcadena: " << endl;
  for (int k = subcadena.size() - 1; k >= 0; k--)
    cout << subcadena[k];
  cout << endl;
}