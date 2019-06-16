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
    Usuario Tela_login() throw(runtime_error);
    void setCntrISAutenticacao(ISAutenticacao *);
    bool executar_autenticacao(CPF cpf) throw(runtime_error);
};

void inline CntrIUAutenticacao::setCntrISAutenticacao(ISAutenticacao *cntrISAutenticacao) {
    this->cntrISAutenticacao = cntrISAutenticacao;
}

class CntrISAutenticacao : public ISAutenticacao{

  public:
    bool Autenticar(ContainerUsuario *container_usuario, Usuario usuario) throw(runtime_error);
    Usuario Mostrar_Menu(ContainerUsuario *container_u, ContainerCartao_de_credito *container_c, Usuario usuario, Cartao_de_credito cartao_de_credito, ContainerEvento container_e, ContainerApresentacoes container_ap);
};

class CntrIUUsuario : public IUUsuario{

  private:
    ISUsuario *cntrISUsuario;

  public:

    void setCntrISUsuario(ISUsuario *);

    void Menu_Logado(Usuario usuario, ContainerUsuario *container_u, ContainerCartao_de_credito *container_c, ContainerEvento *container_e);
    Usuario Criar_usuario() throw(runtime_error);
    Cartao_de_credito Criar_cartao_de_credito(Usuario usuario) throw(runtime_error);
    Evento Menu_Criar_Evento(Usuario usuario) throw(runtime_error);
    Apresentacao Menu_Criar_Apresentacao(Evento evento) throw(runtime_error);
    Usuario Menu_Edicao_usuario();
    Evento  Menu_Edicao_evento();
    Apresentacao Menu_Edicao_apresentacao();

};

class CntrISUsuario : public ISUsuario{

  public:
    bool Cadastrar(ContainerUsuario *container_u, ContainerCartao_de_credito *container_c, Usuario usuario, Cartao_de_credito cartao_de_credito) throw(runtime_error);
    bool Cadastrar_Evento(ContainerEvento *container_e, Evento evento);

};

void inline CntrIUUsuario::setCntrISUsuario(ISUsuario *cntrISUsuario) {
    this->cntrISUsuario = cntrISUsuario;
}

#endif
