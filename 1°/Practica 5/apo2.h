#ifndef APO_H
#define APO_H
#include <cassert>
#include <iostream>

template <typename T> class Apo {
public:
	explicit Apo(size_t maxNodos); // constructor
	void insertar(const T& e);
	void suprimir();
	const T& cima() const;
	bool vacio() const;
	Apo(const Apo<T>& A); // ctor. de copia
	Apo<T>& operator =(const Apo<T>& A); // asignación de apo
	void mostrar() const;
	void mostrar_Rec(int i) const;
	~Apo(); // destructor
private:
	typedef int nodo; // índice del vector
	// entre 0 y maxNodos-1
	T* nodos; // vector de nodos
	int maxNodos; // tamaño del vector
	nodo ultimo; // último nodo del árbol
	nodo padre(nodo i) const { return (i-1)/2; }
	nodo hIzq(nodo i) const { return 2*i+1; }
	nodo hDer(nodo i) const { return 2*i+2; }
	void flotarPar(nodo i);
	void flotarImpar(nodo i);
	void hundirPar(nodo i);
	const int profundidad(nodo i) const;

};

template <typename T>
void Apo<T>::mostrar_Rec(int i) const {
    int hizq = hIzq(i), hder = hDer(i);
    if(hizq <= ultimo) {
        std::cout << "Hijo izqdo de " << nodos[i] << ": " << nodos[hizq] << std::endl;
        mostrar_Rec(hizq);
    }
    if(hder <= ultimo) {
        std::cout << "Hijo drcho de " << nodos[i] << ": " << nodos[hder] << std::endl;
        mostrar_Rec(hder);
    }
}

template <typename T>
void Apo<T>::mostrar() const {
    if(ultimo == -1)
        std::cout << "APO vacío." << std::endl;
    else {
        std::cout << "Cima: " << nodos[0] << std::endl;
        mostrar_Rec(0);
    }
}

template <typename T>
const int Apo<T>::profundidad(nodo i) const
{
	int profundidad = 0;
	while(i > 0)
	{
		++profundidad;
		i = padre(i);
	}
	return profundidad;
}


template <typename T>
inline Apo<T>::Apo(size_t maxNodos) :
	nodos(new T[maxNodos]),
	maxNodos(maxNodos),
	ultimo(-1) // Apo vacío.
{}

template <typename T>
inline const T& Apo<T>::cima() const
{
	assert(ultimo > -1); // Apo no vacío.
	return nodos[0];
}

template <typename T>
inline bool Apo<T>::vacio() const
{
	return (ultimo == -1);
}

template <typename T>
inline void Apo<T>::insertar(const T& e)
{
	assert(ultimo < maxNodos-1); // Apo no lleno.
	nodos[++ultimo] = e;
	int padrePos = padre(ultimo);
	int profundidadPos = profundidad(ultimo);
	if (ultimo > 0)
	{
		std::cout<<profundidadPos<<std::endl;
		if((profundidadPos % 2) == 0)
		{
			if(nodos[padre(ultimo)] < nodos[ultimo])
			{
				T e = nodos[ultimo];
				nodos[ultimo] = nodos[padrePos];
				nodos[padrePos] = e;
				flotarImpar(padrePos);
			}
			else
				flotarPar(ultimo);
		}
		else
		{
			if(nodos[padre(ultimo)] > nodos[ultimo])
			{
				T e = nodos[ultimo];
				nodos[ultimo] = nodos[padrePos];
				nodos[padrePos] = e;
				flotarPar(padrePos);
			}
			else
				flotarImpar(ultimo);
		}
	}
}

template <typename T>
void Apo<T>::flotarImpar(nodo i)
{
	int posicion = i;
	int abuelo;
	bool correcto = false;
	T e;
	while(posicion > 2 && !correcto)
	{
		abuelo = padre(padre(posicion));
		if(nodos[posicion] > nodos[abuelo])
		{
			e = nodos[posicion];
			nodos[posicion] = nodos[abuelo];
			nodos[abuelo] = e;
		}
		else
			correcto = true;
	}
}

template <typename T>
void Apo<T>::flotarPar(nodo i)
{
	int posicion = i;
	int abuelo;
	bool correcto = false;
	T e;
	while(posicion > 0 && !correcto)
	{
		abuelo = padre(padre(posicion));
		if(nodos[posicion] < nodos[abuelo])
		{
			e = nodos[posicion];
			nodos[posicion] = nodos[abuelo];
			nodos[abuelo] = e;
		}
		else
			correcto = true;
	}
}

