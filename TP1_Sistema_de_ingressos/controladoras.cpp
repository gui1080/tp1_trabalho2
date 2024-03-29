#include "controladoras.h"
#include <stdio.h>

bool CntrIUAutenticacao::executar_autenticacao(CPF cpf) throw(runtime_error) {

}

Usuario CntrIUAutenticacao::Tela_login()throw(runtime_error){

    Usuario usuario_aux;
    long long int cpf_aux_login;
    char senha_aux_login[7];

    cout << "------------------------------------------------------" << endl;
    cout << "-- Digite os seguinter dados para concluir o login: --" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "----------- CPF: ";
    cin >> cpf_aux_login;
    cout << "----------- Senha: ";
    cin >> senha_aux_login;
    cout << "------------------------------------------------------" << endl;

    try{
        usuario_aux.setUsuario(cpf_aux_login, senha_aux_login);
    }
    catch(invalid_argument excecao){

    cout << "Erros cometidos!" <<endl;
    exit(0);

    }

    return usuario_aux;
}

bool CntrISAutenticacao::Autenticar(ContainerUsuario *container_usuario, Usuario usuario) throw(runtime_error){

    CPF cpf_aux;
    Senha senha_aux;
    ResultadoUsuario resultado_usuario;

    usuario.getUsuario(&cpf_aux, &senha_aux);

    resultado_usuario = container_usuario->pesquisar(cpf_aux);

    if(resultado_usuario.getValor() == resultado_usuario.FALHA){

        cout << "\n------------------------------------------------------" << endl;
        cout << "------------ USUARIO NAO CADASTRADO -------------------" << endl;
        cout << "-------------------------------------------------------" << endl;

        return false;

    } else if(resultado_usuario.getValor() == resultado_usuario.SUCESSO){

    cout << "\n------------------------------------------------------" << endl;
        cout << "--------------- USUARIO ENCONTRADO --------------------" << endl;
        cout << "-------------------------------------------------------" << endl;

        return true;

    }

}

Usuario CntrISAutenticacao::Mostrar_Menu(ContainerUsuario *container_u, ContainerCartao_de_credito *container_c, Usuario usuario_cliente, Cartao_de_credito cartao_de_credito_cliente, ContainerEvento container_e, ContainerApresentacoes container_ap){

    CntrGeral cntrGeral;
    CntrIUAutenticacao cntrIUAutenticacao;
    CntrISAutenticacao cntrISAutenticacao;
    CntrISUsuario cntrISUsuario;
    CntrIUUsuario cntrIUUsuario;

    cntrGeral.setCntrIUAutenticacao(&cntrIUAutenticacao);
    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);

    cntrIUAutenticacao.setCntrISAutenticacao(&cntrISAutenticacao);
    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);

    bool mostra_evento, mostra_apresentacao;

    bool login = false;

    while (login == false){

    int escolha_inicial;

    cout << "------------------------------------------------------" << endl;
    cout << "--------  Escolha o que se deseja fazer: -------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "----------    Criar usuario: Digite 1 ----------------" << endl;
    cout << "----------     Fazer login:  Digite 2 ----------------"  << endl;
    cout << "----  Apenas ver os eventos disponiveis: Digite 3  ---" << endl;
    cout << "---------  Fechar o software: Digite 4 ---------------" << endl;
    cout << "------------------------------------------------------\n" << endl;

    cin >> escolha_inicial;

    switch (escolha_inicial){

    case 1:

            usuario_cliente = cntrIUUsuario.Criar_usuario();
            cartao_de_credito_cliente = cntrIUUsuario.Criar_cartao_de_credito(usuario_cliente);
            cntrISUsuario.Cadastrar(container_u, container_c, usuario_cliente, cartao_de_credito_cliente);

            break;

        case 2:

            usuario_cliente = cntrIUAutenticacao.Tela_login();
            if(cntrISAutenticacao.Autenticar(container_u, usuario_cliente) == true){
                  login = true;
                  return usuario_cliente;
            }

            break;

        case 3:

            mostra_evento = container_e.mostrar();
            mostra_apresentacao = container_ap.mostrar();

            break;

        case 4:

        cout << "\n------------------------------------------------------" << endl;
        cout << "-------------- ADEUS E VOLTE SEMPRE -------------------" << endl;
        cout << "-------------------------------------------------------" << endl;
            exit(0);

            break;
        }

    }
}

