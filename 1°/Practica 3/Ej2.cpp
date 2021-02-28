#include <iostream>
#include <fstream>
#include "agenlis.h"
#include "agen_E-S.h"

typedef char T;

unsigned profundidad(const Agen<T>& A, typename Agen<T>::nodo n)
{
	if(A.arbolVacio())
	{
		return 0;
	}
	else if(n == A.raiz())
	{
		return 0;
	}
	else
	{
		return 1 + profundidad(A, A.padre(n));
	}
}

int main()
{
	Agen<T> A(16);
	cout << "\n*** Lectura de arbol A de agen.dat ***\n";
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	cout << "\n*** Mostrar arbol A ***\n";
	imprimirAgen(A); // En std::cout
	std::cout<<A.elemento(A.hijoIzqdo(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))))))<<std::endl;
	std::cout<<"profundidad: "<<profundidad(A,A.hijoIzqdo(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))))))<<std::endl;
}