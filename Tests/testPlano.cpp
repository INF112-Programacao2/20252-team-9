//Arquivo para teste dos métodos da classe plano.h
//Includes
#include <iostream>
#include "../Headers/Plano.h"

int main(){
    //Teste padrao, sem envolver o tratamento de excessões
    Plano plano1("UNIMED", 0.3);
    std::cout << "Nome do plano: " << plano1.getNome() << std::endl;
    std::cout << "Desconto do plano: " << plano1.getDesconto()*100 << "%\n";

    plano1.setNome("AGROS");
    plano1.setDesconto(0.25);
    std::cout << "Nome do plano: " << plano1.getNome() << std::endl;
    std::cout << "Desconto do plano: " << plano1.getDesconto()*100 << "%\n";

    /*Exceptions*/

    //Construtor
    std::cout << "Teste dos erros para o construtor:\n";

    //String vazia
    try{Plano plano2("", 0.5);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //String com espaços
    try{Plano plano3("      ", 0.5);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Valores negativos para desconto
    try{Plano plano4("Plano 4", -3.5);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Valores de desconto maiores que 100%
    try{Plano plano5("Plano 5", 1.2);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Sets
    std::cout << "Teste dos erros para os sets:\n";
    Plano teste("Amil", 0.15);

    //String vazia
    try{teste.setNome("");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //String com espaços
    try{teste.setNome("      ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Valores negativos para desconto
    try{teste.setDesconto(-3.5);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Valores de desconto maiores que 100%
    try{teste.setDesconto(1.2);}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    return 0;
}