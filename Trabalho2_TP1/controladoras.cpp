#include "controladoras.h"

bool CntrIUAutenticacao::executar_autenticacao(CPF cpf) throw(runtime_error) {

}

bool CntrISAutenticacao::Autenticar(ContainerUsuario container_usuario, Usuario usuario) throw(runtime_error){

bool resultado;
CPF cpf_aux;
Senha senha_aux;
ResultadoUsuario resultado_usuario;

usuario.getUsuario(&cpf_aux, &senha_aux);

resultado_usuario = container_usuario.pesquisar(cpf_aux);

if(resultado_usuario.getValor() == false){

    cout << "Usuario nao cadastrado\n";

    return false;

} else if(resultado_usuario.getValor() == true){

cout << "usuario encontrado\n";

    return true;

}

}

void CntrISAutenticacao::Mostrar_Menu(){

    int escolha_inicial;

    cout << "Escolha o que se deseja fazer:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "----------    Criar usuario: Digite 1 ----------------" << endl;
    cout << "----------     Fazer login:  Digite 2 ----------------"  << endl;
    cout << "----  Apenas ver os eventos disponiveis: Digite 3  ---" << endl;
    cout << "---------  Fechar o software: Digite 4 ---------------" << endl;
    cout << "------------------------------------------------------\n" << endl;

    cin >> escolha_inicial;

    switch (escolha_inicial){

    case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            cout << "Adeus e volte sempre!" << endl;

            break;
        }


}

Usuario CntrIUUsuario::Criar_usuario() throw(runtime_error){

Usuario usuario_aux;
CPF cpf_aux;
Senha senha_aux;

usuario_aux.setUsuario(29700582191, "Pao123");
usuario_aux.getUsuario(&cpf_aux, &senha_aux);

cout << "Seu CPF e: " << cpf_aux.getCPF() << "\n";
cout << "Sua senha e: " << senha_aux.getSenha() << "\n\n";

return usuario_aux;

}

Apresentacao CntrIUUsuario::Menu_Edicao_apresentacao(){

Apresentacao apresentacao;

}

Usuario CntrIUUsuario::Menu_Edicao_usuario(){

}
