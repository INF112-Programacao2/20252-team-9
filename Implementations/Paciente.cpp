#include "../Headers/Paciente.h"
#include "../Headers/Utils.h"
#include "../Headers/Clinica.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>

Paciente::Paciente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string dataDeNascimento, char sexo, std::string observacoes, Plano* plano)
    :Pessoa(nome, cpf, senha, telefone){
        if(!validaData(dataDeNascimento))
            throw std::invalid_argument("Data de nascimento invalida\n");
        this->dataDeNascimento = dataDeNascimento;

        if(sexo != 'F' && sexo != 'M')
            throw std::invalid_argument("Sexo invalido, deve ser fornecido apenas um caractere maisculo, M para homem ou F para mulher)");
        this->sexo = sexo;

        if(stringVazia(observacoes))
            throw std::invalid_argument("Observacao para paciente invalida, nao pode ser vazia");
        this->observacoes = observacoes;

        if(plano == nullptr)
            throw std::invalid_argument("Ponteiro para plano nao pode ser vazio");
        this->plano = plano;
    }

Paciente::~Paciente(){}
        
//Gets
std::string Paciente::getDataDeNascimento() const {return dataDeNascimento;}
char Paciente::getSexo() const {return sexo;}
std::string Paciente::getObservacoes() const {return observacoes;}
Plano* Paciente::getPlano() const {return plano;}
        
//Sets
void Paciente::setObservacoes(std::string observacoes){
    if(stringVazia(observacoes))
            throw std::invalid_argument("Observacao para paciente invalida, nao pode ser vazia");
    this->observacoes = observacoes;
}

void Paciente::setSexo(char sexo){
    if(sexo != 'F' && sexo != 'M')
            throw std::invalid_argument("Sexo invalido, deve ser fornecido apenas um caractere maisculo, M para homem ou F para mulher)");
        this->sexo = sexo;
}

void Paciente::setPlano(Plano *plano){
    if(plano == nullptr)
        throw std::invalid_argument("Ponteiro para plano nao pode ser vazio");
    this->plano = plano;
}
        

