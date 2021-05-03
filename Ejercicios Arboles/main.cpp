#include <iostream>
#include <fstream>
#include <string>
#include "abin.h"
#include "abin_E-S.h"
#include "agen.h"
#include "agen_E-S.h"
#include "nostalgicosAbin.h"
#include "nostalgicosAgen.h"
#include "prosperosAbin.h"
#include "prosperosAgen.h"
#include "septiembre2020.h"

typedef char T;

void nostalgicosAbin()
{
    Abin<T> A;
    std::ifstream f("abin.dat");
    rellenarAbin(f, A);
    f.close();
    std::cout << "\nNodos Nostalgicos Abin: " << numNostalgicos(A) << std::endl;
}

void nostalgicosAgen()
{
    Agen<T> A;
    std::ifstream f("agen.dat");
    rellenarAgen(f, A);
    f.close();
    std::cout << "\nNodos Nostalgicos Agen: " << numNostalgicos(A) << std::endl;
}

void prosperosAbin()
{
    Abin<T> A;
    std::ifstream f("abin.dat");
    rellenarAbin(f, A);
    f.close();
    std::cout << "\nNodos Prosperos Abin: " << numProsperos(A) << std::endl;
}

void prosperosAgen()
{
    Agen<T> A;
    std::ifstream f("agen.dat");
    rellenarAgen(f, A);
    f.close();
    std::cout << "\nNodos Prosperos Agen: " << numProsperos(A) << std::endl;
}

void descifrarMensaje()
{
    std::string cifrado = "ESE_AJUE__NSE_CRTEMETEO.SNS";
    std::cout << descifrar(cifrado) << std::endl; 
}

int main()
{
    // nostalgicosAbin();
    // nostalgicosAgen();
    // prosperosAbin();
    // prosperosAgen();
    descifrarMensaje();
}