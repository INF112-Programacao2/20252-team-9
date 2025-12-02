#include <bits/stdc++.h>
#include "../Headers/Clinica.h"
#include "../Headers/Plano.h"
#include "../Headers/Utilsmain.h"
#include "../Headers/Utils.h"

int main(){
    Clinica clinica("Xulio Medicina");
    clinica.popularClinica("populacao.txt");

    Atendente atendente("Marcia", "103.268.216-78", "123456", "(32) 99968-2006", "0001");
    clinica.setAtendente(atendente);
    
    Medico* medico = nullptr;
    Paciente* paciente = nullptr;

    unsigned int escolha;
    
    std::cout << "Você entrou na " << clinica.getNome() << "!\n";

    enterParaContinuar();
    while (true){
        exibirMenuInicial();
        escolha = lerInteiro("Digite sua escolha: ", 1, 4);

        if(escolha == 1) {
            std::cout << "\n<===========>\n";
            std::cout << "Você deseja: \n";
            std::cout << "1.: Cadastrar-se\n";
            std::cout << "2.: Fazer login\n";
            std::cout << "3.: Voltar\n";
            std::cout << "\n<===========>\n";
            int escolha = lerInteiro("Digite sua escolha: ", 1, 3);
            if(escolha == 1){
                std::string nome, cpf, senha, telefone, dataDeNascimento, observacoes;
                char sexo;
                Plano* plano = nullptr;
                if(dadosValidos(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano, &clinica)){
                    Paciente novoPaciente = Paciente(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano);
                    novoPaciente.VizualizaDados();
                    
                    std::cout << "Voce realmente deseja se cadastrar?\n";
                    std::cout << "\n1.: Sim\n2.: Nao\n";
                    int confirmacao = lerInteiro("Digite sua escolha: ", 1, 2);
                    if(confirmacao == 2){
                        std::cout << "Voltando para o menu\n";
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
                bool tentouNovamente = true;
                while (true) {
                    std::string cpf, senha;
                    bool acertou = true;
                    exibirMenuLogin(cpf, senha, acertou);
                    int sucesso_login = clinica.validarPaciente(cpf, senha);
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
                        std::cout << "Login efetuado com sucesso!\n";
                        acharPaciente(&clinica, cpf, paciente);
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
                    exibirMenuPaciente();
                    escolha = lerInteiro("Digite o que deseja fazer: ", 1, 7);

                    if(escolha == 1){
                        paciente->VizualizaDados();
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 2){
                        paciente->AlteraDados(&clinica);
                        enterParaContinuar();
                        continue;
                    }
                    else if(escolha == 3){
                        paciente->VizualizaAgendamentos(&clinica);
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
                    else if(escolha == 7)
                        break;
                }
                
            }
            else {
                limparTela();
                continue;
            }
        }

        else if(escolha == 2) {
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
                    std::cout << "Login efetuado com sucesso!\n";
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
                escolha = lerInteiro("Digite sua escolha: ", 1, 5);

                if(escolha == 1){
                    medico->VizualizaDados();
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 2){
                    medico->VizualizaAgendamentos(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 3){
                    medico->CancelarAgendamento(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 4){
                    medico->AdicionarFeedBack(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 5)
                    break;

            }

        }

        else if(escolha == 3) {
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
                    std::cout << "Cpf incorreto, deve ser no formato XXX.XXX.XXX-XX\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) {
                        limparTela();
                        continue;
                    }
                    else break;
                }
                else if(sucesso_login == 1){
                    std::cout << "Login efetuado com sucesso!\n";
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
                exibirMenuAtendente();
                escolha = lerInteiro("Digite sua escolha: ", 1, 9);

                if(escolha == 1){
                    atendente.VizualizaDados();
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 2){
                    atendente.AlterarServico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 3){
                    atendente.CadastrarMedico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 4){
                    atendente.CadastrarPaciente(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 5){
                    atendente.ConsultaSaldoDaClinica(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 6){
                    atendente.CriarServico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 7){
                    atendente.DesligarMedico(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 8){
                    atendente.agendarParaPaciente(&clinica);
                    enterParaContinuar();
                    continue;
                }
                else if(escolha == 9)
                    break;
            }

        }

        else if(escolha == 4) break;

        else continue;
    }


    std::cout << "Até mais!\n";
    
    return 0;
}