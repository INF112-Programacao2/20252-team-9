#ifndef PROJETO_FINAL_INF_112_TRANSACAO_H
#define PROJETO_FINAL_INF_112_TRANSACAO_H

#include "Paciente.h"
#include "Medico.h"
#include "Servico.h"
#include "Agendamento.h"

#include <string>

class Transacao{
    private:
        std::string horario;
        std::string data;

        Agendamento* agendamento;

    public:
        //Construtor
        Transacao(std::string horario, std::string data, Agendamento* servico);

        //Destrutor
        ~Transacao();

        //Getters
        std::string getHorario() const;
        std::string getData() const;
        Agendamento* getAgendamento() const;
};

#endif