#include "../Headers/Medico.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utils.h"
#include "../Headers/Agendamento.h"
#include "../Headers/Utilsmain.h"
#include <iostream>
#include <vector>
#include <iomanip>


//Construtor
Medico::Medico(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string crm, std::string ocupacao)
    :Pessoa(nome, cpf, senha, telefone){
        if(!validaCrm(crm))
            throw std::invalid_argument("O crm para medico deve seguir o modelo SIGLA/UF NUMERO (Ex: CRO/MG 12345)");
        this->crm = crm;
        
        if(stringVazia(ocupacao))
            throw std::invalid_argument("Ocupacao para medico invalida");
        this->ocupacao = ocupacao;

        this->saldo = 0;
    }

//Destrutor
Medico::~Medico(){}

//Getters
std::string Medico::getCrm() const {return crm;}
std::string Medico::getOcupacao() const {return ocupacao;}
double Medico::getSaldo() const {return saldo;}

//Setters
void Medico::setOcupacao(std::string ocupacao) {
    if(stringVazia(ocupacao))
            throw std::invalid_argument("Ocupacao para medico invalida");
        this->ocupacao = ocupacao;
}

void Medico::setSaldo(double saldo) {
    if(saldo<0){
        throw std::invalid_argument("Saldo do medico nao pode ser nulo ou negativo");
    }
    this->saldo = saldo;
}

//Métodos

//Sobrescrita do método de Pessoa para incluir dados específicos do médico
void Medico::VisualizaDados() {
    //Chama a implementação da classe base primeiro
    Pessoa::VisualizaDados();
    
    std::cout << " | CRM: " << this->crm << std::endl;
    std::cout << " | Ocupação: " << this->ocupacao << std::endl;
    std::cout << " | Saldo: R$ " << this->saldo << std::endl;
}

