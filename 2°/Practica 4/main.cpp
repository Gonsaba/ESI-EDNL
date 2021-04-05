#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"

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

void ej3()
{
    Abb<int> A, B;
    int vec1[] = {7, 5, 12, 9, 17, 8, 11, 10};
    int vec2[] = {2, 4, 6, 3, 1};
    unsigned n1 = sizeof(vec1) / sizeof(int);
    unsigned n2 = sizeof(vec2) / sizeof(int);
    for (int i = 0; i < n1; ++i)
        A.insertar(vec1[i]);
    for (int i = 0; i < n2; ++i)
        B.insertar(vec2[i]);

    A = unionEquilibrada(A, B);
    imprimirAbb(A);
}

void ej4()
{
    Abb<int> A, B;
    int vec1[] = {7, 5, 12, 9, 17, 8, 11, 10};
    int vec2[] = {2, 4, 6, 3, 1, 7, 5, 12, 9};
    unsigned n1 = sizeof(vec1) / sizeof(int);
    unsigned n2 = sizeof(vec2) / sizeof(int);
    for (int i = 0; i < n1; ++i)
        A.insertar(vec1[i]);
    for (int i = 0; i < n2; ++i)
        B.insertar(vec2[i]);

    A = interseccionEquilibrada(A, B);
    imprimirAbb(A);
}

void ej5()
{
    Abb<int> A, B;
    int vec1[] = {7, 5, 12, 9, 17, 8, 11, 10};
    int vec2[] = {2, 4, 6, 3, 1, 7, 5, 12, 9};
    unsigned n1 = sizeof(vec1) / sizeof(int);
    unsigned n2 = sizeof(vec2) / sizeof(int);
    for (int i = 0; i < n1; ++i)
        A.insertar(vec1[i]);
    for (int i = 0; i < n2; ++i)
        B.insertar(vec2[i]);

    // imprimirAbb(A | B);
    // imprimirAbb(A & B);
    // imprimirAbb(A - B);
    imprimirAbb(A * B);
}

int main() 
{
    // ej1();
    // ej2();
    // ej3();
    // ej4();
    ej5();
}