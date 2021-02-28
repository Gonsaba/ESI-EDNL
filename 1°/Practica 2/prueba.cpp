#include <cassert>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

int max(int a,int b)
{
	return (a<b)?b:a;
}

int recprofundidad(char *a,int nNodos,char nodo,int altmax,int indice,int profundidadHijos)
{
	if(indice >= nNodos || profundidadHijos > altmax || a[indice] == '-')
	{
		
		return -1;
	}
	else if(a[indice] == nodo)
	{
		
		return profundidadHijos;
	}
	else
	{
		
		++profundidadHijos;
		int aux = (nNodos+1)/pow(2,profundidadHijos + 1);
		return max(recprofundidad(a,nNodos,nodo,altmax,indice - aux,profundidadHijos)
			,recprofundidad(a,nNodos,nodo,altmax,indice + aux,profundidadHijos));
	}
}

int profundidad(char *a,int nNodos,char nodo,int altmax)
{
	int raiz = (nNodos-1)/2;
	if(a[raiz] == '-')
	{
		return 0;
	}
	else if(a[raiz] == nodo)
	{
		return 0;
	}
	else
	{
		int aux = (nNodos+1)/4;
	
		return max(recprofundidad(a,nNodos,nodo,altmax,raiz - aux,1)
			,recprofundidad(a,nNodos,nodo,altmax,raiz + aux,1));
	}
}

int main()
{
	std::cout<<"Pruebas Jezusito"<<std::endl;
	char a[32] = {'-','-','-','n','-','-','-','a','f','l','-','b','-','d','-','h','-','-','-','-','-','-','-','m','-','c','-','j','-','-','-'};
	for(int i = 0; i < 32 ; ++i)
		if(a[i] != '-')
			std::cout<<"profundidad de "<<a[i]<<": "<<profundidad(a,31,a[i],4)<<std::endl;
}