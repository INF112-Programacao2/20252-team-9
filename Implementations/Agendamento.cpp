//Includes
#include "../Headers/Agendamento.h"
#include "../Headers/Utils.h"
#include <iostream>
#include <iomanip>

//Define a data tida como referencia para saber se os agendamentos atuais já aconteceram ou não
std::string Agendamento::dateReference = "02/12/2025";

//Construtor
Agendamento::Agendamento(std::string data, std::string horario, Paciente* paciente, Medico* medico, Servico* servico){
    //Feedback é vazio quando cria o agendamento
    feedback = "";

    if(!validaData(data))
        throw std::invalid_argument("Data de agendamento invalida");
    this->data = data;

    if(!validaHorario(horario))
        throw std::invalid_argument("Horario de agendamento invalido");
    this->horario = horario;

    if(paciente == nullptr)
        throw std::invalid_argument("Ponteiro para paciente no agendamento nao pode ser nulo");
    this->paciente = paciente;
       
    if(medico == nullptr)
        throw std::invalid_argument("Ponteiro para medico no agendamento nao pode ser nulo");
    this->medico = medico;

    if(servico == nullptr)
        throw std::invalid_argument("Ponteiro para servico no agendamento nao pode ser nulo");
    this->servico = servico;

    //Compara a data do agendamento com a referencia para determinar se já ocorreu ou não
    if(comparaData(data, dateReference) == -1)
        this->concluido = true;
    else
        this->concluido = false;
}

//Destrutor
Agendamento::~Agendamento(){}

//Getters
std::string Agendamento::getData() const {return data;}
std::string Agendamento::getHorario() const {return horario;}
std::string Agendamento::getFeedback() const {return feedback;}
std::string Agendamento::getDateReference() {return dateReference;}
Paciente* Agendamento::getPaciente() const {return paciente;}
bool Agendamento::isConcluido() const {return concluido;}
Medico* Agendamento::getMedico() const {return medico;}
Servico* Agendamento::getServico() const {return servico;}

//Setters
void Agendamento::setData(std::string data){
    if(!validaData(data))
        throw std::invalid_argument("Data de agendamento invalida, deve seguir o modelo XX/XX/XXXX");
    this->data = data;
}

void Agendamento::setHorario(std::string horario){
    if(!validaHorario(horario))
        throw std::invalid_argument("Horario de agendamento invalido, deve seguir o modelo XX:XX");
    this->horario = horario;
}

void Agendamento::setFeedback(std::string feedback){
    if(stringVazia(feedback))
        throw std::invalid_argument("Feedback nao pode ser vazio");
    this->feedback = feedback;
}

void Agendamento::setPaciente(Paciente* paciente){
    if(paciente == nullptr)
        throw std::invalid_argument("Ponteiro para paciente no agendamento nao pode ser nulo");
    this->paciente = paciente;
}

void Agendamento::setMedico(Medico* medico){
    if(medico == nullptr)
        throw std::invalid_argument("Ponteiro para medico no agendamento nao pode ser nulo");
    this->medico = medico;
}

void Agendamento::setServico(Servico* servico){
    if(servico == nullptr)
        throw std::invalid_argument("Ponteiro para servico no agendamento nao pode ser nulo");
    this->servico = servico;
}

//Imprime os dados do agendamento detalhadamente
void Agendamento::imprimirDetalhado() const{
    std::cout << "\n | Data: " << data << " - Horario: " << horario << std::endl;
    std::cout << " | Valor: R$ " << std::fixed << std::setprecision(2) << servico->getValor() - servico->getValor() * paciente->getPlano()->getDesconto();
    std::cout << " | Duracao: " << servico->getDuracao() << " minutos" << std::endl;
    std::cout << " | Paciente: " << paciente->getNome() << std::endl;
    std::cout << " | Medico responsavel: " << medico->getNome() << std::endl;

    if(feedback.empty())
        std::cout << " | Feedback: pendente\n";
    else
        std::cout << " | Feedback: " << feedback << std::endl;

    std::cout << "\n----------------------------------------\n";
}

//Imprime os dados do agendamento resumidamente
void Agendamento::imprimirResumido() const{
    std::cout << "Data: " << data << " | Paciente: " << paciente->getNome() << " | Servico: " << servico->getNome();
    std::cout << " | Duracao: " << servico->getDuracao() << " minutos\n" << " | Valor (R$) : " << servico->getValor() - servico->getValor() * paciente->getPlano()->getDesconto();
}