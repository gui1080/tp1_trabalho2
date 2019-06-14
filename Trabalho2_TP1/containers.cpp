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
///////////////////////////////////// CARTAO DE CREDITO /////////////////////////////////////////////////////

ResultadoCartao_de_credito ContainerCartao_de_credito::incluir(Cartao_de_credito cartao_de_credito){

    ResultadoCartao_de_credito resultado;
    CPF cpf_aux;
    Numero_Cartao_Credito numero_aux;
    Codigo_de_Seguranca_Cartao_Credito codigo_aux;
    Data_Validade_Cartao_Credito data_aux;

    long long int resultado_cpf;

    resultado.setValor(Resultado::FALHA);
    cartao_de_credito.getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);

    long long int chave = cpf_aux.getCPF();

    for(list<Cartao_de_credito>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);
           resultado_cpf = cpf_aux.getCPF();

        if (resultado_cpf == chave){

            // Elemento localizado.

            resultado.setValor(Resultado::FALHA);
            cout << "cartao de credito ja cadastrado" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(cartao_de_credito);
    resultado.setValor(Resultado::SUCESSO);
    cout << "cartao de credito cadastrado com sucesso" << "\n\n";
    return resultado;

}

ResultadoCartao_de_credito ContainerCartao_de_credito::pesquisar(CPF cpf){

    // Procurar elemento.

    ResultadoCartao_de_credito resultado;
    CPF cpf_aux;
    Numero_Cartao_Credito numero_aux;
    Codigo_de_Seguranca_Cartao_Credito codigo_aux;
    Data_Validade_Cartao_Credito data_aux;

    long long int resultado_cpf;

    resultado.setValor(Resultado::FALHA);

    long long int chave = cpf.getCPF();

    for(list<Cartao_de_credito>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);
           resultado_cpf = cpf_aux.getCPF();

        if (resultado_cpf == chave){

            // Elemento localizado.

            resultado.setCartao_de_credito(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            cout << "cartao encontrado encontrado";
            cout << "\n";
            return resultado;
        }
    }

    cout << "cartao nao encontrado";
    cout << "\n";
    return resultado;
}

ResultadoCartao_de_credito ContainerCartao_de_credito::remover(Cartao_de_credito cartao_de_credito){

    // Procurar e remover um elemento.

    ResultadoCartao_de_credito resultado;
    CPF cpf_aux;
    Numero_Cartao_Credito numero_aux;
    Codigo_de_Seguranca_Cartao_Credito codigo_aux;
    Data_Validade_Cartao_Credito data_aux;

    long long int resultado_cpf;

    resultado.setValor(Resultado::FALHA);
    cartao_de_credito.getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);

    long long int chave = cpf_aux.getCPF();

    for(list<Cartao_de_credito>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);
           resultado_cpf = cpf_aux.getCPF();

        if (resultado_cpf == chave){
            // Elemento localizado.

            container.erase(elemento);
            resultado.setValor(Resultado::SUCESSO);
        }
    }

    return resultado;
}

//////////////////////////////////////////EVENTOS/////////////////////////////////////////////////////////////

bool ContainerEvento::incluir(Evento evento){

    ResultadoEvento resultado;

    //CPF cpf_aux;
    //Senha senha_aux;
    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    int resultado_cod_evento_incluir;

    // a chave vai ser o cpf

    evento.getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);

    int chave = codigo_de_evento_aux.getCodigo_de_Evento();
    //cout << "chave eh: " << chave << "\n";

    // Procurar o elemento.

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

       elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);
       resultado_cod_evento_incluir = codigo_de_evento_aux.getCodigo_de_Evento();

        if (resultado_cod_evento_incluir == chave){
            // Elemento localizado.

            resultado.setValor(Resultado::FALHA);
            cout << "evento ja cadastrado" << "\n\n";
            return false;
        }
    }

    // Incluir o elemento no container.

    container.push_back(evento);
    resultado.setValor(Resultado::SUCESSO);
    cout << "evento cadastrado com sucesso" << "\n\n";
    return true;

}

