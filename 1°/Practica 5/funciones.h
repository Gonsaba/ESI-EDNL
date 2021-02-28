#include <iostream>
#include "apo2.h"

typedef int T;

void imprimirApo(Apo<T> A)
{
	while(!A.vacio())
	{
		std::cout<<A.cima()<<" ";
		A.suprimir();
	}
	std::cout<<std::endl;
}