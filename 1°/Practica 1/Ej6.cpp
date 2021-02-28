#include <iostream>
#include <fstream> 
#include "abin.h"
#include "abin_E-S.h"
typedef char T;

int max3(int a,int b,int c)
{
	int res = a;
	if(res < b) 
		res = b;
	if(res < c)
		res = c;
	return res;
}

int desequilibrioAbinRec(Abin<T> A,typename Abin<T>::nodo n)
{
	if(n == Abin<T>::NODO_NULO){
		return 0;
	}
	else{
		return max3(A.altura(A.hijoIzqdo(n)) - A.altura(A.hijoDrcho(n)),desequilibrioAbinRec(A,A.hijoIzqdo(n)),desequilibrioAbinRec(A,A.hijoDrcho(n)));
	}
}

int desequilibrioAbin(const Abin<T> A)
{
	return desequilibrioAbinRec(A,A.raiz());
}

int main()
{
	Abin<T> A;
	std::ifstream fe("abin.dat");
	rellenarAbin(fe,A);
	fe.close();
	std::cout<<desequilibrioAbin(A);
}
