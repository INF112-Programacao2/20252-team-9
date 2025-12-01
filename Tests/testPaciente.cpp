#include <iostream>
#include "../Headers/Paciente.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include "../Headers/Plano.h"

int main(){

    std::cout <<"Testando a classe Pacientes.\n";

    Clinica clinica("Salle's medic clinic");
    clinica.popularClinica("../populacao.txt");

    
    Plano plano1("Nenhum", 0);
    Plano plano2("UNIMED", 0.3);
    
    //Paciente okay
    Paciente p1("Maria Gomes","123.456.789-10", "abc", "(32) 98856-1271", "25/01/1980", 'F', "Usa aparelho ortodontico a 1 ano e meio", &plano1);
    
    //TESTE DE EXCEÇÕES:
    //Nome, cpf, telefone e senha já foram testados em testPessoa

    try{ //Data de nascimento
        Paciente p2("Jessica Padilha", "012.056.968-10", "ufv25", "(31) 6678-5144", "54/01/1991", 'F', "Nenhuma observacao", &plano2);
    }
    catch(std::invalid_argument &e){ 
        std::cerr<<e.what()<<std::endl;}
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;}
    
    try{ //Sexo
        Paciente p3("Jonas Brothers", "123.548.958-98", "dpi25", "(32) 6685-7834", "31/12/1989", '4', "Mandibula deslocada, cuidado com procedimentos longos", &plano1);
    }
    catch(std::invalid_argument &e){ 
        std::cerr<<e.what()<<std::endl;}
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;}

    try{ //Sexo
        Paciente p4("Timoteo Oswaldo", "120.589.123-87", "boliche32", "(32) 98715-7348", "05/07/1945", 'M', " ", &plano1);
    }
    catch(std::invalid_argument &e){ 
        std::cerr<<e.what()<<std::endl;}
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;}

    try{ //Plano
        Paciente p5("Gerluce Graca", "820.571.004-30", "12345", "(42) 84565-7378", "18/11/1992", 'F', " Sem observacoes ", nullptr);
    }
    catch(std::invalid_argument &e){ 
        std::cerr<<e.what()<<std::endl;}
    catch(std::exception &e){
        std::cerr<<e.what()<<std::endl;}

    //Agora, testando os métodos de Paciente com p1:
    
    //Gets:
    std::cout<<"----------Testando os gets-----------"<<std::endl;
    
    std::cout << "Nome: " << p1.getNome() << std::endl;
    std::cout << "CPF: " << p1.getCpf() << std::endl;
    std::cout << "Senha: " << p1.getSenha() << std::endl;
    std::cout << "Telefone: " << p1.getTelefone() << std::endl;
    std::cout << "Data de nascimento: " << p1.getDataDeNascimento() << std::endl;
    std::cout << "Sexo: " << p1.getSexo() << std::endl;
    std::cout << "Obs: " << p1.getObservacoes() << std::endl;
    std::cout << "Plano: " << p1.getPlano()->getNome() << std::endl;

    //Sets:

    p1.setNome("Marisa Gomes");
    p1.setSenha("123abc");
    p1.setTelefone("(31) 98812-3456");
    p1.setPlano(&plano2);
    p1.setObservacoes("Resistente a anestesia. No caso de cirurgias, aplicar uma dosagem ligeiramente maior.");


    std::cout<<"----------Testando os sets-----------"<<std::endl;
    
    std::cout << "Nome: " << p1.getNome() << std::endl;
    std::cout << "CPF: " << p1.getCpf() << std::endl;
    std::cout << "Senha: " << p1.getSenha() << std::endl;
    std::cout << "Telefone: " << p1.getTelefone() << std::endl;
    std::cout << "Data de nascimento: " << p1.getDataDeNascimento() << std::endl;
    std::cout << "Sexo: " << p1.getSexo() << std::endl;
    std::cout << "Obs: " << p1.getObservacoes() << std::endl;
    std::cout << "Plano: " << p1.getPlano()->getNome() << std::endl;



    //Testando Alteração dados
    bool alterando = true;
    std::cout<<"Testando a alteracao de dados"<<std::endl;
    while(alterando){
        p1.AlteraDados(&clinica);
        std::cout << std::endl;
        std::cout<<"Deseja continuar alterando?\n 0 - Nao\n 1-Sim\n"<<std::endl;
        std::cin>>alterando;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Testa a vizualização de dados:
    std::cout<<"Testando a vizualizacao de dados"<<std::endl;
    p1.VizualizaDados();
    std::cout << std::endl;

    //Testa a vizualização de agendamentos que está vazio
    std::cout<<"Testando a vizualizacao de agendamentos"<<std::endl;
    p1.VizualizaAgendamentos(&clinica);
    std::cout << std::endl;

    //Agenda um procedimento
    p1.Agendar(&clinica);
    std::cout << std::endl;

    //Testa de novo a vizualização de agendamentos, que agora possui 1
    std::cout<<"Testando a vizualizacao de agendamentos"<<std::endl;
    p1.VizualizaAgendamentos(&clinica);
    std::cout << std::endl;

    //Remove o agendamento
    std::cout<<"Testando o cancelamento de agendamentos"<<std::endl;
    p1.CancelarAgendamento(&clinica);
    std::cout << std::endl;

    //Testa a vizualização de agendamentos que está vazio novamente
    std::cout<<"Testando a vizualizacao de agendamentos"<<std::endl;
    p1.VizualizaAgendamentos(&clinica);
    std::cout << std::endl;

    //Tenta cancelar o procedimento de uma agenda vazia
    std::cout<<"Testando o cancelamento de agendamentos em uma agenda vazia"<<std::endl;
    p1.CancelarAgendamento(&clinica);
    std::cout << std::endl;

    return 0; //Fim do teste
}