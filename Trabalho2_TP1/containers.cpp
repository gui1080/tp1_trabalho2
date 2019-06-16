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

bool ContainerEvento::remover(Codigo_de_Evento codigo_ev){

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;
    // a chave vai ser o cpf

    int chave = codigo_ev.getCodigo_de_Evento();
    int chave_atual;
    //cout << "chave eh: " << chave << "\n";

    // Procurar o elemento.

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

       elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);
       chave_atual = codigo_de_evento_aux.getCodigo_de_Evento();

        if (chave_atual == chave){
            // Elemento localizado.

            container.erase(elemento);
            return true;
        }
    }

    return false;

}

bool ContainerEvento::pesquisar(Codigo_de_Evento codigo_ev){

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

    int chave = codigo_ev.getCodigo_de_Evento();
    // ver os elementos.

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);

        cod_evento_mostrar = codigo_de_evento_aux.getCodigo_de_Evento();
        nome_evento_mostrar = nome_de_evento_aux.getNome_de_Evento();
        cidade_mostrar = cidade_aux.getCidade();
        estados_br_mostrar = estados_br_aux.getEstado();
        classe_de_evento_mostrar = classe_de_evento_aux.getClasse_Evento();
        faixa_etaria_mostrar = faixa_etaria_aux.getFaixa_Etaria();
        cpf_mostrar = cpf_aux.getCPF();

        if(chave == cod_evento_mostrar){

            cout << "Achamos um evento que satisfaz a sua busca!" << endl;
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

    return true;

}

ResultadoEvento ContainerEvento::pesquisar_Evento(Codigo_de_Evento codigo_e){

    // Procurar elemento.

    ResultadoEvento resultado;

    Codigo_de_Evento cod_evento_aux;
    Nome_de_Evento nome_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_f_aux;

    int resultado_cod_evento;

    resultado.setValor(Resultado::FALHA);

    int chave = codigo_e.getCodigo_de_Evento();

    for(list<Evento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getEvento(&cod_evento_aux, &nome_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_f_aux);
           resultado_cod_evento = cod_evento_aux.getCodigo_de_Evento();

        if (resultado_cod_evento == chave){

            // Elemento localizado.
            resultado.setEvento(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            cout << "Evento encontrado";
            cout << "\n";
            return resultado;
        }
    }

    cout << "Evento nao encontrado";
    cout << "\n";
    return resultado;
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
    Codigo_de_Evento cod_evento_aux;

    bool resultado;
    int resultado_codigo;

    apresentacao.getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);

    int chave = codigo_aux.getCodigo_de_Apresentacao();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);
           resultado_codigo = codigo_aux.getCodigo_de_Apresentacao();

        if (resultado_codigo == chave){
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
    Codigo_de_Evento cod_evento_aux;

    bool resultado;
    int resultado_codigo;
    apresentacao.getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);
    int chave = codigo_aux.getCodigo_de_Apresentacao();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);
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
    Codigo_de_Evento cod_evento_aux;

    int codigo_mostrar;

    Apresentacao resultado;
    string resultado_data;
    string chave = data.getData();

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);
           resultado_data = data_aux.getData();

        codigo_mostrar = codigo_aux.getCodigo_de_Apresentacao();

        if (resultado_data == chave){

            // Elemento localizado.

            resultado.setApresentacao(codigo_aux.getCodigo_de_Apresentacao(), data_aux.getData(), horario_aux.getHorario(), preco_aux.getPreco(),
            sala_aux.getNumero_de_Sala(), disponibilidade_aux.getDisponibilidade(), cod_evento_aux.getCodigo_de_Evento());
            cout << "Apresentacao encontrada!" << endl;
            cout << "Codigo da apresentacao: ";
            cout << codigo_mostrar;
            cout << "\n";
            return resultado;
        }
    }

    cout << "Apresentacao nao encontrada";
    cout << "\n";
    return resultado;
}

ResultadoApresentacao ContainerApresentacoes::pesquisar_Cod(Codigo_de_Apresentacao codigo){

    // Procurar elemento.

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;
    Codigo_de_Evento cod_evento_aux;

    int codigo_mostrar;

    ResultadoApresentacao resultado;
    int resultado_cod;
    int chave = codigo.getCodigo_de_Apresentacao();

    resultado.setValor(Resultado::FALHA);

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &cod_evento_aux);
           resultado_cod = codigo_aux.getCodigo_de_Apresentacao();

        if (resultado_cod == chave){

            // Elemento localizado.

            resultado.setApresentacao(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            cout << "Apresentacao encontrada!" << endl;
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
    Codigo_de_Evento codigo_de_evento_aux;

    int cod_ap_mostrar;
    string data_mostrar;
    string horario_mostrar;
    float preco_mostrar;
    int num_sala_mostrar;
    int disp_mostrar;
    int cod_ev_mostrar;

    // ver os elementos.
    cout << "Apresentacoes disponiveis:\n" <<endl;

    for(list<Apresentacao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

        elemento->getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux,
                   &sala_aux, &disponibilidade_aux, &codigo_de_evento_aux);

        cod_ap_mostrar = codigo_aux.getCodigo_de_Apresentacao();
        data_mostrar = data_aux.getData();
        horario_mostrar = horario_aux.getHorario();
        preco_mostrar = preco_aux.getPreco();
        num_sala_mostrar = sala_aux.getNumero_de_Sala();
        disp_mostrar = disponibilidade_aux.getDisponibilidade();
        cod_ev_mostrar = codigo_de_evento_aux.getCodigo_de_Evento();

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
        cout << "Evento ao qual a apresentacao esta relacionada: ";
        cout << cod_ev_mostrar << endl;
        cout << "\n" << endl;
    }


    return true;

}

