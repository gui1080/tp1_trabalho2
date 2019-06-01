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

    int escolha_inicial = 0;

    system("Color 0A");


    menu_tela_inicial(&escolha_inicial);

    cout << "Sua escolha: ";
    cout << escolha_inicial << endl;
    cout << "\n\n";

    switch (escolha_inicial){

        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
    // printa o container de eventos, minha sugestão é criar um evento padrão que é criado sempre que o programa começa só pra demosntrar que isso funciona. Pode ser um show da Hatsune de boas.
            break;
    }



    //ResultadoUsuario resultado;

    // Criar um container.

    ContainerUsuario container;

    // Exemplos de sucesso na inclus�o.


    return 0;
}
