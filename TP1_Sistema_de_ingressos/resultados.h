#ifndef RESULTADOS_H_INCLUDED
#define RESULTADOS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

using namespace std;

// -------------------------------------------ENTIDADE DE RESULTADO---------------------------------


class Resultado {                                 //classe abstrata

protected:
    int valor;

public:

    const static int SUCESSO = 0;
    const static int FALHA   = 1;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};

class ResultadoUsuario:public Resultado {

private:
    Usuario usuario;

public:
    void setUsuario(const Usuario &usuario){
        this->usuario = usuario;
    }

    Usuario getUsuario() const {
        return usuario;
    }
};

class ResultadoCartao_de_credito:public Resultado {

private:
    Cartao_de_credito cartao_de_credito;

public:

    void setCartao_de_credito(const Cartao_de_credito &cartao){
        this->cartao_de_credito = cartao_de_credito;
    }

    Cartao_de_credito getCartao_de_credito() const {
        return cartao_de_credito;
        }
};

class ResultadoEvento:public Resultado {

private:
    Evento evento;

public:
    void setEvento(const Evento &evento){
        this->evento = evento;
    }

    Evento getEvento() const {
        return evento;
    }
};

class ResultadoApresentacao:public Resultado {

private:
    Apresentacao apresentacao;

public:
    void setApresentacao(const Apresentacao &apresentacao){
        this->apresentacao = apresentacao;
    }

    Apresentacao getApresentacao() const {
        return apresentacao;
    }
};

class ResultadoIngresso:public Resultado {

private:
    Ingresso ingresso;

public:
    void setIngresso(const Ingresso &ingresso){
        this->ingresso = ingresso;
    }

    Ingresso getIngresso() const {
        return ingresso;
    }
};


#endif // RESULTADOS_H_INCLUDED
