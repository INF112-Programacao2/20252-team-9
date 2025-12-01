#include <iostream>
#include "../Headers/Atendente.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include "../Headers/Plano.h"

int main(){
    Clinica clinica("Salle's medic clinic");

    Atendente atendente("Marcia", "103.268.216-78", "123456", "(32) 99968-2006", "0001");
    atendente.VizualizaDados();

    clinica.popularClinica("../populacao.txt");

    std::string escolha;
    while(true){
        std::cout << "1 - Alterar serviço\n";
        std::cout << "2 - Cadastrar Médico\n";
        std::cout << "3 - Cadastrar Paciente\n";
        std::cout << "4 - Consultar saldo da clínica\n";
        std::cout << "5 - Criar serviço\n";
        std::cout << "6 - Desligar Médico\n";
        std::cout << "7 - Marcar Agendamento\n";
        std::cout << "8 - Sair\n";
        std::cout << "Digite o que deseja fazer: ";
        getline(std::cin, escolha);

        if(escolha == "1") {
            atendente.AlterarServico(&clinica);
            //for(auto &serv : clinica.getServicos()) serv.get()->visualizarDados();
        }
        else if(escolha == "2") {
            atendente.CadastrarMedico(&clinica);
            for(auto &med : clinica.getMedicos()) med.get()->VizualizaDados();
        }
        else if(escolha == "3") {
            atendente.CadastrarPaciente(&clinica);
            for(auto &pac : clinica.getPacientes()) pac.get()->VizualizaDados();
        }
        else if(escolha == "4") {
            atendente.ConsultaSaldoDaClinica(&clinica);

        }
        else if(escolha == "5") {
            atendente.CriarServico(&clinica);
            for(auto &serv : clinica.getServicos()) serv.get()->visualizarDados();
        }
        else if(escolha == "6") {
            atendente.DesligarMedico(&clinica);
            for(auto &med : clinica.getMedicos()) med.get()->VizualizaDados();
        }
        else if(escolha == "7") {
            atendente.agendarParaPaciente(&clinica);
        }
        else if (escolha == "8") break;
        else continue;
        std::cout << "============\n";
    }
}