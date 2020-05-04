#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

template <typename T>
int ComAltNodos(typename Abin<T>::nodo n,const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
		return -1;
	else
		return std::max(1 + ComAltNodos(A.hijoIzqdo(n),A),1 + ComAltNodos(A.hijoDrcho(n),A));
}

template <typename T>
int AltNodos(const Abin<T>& A)
{
	return ComAltNodos(A.raiz(),A);
}

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	std::cout<<"Ej2 Alt.arbol: "<<AltNodos(A)<<std::endl;
}