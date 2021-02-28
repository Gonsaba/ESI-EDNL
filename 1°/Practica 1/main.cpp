#include <iostream> 
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej6.h"

typedef char T;

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	//imprimirAbin(A);
	
}

void ej1(Abin<T> A){
	std::cout<<numNodosRec(A)<<std::endl;
	std::cout<<numNodos(A)<<std::endl;
}

void ej2(Abin<T> A){
	std::cout<<alturaArbolRec(A)<<std::endl;
	std::cout<<alturaArbol(A)<<std::endl;
}

void ej3(Abin<T> A){
	typename Abin<T>::nodo n = A.hijoIzqdo(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz()))));
	std::cout<<"Profundidad de "<<n->elto<<": "<<profNodoRecv1(A,n)<<std::endl;
	std::cout<<"Profundidad de "<<n->elto<<": "<<profNodoRecv2(A,n)<<std::endl;
}

void ej45(Abin<T> A){
	typename Abin<T>::nodo n = A.hijoIzqdo(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz()))));
	std::cout<<"Altura de "<<n->elto<<": "<<A.altura(n)<<std::endl;
	std::cout<<"Profundidad de "<<n->elto<<": "<<A.profundidad(n)<<std::endl;
}

void ej6(Abin<T> A){
	std::cout<<desequilibrioRec(A);
}