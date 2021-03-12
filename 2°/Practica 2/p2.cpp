#include "abin.h"
#include "abin_E-S.h"
#include "string"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "cmath"

typedef char T;
typedef std::string M;

void ej1() {
    Abin<T> A, B;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();

    std::ifstream fe2("abin2.dat");
    rellenarAbin(fe2, B);
    fe2.close();
    std::cout << "Iguales: " << std::boolalpha << abinIgual(A, A) << std::endl;
}

void ej2() {
    Abin<T> A;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();

    imprimirAbin(A);
    imprimirAbin(abinRef(A));
}

void ej3() {
    Abin<M> A;
    std::ifstream fe("abinMath.dat");
    rellenarAbin(fe, A);
    fe.close();

    imprimirAbin(A);
    std::cout<< "Res: " << abinMathRes(A) << std::endl;
}

void printVec(char *A, int N)
{
    for (int i = 0; i < N; ++i)
        std::cout<< A[i] << ", ";
    std::cout << std::endl;
}

int main()
{
    // ej1();
    // ej2();
    // ej3();
}