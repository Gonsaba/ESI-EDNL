#ifndef EJ1_H_
#define EJ1_H_
#include "abin.h"
#include <typeinfo>
// #include "abin_E-S.h"

template<typename T>
int contarNodosRec(Abin<T> &A, typename Abin<T>::nodo n)
{
    std::cout << n << " " << Abin<T>::NODO_NULO << std::endl;
    std::cout << typeid(n).name() << " " << typeid(Abin<T>::NODO_NULO).name() << std::endl;
    if (n == Abin<T>::NODO_NULO) {
        std::cout << A.elemento(A.padre(n)) << std::endl;
        return 0;
    }
    else
    {
        return 1 + contarNodosRec(A, A.hijoIzqdo(n)) + contarNodosRec(A, A.hijoDrcho(n));
    }
}

template <typename T>
int contarNodos(Abin<T> A)
{
    return contarNodosRec(A, A.raiz());
}

#endif