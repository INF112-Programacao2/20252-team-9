//Arquivo para teste dos métodos da classe Agendamentos.h
//Includes
#include <iostream>
#include "../Headers/Agendamento.h"

int main() {

    std::cout << "===== TESTES DE AGENDAMENTO =====\n\n";

    Plano plano("UNIMED", 0.2);
    Paciente paciente("Gustavo Santos", "121.232.343-55", "guga_santos", "(31) 98989-1212", "01/04/2015", 'M', "Autismo leve, requer paciencia no atendimento", &plano);
    Medico medico("Marcos Oliveira", "123.456.789-00", "senha123", "(31) 98888-1111", "CRO/MG 12345", "Clinico Geral");
    Servico servico("Limpeza e Raspagem", 250.00, 45, "Preventivo");

    // AGENDAMENTO VÁLIDO

    std::cout << "\n--- Criando agendamento válido ---\n";

    Agendamento agendamento("12/12/2024", "10:30", &paciente, &medico, &servico);

    agendamento.imprimirResumido();
    std::cout << std::endl;
    agendamento.imprimirDetalhado();

    std::cout << "Data: " << agendamento.getData() << std::endl;
    std::cout << "Feedback vazio: " << agendamento.getFeedback() << std::endl;

    agendamento.setFeedback("Bom =)");
    std::cout << "Feedback preenchido: " << agendamento.getFeedback() << std::endl;

    std::cout << "Horario: " << agendamento.getHorario() << std::endl;
    std::cout << "Status: " << (agendamento.isConcluido() ? "Concluído" : "Pendente") << std::endl;

    // TESTES DE SETTERS VÁLIDOS
    std::cout << "\n--- Testando setters válidos ---\n";

    agendamento.setData("20/01/2025");
    std::cout << "Nova data: " << agendamento.getData() << std::endl;

    agendamento.setHorario("08:15");
    std::cout << "Novo horário: " << agendamento.getHorario() << std::endl;

    agendamento.setFeedback("Excelente atendimento");
    std::cout << "Novo feedback: " << agendamento.getFeedback() << std::endl;

    // TESTES DE EXCEÇÃO
    std::cout << "\n===== TESTES DE EXCEÇÃO =====\n";

    std::cout << "\n-- Tentando criar agendamento com data inválida --\n";
    try {
        Agendamento a("99/99/9999", "10:00", &paciente, &medico, &servico);
    } catch (const std::exception &e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    std::cout << "\n-- Tentando criar agendamento com horário inválido --\n";
    try {
        Agendamento a("10/10/2025", "99:99", &paciente, &medico, &servico);
    } catch (const std::exception &e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    std::cout << "\n-- Tentando criar agendamento com paciente nulo --\n";
    try {
        Agendamento a("10/10/2025", "10:00", nullptr, &medico, &servico);
    } catch (const std::exception &e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    std::cout << "\n-- Tentando chamar setHorario com horário inválido --\n";
    try {
        agendamento.setHorario("ab:cd");
    } catch (const std::exception &e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    std::cout << "\n-- Tentando chamar setFeedback com string vazia --\n";
    try {
        agendamento.setFeedback("");
    } catch (const std::exception &e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }

    std::cout << "\n===== FIM DOS TESTES =====\n";

    return 0;
}