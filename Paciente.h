#ifndef PROJETO_FINAL_INF_112_PACIENTE_H
#define PROJETO_FINAL_INF_112_PACIENTE_H

#include <string>
#include <vector>
#include "Pessoa.h"

class Agendamentos{};
class Plano{};

class Paciente : public Pessoa{

    private:
        std::string dataDeNascimento; 
        char sexo;
        std::string observacoes; //O paciente pode incluir um pequeno texto, sobre sua saúde,
                                // informando se possui alguma patologia, ou distúrbio, ou qualquer
                                // informação que possa ser útil em uma consulta, exame, cirurgia.
                                //Por exemplo:
                                // "Eu tenho hipertiroidesmo, e faço uso do medicamento x",
                                // "Tenho pressao alta" ou "Tenho SOP(Síndrome dos ovários poliscísticos)"
        
        std::vector <Agendamentos*> agendamentos; //Vetor com todos os agendamentos relacionados a esse paciente
        Plano plano;

    public:
        //Construtor e destrutor:
        Paciente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string dataDeNascimento, char sexo);
        ~Paciente();
        
        //Gets
        std::string getDataDeNascimento() const;
        char getSexo() const;
        std::string getObservacoes() const;
        std::vector<Agendamentos*> getAgendamentos() const;
        Plano getPlano();
        
        
        //Sets
        void setObservacoes( std::string observacoes);
        void setSexo(char sexo);
        void setPlano( Plano plano);
        
        //Métodos
        //Impressão dos dados do usuário:
        void AlteraDados(); //Abre um menu, em que o paciente seleciona usando números qual atributo 
                            // ele deseja alterar, e o método chama o método set correspondente.

        void VizualizaDados() override; // Sobreescrita do método da superclasse, além dos dados de pessoa
                                       // imprime também data de nascimento, sexo, as observações e plano de saúde

        //Impressão dos agendamentos:
        void VizualizaAgendamentos(); //Reescrita do método de pessoa, imprime todos os agendamentos já
                                      // realizados e os previstos para esse paciente.
        
        void Agendar(); //Preenche os dados e cria um agendamento, e o adiciona no vetor agendamentos

        void CancelarAgendamento(); // Cancela um agendamento 

};
    
#endif //PROJETO_FINAL_INF_112_PACIENTE_H