#ifndef EJ3_H_
#define EJ3_H_
#include "iostream"
#include "abin.h"
#include "string"
#include "cstdlib"

float abinMathRes(Abin<std::string> &A);
float abinMathResRec(Abin<std::string> &A, typename Abin<std::string>::nodo n);

float abinMathRes(Abin<std::string> &A)
{
    return abinMathResRec(A, A.raiz());
}

float abinMathResRec(Abin<std::string> &A, typename Abin<std::string>::nodo n) {
    //Comprobar solo si tiene hijo izquierdo
    if(n == Abin<std::string>::NODO_NULO) 
        return 0;
    else
    {
        float iz = abinMathResRec(A, A.hijoIzqdo(n));
        float de = abinMathResRec(A, A.hijoDrcho(n));
        if(A.elemento(n) == "+") 
            return iz + de;
        else if(A.elemento(n) == "-") 
            return iz - de;
        else if(A.elemento(n) == "x") 
            return iz * de;
        else if(A.elemento(n) == "/") 
            return iz / de;
        else 
            return std::stof(A.elemento(n));
    }
}

#endif