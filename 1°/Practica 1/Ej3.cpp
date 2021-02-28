#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

template <typename T>
int Profundidadr(typename Abin<T>::nodo n,const Abin<T>& A)
{
	if(n == A.raiz())
		return 0;
	else
		return 1 + Profundidadr(A.padre(n),A);
}

template <typename T>
int Profundidadi(typename Abin<T>::nodo n,const Abin<T>& A)
{
	int i = 0;
	while(n != A.raiz())
	{
		++i;
		n = A.padre(n);
	}
	return i;
}

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	std::cout<<"Ej3 Prof.arbol: "<<Profundidadi(A.hijoIzqdo(A.hijoDrcho(A.raiz())),A)<<std::endl;
	std::cout<<"Ej3 Prof.arbol: "<<Profundidadr(A.hijoIzqdo(A.hijoDrcho(A.raiz())),A)<<std::endl;
}