//Métodos
//Impressão dos dados do usuário:
void Paciente :: AlteraDados(Clinica* clinica){ //Abre um menu, em que o paciente seleciona usando números qual atributo 
                            // ele deseja alterar, e o método chama o método set correspondente.
    
    //Impressão do menu:
    std::cout <<"\n------------------Menu de Ajuste dos Dados------------------"<<std::endl;
    std::cout <<std::endl;
    std::cout << "1 - Nome\n";
    std::cout << "2 - Senha\n";
    std::cout << "3 - Telefone\n";
    std::cout << "4 - Observacoes\n";
    std::cout << "5 - Sexo\n";
    std::cout << "6 - Plano de saude\n";
    std::cout << "7 - Sair\n";
    
    int escolha = lerInteiro("Digite o numero de qual das opcoes voce deseja alterar:", 1, 7);

    //Switch case para a implementaão do menu
    switch (escolha)
    {
        case 1: //Troca de nome
        {
            std::string novoNome;
            
            while(true){
                std::cout <<"Digite o novo nome do usuario:";
                getline(std::cin, novoNome);
                if(stringVazia(novoNome) || !somenteLetras(novoNome)){
                    std::cout << "Nome nao pode ser vazio e deve conter somente letra. Tente novamente\n";
                    continue;
                }
                break;
            }

            try{
                this->setNome(novoNome);
                std::cout << "Nome alterado com sucesso.\n";
                break;
            }
            catch(std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
            break;
        }

        case 2: //Mudança de senha
        {
            std::cout <<"Para realizar a troca de senha, voce deve primeiro inserir a atual." <<std::endl;
            std::cout <<"Voce possui 3 chances, caso nao se lembre ou nao acerte em nenhuma das 3 tentativas, procure a atendente da clinica para redefinir seua senha de login" <<std::endl;
            std::string senhaComparar;
            int tentativa=3;
            
            while(tentativa>0){
                std::cout<<"Digite sua senha atual:";
                while(true){
                    getline(std::cin, senhaComparar);
                    if(stringVazia(senhaComparar)){
                        std::cout << "Senha invalida, nao pode ser vazia. Tente novamente\n";
                        continue;
                    }
                    break;
                }

                if(senhaComparar != this->senha){
                    std::cout << "Senha incorreta. Tente novamente\n";
                    tentativa--;    
                }
                else
                    break;
            }
             
            if(tentativa == 0){
                std::cout << "Infelizmente suas tentativas se esgotaram, tente novamente mais tarde";
                break;
            }

            std::cout << "Senha verificada corretamente\n";

            std::string novaSenha;
         
            while(true){
                std::cout << "Digite a nova senha: ";
                getline(std::cin, novaSenha);
                if(stringVazia(novaSenha)){
                    std::cout << "Nova senha invalida, ela nao pode ser vazia. Tente novamente\n";
                    continue;
                }
                break;
            }
      
            try{
                this->setSenha(novaSenha);
                std::cout << "Senha alterada com sucesso\n";
                break;
            }
            catch(std::invalid_argument &e){
                std::cout << e.what() << std::endl;
            }
            break;
        }
     
        case 3: //Muda o telefone
        { 
            std::string novoTelefone;
            while(true){
                std::cout << "Digite a nova numero de telefone: ";
                getline(std::cin, novoTelefone);
                if(!validaTelefone(novoTelefone)){
                    std::cout << "Numero de telefone invalido, deve seguir o formato (XX) XXXXX-XXXX ou (XX) XXXX-XXXX. Tente novamente\n";
                    continue;
                }
                break;
            }


            try{
                this->setTelefone(novoTelefone);
                std::cout << "Telefone alterado com sucesso\n";
                break;
            }
            catch(std::invalid_argument &e){
                std::cout << e.what() << std::endl;
            }
            break;
        }

        case 4: //Alterar as observações
        {
            std::string novaObservacao;
            std::cout<<"Digite uma observacao que possa ser relevante aos mediscos(Ex: Alergias):" ;

            while(true){
                std::cout << "Digite a nova observacao do paciente: ";
                getline(std::cin, novaObservacao);
                if(stringVazia(novaObservacao)){
                    std::cout << "Observacao invalida, nao pode ser vazia. Tente novamente\n";
                    continue;
                }
                break;
            }

            try{
                this->setObservacoes(novaObservacao);
                std::cout << "Observacao alterada com sucesso.\n";
                break;
            }
            catch(std::invalid_argument &e){
                std::cout << e.what() << std::endl;
            }
            break;
        }

        case 5: //Altera Sexo
        {
            std::cout <<"Opcoes de sexo:\n";
            std::cout << "1 - Feminino\n";
            std::cout << "2 - Masculino\n";

            int entrada = lerInteiro("Digite a opcao do sexo que voce deseja: ", 1, 2);
            char sexo = entrada == 1? 'F' : 'M';

            try{
                this->setSexo(sexo);
                break;
            }
            catch(std::invalid_argument &e){
                std::cout << e.what() << std::endl;
            }
            std::cout<<"Alteracao bem sucedida.\n";
            break;
        }

        case 6:// Mudança de plano de saúde
        {
            std::cout << "Escolha o seu novo plano\n";
            const std::vector<std::unique_ptr<Plano>>& planos = clinica->getPlanos();

            if(planos.size() == 0){
                std::cout << "A clinica ainda nao possui parceria com nenhum convenio. Tente novamente mais tarde\n";
                break;
            }
            
            for(long unsigned int i=0; i<planos.size(); i++)
                std::cout << i+1 << ". " << planos[i].get()->getNome() << std::endl;

            int entrada = lerInteiro("Digite a opcao de plano desejada: ", 1, planos.size());
            Plano* plano = planos[entrada-1].get();

            try{
                this->setPlano(plano);
                std::cout << "Plano alterado com sucesso.";
                break;
;            }
            catch(std::invalid_argument &e){
                std::cout << e.what() << std::endl;
            }
            break;
        }

        case 7:
        {   
            std::cout<<"Saindo do menu de alteracoes."<<std::endl;
            break;
        }
    }

}

void Paciente :: VizualizaDados(){ // Sobreescrita do método da superclasse, além dos dados de pessoa
                                   // imprime também data de nascimento, sexo, as observações e plano de saúde
    Pessoa::VizualizaDados();
    
    std::cout << "Data de nascimento: " << this->dataDeNascimento << std::endl;
    std::cout << "Observacoes: " << this->observacoes << std::endl;
    std::cout << "Plano: " << plano->getNome() << std::endl; //Remoção da validação com nullptr,para diminuir a chance de bugs 
                                                             //porque vamos ter um objeto "Nenhum" com desconto=0 
                                                             //para os clientes sem plano.
    
}

                                    
//Impressão dos agendamentos do paciente
void Paciente::VizualizaAgendamentos(Clinica *clinica){ 
    std::cout << "\n<==========MEUS AGENDAMENTOS==========>\n" << this->getNome() << std::endl;
    
    bool encontrou = false;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    
    int indexVisual = 1;
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente()->getCpf() == this->cpf){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            encontrou = true;
        }
    }

    if(!encontrou)
        std::cout << "Voce nao possui nenhum agendamento\n";                
}

