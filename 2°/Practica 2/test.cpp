#include <iostream>
#include "abin4.h"
#include "abin_E-S.h"

typedef char T;

int main() {
    Abin4<T> A(31);
    A.insertarRaiz('a');
    std::cout << "insertada" << std::endl;
    A.printVec();
    imprimirAbin(A);
}