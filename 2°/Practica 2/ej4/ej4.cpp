#include <iostream>
#include "abin.h"
#include "ej1.h"

int main() {
    Abin<char> A(31);
    A.insertarRaiz('h');
    A.insertarHijoIzqdo(A.raiz(), 'a');
    A.insertarHijoDrcho(A.raiz(), 'm');
    // A.print();
    A.padre(7);
    // A.insertarRaiz('h');
    // std::cout<< A.elemento(A.hijoDrcho(A.raiz()));
    std::cout<< contarNodos(A);
}