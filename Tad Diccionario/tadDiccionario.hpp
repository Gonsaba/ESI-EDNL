#include <utility>
#include <string>
#include <iostream>
#include "abb.h"

#ifndef DICCIONARIO_HPP_
#define DICCIONARIO_HPP_

class Diccionario
{
public:
    typedef std::pair<std::string,std::string> Par;
    Diccionario();
    void insertar(std::string esp, std::string zeu);
    void eliminar(std::string esp);
    std::string buscar(std::string zeu) const;
    void listar() const;
    friend bool operator ==(const Par& a,const Par& b);
    friend bool operator <(const Par& a,const Par& b);
private:
    Abb<Par> diccionario_;
    void listarRec(const Abb<Par>& subDic) const;
    std::string buscarRec(std::string zeu, const Abb<Par>& subDic) const;
};

#endif