void Medico::alterarDados(Clinica *clinica) {
    while (true){
        limparTela();
        std::cout <<"================================================\n";
        std::cout <<"                      DADOS                     \n";
        std::cout <<"================================================\n";

        this->VisualizaDados();

        std::cout << "\n 1.: Nome\n";
        std::cout << " 2.: Senha\n";
        std::cout << " 3.: Telefone\n";
        std::cout << " 4.: Ocupação\n";
        std::cout << " 5.: Sair\n";
        std::cout << "---------------------------------------\n";
        
        int escolha = lerInteiro("Digite sua escolha: ", 1, 5);

        limparTela();

        //Switch case para a implementção do menu
        switch (escolha)
        {
            case 1: //Troca de nome
            {
                std::string novoNome;
                
                while(true){

                    std::cout <<"================================================\n";
                    std::cout <<"                      DADOS                     \n";
                    std::cout <<"================================================\n";
                    std::cout <<"Digite o novo nome do usuario: ";
                    getline(std::cin, novoNome);
                    if(stringVazia(novoNome) || !somenteLetras(novoNome)){
                        std::cout << "\nNome nao pode ser vazio e deve conter somente letra. Tente novamente\n";
                        continue;
                    }
                    break;
                }

                try{
                    this->setNome(novoNome);
                    std::cout << "\nNome alterado com sucesso.\n";
                    break;
                }
                catch(std::invalid_argument &e) {
                    limparTela();
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case 2: //Mudança de senha
            {
                std::cout <<"================================================\n";
                std::cout <<"                      DADOS                     \n";
                std::cout <<"================================================\n";
                std::cout <<"Antes de alterar, digite a senha atual.\n";
                std::cout <<"Voce possui 3 chances.\n";
                std::cout << "Caso nao se lembre, procure a clinica \npara redefinir seua senha de login.\n";
                std::string senhaComparar;
                int tentativa=3;
                
                while(tentativa>0){
                    std::cout<<"\nDigite sua senha atual: ";
                    while(true){
                        getline(std::cin, senhaComparar);
                        if(stringVazia(senhaComparar)){
                            std::cout << "\nSenha invalida, nao pode ser vazia. Tente novamente\n";
                            continue;
                        }
                        break;
                    }

                    if(senhaComparar != this->senha){
                        std::cout << "\nSenha incorreta. Tente novamente!\n";
                        tentativa--;    
                    }
                    else
                        break;
                }
                
                if(tentativa == 0){
                    limparTela();
                    std::cout <<"================================================\n";
                    std::cout <<"                      DADOS                     \n";
                    std::cout <<"================================================\n";
                    std::cout <<"Infelizmente suas tentativas esgotaram. \n Tente novamente mais tarde.";
                    break;
                }

                std::cout << "\nSenha verificada corretamente\n";
                enterParaContinuar();

                std::string novaSenha;
            
                while(true){
                    std::cout <<"================================================\n";
                    std::cout <<"                      DADOS                     \n";
                    std::cout <<"================================================\n";
                    std::cout << "Digite a nova senha: ";

                    getline(std::cin, novaSenha);
                    if(stringVazia(novaSenha)){
                        std::cout << "\nNova senha invalida, ela nao pode ser vazia. Tente novamente\n";
                        enterParaContinuar();
                        continue;
                    }
                    break;
                }
        
                try{
                    this->setSenha(novaSenha);
                    std::cout << "\nSenha alterada com sucesso\n";
                    break;
                }
                catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
        
            case 3: //Muda o telefone
            { 
                std::string novoTelefone;
                while(true){
                    std::cout <<"================================================\n";
                    std::cout <<"                      DADOS                     \n";
                    std::cout <<"================================================\n";
                    std::cout << "Digite o novo numero de telefone: ";
                    getline(std::cin, novoTelefone);
                    if(!validaTelefone(novoTelefone)){
                        std::cout << "\nNumero de telefone invalido, deve seguir o formato (XX) XXXXX-XXXX ou (XX) XXXX-XXXX. Tente novamente\n";
                        enterParaContinuar();
                        continue;
                    }
                    break;
                }


                try{
                    this->setTelefone(novoTelefone);
                    std::cout << "\nTelefone alterado com sucesso\n";
                    break;
                }
                catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case 4:// Mudança de ocupação
            {
                std::string nova_ocupacao;
                while(true){
                    std::cout<<"================================================\n";
                    std::cout<<"                       DADOS                    \n";
                    std::cout<<"================================================\n";
                    std::cout << "Informe a nova ocupação do médico(a): ";
                    
                    getline(std::cin, nova_ocupacao);

                    if(stringVazia(nova_ocupacao) || !somenteLetras(nova_ocupacao)){
                        std::cout << "Ocupação nova inválida, tente novamente.\n";
                        continue;
                    }
                    break;
                }
                
                try {
                    this->setOcupacao(nova_ocupacao);

                }
                catch(std::invalid_argument &e) {
                    std::cout << e.what() << "\n";
                }

            }

            case 5: //sair do menu
            {   
                std::cout<<"\nSaindo do menu de alteracoes.\n"<<std::endl;
                break;
            }
        }
        int sair = lerInteiro("\nDeseja continuar alterando os dados?\n 1.: Sim\n 2.: Não\n\nDigite sua escolha:", 1, 2);
        if(sair == 1) continue;
        else if (sair == 2) break;
    }
}

//Itera sobre o banco de dados da clínica para achar agendamentos deste médico
void Medico::VisualizaAgendamentos(Clinica*clinica) {
    limparTela();
    std::cout << "\n====================MEUS AGENDAMENTOS====================\n" << std::endl;
    
    bool encontrou = false;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    
    int indexVisual = 1;
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            encontrou = true;
        }
    }

    if(!encontrou)
         std::cout << "Nao existe nenhum agendamento\n";
}

//Interage com usuário para cancelar agendamento específico
void Medico::CancelarAgendamento(Clinica* clinica) {
    limparTela();
    std::cout << "\n====================AGENDAMENTOS PENDENTES====================\n" << std::endl;

    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    int indexVisual=1;
    std::vector<int> agendamentosValidos;

    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm && !agendamentos[i].get()->isConcluido()){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            agendamentosValidos.push_back(i);
        }
    }
    
    if(agendamentosValidos.empty()){
        std::cout << "\nVoce nao possui nenhum agendamento\n";
        return;
    }
    
    std::cout << indexVisual << ".: Voltar\n";

    std::cout << "---------------------------------------\n";
    int escolha = lerInteiro("Digite sua escolha: ", 1, indexVisual+1);

    if(escolha == indexVisual){
        std::cout << "\nRetornando ao menu anterior\n";
        return;
    }

    //Acha e exclui o agaendamento escolhido
    try{
        Agendamento* ptr = agendamentos[agendamentosValidos[escolha-1]].get();
        clinica->removerAgendamento(ptr);
        std::cout << "\nAgendamento excluido com sucesso!\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

//Adiciona feedback
void Medico::AdicionarFeedBack(Clinica* clinica) {
    limparTela();
    std::cout << "\n====================FEEDBACKS PENDENTES====================\n" << std::endl;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();

    int indexVisual=1;
    std::vector<int> agendamentosValidos;
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getMedico()->getCrm() == this->crm && agendamentos[i].get()->isConcluido() && agendamentos[i].get()->getFeedback() == ""){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            agendamentosValidos.push_back(i);
        }
    }
    
    
    if(agendamentosValidos.empty()){
        std::cout << "\nVoce nao possui nenhum agendamento com feedback pendente\n";
        return;
    }
    
    std::cout << indexVisual << ".: Voltar\n";
    
    std::cout << "---------------------------------------\n";
    int escolha = lerInteiro("Digite sua escolha: ", 1, indexVisual+1);
    std::string feedback;

    if(escolha == indexVisual){
        std::cout << "\nRetornando ao menu anterior\n";
        return;
    }


    bool feedbackValido = false;
    while(!feedbackValido){
        std::cout <<"========================================\n";
        std::cout <<"                FEEDBACK                \n";
        std::cout <<"========================================\n";
        std::cout << "Digite o feedback: ";
        getline(std::cin, feedback);
        if(stringVazia(feedback)){
            std::cout << "\nFeedback invalido, ele nao pode ser vazio. Tente novamente.\n";
            enterParaContinuar();
            continue;
        }

        try{
            agendamentos[agendamentosValidos[escolha-1]].get()->setFeedback(feedback);
            feedbackValido = true;
            std::cout << "\nFeedback adicionado com sucesso\n";
        }catch(std::invalid_argument &e){
            std::cout << e.what() << std::endl;
        }
    }
}

void Medico::exibirHistoricoTransacoes(Clinica* clinica){
    limparTela();

    //Recebe todas as transacoes
    const std::vector<std::unique_ptr<Transacao>>& transacoes = clinica->getTransacoes();

    //Exibe o histórico
    std::cout << "================================================\n";
    std::cout << "                   HISTORICO                    \n";
    std::cout << "================================================\n";
    
    int indexVisual = 1;
    for(long unsigned int i=0; i<transacoes.size(); i++){
        Agendamento* agendamento = transacoes[i]->getAgendamento();
       if(agendamento->getMedico()->getCrm() == this->crm){
            std::cout << indexVisual << ".: ";
            std::cout << "Data: " << transacoes[i]->getData() << " | Horario: " << transacoes[i]->getHorario() << " | Paciente: " << transacoes[i]->getAgendamento()->getPaciente()->getNome() << " | Valor(R$): " << std::fixed << std::setprecision(2) << agendamento->getServico()->getValor()*0.6 << " | Serviço: " << agendamento->getServico()->getNome() << std::endl;
            indexVisual++;
       }
    }

    if(indexVisual == 1){
        std::cout << "\nAinda nao há nenhuma transacao\n";
        return;
    }

}
