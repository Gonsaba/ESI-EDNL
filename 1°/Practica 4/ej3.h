#ifndef EJ3_H_
#define EJ3_H_

#include "abb.h"

template<typename T>
void vecInorden2(const Abb<T> &A,std::vector<T> &vec){
    if(!A.izqdo().vacio())
        vecInorden(A.izqdo(),vec);

    vec.push_back(A.elemento());

    if(!A.drcho().vacio())
        vecInorden(A.drcho(),vec);
}

template<typename T>
std::vector<T> unirVectores(std::vector<T> v1,std::vector<T> v2){
    int i,j;
    i = j = 0;
    std::vector<T> v;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            v.push_back(v1[i]);
            ++i;
        }
        else{
            v.push_back(v2[j]);
            ++j;
        }
    }
    while(i < v1.size()){
        v.push_back(v1[i]);
        ++i;
    }
    while(j < v2.size()){
        v.push_back(v2[j]);
        ++j;
    }

    return v;
}

template<typename T>
void generarArbol2(Abb<T> &A,std::vector<T> vec,int inicio,int fin){
    int media = ((fin - inicio)/2) + inicio;
    int tam = vec.size();
    if(fin - inicio >= 0 && media < vec.size()){
        A.insertar(vec[media]);
        generarArbol(A,vec,inicio,media-1);
        generarArbol(A,vec,media+1,fin);
    }
}

template<typename T>
Abb<T> equilibrar2arboles(const Abb<T> &A,const Abb<T> &B){
    std::vector<T> v,v1,v2;
    Abb<T> C;
    vecInorden2(A,v1);
    vecInorden2(B,v2);
    v = unirVectores(v1,v2);
    generarArbol2(C,v,0,v.size());
    return C;
}

#endif