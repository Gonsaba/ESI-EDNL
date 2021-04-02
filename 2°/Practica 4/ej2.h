#ifndef EJ2_H_
#define EJ2_H_
#include "abb.h"
#include "colaenla.h"

template <typename T>
void equilibrarAbbRec(Abb<T> &A, Cola<T> &elementos, int n)
{
    Cola<T> elemIzq;
    Cola<T> elemDer;
    int mediana = (n / 2);
    if(n > 0)
    {
        for(int i = 0; i < mediana; ++i)
        {
            elemIzq.push(elementos.frente());
            elementos.pop();
        }

        A.insertar(elementos.frente());
        elementos.pop();

        for (int i = mediana + 1; i < n; ++i)
        {
            elemDer.push(elementos.frente());
            elementos.pop();
        }

        equilibrarAbbRec(A, elemIzq, mediana);
        equilibrarAbbRec(A, elemDer, n - mediana - 1);
    }
}

template <typename T>
void equilibrarAbb(Abb<T> &A)
{
    Cola<T> elementos;
    int n = 0;
    inorden(A, elementos, n);
    for(int i = 0; i < n; ++i)
        A.eliminar(A.elemento());
    equilibrarAbbRec(A, elementos, n);
}

template <typename T>
void inorden(const Abb<T> &A, Cola<T> &elementos, int &n)
{
    if(!A.izqdo().vacio())
        inorden(A.izqdo(), elementos, n);

    elementos.push(A.elemento());
    ++n;

    if (!A.drcho().vacio())
        inorden(A.drcho(), elementos, n);
}

#endif