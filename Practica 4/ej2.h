#ifndef EJ2_H_
#define EJ2_H_

#include <vector>
#include "abb.h"


template<typename T>
Abb<T> equilibrar(Abb<T> &A){
    std::vector<T> vec;
    vecInorden(A,vec);
    for(int i = 0; i < vec.size(); ++i)
        std::cout<<vec[i]<<" ";
    std::cout<<std::endl;

    Abb<T> B;
    generarArbol(B,vec,0,vec.size());
    //imprimirAbb(B);
    return B;
}

template<typename T>
void vecInorden(const Abb<T> &A,std::vector<T> &vec){
    if(!A.izqdo().vacio())
        vecInorden(A.izqdo(),vec);

    vec.push_back(A.elemento());

    if(!A.drcho().vacio())
        vecInorden(A.drcho(),vec);
}

template<typename T>
void generarArbol(Abb<T> &A,std::vector<T> vec,int inicio,int fin){
    int media = ((fin - inicio)/2) + inicio;
    if(fin - inicio > 0){
        A.insertar(vec[media]);
        generarArbol(A,vec,inicio,media-1);
        generarArbol(A,vec,media+1,fin);
    }
}

#endif