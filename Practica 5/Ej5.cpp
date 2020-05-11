#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"

typedef char T;

int main()
{
	Agen<T> A;
	cout << "\n*** Lectura de arbol A de agen.dat ***\n";
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();

	cout << "\n*** Mostrar arbol A ***\n";
	imprimirAgen(A); // En std::cout
}