#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declaracao adiantada.

/*

class ILNGerente;

class IUGerente {
public:

    // solicita servico.

    virtual void executar(const Matricula&) = 0;

    // link com controladora de negocio.

    virtual void setCntrLNGerente(ILNGerente *) = 0;

    // Destrutor virtual.

    virtual ~IUGerente(){}

};

// Declaracao de interface da camada de negocio
// ------------------------------------------------------------------

class ILNGerente {
public:

    // Metodos por meio dos quais sao solicitados servicos.

    virtual Resultado criar_user(const Gerente&) throw(runtime_error) = 0;
    virtual Resultado login(const Matricula&) throw(runtime_error) = 0;
    virtual ResultadoGerente ver_eventos(const Matricula&) throw(runtime_error) = 0;

    // Destrutor virtual.

    virtual ~ILNGerente(){}
};

*/

#endif // INTERFACES_H_INCLUDED
