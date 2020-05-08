#include <iostream>
#include <fstream>
#include "agenlis.h"
#include "agen_E-S.h"

typedef char T;

unsigned gradoRec(const Agen<T>& A, typename Agen<T>::nodo n)
{
	unsigned gradoMaxHerm = 0, gradoMax = 0;
	
	if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
	{
		
		typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			gradoMax++;
			unsigned gradoHerm = gradoRec(A,hijo);
			if(gradoMaxHerm < gradoHerm) 
				gradoMaxHerm = gradoHerm;
			hijo = A.hermDrcho(hijo);
		}
		if(gradoMax < gradoMaxHerm)
			gradoMax = gradoMaxHerm;
		
		return gradoMax;
	}
	else 
		return 0;
}

unsigned grado(const Agen<T>& A)
{
	if(!A.arbolVacio())
	{
		return gradoRec(A,A.raiz());
	}
	else 
		return 0;
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

	std::cout<<"Grado: "<<grado(A)<<std::endl;
}