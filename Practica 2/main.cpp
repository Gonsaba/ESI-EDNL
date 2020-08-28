#include <iostream>
#include <string>
#include "abin.h"
#include "abin_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"

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

void construirArbolv2(Abin<T> &A,typename Abin<T>::nodo n,std::string s,int inicio,int fin){
	int mitad = ((fin-inicio)/2)+inicio;
	int mitadizq = (((mitad-1)-inicio)/2)+inicio;
	int mitadder = ((fin-(mitad+1))/2)+(mitad+1);
	if(s[mitadizq] != '-' && inicio < fin){
		A.insertarHijoIzqdo(n,s[mitadizq]);
		construirArbolv2(A,A.hijoIzqdo(n),s,inicio,mitad-1);
	}
	if(s[mitadder] != '-' && inicio < fin){
		A.insertarHijoDrcho(n,s[mitadder]);
		construirArbolv2(A,A.hijoDrcho(n),s,mitad+1,fin);
	}
}

int main ()
{
	Abin<T> A;
	std::string s = "---n---afl-b-d-h-------m-c-j---";
	A.insertarRaiz(s[s.size()/2]);
	construirArbolv2(A,A.raiz(),s,0,s.size());
	imprimir(A);
}