Usuario CntrIUUsuario::Criar_usuario() throw(runtime_error){

    Usuario usuario_aux;
    CPF cpf_aux;
    Senha senha_aux;
    long long int novo_cpf;
    char nova_senha[7];

    cout << "------------------------------------------------------" << endl;
    cout << "--- Informe os seguintes dados para criar a conta: ---" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "---------- Informacoes sobre o usuario : -------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "----------- CPF: ";
    cin >> novo_cpf;
    cout << "----------- Senha: ";
    cin >> nova_senha;
    cout << "------------------------------------------------------" << endl;


    try{
        usuario_aux.setUsuario(novo_cpf, nova_senha);
    }
    catch(invalid_argument excecao){

        cout << "Erros cometidos!" <<endl;
        exit(0);

    }


    usuario_aux.getUsuario(&cpf_aux, &senha_aux);

    cout << "---------- Seu CPF e: " << cpf_aux.getCPF() << "---------------------\n";
    cout << "---------- Sua senha e: " << senha_aux.getSenha() << "------------------------\n";
    cout << "------------------------------------------------------" << endl;

    return usuario_aux;

}

Cartao_de_credito CntrIUUsuario::Criar_cartao_de_credito(Usuario usuario) throw(runtime_error){

    CPF cpf_aux;
    Numero_Cartao_Credito numero_aux;
    Codigo_de_Seguranca_Cartao_Credito codigo_aux;
    Data_Validade_Cartao_Credito data_aux;
    Cartao_de_credito cartao_de_credito_aux;
    Senha senha_aux;
    long long int novo_num_cartao;
    int novo_cod_cartao;
    char nova_data[6];

    usuario.getUsuario(&cpf_aux, &senha_aux);

    cout << "------ Informacoes sobre o cartao de credito: --------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "--- Numero do cartao de credito: ";
    cin >> novo_num_cartao;
    cout << "--- Codigo de seguranca do cartao de credito: ";
    cin >> novo_cod_cartao;
    cout << "--- Data de validade do cartao de credito: ";
    cin >> nova_data;
    cout << "------------------------------------------------------" << endl;

    //cartao_de_credito_aux.setCartao_de_credito(30211944335337, 123, "10/10", cpf_aux.getCPF());

    try{
        cartao_de_credito_aux.setCartao_de_credito(novo_num_cartao, novo_cod_cartao, nova_data, cpf_aux.getCPF());
    }
    catch(invalid_argument excecao){
        cout << "Erros cometidos!" <<endl;
        exit(0);
    }

    cartao_de_credito_aux.getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);

    cout << "-- Seu CPF e: " << cpf_aux.getCPF() << "-----------------------------\n";
    cout << "-- Seu numero de cartao de credito e: " << numero_aux.getNumero_Cartao_Credito() << "--\n";
    cout << "-- Seu codigo de cartao de credito e: " << codigo_aux.getCodigo_de_Seguranca_Cartao_Credito() << "-------------\n";
    cout << "- A data de validade do seu cartao de credito e: " << data_aux.getData_Validade_Cartao_Credito() << "\n";
    cout << "------------------------------------------------------\n" << endl;

    return cartao_de_credito_aux;

}

bool CntrISUsuario::Cadastrar(ContainerUsuario *container_u, ContainerCartao_de_credito *container_c, Usuario usuario, Cartao_de_credito cartao_de_credito) throw(runtime_error){

    Usuario usuario_aux;
    ResultadoUsuario resultado_usuario;
    ResultadoCartao_de_credito resultado_cartao_de_credito;

    resultado_usuario = container_u->incluir(usuario);
    resultado_cartao_de_credito = container_c->incluir(cartao_de_credito);

    if(resultado_usuario.getValor() == true && resultado_cartao_de_credito.getValor() == true){
        return true;
    } else {
    return false;
    }

}

