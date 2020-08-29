#ifndef EJ1_H_
#define EJ1_H_

#include "agen.h"

template<typename T>
int gradoAgen(Agen<T> A){
    if(!A.arbolVacio())
        return gradoAgenRec(A,A.raiz());
    else
        return 0;
}

template<typename T>
int gradoAgenRec(Agen<T> A,typename Agen<T>::nodo n){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int gradomax,gradomaxhijo,gradohijo;
    gradomax = gradomaxhijo = gradohijo = 0;
    while(hijo != Agen<T>::NODO_NULO){
        ++gradomax;
        gradohijo = gradoAgenRec(A,hijo);
        if(gradomaxhijo < gradohijo)
            gradomaxhijo = gradohijo;
        hijo = A.hermDrcho(hijo);
    }

    if(gradomax < gradomaxhijo)
        return gradomaxhijo;
    else
        return gradomax;
}

#endif