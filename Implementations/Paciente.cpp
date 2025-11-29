#include "../Headers/Paciente.h"
#include "../Headers/Utils.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <vector>



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
        case 1: //Troca de nome
        {
            std::cout <<"Digite o novo nome do usuario:" <<std::endl;
            std::string novoNome;
            
            try{ //Valida o novo nome
                std::getline(std::cin, novoNome);
                if(!somenteLetras(novoNome)){ //Se tiver algum caracter que não é letra, lança a exceção
                    throw std::invalid_argument ("Seu nome nao pode conter numeros, nem caracteres especiais, Digite novamente:");
                }
            }
            catch(std::invalid_argument& e){ //Trata a entrada inválida
                while(!somenteLetras(novoNome)){
                    std::cerr<<e.what();
                    std::getline(std::cin, novoNome);
                }
            }
            catch(std::exception &e){//Erros + genéricos que pode acontecer quando o usuário insere a entrada. 
                std::cout <<"Desculpe, ocorreu um erro no sistema, por favor tente novamente mais tarde.";
                break;
            }
            //Com o nome validado, chama o set para fazer a alteração
            setNome(novoNome);
            std::cout<<"Seu nome foi atualizado no sistema." <<std::endl;
            break;
        }

        case 2: //Mudança de senha
        {
            std::cout <<"Para realizar a troca de senha, voce deve primeiro inserir a atual." <<std::endl;
            std::cout <<"Voce possui 3 chances, caso nao se lembre ou nao acerte em nenhuma das 3 tentativas, procure a atendente da clinica para redefinir seua senha de login" <<std::endl;
            std::string s;
            int tentativa=3;
            std::cout<<"Digite sua senha atual:";
            try{
                std::getline(std::cin, s);
                if (s!= senha){
                    throw std::invalid_argument("Senha incorreta");
                }
            }
            catch (std::exception &e){
                while(tentativa>0 && s!=senha){
                    tentativa--;
                    std::cerr<<e.what() <<std::endl;
                    std::cout<<"Voce possui " << tentativa <<" tentativas restante(s).\n Digite novamente:";
                    std::cin>>s;
                }
            }
            catch(std::exception &e){//Erro + genérico que pode acontecer quando o usuário insere a entrada. 
                std::cout <<"Desculpe, ocorreu um erro no sistema, por favor tente novamente mais tarde.";
                break;
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
                break;
            }
        }
     
        case 3: //Muda o telefone
        { 
            std::string novoTelefone;
            std::cout<<"Digite o novo numero de telefone, incluindo o DDD e sem espaco ou "-" entre os números." <<std::endl;
            std::cout <<"Exemplo de entrada: 31988123456 \n";
            try{ //Analisa  a entrada para ver se está no formato válido
                std::cin>> novoTelefone;
                if(novoTelefone.length()!=11 ||!somenteNumeros(novoTelefone)){
                    //Se não estiver, lança uma exceção
                    throw std::invalid_argument("Formato invalido, certifique de que contenha apenas números e inclua o DDD\n");
                }
            }
            catch(std::invalid_argument &e){ //Captura a exceção e solicita uma nova entrada
                while(novoTelefone.length()!=11 ||!somenteNumeros(novoTelefone)){
                    std::cerr<<e.what();
                    std::cout <<"Digite novamente:";
                    std::cin>>novoTelefone;
                }
            }
            catch(std::exception &e){//Trata algum erro + genérico que pode acontecer quando o usuário insere a entrada. 
                std::cout <<"Desculpe, ocorreu um erro no sistema, por favor tente novamente mais tarde.";
                break;
            }
            //Depois que a entrada é validada, chama o setTelefone e faz a alteração
            setTelefone(novoTelefone);
            std::cout<<"Alteracao do numero de telefone concluida.\n";//Mensagem de confirmação
            break;
        }

        case 4: //Alterar as observações
        {
            std::string novaObservacao;
            std::cout<<"Digite um paragrafo sucinto, com informacoes gostaria de colocar no bloco de observacoes, por exemplo: comorbidades, uso de medicamentos, etc..\n ";
            try{
                std::cin>>novaObservacao;
            }
            catch(std::exception &e){//Não tem nenhuma restrição específica para observações, esse tray/catch trata algum erro + genérico que pode acontecer quando o usuário insere a entrada. 
                std::cout <<"Desculpe, ocorreu um erro no sistema, por favor tente novamente mais tarde.";
                break;
            }
            setObservacoes(novaObservacao);
            std::cout<<"Suas informacoes no campo de 'observacoes' foram alteradas\n";
            break;
        }

        case 5: //Altera Sexo
        {
            std::cout <<"Digite uma das opções abaixo para fazer a alteração:"<<std::endl;
            std::cout <<std::endl;
            std::cout << "1 - Feminino\n";
            std::cout << "2 - Masculino\n";
            std::cout << "3 - Outro ou prefiro nao dizer.\n";
            int a;
            while(true){
                std::cin>>a;
                if(a==1||a==2||a==3){
                    break; //Sai do while
                }
                else{
                    std::cout<<"Opcao invalida, por favor digite novamente.\n";
                }
            }
            if(a==1){
                setSexo('F');
            }
            if(a==2){
                setSexo('M');
            }
            if(a==3){
                setSexo('O');
            }
            std::cout<<"Alteracao concluida\n";//Mensagem de sucesso
            break;
        }

        case 6:// Mudança de plano de saúde
        {
            
        }
    }
}

void Paciente :: VizualizaDados(){ // Sobreescrita do método da superclasse, além dos dados de pessoa
                                   // imprime também data de nascimento, sexo, as observações e plano de saúde
    Pessoa::VizualizaDados();
    
    std::cout << "Data de nascimento: " << this->dataDeNascimento << std::endl;
    std::cout << "Observacoes: " << this->observacoes << std::endl;
    
    if(plano!=nullptr){
        std::cout << "Plano: " << plano->getNome() << std::endl;
    }
    else{
        std::cout << "Esse paciente nao e cliente de nenhum plano" << std::endl;
    }
}

                                    
//Impressão dos agendamentos:
void Paciente :: VizualizaAgendamentos(Clinica &clinica){ //Reescrita do método de pessoa, imprime todos os agendamentos já
                                                          // realizados e os previstos para esse paciente.
    

                                                        
}
void Paciente :: Agendar(Clinica &clinica){} //Preenche os dados e cria um agendamento, e o adiciona no vetor agendamentos

void Paciente :: CancelarAgendamento(Clinica &clinica){} // Cancela um agendamento 
