#ifndef PROJETO_FINAL_INF_112_PESSOA_H
#define PROJETO_FINAL_INF_112_PESSOA_H

#include <string>

class Clinica;

class Pessoa{
    protected:
        std::string nome; 
        std::string cpf;
        std::string senha;
        std::string telefone;

    public:
        //Construtor e destrutor:
        Pessoa(std::string nome, std::string cpf, std::string senha, std::string telefone);
        ~Pessoa();
        
        //Gets
        std::string getNome() const;
        std::string getCpf() const;
        std::string getSenha() const;
        std::string getTelefone() const;
        
        //Sets
        void setNome( std::string nome);
        //CPF é uma informação "imutável", então não precisa de um método set()
        void setSenha(std::string senha);
        void setTelefone(std::string telefone);
        
        //Métodos
        //Impressão dos dados do usuário:
        virtual void VisualizaDados(); // Versão genérica com só os dados de pessoa 
                                       // e vai ser redefinida nas subclasses, com os dados
                                       // específicos de médico, atendente e cliente.
        //Impressão dos agendamentos:
        virtual void VisualizaAgendamentos(Clinica* clinica)=0; //Virtual pura, só vai ser implementada nas subclasses 
                                                // porque além do comportamento diferir entre as classes, não
                                                // existem um genérico.
        virtual void alterarDados(Clinica* clinica) = 0; //virtual puro, cada classe acima dela possui um modo 
                                                //diferente de alteração de dados
};

#endif //PROJETO_FINAL_INF_112_PESSOA_H