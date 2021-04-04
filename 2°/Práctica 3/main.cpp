#include <iostream>
#include <fstream>
#include "agenLis.h"
#include "agen_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"

typedef char T;

const T fin = '#'; // fin de lectura 

void ej1() {
    Agen<T> A(16);
    std::ifstream fe("agen.dat");
    rellenarAgen(fe, A);
    fe.close();
    std::cout << "Grado: " << grado(A) << std::endl;
}

void ej2()
{
    Agen<T> A(16);
    std::ifstream fe("agen.dat");
    rellenarAgen(fe, A);
    fe.close();
    std::cout << "Profundidad: " << profundidad(A, 
    A.hijoIzqdo(A.hermDrcho(A.hijoIzqdo(A.raiz())))) << std::endl;
}

void ej3()
{
    Agen<T> A(16);
    std::ifstream fe("agen.dat");
    rellenarAgen(fe, A);
    fe.close();
    // std::cout << "Altura: " << altura(A, A.raiz()) << std::endl;
    std::cout << "Desequilibrio: " << desequilibrio(A) << std::endl;
}

int main () {
    ej1();
    ej2();
    ej3();
}