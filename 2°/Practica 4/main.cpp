#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"

typedef int T;

void ej1()
{
    Abb<int> A;
    int vec[] = {7, 5, 12, 9, 17, 8, 11, 10};
    unsigned n = sizeof(vec) / sizeof(int);
    for (int i = 0; i < n; ++i)
        A.insertar(vec[i]);

    int a = 9;

    imprimirAbb(A);
    eliminarSubArbol(A, a);
    imprimirAbb(A);
}

int main() 
{
    ej1();
}