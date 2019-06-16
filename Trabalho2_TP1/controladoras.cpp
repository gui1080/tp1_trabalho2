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

usuario_aux.setUsuario(cpf_aux_login, senha_aux_login);

return usuario_aux;
}

bool CntrISAutenticacao::Autenticar(ContainerUsuario *container_usuario, Usuario usuario) throw(runtime_error){

CPF cpf_aux;
Senha senha_aux;
ResultadoUsuario resultado_usuario;

usuario.getUsuario(&cpf_aux, &senha_aux);

resultado_usuario = container_usuario->pesquisar(cpf_aux);

if(resultado_usuario.getValor() == resultado_usuario.FALHA){

    cout << "Usuario nao cadastrado\n";

    return false;

} else if(resultado_usuario.getValor() == resultado_usuario.SUCESSO){

cout << "usuario encontrado\n";

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
    //CntrISAutenticacao cntrISAutenticacao;
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

            cout << "Adeus e volte sempre!" << endl;
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

//usuario_aux.setUsuario(29700582191, "Pao123");
usuario_aux.setUsuario(novo_cpf, nova_senha);
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
cartao_de_credito_aux.setCartao_de_credito(novo_num_cartao, novo_cod_cartao, nova_data, cpf_aux.getCPF());
cartao_de_credito_aux.getCartao_de_credito(&numero_aux, &codigo_aux, &data_aux, &cpf_aux);

cout << "-- Seu CPF e: " << cpf_aux.getCPF() << "-----------------------------\n";
cout << "-- Seu numero de cartao de credito e: " << numero_aux.getNumero_Cartao_Credito() << "--\n";
cout << "-- Seu codigo de cartao de credito e: " << codigo_aux.getCodigo_de_Seguranca_Cartao_Credito() << "-------------\n";
cout << "- A data de validade do seu cartao de credito e: " << data_aux.getData_Validade_Cartao_Credito() << "\n";
cout << "------------------------------------------------------\n" << endl;

return cartao_de_credito_aux;

}

Apresentacao CntrIUUsuario::Menu_Edicao_apresentacao(){

Apresentacao apresentacao;

}

Usuario CntrIUUsuario::Menu_Edicao_usuario(){

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

void CntrIUUsuario::Menu_Logado(Usuario usuario, ContainerUsuario *container_u,
                                ContainerCartao_de_credito *container_c, ContainerEvento *container_e){

    int escolha;

    CntrGeral cntrGeral;
    CntrIUAutenticacao cntrIUAutenticacao;
    CntrISAutenticacao cntrISAutenticacao;
    CntrISUsuario cntrISUsuario;
    CntrIUUsuario cntrIUUsuario;

    cntrGeral.setCntrIUAutenticacao(&cntrIUAutenticacao);
    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);

    cntrIUAutenticacao.setCntrISAutenticacao(&cntrISAutenticacao);
    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);

    ResultadoUsuario resultado_meus_dados;
    ResultadoCartao_de_credito resultado_meu_cartao;

    Usuario usuario_aux;
    Evento evento_aux;
    CPF cpf_aux;
    Senha senha_aux;

    usuario.getUsuario(&cpf_aux, &senha_aux);

while(escolha != 8){

    cout << "\n------------------------------------------------------" << endl;
    cout << "--------  Escolha o que se deseja fazer: -------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "-------- Visualizar dados da conta: Digite 1 ---------" << endl;
    cout << "----------     Editar conta:  Digite 2 ---------------"  << endl;
    cout << "-------- Consultar apresentacoes: Digite 3 -----------" << endl;
    cout << "----------- Cadastrar evento: Digite 4 ---------------" << endl;
    cout << "-------- Editar evento cadastrado: Digite 5 ----------" << endl;
    cout << "------------- Comprar Ingresso: Digite 6 -------------" << endl;
    cout << "------- Visualizar minhas vendas: Digite 7 -----------" << endl;
    cout << "-------------- Fazer logout: Digite 8 ----------------" << endl;
    cout << "------------------------------------------------------\n" << endl;

    cin >> escolha;

    switch (escolha){

    case 1:

             cout << "------------------- MEU USUARIO ----------------------" << endl;
             cout << "CPF: " << cpf_aux.getCPF() << endl;
             cout << "Senha: " << senha_aux.getSenha() << endl;
             cout << "------------- MEU CARTAO DE CREDITO ------------------" << endl;
            //cout << "CPF: " << resultado_meus_dados.getUsuario();
             cout << "------------- CODIGO DOS MEUS EVENTOS ----------------" << endl;
             cout << "------- CODIGO DOS MEUS INGRESSOS COMPRADOS ----------" << endl;
             cout << "------- CODIGO DOS MEUS INGRESSOS VENDIDOS -----------" << endl;

            break;

    case 2:

            break;

    case 3:

            break;

    case 4:

            evento_aux = cntrIUUsuario.Menu_Criar_Evento(usuario);
            cntrISUsuario.Cadastrar_Evento(container_e, evento_aux);
            break;

    case 5:

            break;

    case 6:

            break;

    case 7:

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

    evento_final.setEvento(codigo_evento, nome_evento, cidade_evento, estado_evento, classe_evento, faixa_evento, cpf_aux.getCPF());

    return evento_final;
}

bool CntrISUsuario::Cadastrar_Evento(ContainerEvento *container_e, Evento evento){

bool resultado;

resultado = container_e->incluir(evento);

return resultado;

}

Apresentacao CntrIUUsuario::Menu_Criar_Apresentacao(Evento evento) throw(runtime_error){

}
