//Arquivo para teste dos métodos da classe Medico.h
//Includes
#include "../Headers/Medico.h"
#include "../Headers/Clinica.h"
#include  "../Headers/Utils.h"
#include <iostream>

int main(){
    //Populacao da clinica para facilitar os testes do medico
    Clinica clinica = Clinica("Centro odontologico");
    clinica.popularClinica("populacao.txt");

    //Teste padrao, sem envolver o tratamento de excessões(Apenas atributos que diferem de pessoa)
    Medico medico = Medico("Manhago", "192.025.935-69", "senha123", "(31) 9999-9999", "CRM/MG 123456", "Dentista estetica");

    std::cout << "Teste dos gets\n";
    std::cout << "CRM: " << medico.getCrm() << std::endl;
    std::cout << "Ocupacao: " << medico.getOcupacao() << std::endl;
    std::cout << "Saldo: " << medico.getSaldo() << std::endl;

    //Teste de setters
    medico.setOcupacao("Cirurgiao");
    medico.setSaldo(1000);
    std::cout << "Tste dos setters:\n";
    std::cout << "Ocupacao: " << medico.getOcupacao() << std::endl;
    std::cout << "Saldo: " << medico.getSaldo() << std::endl;


    //Teste do metodo visualizar dados
    std::cout << "Metodo visualizar dados:\n";
    medico.VizualizaDados();

    //Uso de medicos da populacao para testar os restantes do metodos
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica.getMedicos();

    //Metodo de visualizar agendamentos
    medicos[0].get()->VizualizaAgendamentos(&clinica);

    //Metodo de cancelar um agendamento
    medico.CancelarAgendamento(&clinica);
    medicos[0].get()->CancelarAgendamento(&clinica);
    medicos[0].get()->VizualizaAgendamentos(&clinica);


    //Metodo para adicionar feedback
    medicos[0].get()->AdicionarFeedBack(&clinica);

    /*Exceptions*/

    //Construtor
    std::cout << "Teste de erros para construtor:\n";

    //CRM com formato invalido
    try{Medico medico = Medico("Icaro", "192.123.935-43", "senha123", "(31) 5313-9999", "CRMMG 123456", "Dentista estetica");}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    //Ocupacao vazia ou com espaços
    try{Medico medico = Medico("Icaro", "192.123.935-43", "senha123", "(31) 5313-9999", "CRM/MG 123456", "    ");}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    //Setters
    std::cout << "Teste de erros para os setters:\n";
    Medico medico3 = Medico("Icaro", "192.123.935-43", "senha123", "(31) 5313-9999", "CRM/MG 123456", "Dentista estetica");

    //Ocupacao vazia ou com espaçoes
    try{medico3.setOcupacao("   ");}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}
    
    //Saldo negativo
    try{medico3.setSaldo(-10);}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    return 0;
}