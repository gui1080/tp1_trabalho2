/**
 * @file main.cpp
 *
 * @brief Arquivo com a implementação básica do programa.
 *
 * @author Gabriel e Guilherme
 *
 */

#include "dominios.h"
#include "dominios.cpp"
#include "entidades.h"
#include "entidades.cpp"
#include "funcoes_auxiliares.h"
#include "funcoes_auxiliares.cpp"
#include "containers.cpp"
#include "containers.h"
#include "controladoras.h"

/*
Feito por:
Guilherme Braga Pinto
Gabriel Matheus da Rocha de Oliveira
Last Update: xx/xx/2019
UnB
*/

//Obs- Seguimos certas convenções como as que foram demonstradas em exeplos de sala de aula ao dar nome às variáveis, classes e testes.

using namespace std;

int main(){

    system("Color 0A");

    /*
    int escolha_inicial = 0;
    bool mostra_evento;
    bool mostra_apresentacao;
    */
//-----------------------------------CONTAINERS-----------------------------------------------------------------

    ResultadoUsuario resultado;
    ContainerUsuario container;

    bool resultado_e;
    ContainerEvento container_e;

    ContainerApresentacoes container_ap;
    bool resultado_ap;
//----------------------------------INICIALIZANDO OS EVENTOS DEFAULT----------------------------------------------------------

    std::cout.setstate(std::ios_base::failbit);       // essa linha "bloqueia" os prints no comeco do programa

    Evento evento_padrao_1;
    Apresentacao apresentacao_padrao_1, apresentacao_padrao_1_2, apresentacao_padrao_1_3;       // CPF padrao = 79410739276

    evento_padrao_1.setEvento(645, "Hatsune Miku Live!", "Brasilia", "DF", 4, "L", 79410739276);
    apresentacao_padrao_1.setApresentacao(143, "100410", "13:45", 54, 5, 79, 645);
    apresentacao_padrao_1_2.setApresentacao(113, "110610", "11:30", 78, 4, 100, 645);
    apresentacao_padrao_1_3.setApresentacao(123, "091010", "15:15", 100, 2, 50, 645);

    resultado_e = container_e.incluir(evento_padrao_1);
    resultado_ap = container_ap.incluir(apresentacao_padrao_1);
    resultado_ap = container_ap.incluir(apresentacao_padrao_1_2);
    resultado_ap = container_ap.incluir(apresentacao_padrao_1_3);

    Evento evento_padrao_2;
    Apresentacao apresentacao_padrao_2, apresentacao_padrao_2_2;
    evento_padrao_2.setEvento(132, "Black Sabbath Tour!", "Rio de Janeiro", "RJ", 4, "14", 79410739276);
    apresentacao_padrao_2.setApresentacao(143, "100416", "13:45", 54, 5, 79, 645);
    apresentacao_padrao_2_2.setApresentacao(143, "100417", "13:45", 54, 5, 79, 645);
    resultado_e = container_e.incluir(evento_padrao_2);
    resultado_ap = container_ap.incluir(apresentacao_padrao_2);
    resultado_ap = container_ap.incluir(apresentacao_padrao_2_2);

    Evento evento_padrao_3;
    Apresentacao apresentacao_padrao_3;
    evento_padrao_3.setEvento(984, "Hamlet", "Sao Paulo", "SP", 1, "12", 79410739276);
    apresentacao_padrao_3.setApresentacao(143, "100418", "13:45", 54, 5, 79, 645);
    resultado_e = container_e.incluir(evento_padrao_3);
    resultado_ap = container_ap.incluir(apresentacao_padrao_3);

    Evento evento_padrao_4;
    Apresentacao apresentacao_padrao_4;
    evento_padrao_4.setEvento(623, "Jota Quest Acustico", "Sao Paulo", "SP", 3, "L", 79410739276);
    apresentacao_padrao_4.setApresentacao(143, "100419", "13:45", 54, 5, 79, 645);
    resultado_e = container_e.incluir(evento_padrao_4);
    resultado_ap = container_ap.incluir(apresentacao_padrao_4);

    std::cout.clear();

//--------------------------------------------INICIALIZANDO O USUÁRIO--------------------------------------------------------
    /*
    Usuario usuario1;

//-------------------------------------------- TESTES --------------------------------------

    Container_Apresentacoes container_ap_cpf;
    bool resultado_ap_cpf;
    Ingresso teste1;
    CPF teste2;
    Ingressos_CPF teste3, teste4;

    teste1.setIngresso(12345);
    teste2.setCPF(29700582191);
    teste3.setIngressos_CPF(teste1, teste2);

    container_ap_cpf.setApresentacao(143, "100410", "13:45", 54, 5, 79);
    resultado_ap_cpf = container_ap_cpf.incluir(teste3);
    if(resultado_ap_cpf == true){
        cout << "deu certo\n" << endl;
    } else {
         cout << ";-;\n";
    }
    Codigo_de_Ingresso exemplo;
    teste1.getIngresso(&exemplo);
    teste4 = container_ap_cpf.pesquisar(exemplo);

    Codigo_de_Apresentacao codigo_aux;
    Data data_aux;
    Horario horario_aux;
    Preco preco_aux;
    Numero_de_Sala sala_aux;
    Disponibilidade disponibilidade_aux;

    container_ap_cpf.getApresentacao(&codigo_aux, &data_aux, &horario_aux, &preco_aux, &sala_aux, &disponibilidade_aux);

    cout << "codigo: " << codigo_aux.getCodigo_de_Apresentacao() << "\n\n";
    cout << "data: " << data_aux.getData() << "\n\n";
    cout << "horario: " << horario_aux.getHorario() << "\n\n";
    cout << "preco: " << preco_aux.getPreco() << "\n\n";
    cout << "sala: " << sala_aux.getNumero_de_Sala() << "\n\n";
    cout << "disponibilidade: " << disponibilidade_aux.getDisponibilidade() << "\n\n";

 //----------------------------------------------------------------------------------------------------------

    // mensagem de boas vindas inicial, exibida apenas 1 vez

    cout << "BEM VINDO AO SISTEMA DE VENDA DE INGRESSOS" << endl;

    while(1){

    long long int novo_CPF;
    long long int CPF_login_aux;
    CPF CPF_login;
    char nova_senha[7];
    char senha_login_aux[7];
    Senha senha_login;

//---------------------------------------MENU-----------------------------------------------------

    menu_tela_inicial(&escolha_inicial);

    cout << "Sua escolha: ";
    cout << escolha_inicial << endl;
    cout << "\n";

    switch (escolha_inicial){

//----------------------------------OPT 1, novo usuario----------------------------------------------------------

        case 1:          // estou usando 69386992086 como exemplo de valor valido de CPF e pAo123 como a senha valida, que nem nos testes do trabalho 1
            cout << "Digite seu CPF (apenas os numeros): " << endl;
            cin >> novo_CPF;

            cout << "Seu CPF: ";
            cout << novo_CPF;
            cout << "\n";

            cout<<"Digite sua senha: " << endl;
            cin >> nova_senha;

            cout << "Sua senha: ";
            cout << nova_senha;
            cout << "\n";

            usuario1.setUsuario(novo_CPF, nova_senha);

            resultado = container.incluir(usuario1);

            break;

        case 2:

            cout << "Digite seu CPF (apenas os numeros): " << endl;
            cin >> CPF_login_aux;

            cout << "Seu CPF: ";
            cout << CPF_login_aux;
            cout << "\n";

            cout<<"Digite sua senha: " << endl;
            cin >> senha_login_aux;

            cout << "Sua senha: ";
            cout << senha_login_aux;
            cout << "\n";

            CPF_login.setCPF(CPF_login_aux);
            senha_login.setSenha(senha_login_aux);

            resultado = container.pesquisar(CPF_login);
            cout << resultado.getValor();
            cout << "\n";

            break;

        case 3:

            // printa o container de eventos, minha sugestão é criar um evento padrão que é criado sempre que o programa começa só pra demosntrar que isso funciona. Pode ser um show da Hatsune de boas.
            mostra_evento = container_e.mostrar();
            mostra_apresentacao = container_ap.mostrar();
            cout << "\n";
            break;

        case 4:

            cout << "Adeus e volte sempre!" << endl;
            return 0;

            break;
        }
    }

    return 0;
    */
            cout << "\n";

    CntrGeral cntrGeral;
    CntrIUAutenticacao cntrIUAutenticacao;
    CntrISAutenticacao cntrISAutenticacao;
    CntrISUsuario cntrISUsuario;
    CntrIUUsuario cntrIUUsuario;

    cntrGeral.setCntrIUAutenticacao(&cntrIUAutenticacao);
    cntrGeral.setCntrIUUsuario(&cntrIUUsuario);

    cntrIUAutenticacao.setCntrISAutenticacao(&cntrISAutenticacao);
    cntrIUUsuario.setCntrISUsuario(&cntrISUsuario);

    Usuario usuario_cliente;
    Cartao_de_credito cartao_de_credito_cliente;
    ContainerUsuario container_usuario;
    ContainerCartao_de_credito container_cartao_de_credito;

    //ContainerEvento container_e;

    //ContainerApresentacoes container_ap;

    //usuario_cliente = cntrIUUsuario.Criar_usuario();
    //cartao_de_credito_cliente = cntrIUUsuario.Criar_cartao_de_credito(usuario_cliente);

    //cntrISUsuario.Cadastrar(&container_usuario, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente);
    //cntrISAutenticacao.Autenticar(&container_usuario, usuario_cliente);

    /*
    while( cntrISAutenticacao.Mostrar_Menu(&container_usuario, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente) == false ){
    cout << "Faca o login para mais opcoes\n"
    }
    cout << "------------------------------------------------------" << endl;
    cout << "------- Faca o login para mais opcoes ----------------" << endl;
    cout << "------------------------------------------------------" << endl;
    */
    cntrISAutenticacao.Mostrar_Menu(&container_usuario, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente, container_e, container_ap);

    //cntrISAutenticacao.Mostrar_Menu(&container_usuario, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente);
    //cntrISAutenticacao.Mostrar_Menu(&container_usuario, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente);
    return 0;
}
