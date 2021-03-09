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
    std::cout << "Iguales: " << std::boolalpha << abinIgual(A, B) << std::endl;
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

void printVec(char *abin, int nodosMax)
{
    for (int i = 0; i < nodosMax; ++i)
        std::cout<< abin[i] << ", ";
    std::cout << std::endl;
}

void raiz(char* abin, int nodosMax) {
    std::cout << abin[nodosMax / 2] << std::endl;
}

int hijoIzqdo(char* abin, int nodosMax, int n) {
    int i = (n - (nodosMax + 1) / std::pow(2, 0 + 2));
    std::cout << abin[i];
    return i;
}

int hijoDrcho(char* abin, int nodosMax, int n) {
    int i = (n + (nodosMax + 1) / std::pow(2, 0 + 2));
    std::cout << abin[i];
    return i;
}

void ej4() {
    int n = 31;
    char abin[] = { '-', '-', '-', 'n', '-', '-', '-', 'a', 'f', 'l', '-', 'b',
                    '-', 'd', '-', 'h', '-', '-', '-', '-', '-', '-', '-', 'm',
                    '-', 'c', '-', 'j', '-', '-', '-'};
    printVec(abin, n);
    raiz(abin, n);
    hijoIzqdo(abin, n, n / 2);
    hijoDrcho(abin, n, n / 2);
}

int main()
{
    // ej1();
    ej2();
    // ej3();
    // ej4();
}