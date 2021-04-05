#ifndef EJ1_H_
#define EJ1_H_
#include "agen.h"

template <typename T>
int gradoRec(Agen<T> A, typename Agen<T>::nodo n)
{
    int nHijos = 0;
    int maxHijos = 0;
    int aux;
    typename Agen<T>::nodo hijo;
    if (A.raiz() == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO)
        {
            ++nHijos;
            aux = gradoRec(A, hijo);
            if (maxHijos < aux)
                maxHijos = aux;
            hijo = A.hermDrcho(hijo);
        }
        return std::max(nHijos, maxHijos);
    }
}

template <typename T>
int grado(Agen<T> A) 
{
    return gradoRec(A, A.raiz());
}

#endif