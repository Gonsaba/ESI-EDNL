#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"
#include "ej2.h"

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
    eliminarSubarbolRec(A, a);
    imprimirAbb(A);
}

void ej2()
{
    Abb<int> A;
    int vec[] = {7, 5, 12, 9, 17, 8, 11, 10};
    unsigned n = sizeof(vec) / sizeof(int);
    for (int i = 0; i < n; ++i)
        A.insertar(vec[i]);
    
    equilibrarAbb(A);
    imprimirAbb(A);
}

int main() 
{
    // ej1();
    ej2();
}