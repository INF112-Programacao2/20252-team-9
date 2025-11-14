//Protecao contra multiplas compilacoes
#ifndef PROJETO_FINAL_INF_112_ATENDENTE
#define PROJETO_FINAL_INF_112_ATENDENTE

//Includes
#include <string>
#include "Pessoa.h"


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
        void setMatricula(std::string matricula);

        //Metodos
        void VizualizaDados() override;
        void VizualizaAgendamentos() override; // Metodos herdados de pessoa
        void CadastrarMedico();
        void DesligarMedico();
        void MarcarAgendamento(); //Função que também pode ser executada pelo paciente
        void ConsultaSaldoDaClinica();
        void CriarServico();
        void AlterarServico();
        
};

#endif // PROJETO_FINAL_INF_112_ATENDENTE