#ifndef EJ4_H_
#define EJ4_H_
#include <iostream>
#include "ej1.h"
//generar arbol expansion maxima

GrafoP<double> canalesEmasajer(GrafoP<double> G)
{
    return KruskallMax(G);
} 

#endif