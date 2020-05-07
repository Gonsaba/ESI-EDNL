#include <iostream>
#include "listaDobleEnla.h"

int main()
{
    Lista<int> l;
    l.insertar(1,l.primera());
    auto a = l.siguiente(l.primera());
    std::cout<<l.elemento(a)<<std::endl;
}