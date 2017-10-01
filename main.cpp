
#include "Subcadena.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 2."<< endl;
    exit(-1);
  }
  
  Subcadena a(argv[1], argv[2]);
  a.calcularSubcadena();
}