void CntrIUUsuario::Menu_Logado(Usuario usuario, ContainerUsuario *container_u, ContainerCartao_de_credito *container_c,
                                 ContainerEvento *container_e, ContainerApresentacoes *container_ap, ContainerIngresso *container_i){

    int escolha;
    int escolha_ap;

    CntrGeral cntrGeral;

    CntrIUAutenticacao cntrIUAutenticacao;
    CntrISAutenticacao cntrISAutenticacao;
    CntrIUUsuario cntrIUUsuario;
    CntrISUsuario cntrISUsuario;
    CntrIUVendas cntrIUVendas;
    CntrISVendas cntrISVendas;

    cntrGeral.setCntrIUAutenticacao(&cntrIUAutenticacao);
    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);
    cntrGeral.setCntrIUVendas(&cntrIUVendas);

    cntrIUAutenticacao.setCntrISAutenticacao(&cntrISAutenticacao);
    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);
    cntrIUVendas.setCntrISVendas(&cntrISVendas);

    ResultadoUsuario resultado_meus_dados;
    ResultadoCartao_de_credito resultado_meu_cartao;
    ResultadoIngresso resultado_ing;
    ResultadoEvento resultado_e;

    Usuario usuario_aux;
    Evento evento_aux;
    Apresentacao apresentacao_aux;
    Ingresso ingresso_aux;

    CPF cpf_aux;
    Senha senha_aux;

    usuario.getUsuario(&cpf_aux, &senha_aux);

while(escolha != 8){

    cout << "\n------------------------------------------------------" << endl;
    cout << "--------  Escolha o que se deseja fazer: -------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "-------- Visualizar dados da conta: Digite 1 ---------" << endl;
    cout << "--- Visualizar eventos e apresentacoes: Digite 2 -----" << endl;
    cout << "----------- Cadastrar evento: Digite 3 ---------------" << endl;
    cout << "---------- Editar evento cadastrado: Digite 4 --------" << endl;
    cout << "------------- Comprar Ingresso: Digite 5 -------------" << endl;
    cout << "------- Visualizar minhas vendas: Digite 6 -----------" << endl;
    cout << "------- Remover Evento cadastrado: Digite 7 ----------" << endl;
    cout << "-------------- Fazer logout: Digite 8 ----------------" << endl;
    cout << "------------------------------------------------------\n" << endl;

    cin >> escolha;

    switch (escolha){

    case 1:

             cout << "------------------- MEU USUARIO ----------------------" << endl;
             cout << "---------------- CPF: " << cpf_aux.getCPF() << endl;
             cout << "---------------- Senha: " << senha_aux.getSenha() << endl;
             cout << "------- CODIGO DOS MEUS INGRESSOS COMPRADOS ----------\n" << endl;
             cntrISUsuario.Mostrar_Compras(usuario, container_i);


            break;

    case 2:

            container_e->mostrar();
            container_ap->mostrar();

            break;

    case 3:

            evento_aux = cntrIUUsuario.Menu_Criar_Evento(usuario);
            cntrISUsuario.Cadastrar_Evento(container_e, evento_aux);

            while(escolha_ap != 2){

            apresentacao_aux = cntrIUUsuario.Menu_Criar_Apresentacao(evento_aux);
            cntrISUsuario.Cadastrar_Apresentacao(container_ap, apresentacao_aux);

      cout << "\n--------------------------------------------------------------------" << endl;
        cout << "-DIGITE 1 SE DESEJA ADICIONAR APRESENTACOES E 2 CASO DESEJE VOLTAR -" << endl;
        cout << "--------------------------------------------------------------------" << endl;
            cin >> escolha_ap;

            }
            escolha_ap = 1;

            break;

    case 4:

            resultado_e = cntrIUUsuario.Menu_Edicao_evento(usuario, container_e, container_i);

            if(resultado_e.getValor() == resultado_e.SUCESSO){

               cntrISUsuario.Editar_Evento(resultado_e.getEvento(), container_e);

            }
            break;

    case 5:

            resultado_ing = cntrIUVendas.Achar_Ingresso(usuario, container_e, container_ap);
            ingresso_aux = resultado_ing.getIngresso();
            cntrISVendas.Comprar_Ingresso(ingresso_aux, container_i);

            break;

    case 6:

            cntrISUsuario.Mostrar_Vendas(usuario, container_i);

            break;

    case 7:

            resultado_e = cntrIUUsuario.Menu_Remocao_Evento(usuario, container_e, container_i);

            if(resultado_e.getValor() == resultado_e.SUCESSO){

               cntrISUsuario.Descadastrar_Evento(resultado_e.getEvento(), container_e, container_ap);

            }
            break;

        }
    }

}

