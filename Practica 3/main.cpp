#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"
#include "ej1.h"
#include "ej2.h"

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

int main(){
    Agen<T> A;
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

    
}