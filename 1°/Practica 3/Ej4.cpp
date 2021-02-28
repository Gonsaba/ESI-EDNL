#include <iostream>
#include <fstream>
#include "agenlis.h"
#include "agen_E-S.h"

typedef char T;

void podaRec(Agen<T>& A,typename Agen<T>::nodo n)
{
	if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
	{
		podaRec(A,A.hijoIzqdo(n));
		A.eliminarHijoIzqdo(n);
	}
	if(A.hermDrcho(n) != Agen<T>::NODO_NULO)
	{
		podaRec(A,A.hermDrcho(n));
		A.eliminarHermDrcho(n);
	}
}

void copiar(Agen<T>& A,typename Agen<T>::nodo a, typename Agen<T>::nodo b)
{
	A.elemento(a) = A.elemento(b);
	if(A.hijoIzqdo(b) != Agen<T>::NODO_NULO)
	{
		typename Agen<T>::nodo hijo = A.hijoIzqdo(b);
		A.insertarHijoIzqdo(a,A.elemento(hijo));
		copiar(A,A.hijoIzqdo(a),hijo);
	}
	if(A.hermDrcho(b) != Agen<T>::NODO_NULO)
	{
		typename Agen<T>::nodo hermano = A.hermDrcho(b);
		A.insertarHermDrcho(a,A.elemento(hermano));
		copiar(A,A.hermDrcho(a),hermano);
	}
}

void copiaHermano(Agen<T>& A,typename Agen<T>::nodo x)
{
	if(A.hermDrcho(x) != Agen<T>::NODO_NULO)
	{
		typename Agen<T>::nodo hermano = A.hermDrcho(x);

		if(A.hijoIzqdo(x) != Agen<T>::NODO_NULO)
		{
			podaRec(A,A.hijoIzqdo(x));
			A.eliminarHijoIzqdo(x);
		}
		
		if(A.hijoIzqdo(hermano) != Agen<T>::NODO_NULO);
			A.insertarHijoIzqdo(x,A.hijoIzqdo(hermano));

		A.elemento(x) = A.elemento(hermano);
		copiar(A,A.hijoIzqdo(x),A.hijoIzqdo(hermano));

		copiaHermano(A,hermano);
		
		if(A.elemento(x) == A.elemento(hermano))
		{
			podaRec(A,hermano);
			A.eliminarHermDrcho(x);
		}
	}
}

void procesarPoda(Agen<T>& A,typename Agen<T>::nodo x)
{
	if(!A.arbolVacio() || A.hijoIzqdo(x) != Agen<T>::NODO_NULO)
	{
		podaRec(A,A.hijoIzqdo(x));
		A.eliminarHijoIzqdo(x);
		if(A.hermDrcho(x) != Agen<T>::NODO_NULO)
		{
			copiaHermano(A,x);
		}
	}
}

void busquedaRec(Agen<T>& A,T x,typename Agen<T>::nodo n)
{
	if(A.elemento(n) != x)
	{
		if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
		{
			busquedaRec(A,x,A.hijoIzqdo(n));
		}
		if(A.hermDrcho(n) != Agen<T>::NODO_NULO)
		{
			busquedaRec(A,x,A.hermDrcho(n));
		}
	}
	else
	{
		procesarPoda(A,n);
	}
}

void poda(Agen<T>& A,T x)
{
	if(!A.arbolVacio())
	{
		busquedaRec(A,x,A.raiz());
	}
}

int main()
{
	Agen<T> A(25);
	std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
	rellenarAgen(fe, A); // Desde fichero.
	fe.close();
	T c;
	std::cout<<"Nodo a podar: ";
	std::cin>>c;
	imprimirAgen(A);
	poda(A,c);
	std::cout<<std::endl;
	imprimirAgen(A);
}