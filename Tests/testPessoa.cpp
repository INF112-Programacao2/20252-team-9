//Arquivo para teste dos métodos da classe pessoa.h
//Includes
#include <iostream>
#include "../Headers/Pessoa.h"

//Criei uma classe momentania nesse arquivo, que é exatamente igual a pessoa, com o unico objetivo de testar seus métodos
//Foi necessário porque quando você tem uma implementacao virtual=0, você nao pode nem sequer instanciar a variavel
class PessoaMock : public Pessoa {
public:
    PessoaMock(std::string nome, std::string cpf, std::string senha, std::string telefone)
        :Pessoa(nome, cpf, senha, telefone){}

    void VizualizaAgendamentos(Clinica* clinica) override{
        std::cout << "[Teste] VizualizaAgendamentos foi chamado." << std::endl;
    }
};

int main(){
    //Teste padrao, sem envolver o tratamento de excessões
    PessoaMock pessoa1 = PessoaMock("Carlos Silva", "128.025.405-00", "carlos123", "(31) 94534-1010");
    std::cout << "Teste dos gets:\n";
    std::cout << "Nome: " << pessoa1.getNome() << std::endl;
    std::cout << "CPF: " << pessoa1.getCpf() << std::endl;
    std::cout << "Senha: " << pessoa1.getSenha() << std::endl;
    std::cout << "Telefone: " << pessoa1.getTelefone() << std::endl;

    //Teste dos sets
    pessoa1.setNome("Mariana Souza");
    pessoa1.setSenha("senha123");
    pessoa1.setTelefone("(31) 98434-9432");

    std::cout << "Teste dos sets:\n";
    std::cout << "Nome: " << pessoa1.getNome() << std::endl;
    std::cout << "CPF: " << pessoa1.getCpf() << std::endl;
    std::cout << "Senha: " << pessoa1.getSenha() << std::endl;
    std::cout << "Telefone: " << pessoa1.getTelefone() << std::endl;

    //Teste do método visualizar dados
    std::cout << "Teste do metodo visualizar dados:\n";
    pessoa1.VizualizaDados();

    /*Exceptions*/

    //Construtor
    std::cout << "Teste de erros para o construtor:\n";

    //Nome vazio ou com espaços apenas
    try{PessoaMock pessoa = PessoaMock("   ", "128.025.405-00", "carlos123", "(31) 94534-1010");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //CPF com formato invalido
    try{PessoaMock pessoa = PessoaMock("Carlos Silva", "12803489555", "carlos123", "(31) 94534-1010");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Senha vazia ou com espaços apenas
    try{PessoaMock pessoa = PessoaMock("Carlos Silva", "128.025.405-00", "", "(31) 94534-1010");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Telefone com formato invalido
    try{PessoaMock pessoa = PessoaMock("Carlos Silva", "128.025.405-00", "carlos123", "31934218432");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch(std::exception &e){std::cout << e.what() << std::endl;}

    //Sets
    std::cout << "Teste dos erros para os sets:\n";
    PessoaMock pessoa2 = PessoaMock("Joao Pedro Alvesa", "348.765.835-40", "joao_pedro", "(31) 97435-8527");

    //Nome vazio ou com espacos
    try{pessoa2.setNome("  ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    //Senha vazia ou com espaços
    try{pessoa2.setSenha("  ");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}

    //Telefone com formato invalido
    try{pessoa2.setTelefone("31974358527");}
    catch(std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    return 0;
}