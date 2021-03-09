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

int profNodo(char *A, int N, int n)
{
    int profindidad = 0;
    int inicio = 0, fin = N - 1;
    int medio = (fin - inicio) / 2;
    while(medio >= 0 && medio != n){
        if(medio < n)
            inicio = medio + 1;
        else                    
            fin = medio - 1;

        medio = (fin - inicio) / 2;
        ++profindidad;
    }
    return profindidad;
}

int raiz(char *A, int N)
{
    std::cout << A[N / 2] << std::endl;
    return (N - 1) / 2;
}

int hijoIzqdo(char *A, int N, int n)
{
    int i = (n - (N + 1) / std::pow(2, profNodo(A, N, n) + 2));
    std::cout << A[i] << std::endl;
    return i;
}

int hijoDrcho(char *A, int N, int n)
{
    int i = (n + (N + 1) / std::pow(2, profNodo(A, N, n) + 2));
    std::cout << A[i] << std::endl;
    return i;
}

void insertarRaizB(char *A, int N, char e)
{
    A[(N - 1) / 2] = e;
}

void insertarHijoIzqdo(char *A, int N, int n, char e)
{
    int i = n - ((N + 1) / 
    std::pow(2, profNodo(A, N, n) + 2));
    std::cout << i << std::endl;
    A[i] = e;
}

void insertarHijoDrcho(char *A, int N, int n, char e)
{
    int i = n + ((N + 1) / 
    std::pow(2, profNodo(A, N, n) + 2));
    std::cout << i << std::endl;
    A[i] = e;
}

int padre(char *A, int N, int n)
{
    if(n)
}

void ej4() {
    int N = 31;
    char A[] = { '-', '-', '-', 'n', '-', '-', '-', 'a', 'f', 'l',
                    '-', 'b', '-', 'd', '-', 'h', '-', '-', '-', '-',
                    '-', '-', '-', 'm', '-', 'c', '-', 'j', '-', '-', '-'};
    hijoIzqdo(A, N, hijoIzqdo(A, N, raiz(A, N)));
    insertarRaizB(A, N, 'p');
    insertarHijoIzqdo(A, N, raiz(A, N), 'x');
    insertarHijoDrcho(A, N, raiz(A, N), 'x');
    printVec(A, N);
    // raiz(abin, n);
    // hijoIzqdo(abin, n, n / 2);
    // hijoDrcho(abin, n, n / 2);
    // std::cout << profNodo(abin, 3, n) << std::endl; 
}

int main()
{
    // ej1();
    // ej2();
    // ej3();
    ej4();
}