#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

bool AbinSimilaresRec(Abin<T> A,Abin<T> B,typename Abin<T>::nodo n1,typename Abin<T>::nodo n2){
	if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO){
		return true;
	}
	else if(n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO){
		return false;
	}
	else{
		return AbinSimilaresRec(A,B,A.hijoIzqdo(n1),B.hijoIzqdo(n2))*AbinSimilaresRec(A,B,A.hijoDrcho(n1),B.hijoDrcho(n2));
	}
}

bool AbinSimilares(Abin<T> A,Abin<T> B){
	return AbinSimilaresRec(A,B,A.raiz(),B.raiz());
}

int main(){
	Abin<T> A,B;
	std::ifstream fe("abin1.dat");
	rellenarAbin(fe,A);
	fe.close();
	std::ifstream fe2("abin2.dat");
	rellenarAbin(fe2,B);
	fe2.close();
	std::cout<<AbinSimilares(A,A)<<std::endl;
	std::cout<<AbinSimilares(A,B)<<std::endl;
	std::cout<<AbinSimilares(B,B)<<std::endl;
}