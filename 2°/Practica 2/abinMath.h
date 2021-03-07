#ifndef ABIN_H
#define ABIN_H
#include <algorithm>
#include <cassert>

template <typename T> class Abin4 
{
	struct celda; // declaración adelantada privada
public:
	typedef celda* nodo;
	static const nodo NODO_NULO;
	Abin4(); // constructor
	void insertarRaiz(const T& e);
	void insertarHijoIzqdo(nodo n, const T& e);
	void insertarHijoDrcho(nodo n, const T& e);
	void eliminarHijoIzqdo(nodo n);
	void eliminarHijoDrcho(nodo n);
	void eliminarRaiz();
	bool arbolVacio() const;
	const T& elemento(nodo n) const; // acceso a elto, lectura
	T& elemento(nodo n); // acceso a elto, lectura/escritura
	nodo raiz() const;
	nodo padre(nodo n) const;
	nodo hijoIzqdo(nodo n) const;
	nodo hijoDrcho(nodo n) const;
	Abin4(const Abin4<T>& a); // ctor. de copia
	Abin4<T>& operator =(const Abin4<T>& A); // asig.de árboles
	int altura(nodo n);
	int profundidad(nodo n);
	~Abin4(); // destructor
private:
	struct celda {
		T elto;
		nodo padre, hizq, hder;
		celda(const T& e, nodo p = NODO_NULO): elto(e),
		padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
	};
	nodo r; // nodo raíz del árbol
	void destruirNodos(nodo& n);
	nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin4<T>::nodo Abin4<T>::NODO_NULO(0);

/*--------------------------------------------------------*/
/* Métodos públicos */
/*--------------------------------------------------------*/
template <typename T> 
int Abin4<T>::altura(Abin4<T>::nodo n)
{
	if(n == NODO_NULO)
		return -1;
	else
		return 1 + std::max(altura(n->hizq),altura(n->hder));
}

template <typename T>
int Abin4<T>::profundidad(Abin4<T>::nodo n)
{
	if(n->padre == NODO_NULO)
		return 0;
	else
		return 1 + profundidad(n->padre);
}

template <typename T>
inline Abin4<T>::Abin4() : r(NODO_NULO) {}

template <typename T>
inline void Abin4<T>::insertarRaiz(const T& e)
{
	assert(r == NODO_NULO); // Árbol vacío
	r = new celda(e);
}

template <typename T>
inline void Abin4<T>::insertarHijoIzqdo(Abin4<T>::nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hizq == NODO_NULO); // No existe hijo izqdo.
	n->hizq = new celda(e, n);
}

template <typename T>
inline void Abin4<T>::insertarHijoDrcho(Abin4<T>::nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hder == NODO_NULO); // No existe hijo drcho.
	n->hder = new celda(e, n);
}

template <typename T>
inline void Abin4<T>::eliminarHijoIzqdo(Abin4<T>::nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hizq != NODO_NULO); // Existe hijo izqdo.
	assert(n->hizq->hizq == NODO_NULO && // Hijo izqdo.
	n->hizq->hder == NODO_NULO); // es hoja.
	delete n->hizq;
	n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin4<T>::eliminarHijoDrcho(Abin4<T>::nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hder != NODO_NULO); // Existe hijo drcho.
	assert(n->hder->hizq == NODO_NULO && // Hijo drcho.
	n->hder->hder == NODO_NULO); // es hoja
	delete n->hder;
	n->hder = NODO_NULO;
}

template <typename T>
inline void Abin4<T>::eliminarRaiz()
{
	assert(r != NODO_NULO); // Árbol no vacío.
	assert(r->hizq == NODO_NULO &&
	r->hder == NODO_NULO); // La raíz es hoja.
	delete r;
	r = NODO_NULO;
}

template <typename T> inline bool Abin4<T>::arbolVacio() const
{ 
	return (r == NODO_NULO); 
}

template <typename T>
inline const T& Abin4<T>::elemento(Abin4<T>::nodo n) const
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline T& Abin4<T>::elemento(Abin4<T>::nodo n)
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline typename Abin4<T>::nodo Abin4<T>::raiz() const
{ 
	return r; 
}

template <typename T> inline
typename Abin4<T>::nodo Abin4<T>::padre(Abin4<T>::nodo n) const
{
assert(n != NODO_NULO);
return n->padre;
}

template <typename T> inline
typename Abin4<T>::nodo Abin4<T>::hijoIzqdo(Abin4<T>::nodo n) const
{
	assert(n != NODO_NULO);
	return n->hizq;
}

template <typename T> inline
typename Abin4<T>::nodo Abin4<T>::hijoDrcho(Abin4<T>::nodo n) const
{
	assert(n != NODO_NULO);
	return n->hder;
}

template <typename T>
inline Abin4<T>::Abin4(const Abin4<T>& A)
{
	r = copiar(A.r); // Copiar raíz y descendientes.
}

template <typename T>
Abin4<T>& Abin4<T>::operator =(const Abin4<T>& A)
{
	if (this != &A) // Evitar autoasignación.
	{
		this->~Abin4(); // Vaciar el árbol.
		r = copiar(A.r); // Copiar raíz y descendientes.
	}
	return *this;
}

template <typename T>
inline Abin4<T>::~Abin4()
{
	destruirNodos(r); // Vaciar el árbol.
}

/*--------------------------------------------------------*/
/* Métodos privados */
/*--------------------------------------------------------*/
// Destruye un nodo y todos sus descendientes
template <typename T>
void Abin4<T>::destruirNodos(Abin4<T>::nodo& n)
{
	if (n != NODO_NULO)
	{
		destruirNodos(n->hizq);
		destruirNodos(n->hder);
		delete n;
		n = NODO_NULO;
	}
}

// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename Abin4<T>::nodo Abin4<T>::copiar(Abin4<T>::nodo n)
{
	nodo m = NODO_NULO;
	if (n != NODO_NULO) 
	{
		m = new celda(n->elto); // Copiar n.
		m->hizq = copiar(n->hizq); // Copiar subárbol izqdo.
		if (m->hizq != NODO_NULO) m->hizq->padre = m;
		m->hder = copiar(n->hder); // Copiar subárbol drcho.
		if (m->hder != NODO_NULO) m->hder->padre = m;
	}
	return m;
}
#endif // ABIN_H