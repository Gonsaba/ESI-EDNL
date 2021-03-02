#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej6.h"
#include "ej7.h"

typedef char T;
const T fin = '#'; // Fin de lectura. int main

Abin<T>::nodo buscarNodoRec(Abin<T> &A, typename Abin<T>::nodo n, T e){
    if(n == Abin<T>::NODO_NULO)
        return Abin<T>::NODO_NULO;
    else if(A.elemento(n) == e)
        return n;
    else {
        typename Abin<T>::nodo ni, nd;
        ni = buscarNodoRec(A, A.hijoIzqdo(n), e);
        nd = buscarNodoRec(A, A.hijoDrcho(n), e);
        if(ni != Abin<T>::NODO_NULO)
            return ni;
        else
            return nd;
    }
}

Abin<T>::nodo buscarNodo(Abin<T> &A, T e) {
    return buscarNodoRec(A, A.raiz(), e);
}

void ej1() {
    Abin<T> A;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();
    std::cout << "Nodos: " << contarNodos(A) << std::endl;
}

void ej2() {
    Abin<T> A;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();
    std::cout << "Altura: " << calcAltura(A) << std::endl;
}

void ej3() {
    Abin<T> A;
    char nodos[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();
    for(int i = 0; i < sizeof(nodos); ++i)
        std::cout << "Profundidad de " << nodos[i] << ": "
            << calcProfRec(A, buscarNodo(A, nodos[i])) << std::endl;
}

void ej6() {
    Abin<T> A;
    std::ifstream fe("abin3.dat");
    rellenarAbin(fe, A);
    fe.close();
    std::cout << "Desequilibrio: " << desequilibrio(A) << std::endl;
}

void ej7() {
    Abin<T> A;
    std::ifstream fe("abin2.dat");
    rellenarAbin(fe, A);
    fe.close();
    if(pseudocompleto(A))
        std::cout << "Pseudocompleto" << std::endl;
    else
        std::cout << "No Pseudocompleto" << std::endl;
}

int main () {    
    ej1();
    ej2();
    ej3();
    ej6();
    ej7();
}

