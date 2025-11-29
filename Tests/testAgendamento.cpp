//Arquivo para teste dos métodos da classe Agendamentos.h
//Includes
#include <iostream>
#include "../Headers/Agendamento.h"

int main(){
    //Variáveis de outras classes para interagir com os testes do agendamento
    Plano plano = Plano("UNIMED", 0.2);
    Paciente paciente = Paciente("Gustavo Santos", "121.232.343-55", "guga_santos", "(31) 98989-1212", "01/04/2015", 'M', "Autismo leve, requer paciencia no atendimento", &plano);
    Medico medico = Medico("Marcos Oliveira", "123.456.789-00", "senha123", "(31) 98888-1111", "CRO/MG 12345", "Clinico Geral");
    Servico servico = Servico("Limpeza e Raspagem", 250.00, 45, "Preventivo");

    return 0;
}