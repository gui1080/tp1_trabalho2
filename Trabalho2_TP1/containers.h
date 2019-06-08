#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

class ContainerUsuario{

private:

    // Refer�ncia para o container.

    list<Usuario> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    ResultadoUsuario incluir(Usuario);
    ResultadoUsuario remover(CPF);
    ResultadoUsuario pesquisar(CPF);
};

class ContainerEvento{

private:

    // Refer�ncia para o container.

    list<Evento> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    ResultadoEvento incluir(Evento);
    // (a fazer:) // ResultadoEvento remover(Codigo_de_Evento);
    //ResultadoEvento pesquisar(Codigo_de_Evento);
    bool mostrar();
};


#endif // CONTAINERS_H_INCLUD
