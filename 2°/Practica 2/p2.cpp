#include "abin.h"
#include "abin_E-S.h"
#include "string"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"

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

int main() {
    ej1();
    ej2();
    ej3();
}