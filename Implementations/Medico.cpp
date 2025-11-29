#include "Medico.h"
#include "Clinica.h"
#include <iostream>

//Construtor
Medico::Medico(std::string nome, std::string cpf, std::string senha, std::string telefone, 
               std::string crm, std::string ocupacao)
    : Pessoa(nome, cpf, senha, telefone), crm(crm), ocupacao(ocupacao){
        this->saldo = 0;
    }

//Destrutor
Medico::~Medico() {
}

//Getters
std::string Medico::getCrm() const { 
    return crm; 
}

std::string Medico::getOcupacao() const { 
    return ocupacao; 
}

double Medico::getSaldo() const { 
    return saldo; 
}

//Setters
void Medico::setOcupacao(std::string ocupacao) {
    this->ocupacao = ocupacao;
}

void Medico::setSaldo(double saldo) {
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
void Medico::VizualizaAgendamentos(Clinica &clinica) {
    std::cout << "\nAgendamentos do Medico(a) " << this->getNome() << std::endl;
    
    bool encontrou = false;
    
    const auto& listaAgendamentos = clinica.getAgendamentos();

    for (const auto& ag : listaAgendamentos) {
        //Verifica se o médico do agendamento tem o mesmo CPF que este objeto
        if (ag->getMedico()->getCpf() == this->getCpf()) {
            ag->imprimir();
            encontrou = true;
        }
    }

    if (!encontrou) {
        std::cout << "Nenhum agendamento encontrado." << std::endl;
    }
}

//Interage com usuário para cancelar agendamento específico
void Medico::CancelarAgendamento(Clinica &clinica) {
    std::string dataAlvo, horarioAlvo;

    std::cout << "Cancelar Agendamento" << std::endl;
    std::cout << "Data (DD/MM/AAAA): ";
    std::cin >> dataAlvo;
    std::cout << "Horario: ";
    std::cin >> horarioAlvo;

    const auto& listaAgendamentos = clinica.getAgendamentos();
    Agendamento* alvo = nullptr;

    //Busca o ponteiro bruto do agendamento desejado
    for (const auto& ag : listaAgendamentos) {
        if (ag->getMedico()->getCpf() == this->getCpf() &&
            ag->getData() == dataAlvo &&
            ag->getHorario() == horarioAlvo) {
            
            alvo = ag.get(); 
            break;
        }
    }

    if (alvo != nullptr) {
        clinica.removerAgendamento(alvo);
        std::cout << "Agendamento cancelado com sucesso." << std::endl;
    } else {
        std::cout << "Agendamento nao encontrado." << std::endl;
    }
}

//Adiciona feedback
void Medico::AdicionarFeedBack(Clinica &clinica) {
    std::string dataAlvo, horarioAlvo;

    std::cout << "Adicionar Feedback" << std::endl;
    std::cout << "Data: ";
    std::cin >> dataAlvo;
    std::cout << "Horario: ";
    std::cin >> horarioAlvo;

    const auto& listaAgendamentos = clinica.getAgendamentos();
    Agendamento* alvo = nullptr;

    for (const auto& ag : listaAgendamentos) {
        if (ag->getMedico()->getCpf() == this->getCpf() &&
            ag->getData() == dataAlvo &&
            ag->getHorario() == horarioAlvo) {
            
            alvo = ag.get();
            break;
        }
    }

    if (alvo != nullptr) {
        std::string texto;
        std::cout << "Digite o feedback: ";
        std::cin.ignore(); //Limpar buffer
        std::getline(std::cin, texto);
        
        alvo->setFeedback(texto);
        
        std::cout << "Feedback registrado com sucesso!" << std::endl;
    } else {
        std::cout << "Agendamento nao encontrado." << std::endl;
    }
}

