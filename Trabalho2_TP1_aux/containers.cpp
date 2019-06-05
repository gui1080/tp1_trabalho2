#include "containers.h"
/* fazer classe resultado em um novo arquivo
*/

ResultadoUsuario ContainerUsuario::incluir(Usuario usuario){

    ResultadoUsuario resultado;
    CPF cpf_aux;
    Senha senha_aux;
    long long int resultado_cpf_incluir;

    // a chave vai ser o cpf

    usuario.getUsuario(&cpf_aux, &senha_aux);
    long long int chave = cpf_aux.getCPF();
    //cout << "chave eh: " << chave << "\n";

    // Procurar o elemento.

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

       cout << "entrou" << "\n\n\n\n\n\n\n";
       elemento->getUsuario(&cpf_aux, &senha_aux);
       resultado_cpf_incluir = cpf_aux.getCPF();

       cout << "resultado cpf eh:>" << resultado_cpf_incluir << "\n";

        if (resultado_cpf_incluir == chave){
                cout << "resultado_cpf_incluir> " << resultado_cpf_incluir << "  chave> " << chave << "\n";
            // Elemento localizado.

            resultado.setValor(Resultado::FALHA);
            cout << "usuario ja cadastrado" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(usuario);
    resultado.setValor(Resultado::SUCESSO);
    cout << "usuario cadastrado com sucesso" << "\n\n";
    return resultado;

}


ResultadoUsuario ContainerUsuario::remover(CPF cpf){

    // Procurar e remover um elemento.

    ResultadoUsuario resultado;

    CPF cpf_aux;
    Senha senha_aux;
    long long int resultado_cpf_remover;

    resultado.setValor(Resultado::FALHA);

    long long int chave = cpf.getCPF();

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){


       cout << "entrou" << "\n\n\n\n\n\n\n";
       elemento->getUsuario(&cpf_aux, &senha_aux);
       resultado_cpf_remover = cpf_aux.getCPF();

       cout << "resultado cpf eh:>" << resultado_cpf_remover << "\n";

        if (resultado_cpf_remover == chave){
            // Elemento localizado.

            container.erase(elemento);
            resultado.setValor(Resultado::SUCESSO);
        }
    }

    return resultado;
}

ResultadoUsuario ContainerUsuario::pesquisar(CPF cpf){

    // Procurar elemento.

    ResultadoUsuario resultado;
    CPF teste_cpf;
    Senha teste_senha;
    long long int resultado_cpf;

    resultado.setValor(Resultado::FALHA);

    long long int chave = cpf.getCPF();
    cout << "chave eh:" << chave;
    cout << "\n";

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getUsuario(&teste_cpf, &teste_senha);
           resultado_cpf = teste_cpf.getCPF();

           cout << "resultado cpf>" << resultado_cpf << "\n";

        if (resultado_cpf == chave){

            // Elemento localizado.

            resultado.setUsuario(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            cout << "usuario encontrado";
            cout << "\n";
            return resultado;
        }
    }

    cout << "usuario nao encontrado";
    cout << "\n";
    return resultado;
}