Evento CntrIUUsuario::Menu_Criar_Evento(Usuario usuario)throw(runtime_error){

    CPF cpf_aux;
    Senha senha_aux;

    usuario.getUsuario(&cpf_aux, &senha_aux);

    Evento evento_final;

    int codigo_evento;
    char nome_evento[21];
    char cidade_evento[16];
    char estado_evento[3];
    int classe_evento;
    char faixa_evento[3];
    long long int cpf_dono_evento;

    cout << "\n------------------------------------------------------" << endl;
    cout << "------------------  CRIAR EVENTO: --------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "-------- DIGITE AS INFORMACOES PEDIDAS: --------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "--------------- Codigo do evento: --------------------" << endl;
    cin >> codigo_evento;
    cout << "---------------- Nome do evento: ---------------------" << endl;
    cin >> nome_evento;
    getchar();
    cout << "---------------- Cidade do evento: -------------------" << endl;
    cin >> cidade_evento;
    getchar();
    cout << "---------------- Estado do evento: -------------------" << endl;
    cin >> estado_evento;
    cout << "---------------- Classe do evento: -------------------" << endl;
    cin >> classe_evento;
    cout << "-------------- Faixa Etaria do evento: ---------------" << endl;
    cin >> faixa_evento;
    cout << "------------------------------------------------------\n" << endl;

    try {

    evento_final.setEvento(codigo_evento, nome_evento, cidade_evento, estado_evento, classe_evento, faixa_evento, cpf_aux.getCPF());

    } catch (invalid_argument excecao){
    cout << "Evento Invalido";
    exit(0);

    }

    return evento_final;
}

bool CntrISUsuario::Validar_Edicao_Evento(int codigo_e_aux, Usuario usuario, ContainerEvento *container_e, ContainerIngresso *container_i){

    ResultadoEvento resultado_e;
    Codigo_de_Evento codigo_e;
    Evento evento_ed;

    Senha senha_aux;
    CPF cpf_aux_usuario;

    usuario.getUsuario(&cpf_aux_usuario, &senha_aux);

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    codigo_e.setCodigo_de_Evento(codigo_e_aux);

    resultado_e = container_e->pesquisar_Evento(codigo_e);
    evento_ed = resultado_e.getEvento();

    evento_ed.getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);


    if(cpf_aux.getCPF() != cpf_aux_usuario.getCPF()){

        cout << "\n------------------------------------------------------" << endl;
        cout << "---- VOCE NAO TEM PERMISSAO PARA EDITAR ESSE EVENTO ---" << endl;
        cout << "-------------------------------------------------------" << endl;

        return false;

    }

    ResultadoIngresso resultado_i;
    Ingresso ingresso;

    Codigo_de_Ingresso codigo_i_aux;
    Codigo_de_Apresentacao codigo_ap_aux;
    CPF cpf_f_aux;
    CPF cpf_c_aux;
    Senha teste_senha;

    resultado_i = container_i->pesquisar_CPF(cpf_aux_usuario);

    if(resultado_i.getValor() == resultado_i.SUCESSO){

        cout << "\n------------------------------------------------------" << endl;
        cout << "-VOCE NAO PODE EDITAR UM EVENTO COM INGRESSOS VENDIDOS-" << endl;
        cout << "-------------------------------------------------------" << endl;

        return false;
    }

    return true;


}

