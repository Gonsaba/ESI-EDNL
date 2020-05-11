#include <iostream>
#include "tadDiccionario.hpp"

int main()
{
    Diccionario d;
    d.insertar("hola","tusmuertos");
    d.insertar("adios","pene");
    d.insertar("maricon","gay");

    std::cout<<d.buscar("tusmuertos")<<std::endl;
}