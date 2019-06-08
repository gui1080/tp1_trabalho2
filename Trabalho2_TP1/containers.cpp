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

       elemento->getUsuario(&cpf_aux, &senha_aux);
       resultado_cpf_incluir = cpf_aux.getCPF();

        if (resultado_cpf_incluir == chave){
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

       elemento->getUsuario(&cpf_aux, &senha_aux);
       resultado_cpf_remover = cpf_aux.getCPF();

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

    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getUsuario(&teste_cpf, &teste_senha);
           resultado_cpf = teste_cpf.getCPF();

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


//////////////////////////////////////////EVENTOS/////////////////////////////////////////////////////////////

ResultadoEvento ContainerEvento::incluir(Evento evento){

    ResultadoEvento resultado;

    //CPF cpf_aux;
    //Senha senha_aux;
    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;

    int resultado_cod_evento_incluir;

    // a chave vai ser o cpf

    evento.getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux);

    int chave = codigo_de_evento_aux.getCodigo_de_Evento();
    //cout << "chave eh: " << chave << "\n";

    // Procurar o elemento.

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

       elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux);
       resultado_cod_evento_incluir = codigo_de_evento_aux.getCodigo_de_Evento();

        if (resultado_cod_evento_incluir == chave){
            // Elemento localizado.

            resultado.setValor(Resultado::FALHA);
            cout << "evento ja cadastrado" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(evento);
    resultado.setValor(Resultado::SUCESSO);
    cout << "evento cadastrado com sucesso" << "\n\n";
    return resultado;

}

bool ContainerEvento::mostrar(){

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;

    int cod_evento_mostrar;
    string nome_evento_mostrar;
    string cidade_mostrar;
    string estados_br_mostrar;
    int classe_de_evento_mostrar;
    string faixa_etaria_mostrar;

    // ver os elementos.
    cout << "Eventos disponiveis:\n" <<endl;

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux);

        cod_evento_mostrar = codigo_de_evento_aux.getCodigo_de_Evento();
        nome_evento_mostrar = nome_de_evento_aux.getNome_de_Evento();
        cidade_mostrar = cidade_aux.getCidade();
        estados_br_mostrar = estados_br_aux.getEstado();
        classe_de_evento_mostrar = classe_de_evento_aux.getClasse_Evento();
        faixa_etaria_mostrar = faixa_etaria_aux.getFaixa_Etaria();

        cout << "Codigo de Evento: ";
        cout << cod_evento_mostrar << endl;
        cout << "Nome do Evento: ";
        cout << nome_evento_mostrar <<endl;
        cout << "Cidade: ";
        cout << cidade_mostrar << endl;
        cout << "Estado Brasileiro onde ocorre o Evento: ";
        cout << estados_br_mostrar << endl;
        cout << "Classe de Evento: ";
        cout << classe_de_evento_mostrar <<endl;
        cout << "Faixa Estaria: ";
        cout << faixa_etaria_mostrar << endl;
        cout << "\n" << endl;
    }


    return true;

}
