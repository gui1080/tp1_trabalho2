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

class ContainerCartao_de_credito{

private:

    // Refer�ncia para o container.

    list<Cartao_de_credito> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    ResultadoCartao_de_credito incluir(Cartao_de_credito);
    ResultadoCartao_de_credito remover(Cartao_de_credito);
    ResultadoCartao_de_credito pesquisar(CPF);
};

class ContainerEvento{

private:

    // Refer�ncia para o container.

    list<Evento> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    bool incluir(Evento);
    bool remover(Codigo_de_Evento);
    bool pesquisar(Codigo_de_Evento);
    ResultadoEvento pesquisar_Evento(Codigo_de_Evento);
    bool achar_evento_em_cidade(Cidade);
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
    void remover_ap_usuario(Codigo_de_Evento);
    Apresentacao pesquisar(Data);
    ResultadoApresentacao pesquisar_Cod(Codigo_de_Apresentacao);
    bool mostrar();
};
/*
class Container_Apresentacoes: public Apresentacao{

private:

    // Refer�ncia para o container.
    Apresentacao apresentacao;

    list<Ingressos_CPF> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    //Apresentacao apresentacao;
    bool incluir(Ingressos_CPF);
    bool remover(Ingressos_CPF);
    Ingressos_CPF pesquisar(Codigo_de_Ingresso ingresso);
    bool mostrar();
    void setApresentacao(int novo_codigo, string novo_data, string novo_horario, float novo_preco,
                int novo_sala, int novo_disponibilidade, int novo_codigo_de_evento) throw (invalid_argument);
    void getApresentacao(Codigo_de_Apresentacao *codigo_f, Data *data_f, Horario *horario_f, Preco *preco_f,
                   Numero_de_Sala *sala_f, Disponibilidade *disponibilidade_f, Codigo_de_Evento *codigo_de_evento_f);

};
*/
class ContainerIngresso{

private:

    // Refer�ncia para o container.

    list<Ingresso> container;

public:

    // Metodos por meio dos quais sao solicitados os servicos.

    ResultadoIngresso incluir(Ingresso);
    ResultadoIngresso remover(Ingresso);
    ResultadoIngresso pesquisar(Codigo_de_Ingresso);
    ResultadoIngresso pesquisar_CPF(CPF);
    void Mostrar_Compras_Usuario(CPF);
    void Mostrar_Vendas_Usuario(CPF);
};

#endif // CONTAINERS_H_INCLUD
