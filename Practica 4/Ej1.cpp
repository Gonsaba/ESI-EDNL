#include <iostream>
#include "abb.h"
#include "funciones.h"

typedef int T;

void eliminarRama(Abb<T>& A,T& e)
{
	while(!A.buscar(e).izqdo().vacio())
	{
		A.eliminar(A.buscar(e).izqdo().elemento());
	}
	while(!A.buscar(e).drcho().vacio())
	{
		A.eliminar(A.buscar(e).drcho().elemento());
	}
	A.eliminar(e);
}


int main(){
	Abb<T> A;
	T vec[] = {7,5,12,9,17,8,11,10};
	unsigned tam = sizeof(vec)/sizeof(T);
	for(unsigned i = 0; i < tam; ++i)
		A.insertar(vec[i]);
	T a;

	imprimirAbb(A);
	std::cout<<"Rama a eliminar:";
	std::cin>>a;
	eliminarRama(A,a);
	std::cout<<std::endl;
	imprimirAbb(A);
}