#include <iostream>
#include <string>
#include "abin.h"
#include "abin_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"

typedef char T;

void imprimirRec(const Abin<T> &A, typename Abin<T>::nodo n){
	if(n == Abin<T>::NODO_NULO)
		std::cout<<"# ";
	else{
		std::cout<<A.elemento(n)<<" ";
		imprimirRec(A,A.hijoIzqdo(n));
		imprimirRec(A,A.hijoDrcho(n));
	}
}

void imprimir(const Abin<T> &A){
	imprimirRec(A,A.raiz());
	std::cout<<std::endl;
}

void ej1(){
	Abin<T> A,B;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();

	std::ifstream fe1("abin1.dat");
	rellenarAbin(fe1,B);
	fe1.close();

	std::cout<<std::boolalpha<<similaresRec(A,B);
}

void ej2(){
	Abin<T> A,B;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();

	B = clonar(A);
	imprimir(A);
	imprimir(B);
}

void ej3(){
	Abin<T> A;
	std::ifstream fe("abinm.dat");
	rellenarAbin(fe,A);
	fe.close();

	std::cout<<calcularArbol(A);
}

void ej4(){
	std::string s = "---n---afl-b-d-h-------m-c-j---";
	imprimir(construirArbolv2(s));
}

int main ()
{
	
}

