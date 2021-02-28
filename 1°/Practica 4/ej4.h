#ifndef EJ4_H_
#define EJ4_H_

#include "abb.h"

template<typename T>
void vecInorden3(const Abb<T> &A,std::vector<T> &vec){
    if(!A.izqdo().vacio())
        vecInorden(A.izqdo(),vec);

    vec.push_back(A.elemento());

    if(!A.drcho().vacio())
        vecInorden(A.drcho(),vec);
}

template<typename T>
std::vector<T> vectoresInterseccion(std::vector<T> v1,std::vector<T> v2){
    int i,j;
    i = j = 0;
    std::vector<T> v;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] == v2[j]){
            v.push_back(v1[i]);
            ++i;
            ++j;
        }
        else if(v1[i] < v2[j]){
            ++i;
        }
        else 
            ++j;
    }

    return v;
}

template<typename T>
void generarArbol3(Abb<T> &A,std::vector<T> vec,int inicio,int fin){
    int media = ((fin - inicio)/2) + inicio;
    int tam = vec.size();
    if(fin - inicio >= 0 && media < vec.size()){
        A.insertar(vec[media]);
        generarArbol(A,vec,inicio,media-1);
        generarArbol(A,vec,media+1,fin);
    }
}

template<typename T>
Abb<T> interseccionArboles(const Abb<T> &A,const Abb<T> &B){
    std::vector<T> v,v1,v2;
    Abb<T> C;
    vecInorden3(A,v1);
    vecInorden3(B,v2);
    v = vectoresInterseccion(v1,v2);
    generarArbol3(C,v,0,v.size());
    return C;
}

#endif