bool ContainerEvento::mostrar(){

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    int cod_evento_mostrar;
    string nome_evento_mostrar;
    string cidade_mostrar;
    string estados_br_mostrar;
    int classe_de_evento_mostrar;
    string faixa_etaria_mostrar;
    long long int cpf_mostrar;

    // ver os elementos.
    cout << "Eventos disponiveis:\n" <<endl;

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);

        cod_evento_mostrar = codigo_de_evento_aux.getCodigo_de_Evento();
        nome_evento_mostrar = nome_de_evento_aux.getNome_de_Evento();
        cidade_mostrar = cidade_aux.getCidade();
        estados_br_mostrar = estados_br_aux.getEstado();
        classe_de_evento_mostrar = classe_de_evento_aux.getClasse_Evento();
        faixa_etaria_mostrar = faixa_etaria_aux.getFaixa_Etaria();
        cpf_mostrar = cpf_aux.getCPF();

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
        cout << "CPF de quem disponibiliza o evento: ";
        cout << cpf_mostrar << endl;
        cout << "\n" << endl;
    }


    return true;

}

bool ContainerEvento::achar_evento_em_cidade(Cidade cidade){

    //int achamos_cidade = 0;

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    int cod_evento_mostrar;
    string nome_evento_mostrar;
    string cidade_mostrar;
    string estados_br_mostrar;
    int classe_de_evento_mostrar;
    string faixa_etaria_mostrar;
    long long int cpf_mostrar;

    string cidade_chave;
    string cidade_atual;
    cidade_chave = cidade.getCidade();

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);
        cidade_atual = cidade_aux.getCidade();

        if(cidade_chave != cidade_atual){
            //if(achamamos_cidade == 0){
              //  cout << "Achamos estes eventos na cidade desejada: \n" << endl;    //primeira ocorrencia
                //achamos_cidade = 1;
            //}
            //else{

                cod_evento_mostrar = codigo_de_evento_aux.getCodigo_de_Evento();
                nome_evento_mostrar = nome_de_evento_aux.getNome_de_Evento();
                cidade_mostrar = cidade_aux.getCidade();
                estados_br_mostrar = estados_br_aux.getEstado();
                classe_de_evento_mostrar = classe_de_evento_aux.getClasse_Evento();
                faixa_etaria_mostrar = faixa_etaria_aux.getFaixa_Etaria();
                cpf_mostrar = cpf_aux.getCPF();

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
                cout << "CPF de quem disponibiliza o evento: ";
                cout << cpf_mostrar << endl;
                cout << "\n" << endl;

            }
        }


}


//////////////////////////////////////////APRESENTACOES/////////////////////////////////////////////////////////////

bool ContainerApresentacoes::incluir(Apresentacao apresentacao){

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;

    bool resultado;
    string resultado_data;
    apresentacao.getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);
    string chave = data_aux.getData();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);
           resultado_data = data_aux.getData();

        if (resultado_data == chave){
            // Elemento localizado.

            resultado = false;
            cout << "Apresentacao ja cadastrada" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(apresentacao);
    resultado = true;
    cout << "apresentacao cadastrada com sucesso" << "\n\n";
    return resultado;

}


bool ContainerApresentacoes::remover(Apresentacao apresentacao){

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;

    bool resultado;
    int resultado_codigo;
    apresentacao.getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);
    int chave = codigo_aux.getCodigo_de_Apresentacao();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);
           resultado_codigo = codigo_aux.getCodigo_de_Apresentacao();

        if (resultado_codigo == chave){

            // Elemento localizado.

            container.erase(elemento);
            resultado = true;
        }
    }

    resultado = false;
    return resultado;
}

Apresentacao ContainerApresentacoes::pesquisar(Data data){

    // Procurar elemento.

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;

    Apresentacao resultado;
    string resultado_data;
    string chave = data.getData();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);
           resultado_data = data_aux.getData();

        if (resultado_data == chave){

            // Elemento localizado.

            resultado.setApresentacao(codigo_aux.getCodigo_de_Apresentacao(), data_aux.getData(), horario_aux.getHorario(), preco_aux.getPreco(),
            sala_aux.getNumero_de_Sala(), disponibilidade_aux.getDisponibilidade());
            cout << "Apresentacao encontrada";
            cout << "\n";
            return resultado;
        }
    }

    cout << "Apresentacao nao encontrada";
    cout << "\n";
    return resultado;
}

