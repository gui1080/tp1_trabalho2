#include "funcoes_auxiliares.h"

int menu_tela_inicial(int *escolha_inicial){

    cout << "BEM VINDO AO SISTEMA DE VENDA DE INGRESSOS" << endl;
    cout << "Escolha o que se deseja fazer:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "----------    Criar usuario: Digite 1 ----------------" << endl;
    cout << "----------     Fazer login:  Digite 2 ----------------"  << endl;
    cout << "----  Apenas ver os eventos disponiveis: Digite 3  ---" << endl;
    cout << "---------  Fechar o software: Digite 4 ---------------" << endl;
    cout << "------------------------------------------------------\n" << endl;

    cin >> *escolha_inicial;

    return *escolha_inicial;
}
