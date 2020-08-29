#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"

typedef char T;

void ej1(){
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

    std::cout<<gradoAgen(A);
}

void ej2(){
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

    std::cout<<profundidadv1(A,A.hijoIzqdo(A.hijoIzqdo(A.raiz())))<<std::endl;
    std::cout<<profundidadv2(A,A.hijoIzqdo(A.hijoIzqdo(A.raiz())))<<std::endl;
}

void ej3(){
	Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	std::cout<<desequilibrioAgen(A);
}

int main(){
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	typename Agen<T>::nodo n = buscarNodo(A,'a',A.raiz());
	if(n != Agen<T>::NODO_NULO)
		std::cout<<A.elemento(n);
	else
		std::cout<<"nulo";
}