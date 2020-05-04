#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

template <typename T>
int ContNumNodos(typename Abin<T>::nodo n,const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else
		return 1 + ContNumNodos(A.hijoIzqdo(n),A) + ContNumNodos(A.hijoDrcho(n),A);
}

template <typename T>
int NumNodos(const Abin<T>& A)
{
	return ContNumNodos(A.raiz(),A);
}

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	std::cout<<"Ej1 N.nodos: "<<NumNodos(A)<<std::endl;
}