template <typename T>
inline void Apo<T>::suprimir()
{
	assert(ultimo > -1); // Apo no vacío.
	nodo hundir;
	if (--ultimo > -1) // Apo no queda vacío.
	{
		if(nodos[hIzq(0)] > nodos[hDer(0)])
			hundir = hIzq(0);
		else
			hundir = hDer(0);
		std::cout<<nodos[hundir]<<std::endl;
		nodos[hundir] = nodos[ultimo+1];
		if (ultimo > 0) // Quedan dos o más elementos.
			hundirPar(hundir); // Reordenar.
	}
}

template <typename T>
void Apo<T>::hundirPar(nodo i)
{
	T e;
	bool correcto = false;
	int max, indiceMax, pos = i;
	int nietoIzq1, nietoIzq2, nietoDrh1, nietoDrh2;

	while(!correcto && i != -1 && i <= ultimo)
	{
		nietoIzq1 = hIzq(hDer(pos)); nietoIzq2 = hIzq(hIzq(pos)); 
		nietoDrh1 = hDer(hDer(pos)); nietoDrh2 = hDer(hIzq(pos));
		indiceMax = -1;
		max = -1;
		if(nietoIzq1 <= ultimo)
		{
			if(nodos[nietoIzq1] > max)
			{
				max = nodos[nietoIzq1];
				indiceMax = nietoIzq1;
			}
		}

		if(nietoIzq2 <= ultimo)
		{
			if(nodos[nietoIzq2] > max)
			{
				max = nodos[nietoIzq2];
				indiceMax = nietoIzq2;
			}
		}

		if(nietoDrh1 <= ultimo)
		{
			if(nodos[nietoDrh1] > max)
			{
				max = nodos[nietoDrh1];
				indiceMax = nietoDrh1;
			}
		}

		if(nietoDrh2 <= ultimo)
		{
			if(nodos[nietoDrh2] > max)
			{
				max = nodos[nietoDrh2];
				indiceMax = nietoDrh2;
			}
		}
		
		if(indiceMax != -1)
		{
			if(nodos[padre(indiceMax) > nodos[pos]])
			{
				e = nodos[pos];
				nodos[pos] = nodos[padre(indiceMax)];
				nodos[padre(indiceMax)] = e;
			}

			if(nodos[indiceMax] > nodos[pos])
			{
				e = nodos[pos];
				nodos[pos] = nodos[indiceMax];
				nodos[indiceMax] = e;
			}
		}
		else
		{
			if(hIzq(pos) <= ultimo)
			{
				if(nodos[hIzq(pos)] > max)
					indiceMax = hIzq(pos);
			}

			if(hDer(pos) <= ultimo)
			{
				if(nodos[hDer(pos)] > max)
					indiceMax = hDer(pos);
			}

			if(indiceMax != -1)
			{
				if(nodos[pos] < nodos[indiceMax])
				{
					e = nodos[pos];
					nodos[pos] = nodos[indiceMax];
					nodos[indiceMax] = e;
				}
			}
			else 
				correcto = true;
		}
		pos = indiceMax;
		std::cout<<pos<<std::endl;
	}
}

template <typename T>
inline Apo<T>::~Apo()
{
	delete[] nodos;
}

template <typename T>
Apo<T>::Apo(const Apo<T>& A) :
	nodos(new T[A.maxNodos]),
	maxNodos(A.maxNodos),
	ultimo(A.ultimo)
{
	// Copiar el vector.
	for (nodo n = 0; n <= ultimo; n++)
	nodos[n] = A.nodos[n];
}

template <typename T>
Apo<T>& Apo<T>::operator =(const Apo<T>& A)
{
	if (this != &A) // Evitar autoasignación.
	{ // Destruir el vector y crear uno nuevo si es necesario.
		if (maxNodos != A.maxNodos)
		{
			delete[] nodos;
			maxNodos = A.maxNodos;
			nodos = new T[maxNodos];
		}
		ultimo = A.ultimo;
		// Copiar el vector
		for (nodo n = 0; n <= ultimo; n++)
			nodos[n] = A.nodos[n];
	}
	return *this;
}

#endif // APO_H