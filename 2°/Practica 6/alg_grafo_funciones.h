#ifndef ALG_GRAFO_FUNCIONES
#define ALG_GRAFO_FUNCIONES
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"

template <typename T>
void printMatrix(matriz<T> m)
{
    for (int i = 0; i < m.dimension(); i++)
    {
        for (int j = 0; j < m.dimension(); j++)
            if (m[i][j] < 100000)
                std::cout << m[i][j] << " ";
            else
                std::cout << "inf" << " ";
        std::cout << std::endl;
    }
}

#endif