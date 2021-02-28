#include <iostream>
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

bool prueba()
{
	return true*true;
}

bool pseudocompletoAbinRec(Abin<T> A,typename Abin<T>::nodo n){
	if(n == Abin<T>::NODO_NULO){
		return true;
	}
	else if(A.altura(n) == 1){
		bool i = true,d = true;
		if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO)
			i = false;
		if(A.hijoDrcho(n) == Abin<T>::NODO_NULO)
			d = false;
		return i*d;
	}
	else{
		return pseudocompletoAbinRec(A,A.hijoIzqdo(n))*pseudocompletoAbinRec(A,A.hijoDrcho(n));
	}
}

bool pseudocompletoAbin(Abin<T> A){
	return pseudocompletoAbinRec(A,A.raiz());
}

int main(){
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	imprimirAbin(A);
	if(pseudocompletoAbin(A) == true){
		std::cout<<"Pseudocompleto"<<std::endl;
	}
	else{
		std::cout<<"No pseudocompleto"<<std::endl;
	}

}