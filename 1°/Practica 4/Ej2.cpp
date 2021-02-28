#include <iostream>
#include "colaenla.h"
#include "abb.h"
#include "funciones.h"

typedef int T;

void equilibrarRec(Abb<T> A,Cola<T>& elementos,int& nElementos)
{
	if(!A.izqdo().vacio())
			equilibrarRec(A.izqdo(),elementos,nElementos);

	elementos.push(A.elemento());
	nElementos++;

	if(!A.drcho().vacio())
		equilibrarRec(A.drcho(),elementos,nElementos);
}

void procesarEquilibrar(Abb<T>& A,Cola<T>& elementos,int& nElementos)
{
	if(nElementos > 0)
	{
		Cola<T> elementosMax;
		Cola<T> elementosMin;
		int mediana = nElementos/2;
		int lsup,linf;
		linf = mediana;
		lsup = nElementos - mediana - 1;
		
		for(int i = 0; i < linf; i++)
		{
			elementosMin.push(elementos.frente());
			elementos.pop();
		}

		A.insertar(elementos.frente());
		elementos.pop();

		for(int i = 0; i < lsup; i++)
		{
			elementosMax.push(elementos.frente());
			elementos.pop();
		}

		procesarEquilibrar(A,elementosMax,lsup);
		procesarEquilibrar(A,elementosMin,linf);
	}
}

void equilibrar(Abb<T>& A)
{
	if(!A.vacio())
	{
		int nElementos = 0;
		Cola<T> elementos;
		
		equilibrarRec(A,elementos,nElementos);

		for(int i = 0; i < nElementos; i++)
			A.eliminar(A.elemento());

		procesarEquilibrar(A,elementos,nElementos);
	}
}

int main(){
	Abb<T> A;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
	equilibrar(A);
	imprimirAbb(A);
}