#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

int main()
{
	Abin<T> A;
	std::ifstream fe("abin1.dat");
	rellenarAbin(fe,A);
	fe.close();
	imprimirAbin(A);
}