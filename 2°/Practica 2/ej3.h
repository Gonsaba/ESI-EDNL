#ifndef EJ3_H_
#define EJ3_H_
#include "iostream"
#include "abin.h"
#include "string"
#include "cstdlib"

double abinMathRes(Abin<std::string> &A);
double abinMathResRec(Abin<std::string> &A, typename Abin<std::string>::nodo n);

double abinMathRes(Abin<std::string> &A)
{
    return abinMathResRec(A, A.raiz());
}

double abinMathResRec(Abin<std::string> &A, typename Abin<std::string>::nodo n) {
    if(A.hijoIzqdo(n) == Abin<std::string>::NODO_NULO)
        return std::stod(A.elemento(n));
    else
    {
        if(A.elemento(n) == "+")
            return abinMathResRec(A, A.hijoIzqdo(n)) + abinMathResRec(A, A.hijoDrcho(n));
        else if(A.elemento(n) == "-") 
            return abinMathResRec(A, A.hijoIzqdo(n)) - abinMathResRec(A, A.hijoDrcho(n));
        else if(A.elemento(n) == "x") 
            return abinMathResRec(A, A.hijoIzqdo(n)) * abinMathResRec(A, A.hijoDrcho(n));
        else //if(A.elemento(n) == "/") 
            return abinMathResRec(A, A.hijoIzqdo(n)) / abinMathResRec(A, A.hijoDrcho(n));
        // switch (A.elemento(n))
        // {
        // case "+":
        //     return abinMathResRec(A, A.hijoIzqdo(n)) + abinMathResRec(A, A.hijoDrcho(n));
        //     break;
        // case "-":
        //     return abinMathResRec(A, A.hijoIzqdo(n)) - abinMathResRec(A, A.hijoDrcho(n));
        //     break;
        // case "x":
        //     return abinMathResRec(A, A.hijoIzqdo(n)) * abinMathResRec(A, A.hijoDrcho(n));
        //     break;
        // case "-":
        //     return abinMathResRec(A, A.hijoIzqdo(n)) / abinMathResRec(A, A.hijoDrcho(n));
        //     break;
        // default:
        //     break;
        // }
    }
}

#endif