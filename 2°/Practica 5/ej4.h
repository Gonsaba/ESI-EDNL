#ifndef EJ4_H_
#define EJ4_H_
#include "agen.h"

template <typename T>
bool ternarioRec(Agen<T> A, typename Agen<T>::nodo n)
{
    int nHijos = 0;
    typename Agen<T>::nodo hijo;
    bool ternario = true;
    if(n == Agen<T>::NODO_NULO)
        return true;
    else
    {
        hijo = A.hijoIzqdo(n);
        while(ternario && hijo != Agen<T>::NODO_NULO && nHijos < 4)
        {
            ++nHijos;
            ternario = ternario && ternarioRec(A, hijo);
            hijo = A.hermDrcho(hijo);
        }
        if(nHijos == 0 || nHijos == 3)
            return ternario;
        else
            return false;
    }
}

template <typename T>
bool esTernario(Agen<T> A)
{
    return ternarioRec(A, A.raiz());
}

#endif