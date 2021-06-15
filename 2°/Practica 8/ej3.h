#ifndef EJ3_H_
#define EJ3_H_
#include <iostream>
#include "apoMax.h"

void testApoMax()
{
    ApoMax<int> A(10);
    A.insertar(10);
    A.insertar(12);
    A.insertar(15);
    A.insertar(18);
    A.insertar(20);
    A.insertar(35);
    A.insertar(6);

    while (!A.vacio())
    {
        std::cout << A.cima() << " ";
        A.suprimir();
    }
}

#endif