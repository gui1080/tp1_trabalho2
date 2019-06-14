#ifndef CONTROLADORAS_H
#define CONTROLADORAS_H

#include "interfaces.h"
#include "dominios.h"

using namespace std;

class CntrGeral{

  private:
    IUAutenticacao *cntrIUAutenticacao;
    IUUsuario *cntrIUUsuario;
    IUEventos *cntrIUEventos;
    IUVendas *cntrIUVendas;

  public:
    void setCntrIUAutenticacao(IUAutenticacao *);
    void setCntrIUUsuario(IUUsuario *);
    void setCntrIUEventos(IUEventos *);
    void setCntrIUVendas(IUVendas *);
};

void inline CntrGeral::setCntrIUAutenticacao(IUAutenticacao *cntrIUAutenticacao) {
    this->cntrIUAutenticacao = cntrIUAutenticacao;
}

void inline CntrGeral::setCntrIUEventos(IUEventos *cntrIUEventos) {
    this->cntrIUEventos = cntrIUEventos;
}

void inline CntrGeral::setCntrIUUsuario(IUUsuario *cntrIUUsuario) {
    this->cntrIUUsuario = cntrIUUsuario;
}

void inline CntrGeral::setCntrIUVendas(IUVendas *cntrIUVendas) {
    this->cntrIUVendas = cntrIUVendas;
}

class CntrIUAutenticacao : public IUAutenticacao{

  private:
    ISAutenticacao *cntrISAutenticacao;

  public:
    void setCntrISAutenticacao(ISAutenticacao *);
    bool executar_autenticacao(CPF cpf) throw(runtime_error);
};

void inline CntrIUAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao) {
    this->cntrISAutenticacao = cntrISAutenticacao;
}

class CntrISAutenticacao : public ISAutenticacao{

  public:
    bool Autenticar(ContainerUsuario container_susuario, Usuario usuario) throw(runtime_error);
    void Mostrar_Menu();
};

class CntrIUUsuario : public IUUsuario{

  private:
    ISUsuario *cntrISUsuario;

  public:

    void setCntrISUsuario(ISUsuario *);

    Usuario Criar_usuario() throw(runtime_error);
    Usuario Menu_Edicao_usuario();
    Evento  Menu_Edicao_evento();
    Apresentacao Menu_Edicao_apresentacao();

};

void inline CntrIUUsuario::setCntrISUsuario(ISUsuario *cntrISUsuario) {
    this->cntrISUsuario = cntrISUsuario;
}

#endif
