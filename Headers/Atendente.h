//Protecao contra multiplas compilacoes
#ifndef PROJETO_FINAL_INF_112_ATENDENTE
#define PROJETO_FINAL_INF_112_ATENDENTE

//Includes
#include <string>
#include "Pessoa.h"
#include "Clinica.h"


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
        void VizualizaDados() override;
        void VizualizaAgendamentos(Clinica* clinica) override; // Metodos herdados de pessoa
        void CadastrarPaciente(Clinica *clinica);
        void CadastrarMedico(Clinica* clinica);
        void DesligarMedico(Clinica* clinica);
        void MarcarAgendamento(Clinica* clinica); //Função que também pode ser executada pelo paciente
        void ConsultaSaldoDaClinica(Clinica* clinica);
        void CriarServico(Clinica* clinica);
        void AlterarServico(Clinica* clinica);
        
};

#endif // PROJETO_FINAL_INF_112_ATENDENTE