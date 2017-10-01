
#ifndef SUBCADENA_H_
#define SUBCADENA_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Subcadena {
  private:
    char* cadena1_;
    char* cadena2_;
    int dimcadena1_;
    int dimcadena2_;
  public:
    Subcadena(char*, char*);
    ~Subcadena();
    void calcularSubcadena();
};

#endif /* SUBCADENA_H_ */