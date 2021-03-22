#ifndef ABIN_H
#define ABIN_H
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

template <typename T> class Abin 
{
	// struct celda; // declaración adelantada privada
public:
	typedef int nodo;
	static const nodo NODO_NULO;
	Abin(int maxSize); // constructor
	void print() {
		for (int i = 0; i < N; ++i)
			std::cout << std::boolalpha << A[i] << ", ";
		std::cout<<std::endl;
		for(int i = 0; i < N; ++i)
			std::cout << std::boolalpha << ocupado[i] << " ";
	}
	void insertarRaiz(const T& e);
	void insertarHijoIzqdo(nodo n, const T& e);
	void insertarHijoDrcho(nodo n, const T& e);
	// void eliminarHijoIzqdo(nodo n);
	// void eliminarHijoDrcho(nodo n);
	// void eliminarRaiz();
	// bool arbolVacio() const;
	const T& elemento(nodo n) const; // acceso a elto, lectura
	// T& elemento(nodo n); // acceso a elto, lectura/escritura
	nodo raiz() const;
	nodo padre(nodo n) const;
	nodo hijoIzqdo(nodo n) const;
	nodo hijoDrcho(nodo n) const;
	// Abin(const Abin<T>& a); // ctor. de copia
	// Abin<T>& operator =(const Abin<T>& A); // asig.de árboles
	// int altura(nodo n);
	int profundidad(nodo n) const;
	int profundidad_rec(Abin<T>::nodo n, int inicio, int fin) const
		// ~Abin(); // destructor
		private : T *A;
	bool* ocupado;
	int N;
	// struct celda {
	// 	T elto;
	// 	nodo padre, hizq, hder;
	// 	celda(const T& e, nodo p = NODO_NULO): elto(e),
	// 	padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
	// };
	// nodo r; // nodo raíz del árbol
	// void destruirNodos(nodo& n);
	// nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

/*--------------------------------------------------------*/
/* Métodos públicos */
/*--------------------------------------------------------*/
// template <typename T> 
// int Abin<T>::altura(Abin<T>::nodo n)
// {
// 	if(n == NODO_NULO)
// 		return -1;
// 	else
// 		return 1 + std::max(altura(n->hizq),altura(n->hder));
// }

template <typename T>
int Abin<T>::profundidad(Abin<T>::nodo n) const
{
	int profindidad = 0;
	int inicio = 0, fin = N - 1;

	return profindidad;
}

template <typename T>
int Abin<T>::profundidad_rec(Abin<T>::nodo n, int inicio, int fin) const
{
	int medio = (inicio + fin) / 2
	if (medio == n)
		return 0;
	else if (medio > n)
		profundidad_rec(n, medio + 1, fin);
	else 
		profundidad_rec(n, medio + 1, medio - 1);
}

template <typename T>
inline Abin<T>::Abin(int maxSize) : N(maxSize) {
	A = new T[maxSize];
	ocupado = new bool[maxSize];
	std::fill(ocupado, ocupado + maxSize, false);
	std::fill(A, A + maxSize, '-');
}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
	assert(!ocupado[(N-1)/2]); // Árbol vacío
	A[(N-1)/2] = e;
	ocupado[(N - 1) / 2] = true;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(Abin<T>::nodo n, const T& e)
{
	int i = n - ((N + 1) / 
    	std::pow(2, profundidad(n) + 2));
	assert(!ocupado[i]);
    A[i] = e;
	ocupado[i] = true;
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(Abin<T>::nodo n, const T& e)
{
	int i = n + ((N + 1) / 
    	std::pow(2, profundidad(n) + 2));
	assert(!ocupado[i]);
    A[i] = e;
	ocupado[i] = true;
}

// template <typename T>
// inline void Abin<T>::eliminarHijoIzqdo(Abin<T>::nodo n)
// {
// 	assert(n != NODO_NULO);
// 	assert(n->hizq != NODO_NULO); // Existe hijo izqdo.
// 	assert(n->hizq->hizq == NODO_NULO && // Hijo izqdo.
// 	n->hizq->hder == NODO_NULO); // es hoja.
// 	delete n->hizq;
// 	n->hizq = NODO_NULO;
// }

// template <typename T>
// inline void Abin<T>::eliminarHijoDrcho(Abin<T>::nodo n)
// {
// 	assert(n != NODO_NULO);
// 	assert(n->hder != NODO_NULO); // Existe hijo drcho.
// 	assert(n->hder->hizq == NODO_NULO && // Hijo drcho.
// 	n->hder->hder == NODO_NULO); // es hoja
// 	delete n->hder;
// 	n->hder = NODO_NULO;
// }

// template <typename T>
// inline void Abin<T>::eliminarRaiz()
// {
// 	assert(r != NODO_NULO); // Árbol no vacío.
// 	assert(r->hizq == NODO_NULO &&
// 	r->hder == NODO_NULO); // La raíz es hoja.
// 	delete r;
// 	r = NODO_NULO;
// }

// template <typename T> inline bool Abin<T>::arbolVacio() const
// { 
// 	return (r == NODO_NULO); 
// }

template <typename T>
inline const T& Abin<T>::elemento(Abin<T>::nodo n) const
{
	assert(ocupado[n]);
	return A[n];
}

// template <typename T>
// inline T& Abin<T>::elemento(Abin<T>::nodo n)
// {
// 	assert(n != NODO_NULO);
// 	return n->elto;
// }

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{ 
	int r = (N-1)/2;
	if(ocupado[r]) return (N-1)/2; 
	else return NODO_NULO;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(Abin<T>::nodo n) const
{
	int i = (N + 1) / std::pow(2, profundidad(n) - 1);
	if (n % i == (((N + 1) / std::pow(2, profundidad(n) + 1)) - 1))
		return n + ((N + 1) / std::pow(2, profundidad(n) + 1));
	else
		return n - ((N + 1) / std::pow(2, profundidad(n) + 1));
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(Abin<T>::nodo n) const
{
	int i = (n - (N + 1) / std::pow(2, profundidad(n) + 2));
	if(ocupado[i]) return i;
	else return NODO_NULO;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(Abin<T>::nodo n) const
{
	int i = (n + (N + 1) / std::pow(2, profundidad(n) + 2));
	if(ocupado[i]) return i;
	else return NODO_NULO;
}

// template <typename T>
// inline Abin<T>::Abin(const Abin<T>& A)
// {
// 	r = copiar(A.r); // Copiar raíz y descendientes.
// }

// template <typename T>
// Abin<T>& Abin<T>::operator =(const Abin<T>& A)
// {
// 	if (this != &A) // Evitar autoasignación.
// 	{
// 		this->~Abin(); // Vaciar el árbol.
// 		r = copiar(A.r); // Copiar raíz y descendientes.
// 	}
// 	return *this;
// }

// template <typename T>
// inline Abin<T>::~Abin()
// {
// 	destruirNodos(r); // Vaciar el árbol.
// }

/*--------------------------------------------------------*/
/* Métodos privados */
/*--------------------------------------------------------*/
// Destruye un nodo y todos sus descendientes
// template <typename T>
// void Abin<T>::destruirNodos(Abin<T>::nodo& n)
// {
// 	if (n != NODO_NULO)
// 	{
// 		destruirNodos(n->hizq);
// 		destruirNodos(n->hder);
// 		delete n;
// 		n = NODO_NULO;
// 	}
// }

// // Devuelve una copia de un nodo y todos sus descendientes
// template <typename T>
// typename Abin<T>::nodo Abin<T>::copiar(Abin<T>::nodo n)
// {
// 	nodo m = NODO_NULO;
// 	if (n != NODO_NULO) 
// 	{
// 		m = new celda(n->elto); // Copiar n.
// 		m->hizq = copiar(n->hizq); // Copiar subárbol izqdo.
// 		if (m->hizq != NODO_NULO) m->hizq->padre = m;
// 		m->hder = copiar(n->hder); // Copiar subárbol drcho.
// 		if (m->hder != NODO_NULO) m->hder->padre = m;
// 	}
// 	return m;
// }
#endif // ABIN_H