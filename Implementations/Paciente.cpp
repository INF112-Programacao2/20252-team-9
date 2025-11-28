#include "../Headers/Paciente.h"
#include "../Headers/Pessoa.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <vector>

//Função auxiliar que checa se o string é composto só por letras
bool somenteLetras(const std::string &palavra){ 

    for( char c : palavra){ //Percorre o string caractere por caractere
        if(!std::isalpha(static_cast<unsigned char>(c))){
            return false;
        }
    }

    return true;

}

Paciente :: Paciente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string dataDeNascimento, char sexo, std::string observacoes, Plano* plano)
    : Pessoa(nome, cpf, senha, telefone), dataDeNascimento(dataDeNascimento), sexo(sexo), observacoes(observacoes), plano(plano) {}

Paciente :: ~Paciente(){}
        
//Gets
std::string Paciente :: getDataDeNascimento() const{
    return dataDeNascimento;
}

char Paciente :: getSexo() const{
    return sexo;
}

std::string Paciente :: getObservacoes() const{
    return observacoes;
}

Plano* Paciente :: getPlano() const{
    return plano;
}
        
        
//Sets
void Paciente :: setObservacoes(std::string observacoes){
    (this->observacoes) = observacoes;

}

void Paciente :: setSexo(char sexo){
    (this->sexo)=sexo;

}

void Paciente :: setPlano(Plano &plano){
    (this->plano)=&plano;
}
        

//Métodos
//Impressão dos dados do usuário:
void Paciente :: AlteraDados(){ //Abre um menu, em que o paciente seleciona usando números qual atributo 
                            // ele deseja alterar, e o método chama o método set correspondente.
    int escolha;

    //Impressão do menu:
    std::cout <<"\n------------------Menu de Ajuste dos Dados------------------"<<std::endl;
    std::cout <<std::endl;
    std::cout << "1 - Nome\n";
    std::cout << "2 - Senha\n";
    std::cout << "3 - Telefone\n";
    std::cout << "4 - Observações\n";
    std::cout << "5 - Sexo\n";
    std::cout << "6 - Plano de saude\n";
    std::cout << "7 - Cancelar\n";
    
    std::cout <<"\n Digite o numero de qual das opcoes voce deseja alterar:";
    
    try{ //Validação da entrada com tratamento de exceção

        std::cin>> escolha; // Entrada do usuário
        
        //Se não esta listado no menu, lança a exceção argumento invalido
        if(escolha!=1 && escolha!=2 && escolha!= 3 && escolha!=4 && escolha!=5 && escolha!=6 && escolha!=7){
            throw std::invalid_argument("A opcao escolhida nao e valida, digite novamente:");
        }

    }catch(std::invalid_argument &e){ //Captura a exceção lançada, e fica em loop até que o usuario digite um valor válido
        while(escolha!=1 && escolha!=2 && escolha!= 3 && escolha!=4 && escolha!=5 && escolha!=6 && escolha!=7){
            std::cerr << e.what();
            std::cin>> escolha;
        }
    }

    //Switch case para a implementaão do menu
    switch (escolha)
    {
        case 1: {//Troca de nome
            std::cout <<"Digite o novo nome do usuario:" <<std::endl;
            std::string novoNome;
            
            try{ //Valida o novo nome
                std::cin >> novoNome;
                if(!somenteLetras(novoNome)){ //Se tiver algum caracter que não é letra, lança a exceção
                    throw std::invalid_argument ("Seu nome nao pode conter numeros, nem caracteres especiais, Digite novamente:");
                }
            }catch(std::invalid_argument& e){ //Trata a entrada inválida
                while(!somenteLetras(novoNome)){
                    std::cerr<<e.what();
                    std::cin>>novoNome; 
                }
            }
            //Com o nome validado, chama o set para fazer a alteração
            setNome(novoNome);
            std::cout<<"Seu nome foi atualizado no sistema." <<std::endl;
            break;
        }
        case 2: {//Mudança de senha
            std::cout <<"Para realizar a troca de senha, voce deve primeiro inserir a atual." <<std::endl;
            std::cout <<"Voce possui 3 chances, caso nao se lembre ou nao acerte em nenhuma das 3 tentativas, procure a atendente da clinica para redefinir seua senha de login" <<std::endl;
            std::string s;
            int tentativa=3;
            std::cout<<"Digite sua senha atual:";
            try{
                std::cin >> s;
                if (s!= senha){
                    throw std::invalid_argument("Senha incorreta");
                }
            }catch (std::exception &e){
                while(tentativa>0 && s!=senha){
                    tentativa--;
                    std::cerr<<e.what() <<std::endl;
                    std::cout<<"Voce possui " << tentativa <<" tentativas restante(s).\n Digite novamente:";
                    std::cin>>s;
                }
            }
            
            if(tentativa==0 && s!=senha){
                    std::cout <<"Voce esgotou suas tentativas, entao nao foi possivel alterar a senha. Por favor, procure a atendente da clinica para redefinir sua senha do sistema."<<std::endl;
            }

            if(s==senha){
                std::cout<<"Muito bem, agora informe por favor sua nova senha de login:" <<std::endl;
                std::string novaSenha;
                std::cin>>novaSenha;
                //Vamos ter algum tipo de validação para a senha? Ex: mínimo 4 caracteres
                setSenha(novaSenha);
                std::cout<<"Sua senha foi alterada no sistema."<<std::endl;
            }
        }
     
        case 3:{ //muda telefone

     }


     }
    



}



void Paciente :: VizualizaDados(){} // Sobreescrita do método da superclasse, além dos dados de pessoa
                                       // imprime também data de nascimento, sexo, as observações e plano de saúde

//Impressão dos agendamentos:
void Paciente :: VizualizaAgendamentos(Clinica &clinica){} //Reescrita do método de pessoa, imprime todos os agendamentos já
                                      // realizados e os previstos para esse paciente.
        
void Paciente :: Agendar(Clinica &clinica){} //Preenche os dados e cria um agendamento, e o adiciona no vetor agendamentos

void Paciente :: CancelarAgendamento(Clinica &clinica){} // Cancela um agendamento 
