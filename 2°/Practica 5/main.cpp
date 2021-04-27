#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
#include "agen.h"
#include "agen_E-S.h"
#include "ej1.h"
#include "ej4.h"
#include "ej5.h"

typedef char T;
const T fin = '#'; // Fin de lectura. int main

void ej1()
{
    Abin<T> A;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();
    imprimirAbin(A);
    eliminar(A, '7');
    imprimirAbin(A);
}

void ej4()
{
    Agen<T> A;
    std::ifstream fe("agen2.dat");
    rellenarAgen(fe, A);
    fe.close();
    imprimirAgen(A);
    std::cout << std::boolalpha << esTernario(A) << std::endl;
}

void innorden(Agen<T> A, typename Agen<T>::nodo n, int altura)
{
    typename Agen<T>::nodo hijo;
    
    std::cout << A.elemento(n) << " - " << altura << std::endl;
    hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
        innorden(A, hijo, altura + 1);
        hijo = A.hermDrcho(hijo);
    }
        
}


void ej5()
{
    Agen<T> A;
    std::ifstream fe("agen2.dat");
    
    rellenarAgen(fe, A);
    fe.close();

    char** m = agenAMatriz(A);
    int n = 8;
    
    for (int i = 0; i < n; ++i)
    {
        
        for (int j = 0; j < n; ++j)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    // ej1();
    // ej4();
    ej5();
}
