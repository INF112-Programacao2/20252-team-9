#include <bits/stdc++.h>
#include "../Headers/Clinica.h"
#include "../Headers/Plano.h"
#include "../Headers/Utilsmain.h"
#include "../Headers/Utils.h"

int main(){
    Clinica clinica("Centro Odontológico");
    clinica.popularClinica("populacao.txt");

    Atendente atendente("Marcia", "111.111.111-11", "123", "(32) 99968-2006", "0001");
    clinica.setAtendente(atendente);
    
    Medico* medico = nullptr;
    Paciente* paciente = nullptr;

    unsigned int escolha;
    
    std::cout<<"========================================\n";
    std::cout<<"              BEM VINDO(A)              \n";
    std::cout<<"========================================\n";

    std::cout<< "\nA clínica " << clinica.getNome() << " agradece o seu acesso\n";

    enterParaContinuar();
    while (true){
        exibirMenuInicial();
        escolha = lerInteiro("Digite sua escolha: ", 1, 4);

        if(escolha == 1) {
            limparTela();

            std::cout<<"================================================\n";
            std::cout<<"                    ACESSO                      \n";
            std::cout<<"================================================\n";
            std::cout << "\nO que você deseja fazer: \n\n";
            std::cout << "1.: Cadastrar-se\n";
            std::cout << "2.: Fazer login\n";
            std::cout << "3.: Voltar\n";
            std::cout << "\n--------------------------------------------\n";
            int escolha = lerInteiro("Digite sua escolha: ", 1, 3);
            if(escolha == 1){
                std::string nome, cpf, senha, telefone, dataDeNascimento, observacoes;
                char sexo;
                Plano* plano = nullptr;
                limparTela();

                std::cout<<"================================================\n";
                std::cout<<"                    ACESSO                      \n";
                std::cout<<"================================================\n";

                if(dadosValidos(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano, &clinica)){
                    Paciente novoPaciente = Paciente(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano);
                    novoPaciente.VisualizaDados();

                    limparTela();

                    std::cout<<"================================================\n";
                    std::cout<<"                    ACESSO                      \n";
                    std::cout<<"================================================\n";        
                    
                    std::cout << "Voce realmente deseja realizar o cadastro?\n";
                    std::cout << "\n1.: Sim\n2.: Nao\n";
                    int confirmacao = lerInteiro("Digite sua escolha: ", 1, 2);
                    if(confirmacao == 2){
                        std::cout << "\nVoltando para o menu\n";
                        enterParaContinuar();
                        continue;
                    }

                    clinica.adicionarPaciente(std::make_unique<Paciente>(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano));
                    enterParaContinuar();
                    continue;
                }
                else {
                    limparTela();
                    continue;
                }
            }
            else if(escolha == 2){
                limparTela();
                bool tentouNovamente = true;
                while (true) {
                    std::string cpf, senha;
                    bool acertou = true;
                    exibirMenuLogin(cpf, senha, acertou);
                    int sucesso_login = clinica.validarPaciente(cpf, senha);
                    if(!acertou) {
                        std::cout << "\nCpf incorreto, deve ser no formato XXX.XXX.XXX-XX\n";
                        tentouNovamente = tentarNovamente();
                        if(tentouNovamente) {
                            limparTela();
                            continue;
                        }
                        else break;
                    }
                    else if(sucesso_login == 1){
                        std::cout << "\nLogin efetuado com sucesso!\n";
                        acharPaciente(&clinica, cpf, paciente);
                        enterParaContinuar();
                        break;
                    }
                    else if (sucesso_login == 0) {
                        std::cout << "\nA senha está incorreta.\n";
                        tentouNovamente = tentarNovamente();
                        if(tentouNovamente) {
                            limparTela();
                            continue;
                        }
                        else break;
                    }
                    else if(sucesso_login == -1) {
                        std::cout << "\nO cpf não foi encontrado no sistema.\n";
                        tentouNovamente = tentarNovamente();
                        if(tentouNovamente) {
                            limparTela();
                            continue;
                        }
                        else break;
                    }
                }

                if(!tentouNovamente) {
                    limparTela();
                    continue;
                }

                while(true){
                    exibirMenuPaciente();
                    escolha = lerInteiro("Digite o que deseja fazer: ", 1, 7);

                    if(escolha == 1){
                        paciente->VisualizaDados();
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 2){
                        paciente->alterarDados(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 3){
                        paciente->VisualizaAgendamentos(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 4){
                        paciente->Agendar(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 5){
                        paciente->CancelarAgendamento(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 6){
                        paciente->checarNotificacoes(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 7){
                        limparTela();
                        break;
                    }
                }
                
            }
            else {
                limparTela();
                continue;
            }
        }

        else if(escolha == 2) {
            limparTela();
            bool tentouNovamente = true;
            while(true){
                std::string cpf, senha;
                bool acertou = true;
                exibirMenuLogin(cpf, senha, acertou);

                int sucesso_login = clinica.validarMedico(cpf, senha);
                if(!acertou) {
                    std::cout << "Cpf incorreto, deve ser no formato XXX.XXX.XXX-XX\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
                else if(sucesso_login == 1){
                    std::cout << "\nLogin efetuado com sucesso!\n";
                    acharMedico(&clinica, cpf, medico);
                    enterParaContinuar();
                    break;
                }
                else if (sucesso_login == 0) {
                    std::cout << "A senha está incorreta.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
                else if(sucesso_login == -1) {
                    std::cout << "O cpf não foi encontrado no sistema.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
            }

            if(!tentouNovamente) {
                limparTela();
                continue;
            }

            while(true){
                exibirMenuMedico();
                escolha = lerInteiro("Digite sua escolha: ", 1, 6);

                if(escolha == 1){
                    medico->VisualizaDados();
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 2){
                    medico->VisualizaAgendamentos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 3){
                    medico->alterarDados(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 4){
                    medico->CancelarAgendamento(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 5){
                    medico->AdicionarFeedBack(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 6){
                    limparTela();
                    break;
                }
                    

            }

        }

        else if(escolha == 3) {
            limparTela();
            if(clinica.getAtendente() == nullptr) {
                std::cout << "\nAinda não temos atendente.\n";
                enterParaContinuar();
                continue;
            }
            bool tentouNovamente = true;
            while (true) {
                std::string cpf, senha;
                bool acertou = true;
                exibirMenuLogin(cpf, senha, acertou);
                int sucesso_login = clinica.validarAtendente(cpf, senha);
                if(!acertou) {
                    std::cout << "\nCpf incorreto, deve ser no formato XXX.XXX.XXX-XX\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
                else if(sucesso_login == 1){
                    std::cout << "\nLogin efetuado com sucesso!\n";
                    enterParaContinuar();
                    break;
                }
                else if (sucesso_login == 0) {
                    std::cout << "\nA senha está incorreta.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
                else if(sucesso_login == -1) {
                    std::cout << "\nO cpf não foi encontrado no sistema.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
            }

            if(!tentouNovamente) {
                limparTela();
                continue;
            }

            while(true){
                exibirMenuAtendente();
                escolha = lerInteiro("Digite sua escolha: ", 1, 26);

                if(escolha == 1){
                    atendente.VisualizaDados();
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 2){
                    atendente.VisualizaAgendamentos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 3){
                    atendente.visualizarPacientes(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 4){
                    atendente.visualizarMedicos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 5){
                    atendente.visulizarServicos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 6){
                    atendente.visualizarPlanos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 7){
                    atendente.agendarParaPaciente(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 8){
                    atendente.CadastrarPaciente(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 9){
                    atendente.CadastrarMedico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 10){
                    atendente.cadastrarServico(&clinica);
                    enterParaContinuar();
                    continue;
                }   
                else if(escolha == 11){
                    atendente.adicionarPlanos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 12){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 13){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 14){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 15){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 16){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 17){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 18){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 19){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 20){
                    atendente.DesligarMedico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 21){
                    std::cout << "\nFunção ainda nao implementada\n";
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 22){
                    atendente.removerPlano(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 23){
                    atendente.ConsultaSaldoDaClinica(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 24){
                    atendente.exibirHistoricoTransacoes(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 25){
                    atendente.alterarDados(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 26){
                    limparTela();
                    break;
                }
                    
            }

        }

        else if(escolha == 4) break;

        else continue;
    }


    std::cout << "Até mais!\n";
    
    return 0;
}