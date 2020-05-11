#include <iostream>
#include <vector>
#include "apo2.h"
#include "funciones.h"

typedef int T;

int main()
{
	Apo<T> A(15);
	std::vector<T> v = {3,9,6,15,21,10,16,17,19,25};
	for(unsigned i = 0; i < v.size(); i++)
	{
		A.insertar(v[i]);
	}
	A.mostrar();
	A.suprimir();
	A.mostrar();
	
}