ResultadoEvento CntrIUUsuario::Menu_Edicao_evento(Usuario usuario, ContainerEvento *container_e, ContainerIngresso *container_i){

    CntrGeral cntrGeral;

    CntrIUUsuario cntrIUUsuario;
    CntrISUsuario cntrISUsuario;

    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);

    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);

    ResultadoEvento resultado_e;

    int codigo_e_aux;

    resultado_e.setValor(Resultado::FALHA);

    cout << "\n------------------------------------------------------" << endl;
    cout << "------------------- EDITAR EVENTO: --------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "------ DIGITE O CODIGO DO EVENTO QUE DESEJA EDITAR ----" << endl;
    cout << "-------------------------------------------------------" << endl;
    cin >> codigo_e_aux;

    if(cntrISUsuario.Validar_Edicao_Evento(codigo_e_aux, usuario, container_e, container_i) == true){

     Evento evento_final;

     int codigo_evento;
     char nome_evento[21];
     char cidade_evento[16];
     char estado_evento[3];
     int classe_evento;
     char faixa_evento[3];
     long long int cpf_dono_evento;

     Senha senha_aux;
     CPF cpf_aux_usuario;

     usuario.getUsuario(&cpf_aux_usuario, &senha_aux);

    cout << "------------------------------------------------------" << endl;
    cout << "-------- DIGITE AS INFORMACOES PEDIDAS: --------------" << endl;
    cout << "------------------------------------------------------" << endl;
    codigo_evento = codigo_e_aux;
    cout << "---------------- Nome do evento: ---------------------" << endl;
    cin >> nome_evento;
    getchar();
    cout << "---------------- Cidade do evento: -------------------" << endl;
    cin >> cidade_evento;
    getchar();
    cout << "---------------- Estado do evento: -------------------" << endl;
    cin >> estado_evento;
    cout << "---------------- Classe do evento: -------------------" << endl;
    cin >> classe_evento;
    cout << "-------------- Faixa Etaria do evento: ---------------" << endl;
    cin >> faixa_evento;
    cout << "------------------------------------------------------\n" << endl;
    cpf_dono_evento = cpf_aux_usuario.getCPF();

 try{
        evento_final.setEvento(codigo_evento, nome_evento, cidade_evento, estado_evento, classe_evento, faixa_evento, cpf_dono_evento);
    }
    catch(invalid_argument excecao){
        cout << "Erros cometidos!" <<endl;
        exit(0);
    }

    resultado_e.setValor(Resultado::SUCESSO);

   try{
        resultado_e.setEvento(evento_final);
    }
    catch(invalid_argument excecao){
        cout << "Erros cometidos!" <<endl;
        exit(0);
        //return;
    }

    return resultado_e;
    }    else {

        resultado_e.setValor(Resultado::FALHA);
        return resultado_e;
    }
}

void CntrISUsuario::Editar_Evento(Evento evento, ContainerEvento *container_e){

    Evento evento_aux;

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    evento.getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);

    container_e->remover(codigo_de_evento_aux);
    container_e->incluir(evento);

}

ResultadoEvento CntrIUUsuario::Menu_Remocao_Evento(Usuario usuario, ContainerEvento *container_e, ContainerIngresso *container_i){

    CntrGeral cntrGeral;

    CntrIUUsuario cntrIUUsuario;
    CntrISUsuario cntrISUsuario;

    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);

    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);

    ResultadoEvento resultado_e;
    Codigo_de_Evento codigo_evento;

    int codigo_e_aux;

    resultado_e.setValor(Resultado::FALHA);

    cout << "\n------------------------------------------------------" << endl;
    cout << "------------------- REMOVER EVENTO: --------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "----- DIGITE O CODIGO DO EVENTO QUE DESEJA REMOVER ----" << endl;
    cout << "-------------------------------------------------------" << endl;
    cin >> codigo_e_aux;

    if(cntrISUsuario.Validar_Edicao_Evento(codigo_e_aux, usuario, container_e, container_i) == true){

     Evento evento_final;

    try{
        codigo_evento.setCodigo_de_Evento(codigo_e_aux);
    }
    catch(invalid_argument excecao){
        cout << "Erros cometidos!" <<endl;
        exit(0);
    }

     resultado_e = container_e->pesquisar_Evento(codigo_evento);
     resultado_e.setValor(Resultado::SUCESSO);

    return resultado_e;
    } else {

    resultado_e.setValor(Resultado::FALHA);

    return resultado_e;
    }
}

