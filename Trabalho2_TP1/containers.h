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

class ContainerApresentacoes{

private:

    // Refer�ncia para o container.


    list<Apresentacao> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    bool incluir(Apresentacao);
    bool remover(Apresentacao);
    Apresentacao pesquisar(Data);
    bool mostrar();
};

class Container_Apresentacoes: public Apresentacao{

private:

    // Refer�ncia para o container.
    //Apresentacao apresentacao;

    list<Ingressos_CPF> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    Apresentacao apresentacao;
    bool incluir(Ingressos_CPF);
    bool remover(Ingressos_CPF);
    Ingressos_CPF pesquisar(Codigo_de_Ingresso ingresso);
    bool mostrar();
};


#endif // CONTAINERS_H_INCLUD