ResultadoIngresso ContainerIngresso::incluir(Ingresso ingresso){

    ResultadoIngresso resultado;

    Codigo_de_Ingresso codigo_i_aux;
    Codigo_de_Apresentacao codigo_ap_aux;
    CPF cpf_f_aux;
    CPF cpf_c_aux;
    Senha teste_senha;

    int resultado_codigo_i;

    resultado.setValor(Resultado::FALHA);

    ingresso.getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);

    int chave = codigo_i_aux.getCodigo_de_Ingresso();

    for(list<Ingresso>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);
           resultado_codigo_i = codigo_i_aux.getCodigo_de_Ingresso();

        if (resultado_codigo_i == chave){

            resultado.setValor(Resultado::FALHA);
            cout << "Ingresso ja vendido" << "\n\n";
            return resultado;
        }
    }

    // Incluir o elemento no container.

    container.push_back(ingresso);
    resultado.setValor(Resultado::SUCESSO);
    cout << "ingresso comprado com sucesso" << "\n\n";
    return resultado;

}

ResultadoIngresso ContainerIngresso::remover(Ingresso ingresso){

    // Procurar e remover um elemento.

    ResultadoIngresso resultado;

    Codigo_de_Ingresso codigo_i_aux;
    Codigo_de_Apresentacao codigo_ap_aux;
    CPF cpf_f_aux;
    CPF cpf_c_aux;
    Senha teste_senha;

    int resultado_codigo_i;

    resultado.setValor(Resultado::FALHA);

    ingresso.getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);

    int chave = codigo_i_aux.getCodigo_de_Ingresso();

    for(list<Ingresso>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);
           resultado_codigo_i = codigo_i_aux.getCodigo_de_Ingresso();

        if (resultado_codigo_i == chave){
        // Elemento localizado.

            container.erase(elemento);
            resultado.setValor(Resultado::SUCESSO);
        }
    }

    return resultado;
}

ResultadoIngresso ContainerIngresso::pesquisar(Codigo_de_Ingresso codigo_i){

    ResultadoIngresso resultado;

    Codigo_de_Ingresso codigo_i_aux;
    Codigo_de_Apresentacao codigo_ap_aux;
    CPF cpf_f_aux;
    CPF cpf_c_aux;
    Senha teste_senha;

    int resultado_codigo_i;

    resultado.setValor(Resultado::FALHA);

    int chave = codigo_i.getCodigo_de_Ingresso();

    for(list<Ingresso>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);
           resultado_codigo_i = codigo_i_aux.getCodigo_de_Ingresso();

        if (resultado_codigo_i == chave){

            // Elemento localizado.
            resultado.setIngresso(*elemento);
            resultado.setValor(Resultado::SUCESSO);
            cout << "Ingresso encontrado";
            cout << "\n";
            return resultado;
        }
    }

    cout << "Ingresso nao encontrado";
    cout << "\n";
    return resultado;

}

void ContainerIngresso::Mostrar_Compras_Usuario(CPF cpf_usuario){

    Codigo_de_Ingresso codigo_i_aux;
    Codigo_de_Apresentacao codigo_ap_aux;
    CPF cpf_f_aux;
    CPF cpf_c_aux;
    Senha teste_senha;

    long long int resultado_cpf;

    long long int chave = cpf_usuario.getCPF();

    for(list<Ingresso>::iterator elemento = container.begin(); elemento != container.end(); elemento++){

           elemento->getIngresso(&codigo_i_aux, &codigo_ap_aux, &cpf_f_aux, &cpf_c_aux);
           resultado_cpf = cpf_c_aux.getCPF();

       if (resultado_cpf == chave){

    cout << "------------------------------------------------------" << endl;
    cout << "Codigo da apresentacao: " << codigo_i_aux.getCodigo_de_Ingresso() << endl;
    cout << "------------------------------------------------------\n" << endl;

        }
    }
}
/*
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
*/
