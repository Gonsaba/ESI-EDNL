#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"

typedef int T;

int main()
{
    Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
    imprimirAbin(A);
}