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
	std::cout<<"///EJ1///"<<std::endl;
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

    std::cout<<gradoAgen(A)<<std::endl;
}

void ej2(){
	std::cout<<"///EJ2///"<<std::endl;
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

    std::cout<<profundidadv1(A,A.hijoIzqdo(A.hijoIzqdo(A.raiz())))<<std::endl;
    std::cout<<profundidadv2(A,A.hijoIzqdo(A.hijoIzqdo(A.raiz())))<<std::endl;
}

void ej3(){
	std::cout<<"///EJ3///"<<std::endl;
	Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	std::cout<<desequilibrioAgen(A)<<std::endl;
}

void ej4(){
	std::cout<<"///EJ4///"<<std::endl;
	Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	imprimirAgen(A);

	podav1(A,'b');

	imprimirAgen(A);
}

int main(){
	ej1();
	ej2();
	ej3();
	ej4();
}