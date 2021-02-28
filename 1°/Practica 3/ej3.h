#ifndef EJ3_H_
#define EJ3_H_

#include "agen.h"

template<typename T>
int desequilibrioAgen(const Agen<T> &A){
    return desequilibrioAgenRec(A,A.raiz());
}

template<typename T>
int desequilibrioAgenRec(const Agen<T> &A,typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int min,max,altura,desequlibrio,desequlibriomax;
        desequlibrio = desequlibriomax = 0;
        if(hijo != Agen<T>::NODO_NULO){
            min = max = alturaNodo(A,hijo);
            desequlibriomax = desequilibrioAgenRec(A,hijo);
            hijo = A.hermDrcho(n);
            while(hijo != Agen<T>::NODO_NULO){
                altura = alturaNodo(A,hijo);
                desequlibrio = desequilibrioAgenRec(A,hijo);
                if(max < altura)
                    max = altura;
                if(altura < min)
                    min = altura;
                if(desequlibriomax < desequlibrio)
                    desequlibriomax = desequlibrio;
                hijo = A.hermDrcho(hijo);
            }
        }
        return std::max((max-min),desequlibriomax);
    }
}

template<typename T>
int alturaNodo(const Agen<T> &A, typename Agen<T>::nodo n){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int altura,alturamax;
    altura = alturamax = 0;
    if(hijo != Agen<T>::NODO_NULO){
        while(hijo != Agen<T>::NODO_NULO){
            altura = 1 + alturaNodo(A,hijo);
            if(alturamax < altura)
                alturamax = altura;
            hijo = A.hermDrcho(hijo);
        }
        return alturamax;
    }
    else 
        return 0;
}

#endif