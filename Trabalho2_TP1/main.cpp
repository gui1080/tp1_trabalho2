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

    int escolha_inicial = 0;
    bool mostra_evento;

//-----------------------------------CONTAINERS-----------------------------------------------------------------

    ResultadoUsuario resultado;
    ContainerUsuario container;

    ResultadoEvento resultado_e;
    ContainerEvento container_e;


//----------------------------------INICIALIZANDO OS EVENTOS DEFAULT----------------------------------------------------------

    std::cout.setstate(std::ios_base::failbit);       // essa linha "bloqueia" os prints no comeco do programa

    Evento evento_padrao_1;
    evento_padrao_1.setEvento(645, "Hatsune Miku Live!", "Brasilia", "DF", 4, "L");
    resultado_e = container_e.incluir(evento_padrao_1);

    Evento evento_padrao_2;
    evento_padrao_2.setEvento(132, "Black Sabbath Tour!", "Rio de Janeiro", "RJ", 4, "14");
    resultado_e = container_e.incluir(evento_padrao_2);

    Evento evento_padrao_3;
    evento_padrao_3.setEvento(984, "Hamlet, por Shakespeare", "Sao Paulo", "SP", 1, "12");
    resultado_e = container_e.incluir(evento_padrao_3);

    Evento evento_padrao_4;
    evento_padrao_4.setEvento(923, "Jota Quest Acustico", "Sao Paulo", "SP", 3, "L");
    resultado_e = container_e.incluir(evento_padrao_4);

    std::cout.clear();
//--------------------------------------------INICIALIZANDO O USUÁRIO--------------------------------------------------------
    Usuario usuario1;

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
            cout << "\n";
            break;

        case 4:

            cout << "Adeus e volte sempre!" << endl;
            return 0;

            break;
        }
    }


    return 0;
}
