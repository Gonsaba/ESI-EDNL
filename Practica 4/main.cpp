#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"

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

void ej2(){
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

void ej3(){
	Abb<T> A,B,C;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
	T vec2[] = {1,4,2,6,13,15,16,19};
	unsigned tam2 = sizeof(vec2)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		B.insertar(vec2[i]);
	T a;

	C = equilibrar2arboles(A,B);

	imprimirAbb(C);
}

int main(){
    Abb<T> A;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
}