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
    menu_tela_inicial(&escolha_inicial);

//-----------------------------------CONTAINERS---------------------------------------------------------

    ResultadoUsuario resultado;
    ContainerUsuario container;

//----------------------------------OPT 1, novo usuario----------------------------------------------------------
    Usuario usuario1;

    long long int novo_CPF;
    char nova_senha[7];
//--------------------------------------------------------------------------------------------

    cout << "Sua escolha: ";
    cout << escolha_inicial << endl;
    cout << "\n";

    switch (escolha_inicial){

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

            cout << "se deu certo, aqui da zero: ";
            cout << resultado.getValor();

            break;

        case 2:

            break;

        case 3:

            // printa o container de eventos, minha sugestão é criar um evento padrão que é criado sempre que o programa começa só pra demosntrar que isso funciona. Pode ser um show da Hatsune de boas.

            break;

        case 4:

            cout << "Adeus e volte sempre!" << endl;
            return 0;

            break;
    }


    // ai aqui eu suponho que a gnt faz um while 1 de interacao com o usuario em que a gnt espera o input dele


    return 0;
}
