//Arquivo para teste dos métodos da classe servico.h
//Includes
#include "../Headers/Servico.h"
#include <iostream>
#include <iomanip>

int main(){
    //Teste padrao, sem envolver o tratamento de excessões
    Servico servico1 = Servico("Tratamento de Canal", 800.00, 90, "Endodontia");
    std::cout << "Teste dos gets:\n";
    std::cout << "Id: " << servico1.getId() << std::endl;
    std::cout << "Nome: " << servico1.getNome() << std::endl;
    std::cout << "Valor: R$" << std::fixed << std::setprecision(2) << servico1.getValor() << std::endl;
    std::cout << "Duracao: " << servico1.getDuracao() << " min\n";
    std::cout << "Ocupacao necessaria: " << servico1.getOcupacaoRequerida() << std::endl;

    //Teste dos sets
    servico1.setNome("Extracao de Dente Siso");
    servico1.setValor(450.00);
    servico1.setDuracao(60);
    servico1.setOcupacaoRequerida("Cirurgiao Bucomaxilo");

    std::cout << "Teste dos sets:\n";
    std::cout << "Id: " << servico1.getId() << std::endl;
    std::cout << "Nome: " << servico1.getNome() << std::endl;
    std::cout << "Valor: R$" << std::fixed << std::setprecision(2) << servico1.getValor() << std::endl;
    std::cout << "Duracao: " << servico1.getDuracao() << " min\n";
    std::cout << "Ocupacao necessaria: " << servico1.getOcupacaoRequerida() << std::endl;

    /*Exceptions*/

    //Construtor
    std::cout << "Teste dos erros para o construtor:\n";

    //Nome vazio ou com espaços
    try{Servico servico = Servico("   ", 800.00, 90, "Endodontia");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Valor negativo
    try{Servico servico = Servico("Tratamento de Canal", -10, 90, "Endodontia");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Duracao negativa
    try{Servico servico2 = Servico("Tratamento de Canal", 800.00, -55, "Endodontia");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Duracao nula
    try{Servico servico2 = Servico("Tratamento de Canal", 800.00, 0, "Endodontia");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Ocupacao necessaria vazia ou com espacos
    try{Servico servico2 = Servico("Tratamento de Canal", 800.00, 90, "  ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Sets
    std::cout << "Teste dos erros para os sets:\n";
    Servico servico2 = Servico("Clareamento a Laser", 1200.00, 60, "Dentista Estetica");

    //Nome vazio ou com espacos
    try{servico2.setNome("  ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    //Valor negativo
    try{servico2.setValor(-10);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    //Duracao negativa
    try{servico2.setDuracao(-15);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    //Duracao nula
    try{servico2.setDuracao(0);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}  

    //Ocupacao necessaria vazia ou com espacos
    try{servico2.setOcupacaoRequerida("  ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    return 0;
}
