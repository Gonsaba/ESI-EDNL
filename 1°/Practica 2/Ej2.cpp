#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

enum tipo{izq,der};

void AbinReflejadoRec(Abin<T> A,Abin<T>& B,typename Abin<T>::nodo n1,typename Abin<T>::nodo n2,tipo t){
	if(n1 != Abin<T>::NODO_NULO){
		if(t == izq){
			B.insertarHijoDrcho(n2,A.elemento(n1));
			AbinReflejadoRec(A,B,A.hijoIzqdo(n1),B.hijoDrcho(n2),izq);
			AbinReflejadoRec(A,B,A.hijoDrcho(n1),B.hijoDrcho(n2),der);
		} else if(t == der){
			B.insertarHijoIzqdo(n2,A.elemento(n1));
			AbinReflejadoRec(A,B,A.hijoIzqdo(n1),B.hijoIzqdo(n2),izq);
			AbinReflejadoRec(A,B,A.hijoDrcho(n1),B.hijoIzqdo(n2),der);
		}
	}
}

Abin<T> AbinReflejado(Abin<T> A){
	Abin<T> B;
	B.insertarRaiz(A.elemento(A.raiz()));
	AbinReflejadoRec(A,B,A.hijoIzqdo(A.raiz()),B.raiz(),izq);
	AbinReflejadoRec(A,B,A.hijoDrcho(A.raiz()),B.raiz(),der);
	return B;
}

int main(){
	Abin<T> A;
	std::ifstream fe1("abin3.dat");
	rellenarAbin(fe1,A);
	fe1.close();
	imprimirAbin(A);
	std::cout<<std::endl;
	imprimirAbin(AbinReflejado(A));
}