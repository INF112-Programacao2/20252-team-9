#include "../Headers/Medico.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include "../Headers/Agendamento.h"
#include <iostream>
#include <vector>


//Construtor
Medico::Medico(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string crm, std::string ocupacao)
    :Pessoa(nome, cpf, senha, telefone){
        if(!validaCrm(crm))
            throw std::invalid_argument("O crm para medico deve seguir o modelo SIGLA/UF NUMERO (Ex: CRO/MG 12345)");
        this->crm = crm;
        
        if(stringVazia(ocupacao))
            throw std::invalid_argument("Ocupacao para medico invalida");
        this->ocupacao = ocupacao;
    }

//Destrutor
Medico::~Medico(){}

//Getters
std::string Medico::getCrm() const {return crm;}
std::string Medico::getOcupacao() const {return ocupacao;}
double Medico::getSaldo() const {return saldo;}

//Setters
void Medico::setOcupacao(std::string ocupacao) {
    if(stringVazia(ocupacao))
            throw std::invalid_argument("Ocupacao para medico invalida");
        this->ocupacao = ocupacao;
}

void Medico::setSaldo(double saldo) {
    if(saldo<0){
        throw std::invalid_argument("Saldo do medico nao pode ser nulo");
    }
    this->saldo = saldo;
}

//Métodos

//Sobrescrita do método de Pessoa para incluir dados específicos do médico
void Medico::VizualizaDados() {
    //Chama a implementação da classe base primeiro
    Pessoa::VizualizaDados();
    
    std::cout << "CRM: " << this->crm << std::endl;
    std::cout << "Especialidade: " << this->ocupacao << std::endl;
    std::cout << "Saldo: R$ " << this->saldo << std::endl;
}

//Itera sobre o banco de dados da clínica para achar agendamentos deste médico
void Medico::VizualizaAgendamentos(Clinica*clinica) {
    std::cout << "\n<==========MEUS AGENDAMENTOS==========>\n" << this->getNome() << std::endl;
    
    bool encontrou = false;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    
    int indexVisual = 1;
    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            encontrou = true;
        }
    }

    if(!encontrou)
        std::cout << "Voce nao possui nenhum agendamento\n";
}

//Interage com usuário para cancelar agendamento específico
void Medico::CancelarAgendamento(Clinica* clinica) {
    std::cout << "\n<==========AGENDAMENTOS PENDENTES==========>\n" << this->getNome() << std::endl;

    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    int indexVisual=1;
    std::vector<int> agendamentosValidos;

    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm && !agendamentos[i].get()->isConcluido()){
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

//Adiciona feedback
void Medico::AdicionarFeedBack(Clinica* clinica) {
    std::cout << "\n<==========FEEDBACKS PENDENTES==========>\n" << this->getNome() << std::endl;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();

    int indexVisual=1;
    std::vector<int> agendamentosValidos;
    for(int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm && !agendamentos[i].get()->isConcluido()){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            agendamentosValidos.push_back(i);
        }
    }

    if(agendamentosValidos.empty()){
        std::cout << "Voce nao possui nenhum agendamento com feedback pendente\n";
        return;
    }
    
    std::cout << "\n<====================>\n";
    std::cout << "Digite o numero do agendamento que deseja dar feedback: ";
    int escolha = lerInteiro("Digite o numero do agendamento que deseja dar feedback: ", 1, indexVisual);
    std::string feedback;

    bool feedbackValido = false;
    while(!feedbackValido){
        getline(std::cin, feedback);
        if(stringVazia(feedback)){
            std::cout << "Feedback invalido, ele nao pode ser vazio. Tente novamente.\n";
            continue;
        }

        try{
            agendamentos[agendamentosValidos[escolha-1]].get()->setFeedback(feedback);
            feedbackValido = true;
            std::cout << "Feedback adicionado com sucesso\n";
        }catch(std::invalid_argument &e){
            std::cout << e.what() << std::endl;
        }
    }
}

