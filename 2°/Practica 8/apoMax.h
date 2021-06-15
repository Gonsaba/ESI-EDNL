#ifndef APOMAX_H
#define APOMAX_H
#include <cassert>

template <typename T>
class ApoMax
{
public:
    explicit ApoMax(size_t maxNodos); // constructor
    void insertar(const T &e);
    void suprimir();
    const T &cima() const;
    bool vacio() const;
    ApoMax(const ApoMax &A);      // ctor. de copia
    ApoMax &operator=(const ApoMax &A); // asignaci�n de apo
    ~ApoMax();                       // destructor
private:
    typedef size_t nodo; // �ndice del vector
                         // entre 0 y maxNodos-1
    T *nodos;            // vector de nodos
    size_t maxNodos;     // tama�o del vector
    size_t numNodos;     // n�mero de nodos del �rbol

    nodo padre(nodo i) const { return (i - 1) / 2; }
    nodo hIzq(nodo i) const { return 2 * i + 1; }
    nodo hDer(nodo i) const { return 2 * i + 2; }
    void flotar(nodo i);
    void hundir(nodo i);
};

/*--------------------------------------------------------*/
/* clase Apo gen�rica: Vector de posiciones relativas.    */
/*    Un Apo de n nodos se almacena en celdas             */
/*    consecutivas del vector, desde 0 hasta numNodos-1.  */
/*    La ra�z del APO se almacena en la celda 0 del       */
/*    vector. Al hijo izquierdo del nodo i le corresponde */
/*    la celda 2i+1 y al hijo derecho la celda 2i+2.      */
/*                                                        */
/* Implementaci�n de operaciones                          */
/*--------------------------------------------------------*/

template <typename T>
inline ApoMax<T>::ApoMax(size_t maxNodos) : nodos(new T[maxNodos]),
                                            maxNodos(maxNodos),
                                            numNodos(0) {}

template <typename T>
inline void ApoMax<T>::insertar(const T &e)
{
    assert(numNodos < maxNodos); // Apo no lleno
    nodos[numNodos] = e;
    if (++numNodos > 1)
        flotar(numNodos - 1);
}

template <typename T>
inline void ApoMax<T>::suprimir()
{
    assert(numNodos > 0); // Apo no vac�o
    if (--numNodos > 0)
    { // Apo no queda vac�o.
        nodos[0] = nodos[numNodos];
        if (numNodos > 1) // Quedan dos o m�s elementos.
            hundir(0);    // Reordenar.
    }
}

template <typename T>
inline const T &ApoMax<T>::cima() const
{
    assert(numNodos > 0); // Apo no vac�o
    return nodos[0];
}

template <typename T>
inline bool ApoMax<T>::vacio() const
{
    return (numNodos == 0);
}

template <typename T>
inline ApoMax<T>::~ApoMax()
{
    delete[] nodos;
}

template <typename T>
ApoMax<T>::ApoMax(const ApoMax<T> &A) : nodos(new T[A.maxNodos]),
                                        maxNodos(A.maxNodos),
                                        numNodos(A.numNodos)
{
    // copiar el vector
    for (nodo n = 0; n < numNodos; n++)
        nodos[n] = A.nodos[n];
}

template <typename T>
ApoMax<T> &ApoMax<T>::operator=(const ApoMax<T> &A)
{
    if (this != &A)
    { // evitar autoasignaci�n
        // Destruir el vector y crear uno nuevo si es necesario
        if (maxNodos != A.maxNodos)
        {
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new T[maxNodos];
        }
        numNodos = A.numNodos;
        // Copiar el vector
        for (nodo n = 0; n < numNodos; n++)
            nodos[n] = A.nodos[n];
    }
    return *this;
}

// M�todos privados

template <typename T>
void ApoMax<T>::flotar(nodo i)
{
    T e = nodos[i];
    while (i > 0 && nodos[padre(i)] < e)
    {
        nodos[i] = nodos[padre(i)];
        i = padre(i);
    }
    nodos[i] = e; // colocar e
}

template <typename T>
void ApoMax<T>::hundir(nodo i)
{
    bool fin = false;
    T e = nodos[i];
    while (hIzq(i) < numNodos && !fin)
    {              // hundir e
        nodo hMin; // hijo menor del nodo i
        if (hDer(i) < numNodos && nodos[hIzq(i)] < nodos[hDer(i)])
            hMin = hDer(i);
        else
            hMin = hIzq(i);
        if (e < nodos[hMin])
        { // subir el hijo menor
            nodos[i] = nodos[hMin];
            i = hMin;
        }
        else // e <= hMin
            fin = true;
    }
    nodos[i] = e; // colocar e
}

#endif // APO_H