void CntrISUsuario::Descadastrar_Evento(Evento evento, ContainerEvento *container_e, ContainerApresentacoes *container_ap){

    Evento evento_aux;

    Codigo_de_Evento codigo_de_evento_aux;
    Nome_de_Evento nome_de_evento_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estados_br_aux;
    Classe_Evento classe_de_evento_aux;
    Faixa_Etaria faixa_etaria_aux;
    CPF cpf_aux;

    evento.getEvento(&codigo_de_evento_aux, &nome_de_evento_aux, &cidade_aux, &estados_br_aux, &classe_de_evento_aux, &faixa_etaria_aux, &cpf_aux);

    container_e->remover(codigo_de_evento_aux);
    container_ap->remover_ap_usuario(codigo_de_evento_aux);

}

bool CntrISUsuario::Cadastrar_Evento(ContainerEvento *container_e, Evento evento){

    bool resultado;

    resultado = container_e->incluir(evento);

    return resultado;

}

Apresentacao CntrIUUsuario::Menu_Criar_Apresentacao(Evento evento) throw(runtime_error){

    Codigo_de_Evento codigo_aux;
    Nome_de_Evento nome_aux;
    Cidade cidade_aux;
    Estados_Brasileiros estado_aux;
    Classe_Evento classe_aux;
    Faixa_Etaria faixa_aux;
    CPF cpf_aux;

    evento.getEvento(&codigo_aux, &nome_aux, &cidade_aux, &estado_aux,  &classe_aux, &faixa_aux, &cpf_aux);

    Apresentacao apresentacao_final;

    int codigo_ap;
    char data_ap[7];
    char horario_ap[6];
    float preco_ap;
    int sala_ap;
    int disponibilidade_ap;
    int codigo_ev_ap;

    cout << "\n------------------------------------------------------" << endl;
    cout << "---------------- CRIAR APRESENTACAO: -----------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "-------- DIGITE AS INFORMACOES PEDIDAS: --------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------- Codigo da apresentacao: ----------------" << endl;
    cin >> codigo_ap;
    cout << "------------- Data da apresentacao: ------------------" << endl;
    cin >> data_ap;
    getchar();
    cout << "------------ Horario da apresentacao: ----------------" << endl;
    cin >> horario_ap;
    getchar();
    cout << "-------------- Sala da apresentacao: -----------------" << endl;
    cin >> sala_ap;
    cout << "------------- Preco da apresentacao: -----------------" << endl;
    cin >> preco_ap;
    cout << "---------- Disponibilidade da apresentacao: ----------" << endl;
    cin >> disponibilidade_ap;
    cout << "------------------------------------------------------\n" << endl;

    try{

    apresentacao_final.setApresentacao(codigo_ap, data_ap, horario_ap, preco_ap, sala_ap, disponibilidade_ap, codigo_aux.getCodigo_de_Evento());

    }
    catch(invalid_argument excecao){
        cout << "Erros cometidos!" <<endl;
        exit(0);
        //return;
    }

    return apresentacao_final;
}

bool CntrISUsuario::Cadastrar_Apresentacao(ContainerApresentacoes *container_ap, Apresentacao apresentacao){

    bool resultado;

    resultado = container_ap->incluir(apresentacao);

    return resultado;

}

