//Arquivo para testes da classe clinca.h
//Includes
#include <iostream>
#include "../Headers/Clinica.h"

int main(){
    //Inicialização da variável e população
    Clinica clinica = Clinica("Centro odontologico");
    clinica.popularClinica("populacao.txt");

    //Teste dos gets
    std::cout << "Get dos planos:\n";
    const std::vector<std::unique_ptr<Plano>>& planos = clinica.getPlanos();
    for(unsigned int i=0; i<planos.size(); i++)
        planos[i].get()->visualizarDados();

    std::cout << "\nGet dos servicos:\n";
    const std::vector<std::unique_ptr<Servico>>& servicos = clinica.getServicos();
    for(unsigned int i=0; i<servicos.size(); i++)
        servicos[i].get()->visualizarDados();

    std::cout << "\nGet dos medicos:\n";
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica.getMedicos();
    for(unsigned int i=0; i<medicos.size(); i++)
        medicos[i].get()->VizualizaDados();

    std::cout << "\nGet dos pacientes\n";
    const std::vector<std::unique_ptr<Paciente>>& pacientes = clinica.getPacientes();
    for(unsigned int i=0; i<pacientes.size(); i++)
        pacientes[i].get()->VizualizaDados();

    std::cout << "\nGet dos agendamentos\n";
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica.getAgendamentos();
    for(unsigned int i=0; i<agendamentos.size(); i++)
        agendamentos[i].get()->imprimirResumido();


    //Teste dos sets
    std::cout << "Teste dos saldos:\n";
    clinica.setNome("Centro ortopedico");
    clinica.setSaldo(1000);

    std::cout << clinica.getNome() << std::endl;
    std::cout << clinica.getSaldo() << std::endl;

    //Teste dos metodos de remover
    std::cout << "Testes dos metodos de remover elementos da clinica\n";

    try{
        Plano* plano = planos[0].get();
        clinica.removerPlano(plano);    
        std::cout << "Plano removido com sucesso\n";

        Servico* servico = servicos[0].get();
        clinica.removerServico(servico);
        std::cout << "Servico removido com sucesso\n";

        Medico* medico = medicos[0].get();
        clinica.removerMedico(medico);
        std::cout << "Medico removido com sucesso\n";

        Paciente* paciente = pacientes[0].get();
        clinica.removerPaciente(paciente);
        std::cout << "Paciente removido com sucesso\n";
        
        Agendamento* agendamento = agendamentos[0].get();
        clinica.removerAgendamento(agendamento);
        std::cout << "Agendamento removido com sucesso\n";

    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }

    /*Exceptions*/
    
    //Construtor
    std::cout << "Teste de erros para o construtor\n";

    //Nome vazio ou com espacos
    try{Clinica clinica = Clinica("   ");} 
    catch(std::exception&e) {std::cout << e.what() << std::endl;}

    //Setters
    std::cout << "Teste de erros para os setters:\n";
    Clinica clinica2 = Clinica("Instituicao cuidadora");

    //Nome vazio ou com espacos
    try{clinica2.setNome("   ");} 
    catch(std::exception&e) {std::cout << e.what() << std::endl;}

    //Saldo negativo
    try{clinica2.setSaldo(-1000);} 
    catch(std::exception&e) {std::cout << e.what() << std::endl;}

    //Metodos de remover
    std::cout << "Teste das excessoes metodos de remover:\n";

    Plano* plano = nullptr;
    Servico* servico = nullptr;
    Medico* medico = nullptr;
    Paciente* paciente = nullptr;
    Agendamento* agendamento = nullptr;

    try{clinica2.removerPlano(plano);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    try{clinica2.removerServico(servico);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    try{clinica2.removerMedico(medico);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    try{clinica2.removerPaciente(paciente);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    try{clinica2.removerAgendamento(agendamento);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}  
    
    return 0;
}