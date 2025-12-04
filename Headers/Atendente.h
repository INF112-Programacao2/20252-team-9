//Protecao contra multiplas compilacoes
#ifndef PROJETO_FINAL_INF_112_ATENDENTE
#define PROJETO_FINAL_INF_112_ATENDENTE

//Includes
#include <string>
#include "Pessoa.h"
class Clinica;


class Atendente : public Pessoa{
    private:
        std::string matricula;

    //Metodos
    public:
        //Construtor e destrutor
        Atendente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string matricula);
        ~Atendente();

        //Gets
        std::string getMatricula() const;

        //Sets
        void setMatricula(std::string nova_matricula);

        
        //Metodos
        void alterarDados(Clinica* clinica) override;
        void VisualizaDados() override;
        void VisualizaAgendamentos(Clinica* clinica) override; // Metodos herdados de pessoa
        void CadastrarPaciente(Clinica *clinica);
        void CadastrarMedico(Clinica* clinica);
        void desligarMedico(Clinica* clinica);
        void ConsultaSaldoDaClinica(Clinica* clinica);
        void CriarServico(Clinica* clinica);
        void AlterarServico(Clinica* clinica);
        void agendarParaPaciente(Clinica* clinica);
        void visualizarMedicos(Clinica* clinica);
        void visualizarPacientes(Clinica* clinica);
        void visualizarPlanos(Clinica *clinica);
        void removerPlano(Clinica* clinica);
        void adicionarPlanos(Clinica* clinica);
        void visulizarServicos(Clinica* clinica);
        void cadastrarServico(Clinica* clinica);
        void exibirHistoricoTransacoes(Clinica* clinica);
        void desligarServico(Clinica *clinica);
        void desligarPaciente(Clinica *clinica);
        void alterarPlano(Clinica *clinica);
        void cancelarAgendamento(Clinica *clinica);
};

#endif // PROJETO_FINAL_INF_112_ATENDENTE