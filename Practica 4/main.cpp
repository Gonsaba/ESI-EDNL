#include <iostream>
#include "abb.h"
#include "funciones.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"

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

void ej4(){
	Abb<T> A;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);

	Abb<T> B;
	T vec2[] = {1,4,2,6,9,8,16,19};
	tam = sizeof(vec2)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		B.insertar(vec2[i]);
	
	A = interseccionArboles(A,B);
	imprimirAbb(A);
}

void ej5(){
	Abb<T> A;
	T vec[] = {1,2,4,6,8,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);

	Abb<T> B;
	T vec2[] = {3,5,6,9,10};
	tam = sizeof(vec2)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		B.insertar(vec2[i]);
	
	A = A*B;
	imprimirAbb(A);
}

int main(){
    ej1();
	ej2();
	ej3();
	ej4();
	ej5();
}