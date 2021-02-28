#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

void AlturaProfundidadRec(typename Abin<T>::nodo n,Abin<T>& A)
{
	if(n != Abin<T>::NODO_NULO){
		std::cout<<"Altura/Profundidad de "<<A.elemento(n)<<": "<<A.altura(n)<<"/"<<A.profundidad(n)<<std::endl;
		AlturaProfundidadRec(A.hijoIzqdo(n),A);
		AlturaProfundidadRec(A.hijoDrcho(n),A);
	}
}

void AlturaProfundidad(Abin<T>& A)
{
	AlturaProfundidadRec(A.raiz(),A);
}

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	AlturaProfundidad(A);
}
