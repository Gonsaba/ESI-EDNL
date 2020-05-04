#include <iostream>
#include <fstream>
#include <string>
#include "abin.h"
#include "abin_E-S.h"
typedef std::string T;

template <typename T>
double abinOperacionRec(Abin<T> A,typename Abin<T>::nodo n)
{
	if(A.altura(n) == 0){
		return std::stod(A.elemento(n));
	}
	else{
		if(A.elemento(n) == "+") 
			return abinOperacionRec(A,A.hijoIzqdo(n)) + abinOperacionRec(A,A.hijoDrcho(n));
		else if(A.elemento(n) == "-") 
			return abinOperacionRec(A,A.hijoIzqdo(n)) - abinOperacionRec(A,A.hijoDrcho(n));
		else if(A.elemento(n) == "*") 
			return abinOperacionRec(A,A.hijoIzqdo(n)) * abinOperacionRec(A,A.hijoDrcho(n));
		else if(A.elemento(n) == "/") 
			return abinOperacionRec(A,A.hijoIzqdo(n)) / abinOperacionRec(A,A.hijoDrcho(n));
		else 
			return std::stod(A.elemento(n));
	}
}

template <typename T>
double abinOperacion(Abin<T> A){
	return abinOperacionRec(A,A.raiz());
}

int main(){
	Abin<T> A;
	std::ifstream fe1("op.dat");
	rellenarAbin(fe1,A);
	fe1.close();
	imprimirAbin(A);
	std::cout<<"Resultado: "<<abinOperacion(A)<<std::endl;
}