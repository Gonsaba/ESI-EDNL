#include "abin.h"
#include "abin_E-S.h"
#include "ej1.h"
#include "ej2.h"

typedef char T;

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

int main() {
    ej1();
    ej2();
}