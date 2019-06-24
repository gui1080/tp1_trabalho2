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
#include "containers.cpp"
#include "containers.h"
#include "controladoras.h"

/*
Feito por:
Guilherme Braga Pinto
Gabriel Matheus da Rocha de Oliveira
Data limite de entrega: 25/06/2019
Professor Fernando Antonio de Araújo Chacon de Albuquerque
Primeiro semestre de 2019, UnB
*/

//Obs- Seguimos certas convenções como as que foram demonstradas em exeplos de sala de aula ao dar nome às variáveis, classes e testes.

using namespace std;

int main(){

    system("Color 0A");

//-----------------------------------CONTAINERS-----------------------------------------------------------------

    ResultadoUsuario resultado;
    ContainerUsuario container;
    ContainerIngresso container_i;

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

    //cout << "\n";

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

    while(1){

        usuario_cliente = cntrISAutenticacao.Mostrar_Menu(&container, &container_cartao_de_credito, usuario_cliente, cartao_de_credito_cliente, container_e, container_ap);
        cntrIUUsuario.Menu_Logado(usuario_cliente, &container_usuario, &container_cartao_de_credito, &container_e, &container_ap, &container_i);

    }

    return 0;
}
