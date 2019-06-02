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
    ResultadoUsuario remover(Senha);
    ResultadoUsuario pesquisar(Senha);
};

#endif // CONTAINERS_H_INCLUDED