//Agenda
void Paciente::Agendar(Clinica *clinica){
    std::cout << "<====================\n";
    std::cout << "Vamos comecar o agendamento:\n";
    std::cout << "Primeiro escolha qual servico voce deseja agendar:\n";

    const std::vector<std::unique_ptr<Servico>>& servicos = clinica->getServicos();

    if(servicos.empty()){
        std::cout << "Infelizmente ainda nao ofertamnos nenhum servico na clinica. Tente novamente depois\n";
        return;
    }

    for(long unsigned int i=0; i<servicos.size(); i++){
        std::cout << i+1 << ". " << servicos[i].get()->getNome() << std::endl;
    }
    int escolhaServico = lerInteiro("Digite o numero do servico: ", 1, servicos.size());

    std::cout << "Agora escolha o medico:\n";
    int indexVisual = 1;
    std::vector<int> indexMedicosValidos;
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();
    for(long unsigned int i=0; i<medicos.size(); i++){
        if(servicos[escolhaServico].get()->getOcupacaoRequerida() == medicos[i].get()->getOcupacao()){
            std::cout << indexVisual << ". Dr(a) " << medicos[i].get()->getNome() << std::endl;
            indexMedicosValidos.push_back(i);
            indexVisual++;
        }
    }   

    if(indexMedicosValidos.empty()){
        std::cout << "Infelizmente nao ha nenhum medico no momento que realiza esse servico. Tente novamente depois\n";
        return;
    }
    int escolhaMedico = lerInteiro("Digite o numero do medico: ", 1, indexMedicosValidos.size());
    
    std::string data;
    std::vector<std::string> horarios;
    while(true){
        std::cout << "Digite uma data para o agendamento: ";
        getline(std::cin, data);
        if(!validaData(data)){
            std::cout << "Data de agendamento invalida, deve seguir o modelo XX/XX/XXXX\n";
            continue;
        }
        if(horarios.empty()){
            horarios = buscaHorarioValido(data, clinica);
            std::cout << "Nao ha nenhum horario disponivel nessa data. Tente novamente\n";
            continue;
        }
        break;
    }

    //Imprime horarios disponíveis
    std::cout << "Horarios disponiveis\n";
    for(long unsigned int i=0; i<horarios.size(); i++)
        std::cout << i+1 << ". " << horarios[i] << std::endl;

    int escolhaHorario = lerInteiro("Digite o horario desejado: ", 1, horarios.size());

    Medico* medico = medicos[indexMedicosValidos[escolhaMedico-1]].get();
    Servico* servico = servicos[escolhaServico-1].get();

    try{
        clinica->adicionarAgendamento(std::make_unique<Agendamento>(data, horarios[escolhaHorario-1], (this) , medico, servico));
        std::cout << "Agendamento realizado com sucesso.\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

//Cancelar agendamento
void Paciente::CancelarAgendamento(Clinica *clinica){
   std::cout << "\n<==========AGENDAMENTOS PENDENTES==========>\n" << this->getNome() << std::endl;

    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    int indexVisual=1;
    std::vector<int> agendamentosValidos;

    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente()->getCpf() == this->cpf && !agendamentos[i].get()->isConcluido()){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            agendamentosValidos.push_back(i);
        }
    }

    if(agendamentosValidos.empty()){
        std::cout << "Voce nao possui nenhum agendamento\n";
        return;
    }

    std::cout << "\n<====================>\n";
    int escolha = lerInteiro("Digite o numero do agendamento que deseja excluir: ", 1, indexVisual);

    //Acha e exclui o agaendamento escolhido
    try{
        Agendamento* ptr = agendamentos[agendamentosValidos[escolha-1]].get();
        clinica->removerAgendamento(ptr);
        std::cout << "Agendamento excluido com sucesso\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}


