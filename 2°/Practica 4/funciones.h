#include <iostream>
#include <vector>
#include "colaenla.h"
#include "abb.h"

template <typename T>
void imprimirAbbRec(const Abb<T>& A)
{
	if(!A.vacio())
	{
		if(!A.izqdo().vacio())
		{
			std::cout<<"Hijo izquierdo de "<<A.elemento()<<": "<<A.izqdo().elemento()<<std::endl;
			imprimirAbbRec(A.izqdo());
		}
		if(!A.drcho().vacio())
		{
			std::cout<<"Hijo derecho de "<<A.elemento()<<": "<<A.drcho().elemento()<<std::endl;
			imprimirAbbRec(A.drcho());
		}
	}
}

template <typename T>
void imprimirAbb(const Abb<T> &A)
{
	if (A.vacio())
	{
		std::cout << "Vacio" << std::endl;
	}
	else
	{
		std::cout << "\tRaiz: " << A.elemento() << std::endl;
		imprimirAbbRec(A);
	}
}

template <typename T>
void imprimirCola(Cola<T> &l)
{
	while(!l.vacia())
	{
		std::cout<<l.frente()<<" ";
		l.pop();
	}
	std::cout<<std::endl;
}