bool ContainerApresentacoes::mostrar(){

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;

    int cod_ap_mostrar;
    string data_mostrar;
    string horario_mostrar;
    float preco_mostrar;
    int num_sala_mostrar;
    int disp_mostrar;

    // ver os elementos.
    cout << "Apresentacoes disponiveis:\n" <<endl;

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux);

        cod_ap_mostrar = codigo_aux.getCodigo_de_Apresentacao();
        data_mostrar = data_aux.getData();
        horario_mostrar = horario_aux.getHorario();
        preco_mostrar = preco_aux.getPreco();
        num_sala_mostrar = sala_aux.getNumero_de_Sala();
        disp_mostrar = disponibilidade_aux.getDisponibilidade();

        cout << "Codigo de Apresentacao: ";
        cout << cod_ap_mostrar << endl;
        cout << "Data: ";
        cout << data_mostrar <<endl;
        cout << "Horario: ";
        cout << horario_mostrar << endl;
        cout << "Preco: ";
        cout << preco_mostrar << endl;
        cout << "Numero de sala: ";
        cout << num_sala_mostrar <<endl;
        cout << "Disponibilidade: ";
        cout << disp_mostrar << endl;
        cout << "\n" << endl;
    }


    return true;

}

bool Container_Apresentacoes::incluir( Ingressos_CPF ingressos_cpf){

    int resultado_codigo, resultado_cpf;
    Ingresso ingresso_aux;
    CPF cpf_aux;
    Codigo_de_Ingresso codigo_ingresso;
    bool resultado;

    ingressos_cpf.getIngressos_CPF(&ingresso_aux, &cpf_aux);
    ingresso_aux.getIngresso(&codigo_ingresso);
    int chave = codigo_ingresso.getCodigo_de_Ingresso();

    for(list<Ingressos_CPF>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngressos_CPF(&ingresso_aux, &cpf_aux);
           ingresso_aux.getIngresso(&codigo_ingresso);
           resultado_codigo = codigo_ingresso.getCodigo_de_Ingresso();

        if (resultado_codigo == chave){

            // Elemento localizado.

            resultado = false;
            cout << "Apresentacao ja cadastrada" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(ingressos_cpf);
    resultado = true;
    cout << "apresentacao cadastrada com sucesso" << "\n\n";
    return resultado;

}

bool Container_Apresentacoes::remover(Ingressos_CPF ingressos_cpf){

    int resultado_codigo, resultado_cpf;
    Ingresso ingresso_aux;
    CPF cpf_aux;
    Codigo_de_Ingresso codigo_ingresso;
    bool resultado;

    ingressos_cpf.getIngressos_CPF(&ingresso_aux, &cpf_aux);
    ingresso_aux.getIngresso(&codigo_ingresso);
    int chave = codigo_ingresso.getCodigo_de_Ingresso();

    for(list<Ingressos_CPF>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngressos_CPF(&ingresso_aux, &cpf_aux);
           ingresso_aux.getIngresso(&codigo_ingresso);
           resultado_codigo = codigo_ingresso.getCodigo_de_Ingresso();

        if (resultado_codigo == chave){

            // Elemento localizado.

            container.erase(elemento);
            resultado = true;
        }
    }

    resultado = false;
    return resultado;
}

Ingressos_CPF Container_Apresentacoes::pesquisar(Codigo_de_Ingresso codigo){

    // Procurar elemento.

    int chave = codigo.getCodigo_de_Ingresso();
    int resultado_codigo, resultado_cpf;
    Ingresso ingresso_aux;
    Codigo_de_Ingresso codigo_ingresso;
    CPF cpf_aux;
    Ingressos_CPF resultado;

    for(list<Ingressos_CPF>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngressos_CPF(&ingresso_aux, &cpf_aux);
           ingresso_aux.getIngresso(&codigo_ingresso);
           resultado_codigo = codigo_ingresso.getCodigo_de_Ingresso();

        if (resultado_codigo == chave){

            // Elemento localizado.
            resultado.setIngressos_CPF(ingresso_aux, cpf_aux);
            cout << "Ingresso vinculado encontrado";
            cout << "\n";
            return resultado;
        }
    }

    cout << "Ingresso vinculado nao encontrado";
    cout << "\n\n";
    return resultado;
}
