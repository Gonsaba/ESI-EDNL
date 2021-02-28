#ifndef EJ2_H_
#define EJ2_H_

#include "abin.h"
#include "colaenla.h"

template<typename T>
int alturaArbolRec(const Abin<T> &A){
    return contAlturaArbolRec(A,A.raiz());
}

template<typename T>
int contAlturaArbolRec(const Abin<T> &A, typename Abin<T>::nodo n){
    if(n != Abin<T>::NODO_NULO)
        return 1 + std::max(contAlturaArbolRec(A,A.hijoDrcho(n)),contAlturaArbolRec(A,A.hijoIzqdo(n)));
    else
        return -1;
}  

template<typename T>
int alturaArbol(const Abin<T> &A){
    int num = 0;
    bool hijo;
    Cola<typename Abin<T>::nodo> c1,c2;
    typename Abin<T>::nodo n;
    c1.push(A.raiz());
    while(!c1.vacia()){
        c2 = c1;
        while(!c1.vacia())  c1.pop();
        hijo = false;
        while(!c2.vacia()){
            n = c2.frente();
            if(n != Abin<T>::NODO_NULO){
                std::cout<<n<<" ";
                c1.push(A.hijoDrcho(n));
                c1.push(A.hijoIzqdo(n));
            }
            c2.pop();
        }   
        if(hijo) ++num;
    }
    return num;
}
#endif