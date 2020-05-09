#include <iostream>
#include "colaenla.h"
#include "abb.h"
#include "funciones.h"

typedef int T;

void colaArbolInordenAbb(Abb<T> A,Cola<T>& elementos)
{
	if(!A.izqdo().vacio())
		colaArbolInordenAbb(A.izqdo(),elementos);

	elementos.push(A.elemento());
	
	if(!A.drcho().vacio())
		colaArbolInordenAbb(A.drcho(),elementos);
}

void procesarEquilibrarAbb(Abb<T>& A,Cola<T>& elementos,int& nElementos)
{
	if(nElementos > 0 && !elementos.vacia())
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

		procesarEquilibrarAbb(A,elementosMax,lsup);
		procesarEquilibrarAbb(A,elementosMin,linf);
	}
}

Cola<T> unionColas(Cola<T>& elementosA, Cola<T>& elementosB, int& nElementos)
{
	Cola<T> elementos;
	while(!elementosA.vacia() && !elementosB.vacia())
	{
		if(elementosA.frente() == elementosB.frente())
		{
			elementos.push(elementosA.frente());
			elementosA.pop();
			elementosB.pop();
			nElementos++;
		}
		else if(elementosA.frente() < elementosB.frente())
		{
			elementos.push(elementosA.frente());
			elementosA.pop();
			nElementos++;
		}
		else
		{
			elementos.push(elementosB.frente());
			elementosB.pop();
			nElementos++;	
		}
	}

	while(!elementosA.vacia())
	{
		elementos.push(elementosA.frente());
		elementosA.pop();
		nElementos++;
	}

	while(!elementosB.vacia())
	{
		elementos.push(elementosB.frente());
		elementosB.pop();
		nElementos++;
	}

	return elementos;
}

Abb<T> equilibrarAbb(Abb<T>& A, Abb<T>& B)
{
	Abb<T> Res;
	if(!A.vacio() && !B.vacio())
	{
		int nElementos = 0;
		Cola<T> elementosA,elementosB,elementos;
		
		colaArbolInordenAbb(A,elementosA);
		colaArbolInordenAbb(B,elementosB);

		elementos = unionColas(elementosA,elementosB,nElementos);

		Cola<T> aux = elementos;

		procesarEquilibrarAbb(Res,elementos,nElementos);
	}
	return Res;
}

int main(){
	Abb<T> A,B,C;
	T vecA[] = {7,5,12,9,17,8,11,10};
	T vecB[] = {7,5,12,20,17,8,11,10};
	unsigned tamA = sizeof(vecA)/sizeof(T);
	unsigned tamB = sizeof(vecB)/sizeof(T);
	for(unsigned i = 0; i < tamA; ++i)
		A.insertar(vecA[i]);
	for(unsigned i = 0; i < tamB; ++i)
		B.insertar(vecB[i]);
	C = equilibrarAbb(A,B);
	std::cout<<C.izqdo().elemento()<<std::endl;
	imprimirAbb(C);
}