ResultadoIngresso CntrIUVendas::Achar_Ingresso(Usuario usuario, ContainerEvento *container_e, ContainerApresentacoes *container_ap){

    int codigo_ap;
    int codigo_i = rand()%(999 - 1) + 1;
    Ingresso ingresso_final;

    cout << "------------------------------------------------------" << endl;
    cout << "----------------- COMPRAR INGRESSOS ------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------- Digite o Codigo da apresentacao desejada -----" << endl;
    cin >> codigo_ap;

    Apresentacao apresentacao;
    Evento evento;
    ResultadoEvento resultado;
    ResultadoApresentacao resultado_ap;
    ResultadoIngresso resultado_i;

    Codigo_de_Apresentacao codigo_ap_aux;
    Data data_ap;
    Horario horario_ap;
    Preco preco_ap;
    Numero_de_Sala sala_ap;
    Disponibilidade disponibilidade_ap;
    Codigo_de_Evento codigo_ev_ap;

    codigo_ap_aux.setCodigo_de_Apresentacao(codigo_ap);

    resultado_ap = container_ap->pesquisar_Cod(codigo_ap_aux);
    apresentacao =  resultado_ap.getApresentacao();

    apresentacao.getApresentacao(&codigo_ap_aux, &data_ap, &horario_ap, &preco_ap, &sala_ap, &disponibilidade_ap, &codigo_ev_ap);

    if(resultado_ap.getValor() == Resultado::FALHA){

        cout << "\n------------------------------------------------------" << endl;
        cout << "------------ APRESENTACAO NAO ENCONTRADA --------------" << endl;
        cout << "-------------------------------------------------------" << endl;

        resultado_i.setValor(Resultado::FALHA);

        return resultado_i;

    } else {
        cout << "------------------------------------------------------" << endl;
        cout << "------------- APRESENTACAO ENCONTRADA: ---------------" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Codigo da apresentacao: " << codigo_ap_aux.getCodigo_de_Apresentacao() << endl;
        cout << "Data da apresentacao: " << data_ap.getData() << endl;
        cout << "Horario da apresentacao: " << horario_ap.getHorario() << endl;
        cout << "Sala da apresentacao: " << sala_ap.getNumero_de_Sala() << endl;
        cout << "Preco da apresentacao: "<< preco_ap.getPreco() << endl;
        cout << "Disponibilidade da apresentacao: " << disponibilidade_ap.getDisponibilidade() << endl;
        cout << "------------------------------------------------------\n" << endl;

        resultado = container_e->pesquisar_Evento(codigo_ev_ap);
        evento = resultado.getEvento();

        Codigo_de_Evento codigo_e_aux;
        Nome_de_Evento nome_aux;
        Cidade cidade_aux;
        Estados_Brasileiros estado_aux;
        Classe_Evento classe_aux;
        Faixa_Etaria faixa_aux;
        CPF cpf_e_aux;

        evento.getEvento(&codigo_e_aux, &nome_aux, &cidade_aux, &estado_aux, &classe_aux, &faixa_aux, &cpf_e_aux);

        CPF cpf_c_aux;
        Senha senha_aux;

        usuario.getUsuario(&cpf_c_aux, &senha_aux);

        try{

            ingresso_final.setIngresso(codigo_i, codigo_ap, cpf_e_aux.getCPF(),cpf_c_aux.getCPF());

        }
        catch(invalid_argument excecao){
            cout << "Erros cometidos!" <<endl;
            exit(0);
        //return;
        }


        resultado_i.setValor(Resultado::SUCESSO);

        try{

            resultado_i.setIngresso(ingresso_final);

        }
        catch(invalid_argument excecao){
            cout << "Erros cometidos!" <<endl;
            exit(0);
        //return;
        }

        return resultado_i;
        }
}

bool CntrISVendas::Comprar_Ingresso(Ingresso ingresso, ContainerIngresso *container_i){

    bool resultado;

    container_i->incluir(ingresso);

    Codigo_de_Apresentacao codigo_ap;
    Codigo_de_Ingresso codigo_i;
    CPF cpf_forn;
    CPF cpf_comp;

    ingresso.getIngresso(&codigo_i, &codigo_ap, &cpf_forn, &cpf_comp);

    cout << "------------------------------------------------------" << endl;
    cout << "---------------- INGRESSO GERADO: ----------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Codigo do Ingresso: " << codigo_i.getCodigo_de_Ingresso() << endl;
    cout << "Codigo da apresentacao: " << codigo_ap.getCodigo_de_Apresentacao() << endl;
    cout << "CPF do fornecedor:  " << cpf_forn.getCPF() << endl;
    cout << "CPF do comprador: " << cpf_comp.getCPF() << endl;
    cout << "------------------------------------------------------\n" << endl;

    return resultado;

}

void CntrISUsuario::Mostrar_Compras(Usuario usuario, ContainerIngresso *container_i){

    CPF cpf_aux;
    Senha senha_aux;
    usuario.getUsuario(&cpf_aux, &senha_aux);

    container_i->Mostrar_Compras_Usuario(cpf_aux);
}

void CntrISUsuario::Mostrar_Vendas(Usuario usuario, ContainerIngresso *container_i){

    CPF cpf_aux;
    Senha senha_aux;
    usuario.getUsuario(&cpf_aux, &senha_aux);

    container_i->Mostrar_Vendas_Usuario(cpf_aux);

}
