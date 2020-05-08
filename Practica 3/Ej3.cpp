#include <iostream>
#include <fstream>
#include "agenlis.h"
#include "agen_E-S.h"

typedef char T;

int max(int a, int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int altura(const Agen<T>& A, const Agen<T>::nodo n)
{
	int max = 0;
	if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			int aux = altura(A,hijo);
			if(max < aux)
				max = aux;
			hijo = A.hermDrcho(hijo);
		}
		return 1 + max;
	}
}

int desequilibrioRec(const Agen<T>& A, const Agen<T>::nodo n)
{
	if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
		int maxdes = 0, altMax = 0, altMin = altura(A,hijo);
		while(hijo != Agen<T>::NODO_NULO)
		{
			int auxdes = desequilibrioRec(A,hijo);
			int aux = altura(A,hijo);
			std::cout<<aux<<std::endl;
			if(aux < altMin)
				altMin = aux;
			if(altMax < aux)
				altMax = aux;
			if(maxdes < auxdes)
				maxdes = auxdes;
			hijo = A.hermDrcho(hijo);
			if(hijo != Agen<T>::NODO_NULO) 
				std::cout<<A.elemento(hijo)<<std::endl;
		}
		std::cout<<A.elemento(n)<<" - "<<maxdes<<" - "<<altMax<<" - "<<altMin<<std::endl;
		return max(maxdes,altMax-altMin);
	}
}

int desequilibrio(const Agen<T>& A)
{
	if(A.arbolVacio())
	{
		return 0;
	}
	else
	{	
		return desequilibrioRec(A,A.raiz());
	}
}

int main()
{
	Agen<T> A(25);
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	imprimirAgen(A);

	std::cout<<"Altura: "<<altura(A,A.raiz())<<std::endl;	

	std::cout<<desequilibrio(A)<<std::endl;
}