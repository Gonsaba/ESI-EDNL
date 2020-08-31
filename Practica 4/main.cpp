#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"
#include "ej2.h"

typedef int T;

void ej1(){
	Abb<T> A;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
	T a;

	imprimirAbb(A);
	poda(A,9);
    imprimirAbb(A);
}

int main(){
    Abb<T> A,B;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
	T a;
	
	imprimirAbb(A);
	B = equilibrar(A);
    imprimirAbb(B);
}