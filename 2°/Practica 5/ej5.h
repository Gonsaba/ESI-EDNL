#ifndef EJ5_H_
#define EJ5_H_
#include<math.h>
#include "agen.h"

struct coordenada
{
    int x, y;
};

template <typename T>
int altura(typename Agen<T>::nodo n, Agen<T> A)
{
    typename Agen<T>::nodo hijo;
    int max, alt;
    hijo = A.hijoIzqdo(n);
    if (hijo != Agen<T>::NODO_NULO)
    {
        max = 1 + altura(hijo, A);
        hijo = A.hermDrcho(hijo);
        while (hijo != Agen<T>::NODO_NULO)
        {
            alt = 1 + altura(hijo, A);
            if (max < alt)
                max = alt;
            hijo = A.hermDrcho(hijo);
        }
        return max;
    }
}

void pintar(char **m, coordenada c1, coordenada c2, char color)
{
    for(int i = c1.x; i <= c2.x; ++i)
        for(int j = c1.y; j <= c2.y; ++j)
            m[i][j] = color;
}

template <typename T>
void agenAMatrizRec(typename Agen<T>::nodo n, Agen<T> A,
                    coordenada c1, coordenada c2, int altArbol, int prof, char **Figura)
{
    typename Agen<T>::nodo hijo;
    int longCuadrante;

    if (A.elemento(n) == 'N' || A.elemento(n) == '-') //- es igual a B
        pintar(m, c1, c2, A.elemento(n));
    else
    {
        longCuadrante = std::pow(2, altArbol - (prof + 1));
        
        hijo = A.hijoIzqdo(n);
        agenAMatrizRec(hijo, A, coordenada(c1.x, c1.y),
            coordenada(c1.x + longCuadrante - 1, c1.y + longCuadrante - 1), altArbol, prof + 1, Figura);

        hijo = A.hermDrcho(hijo);
        agenAMatrizRec(hijo, A, coordenada(c1.x, c1.y + longCuadrante),
            coordenada(c1.x + longCuadrante - 1, c2.y), altArbol, prof + 1, Figura);

        hijo = A.hermDrcho(hijo);
        agenAMatrizRec(hijo, A, coordenada(c1.x + longCuadrante, c1.y + longCuadrante),
            coordenada(c2.x, c2.y), altArbol, prof + 1, Figura);

        hijo = A.hermDrcho(hijo);
        agenAMatrizRec(hijo, A, coordenada(c1.x + longCuadrante, c1.y),
            coordenada(c2.x, c1.y + longCuadrante - 1), altArbol, prof + 1, Figura);
    }
}

template <typename T>
char **agenAMatriz(Agen<T> A)
{
    int alt;
    int n;
    char **Figura;

    alt = altura(A.raiz(), A);
    n = std::pow(2, alt, A));
    Figura = new char *[n];

    for (int i = 0; i < n; ++i)
        Figura[i] = new char[n];

    agenAMatrizRec(A.raiz(), A, coordenada(0, 0), coordenada(n - 1, n - 1), alt, 0, Figura);
    //Cambiar a enteros
    return Figura;
}

#endif