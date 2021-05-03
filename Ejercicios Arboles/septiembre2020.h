#ifndef SEPTIEMBRE2020_H_
#define SEPTIEMBRE2020_H_

#include <iostream>
#include <string>
#include <cmath>
#include "abin.h"
#include "colaenla.h"

void insertarHijos(int h, int i, int j, typename Abin<char>::nodo n, Abin<char>& A, std::string cifrado)
{
    int iIzq, iDer;
   
    iIzq = i + 1;
    h = 0;
    if(h > 0)
    {
        A.insertarHijoIzqdo(n, cifrado[iIzq]);
        insertarHijos(h - 1, iIzq, j, A.hijoIzqdo(n), A, cifrado);
        std::cout << A.elemento(n) << " - " << h << std::endl;
        if((j - i - std::pow(2, h)) > (std::pow(2, h - 1) - 1))
            iDer = i + std::pow(2, h);
        else
            iDer = j - std::pow(2, h - 1) + 1;
        if(iDer < j)
        {
            A.insertarHijoDrcho(n, cifrado[iDer]);
            insertarHijos(h - 1, iDer, j, A.hijoDrcho(n), A, cifrado);
        }

    }
}

void construirAbin(Abin<char>& A, std::string cifrado)
{
    int n = cifrado.length();
    int profMax = log2(n);
    A.insertarRaiz(cifrado[0]);
    insertarHijos(0, profMax, 0, n, A.raiz(), A, cifrado);
}

std::string leerAnchura(Abin<char>& A)
{
    std::string mensaje;
    int i = 0;
    typename Abin<char>::nodo n;
    Cola<typename Abin<char>::nodo> nodos;

    nodos.push(A.raiz());

    while(!nodos.vacia())
    {
        n = nodos.frente();
        nodos.pop();
        if(n != Abin<char>::NODO_NULO)
        {
            mensaje[i] = A.elemento(n);
            ++i;
            nodos.push(A.hijoIzqdo(n));
            nodos.push(A.hijoDrcho(n));
        }
    }

    return mensaje;
}

std::string descifrar(std::string cifrado)
{
    Abin<char> A;
    construirAbin(A, cifrado);
    imprimirAbin(A);
    return leerAnchura(A);
}

#endif