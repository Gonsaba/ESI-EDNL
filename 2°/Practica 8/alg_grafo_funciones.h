#ifndef ALG_GRAFO_FUNCIONES
#define ALG_GRAFO_FUNCIONES
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"

template <typename T>
void printMatrix(matriz<T> m)
{
    for (int i = 0; i < m.dimension(); i++)
    {
        for (int j = 0; j < m.dimension(); j++)
            if (m[i][j] < 100000)
                std::cout << m[i][j] << " ";
            else
                std::cout << "-" << " ";
        std::cout << std::endl;
    }
}

template <typename T>
void printGrafo(GrafoP<T> G)
{
    for (int i = 0; i < G.numVert(); i++)
    {
        for (int j = 0; j < G.numVert(); j++)
            if (G[i][j] < 100000)
                std::cout << G[i][j] << " ";
            else
                std::cout << "-" << " ";
        std::cout << std::endl;
    }
}

void printGrafoA(Grafo G)
{
    for (int i = 0; i < G.numVert(); i++)
    {
        for (int j = 0; j < G.numVert(); j++)
            std::cout << std::boolalpha << G[i][j] << " ";
        std::cout << std::endl;
    }
}

template <typename T>
void printVector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void printParticion(Particion p, int n)
{
    for (size_t i = 0; i < n; i++)
        std::cout << p.encontrar(i) << " - " << i << std::endl;
    std::cout << std::endl;
}

#endif