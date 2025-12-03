#include "../Headers/Transacao.h"
#include "../Headers/Utils.h"
#include <stdexcept>

//Construtor
Transacao::Transacao(std::string horario, std::string data, Agendamento* agendamento){
    if(!validaHorario(horario))
        throw std::invalid_argument("\nHorario da transacao deve ser no formato XX:XX");
    this->horario = horario;

    if(!validaData(data))
        throw std::invalid_argument("\nData deve ser no formato XX/XX/XXXX");
    this->data = data;

    if(agendamento == nullptr)
        throw std::invalid_argument("\nObjeto agendamento nao pode ser vazio para transacao\n");
    this->agendamento = agendamento;
}

//Destrutor
Transacao::~Transacao() {}

//Getters
std::string Transacao::getHorario() const {return this->horario;}
std::string Transacao::getData() const {return this->data;}
Agendamento* Transacao::getAgendamento() const {return agendamento;}