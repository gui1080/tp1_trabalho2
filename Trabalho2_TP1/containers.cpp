#include "containers.h"
/* fazer classe resultado em um novo arquivo
*/

ResultadoUsuario ContainerUsuario::incluir(Usuario usuario){

    ResultadoUsuario resultado;

    // a chave vai ser a senha

    int chave = 0;
    chave = usuario.getSenha().getValor();

    // Procurar o elemento.

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        if (elemento->getSenha().getValor() == chave){

            // Elemento localizado.

            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(usuario);
    resultado.setValor(Resultado::SUCESSO);
    return resultado;
}


ResultadoUsuario ContainerUsuario::remover(Senha senha){

    // Procurar e remover um elemento.

    ResultadoUsuario resultado;
    resultado.setValor(Resultado::FALHA);

    int chave = senha.getValor();

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        if (elemento->getSenha().getValor() == chave){

            // Elemento localizado.

            container.erase(elemento);
            resultado.setValor(Resultado::SUCESSO);
        }
    }

    return resultado;
}

ResultadoUsuario ContainerUsuario::pesquisar(Senha senha){

    // Procurar elemento.

    ResultadoUsuario resultado;
    resultado.setValor(Resultado::FALHA);

    int chave = senha.getValor();

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        if (elemento->getSenha().getValor() == chave){

            // Elemento localizado.

            resultado.setUsuario(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
    }

    return resultado;
}



