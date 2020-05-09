#include <iostream>
#include "colaenla.h"
#include "abb.h"
#include "funciones.h"

typedef int T;

void colaArbolInordenAbb(Abb<T> A,Cola<T>& elementos,int& nElementos)
{
	if(!A.izqdo().vacio())
		colaArbolInordenAbb(A.izqdo(),elementos,nElementos);

	elementos.push(A.elemento());
	
	if(!A.drcho().vacio())
		colaArbolInordenAbb(A.drcho(),elementos,nElementos);
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
	}

	while(!elementosB.vacia())
	{
		elementos.push(elementosB.frente());
		elementosB.pop();
	}

	return elementos;
}

Cola<T> interseccionColas(Cola<T>& elementosA, Cola<T>& elementosB,int& nElementos)
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
			elementosA.pop();
		else
			elementosB.pop();
	}
	return elementos;
}

Abb<T> equilibrarAbbUnion(Abb<T>& A, Abb<T>& B)
{
	Abb<T> Res;
	if(!A.vacio() && !B.vacio())
	{
		int nElementos = 0;
		Cola<T> elementosA,elementosB,elementos;
		
		colaArbolInordenAbb(A,elementosA,nElementos);
		colaArbolInordenAbb(B,elementosB,nElementos);

		elementos = unionColas(elementosA,elementosB,nElementos);
		//elementos = interseccionColas(elementosA,elementosB,nElementos);

		procesarEquilibrarAbb(Res,elementos,nElementos);
	}
	return Res;
}

Abb<T> equilibrarAbbInterseccion(Abb<T>& A, Abb<T>& B)
{
	Abb<T> Res;
	if(!A.vacio() && !B.vacio())
	{
		int nElementos = 0;
		Cola<T> elementosA,elementosB,elementos;
		
		colaArbolInordenAbb(A,elementosA,nElementos);
		colaArbolInordenAbb(B,elementosB,nElementos);

		elementos = interseccionColas(elementosA,elementosB,nElementos);
		//elementos = interseccionColas(elementosA,elementosB,nElementos);

		procesarEquilibrarAbb(Res,elementos,nElementos);
	}
	return Res;
}

int main(){
	Abb<T> A,B,C;
	T vecA[] = {7,5,12,9,17,8,11,10};
	T vecB[] = {7,5,12,9,17,8,11,10};
	unsigned tamA = sizeof(vecA)/sizeof(T);
	unsigned tamB = sizeof(vecB)/sizeof(T);
	for(unsigned i = 0; i < tamA; ++i)
		A.insertar(vecA[i]);
	for(unsigned i = 0; i < tamB; ++i)
		B.insertar(vecB[i]);
	C = equilibrarAbbUnion(A,B);
	imprimirAbb(C);
	/*C = equilibrarAbbInterseccion(A,B);
	imprimirAbb(C);*/
}