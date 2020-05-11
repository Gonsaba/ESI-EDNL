#include "tadDiccionario.hpp"

Diccionario::Diccionario(){}

void Diccionario::insertar(std::string esp, std::string zeu)
{
    diccionario_.insertar(Par(esp,zeu));
}

void Diccionario::listar() const
{
    if(!diccionario_.vacio())
    {
        listarRec(diccionario_.izqdo());
        std::cout<<diccionario_.elemento().first<<" - "<<diccionario_.elemento().second<<std::endl;
        listarRec(diccionario_.drcho());
    }
}

void Diccionario::listarRec(const Abb<Par>& subDic) const
{
    if(!subDic.vacio())
    {
        listarRec(subDic.izqdo());
        std::cout<<subDic.elemento().first<<" - "<<subDic.elemento().second<<std::endl;
        listarRec(subDic.drcho());
    }
}

bool operator ==(const Diccionario::Par& a,const Diccionario::Par& b)
{
    return a.first == b.first;
}

bool operator <(const Diccionario::Par& a,const Diccionario::Par& b)
{
    return a.first < b.first;
}

void Diccionario::eliminar(std::string esp)
{
    std::pair<std::string,std::string> p (esp,"");
    diccionario_.eliminar(p);
}

std::string Diccionario::buscar(std::string zeu) const
{
    std::string a,b;
    if(diccionario_.vacio())
        return "";
    else if(diccionario_.elemento().second == zeu)
        return diccionario_.elemento().first;
    else
    {
        a = buscarRec(zeu,diccionario_.izqdo());
        b = buscarRec(zeu,diccionario_.izqdo());
        if(a != "")
            return a;
        else if(b != "")
            return b;
    }

}

std::string Diccionario::buscarRec(std::string zeu, const Abb<Par>& subDic) const
{
    std::string a,b;
    if(subDic.vacio())
        return "";
    else if(diccionario_.elemento().second == zeu)
        return diccionario_.elemento().first;
    else
    {
        a = buscarRec(zeu,diccionario_.izqdo());
        b = buscarRec(zeu,diccionario_.izqdo());
        if(a != "")
            return a;
        else if(b != "")
            return b;
    }
}