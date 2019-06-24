#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "containers.h"
#include <list>

using namespace std;

class IUAutenticacao;
class ISAutenticacao;
class IUUsuario;
class ISUsuario;
class IUEventos;
class ISEventos;
class IUVendas;
class ISVendas;

class IUAutenticacao {
public:

    virtual bool executar_autenticacao(CPF cpf) throw(runtime_error) = 0;

    virtual void setCntrISAutenticacao(ISAutenticacao *) = 0;

    virtual ~IUAutenticacao(){}
};

class ISAutenticacao {
public:

    virtual ~ISAutenticacao(){}
};

class IUUsuario {
public:

    virtual void setCntrISUsuario(ISUsuario *) = 0;

    virtual ~IUUsuario(){}
};

class ISUsuario {
public:

    virtual ~ISUsuario(){}
};

class IUEventos {
public:

    virtual Evento Criar_evento() throw(runtime_error) = 0;

    virtual void setCntrISEventos(ISEventos *) = 0;

    virtual ~IUEventos(){}
};

class ISEventos {
public:

    virtual Mostrar_eventos(ContainerEvento) throw(runtime_error) = 0;
};

class IUVendas {
public:

    virtual void setCntrISVendas(ISVendas *) = 0;

    virtual ~IUVendas(){}
};

class ISVendas {
public:

    virtual ~ISVendas(){}
};
#endif // INTERFACES_H_INCLUDED
