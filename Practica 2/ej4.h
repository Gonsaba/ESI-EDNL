#ifndef EJ4_H_
#define EJ4_H_

#include "abin.h"

void construirArbolv2Rec(Abin<char> &A,typename Abin<char>::nodo n,std::string s,int inicio,int fin){
	int mitad = ((fin-inicio)/2)+inicio;
	int mitadizq = (((mitad-1)-inicio)/2)+inicio;
	int mitadder = ((fin-(mitad+1))/2)+(mitad+1);
	if(s[mitadizq] != '-' && inicio < fin){
		A.insertarHijoIzqdo(n,s[mitadizq]);
		construirArbolv2Rec(A,A.hijoIzqdo(n),s,inicio,mitad-1);
	}
	if(s[mitadder] != '-' && inicio < fin){
		A.insertarHijoDrcho(n,s[mitadder]);
		construirArbolv2Rec(A,A.hijoDrcho(n),s,mitad+1,fin);
	}
}

Abin<char> construirArbolv2(std::string s){
	Abin<char> A;
	A.insertarRaiz(s[s.size()/2]);
	construirArbolv2Rec(A,A.raiz(),s,0,s.size());
	return A;
}

#endif