#include <iostream>
#include <vector>
#include "listaenla.h"
#include "abb.h"

typedef int T;

void imprimirAbb(const Abb<T>& A)
{
	if(!A.vacio())
	{
		//std::cout<<"\tRaiz: "<<A.elemento()<<std::endl;
		if(!A.izqdo().vacio())
		{
			std::cout<<"Hijo izquierdo de "<<A.elemento()<<": "<<A.izqdo().elemento()<<std::endl;
			imprimirAbb(A.izqdo());
		}
		if(!A.drcho().vacio())
		{
			std::cout<<"Hijo derecho de "<<A.elemento()<<": "<<A.drcho().elemento()<<std::endl;
			imprimirAbb(A.drcho());
		}
	}
}

void imprimirCola(Cola<T> &l)
{
	while(!l.vacia())
	{
		std::cout<<l.frente()<<" ";
		l.pop();
	}
	std::cout<<std::endl;
}