#include "abin.h"
#include "abin_E-S.h"
#include "preordIter.h"
#include "anchura.h"

typedef char T;

int main() {
    Abin<T> A, B;
    std::ifstream fe("abin.dat");
    rellenarAbin(fe, A);
    fe.close();

    // preordIter(A);
    anchura(A);
}