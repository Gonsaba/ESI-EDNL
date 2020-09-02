#ifndef EJ5_H_
#define EJ5_H_

#include "abb.h"

template<typename T>
void vecInorden5(const Abb<T> &A,std::vector<T> &vec){
    if(!A.izqdo().vacio())
        vecInorden(A.izqdo(),vec);

    vec.push_back(A.elemento());

    if(!A.drcho().vacio())
        vecInorden(A.drcho(),vec);
}

template<typename T>
std::vector<T> vectoresInterseccion5(const std::vector<T> &v1,const std::vector<T> &v2){
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

std::vector<T> unirVectores5(const std::vector<T> &v1,const std::vector<T> &v2){
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
void generarArbol5(Abb<T> &A,const std::vector<T> &vec,int inicio,int fin){
    int media = ((fin - inicio)/2) + inicio;
    int tam = vec.size();
    if(fin - inicio >= 0 && media < vec.size()){
        A.insertar(vec[media]);
        generarArbol(A,vec,inicio,media-1);
        generarArbol(A,vec,media+1,fin);
    }
}

template<typename T>
std::vector<T> restarVectores(const std::vector<T> &v1, const std::vector<T> &v2){
    int i,j;
    i = j = 0;
    std::vector<T> v;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] != v2[j] && v1[i] < v2[j]){
            v.push_back(v1[i]);
            ++i;
        }
        else if(v1[i] == v2[j]){
            ++i;
            ++j;
        }
        else
            ++j;
    }

    return v;
}

template<typename T>
Abb<T> operator*(const Abb<T> &A,const Abb<T> &B){
    std::vector<T> v,vi,vu,v1,v2;
    Abb<T> C;
    vecInorden5(A,v1);
    vecInorden5(B,v2);
    vi = vectoresInterseccion5(v1,v2);
    vu = unirVectores5(v1,v2);
    v = restarVectores(vu,vi);
    generarArbol5(C,v,0,v.size());
    return C;
}

#endif