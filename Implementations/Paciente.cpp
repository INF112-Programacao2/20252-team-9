#include "../Headers/Paciente.h"
#include "../Headers/Utils.h"
#include "../Headers/Utilsmain.h"
#include "../Headers/Clinica.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <iomanip>

Paciente::Paciente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string dataDeNascimento, char sexo, std::string observacoes, Plano* plano)
    :Pessoa(nome, cpf, senha, telefone){
        if(!validaData(dataDeNascimento))
            throw std::invalid_argument("\nData de nascimento invalida\n");
        this->dataDeNascimento = dataDeNascimento;

        if(sexo != 'F' && sexo != 'M')
            throw std::invalid_argument("\nSexo invalido, deve ser fornecido apenas um caractere maisculo, M para masculino ou F para feminino\n");
        this->sexo = sexo;

        this->observacoes = observacoes;

        if(plano == nullptr)
            throw std::invalid_argument("\nPonteiro para plano nao pode ser vazio\n");
        this->plano = plano;
    }

Paciente::~Paciente(){}
        
//Gets
std::string Paciente::getDataDeNascimento() const {return dataDeNascimento;}
char Paciente::getSexo() const {return sexo;}
std::string Paciente::getObservacoes() const {return observacoes;}
Plano* Paciente::getPlano() const {return plano;}
std::vector<Agendamento*>& Paciente::getNotificacoes() {return notificacoes;}
        
//Sets
void Paciente::setObservacoes(std::string observacoes){
    if(stringVazia(observacoes))
            throw std::invalid_argument("\nObservacao para paciente invalida, nao pode ser vazia\n");
    this->observacoes = observacoes;
}

void Paciente::setSexo(char sexo){
    if(sexo != 'F' && sexo != 'M')
            throw std::invalid_argument("\nSexo invalido, deve ser fornecido apenas um caractere maisculo, M para masculino ou F para feminino\n");
        this->sexo = sexo;
}

void Paciente::setPlano(Plano *plano){
    if(plano == nullptr)
        throw std::invalid_argument("\nPonteiro para plano nao pode ser vazio\n");
    this->plano = plano;
}
        

//Métodos
//Impressão dos dados do usuário:
void Paciente :: alterarDados(Clinica* clinica){ //Abre um menu, em que o paciente seleciona usando números qual atributo 
                            // ele deseja alterar, e o método chama o método set correspondente.
    while(true){
        //Impressão do menu:
        limparTela();
        std::cout <<"================================================\n";
        std::cout <<"                      DADOS                     \n";
        std::cout <<"================================================\n";

        this->VisualizaDados();

        std::cout << "1.: Nome\n";
        std::cout << "2.: Senha\n";
        std::cout << "3.: Telefone\n";
        std::cout << "4.: Observacoes\n";
        std::cout << "5.: Sexo\n";
        std::cout << "6.: Plano de saude\n";
        std::cout << "7.: Sair\n";
        std::cout << "---------------------------------------\n";
        
        int escolha = lerInteiro("Digite sua escolha: ", 1, 7);

        limparTela();

        //Switch case para a implementaão do menu
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

            case 4: //Alterar as observações
            {
                std::string novaObservacao;
                std::cout<<"================================================\n";
                std::cout<<"                      DADOS                     \n";
                std::cout<<"================================================\n";
                std::cout<<"Digite uma nova observacao.\n";
                std::cout<<"Algo relevante aos medicos, ex: alergias.\n";

                while(true){
                    std::cout << "\nDigite a nova observacao: ";
                    getline(std::cin, novaObservacao);
                    if(stringVazia(novaObservacao)){
                        std::cout << "\nObservacao invalida, nao pode ser vazia. Tente novamente\n";
                        enterParaContinuar();
                        continue;
                    }
                    break;
                }

                try{
                    this->setObservacoes(novaObservacao);
                    std::cout << "\nObservacao alterada com sucesso.\n";
                    break;
                }
                catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case 5: //Altera Sexo
            {
                std::cout<<"================================================\n";
                std::cout<<"                      DADOS                     \n";
                std::cout<<"================================================\n";
                std::cout <<"Opcoes:\n";
                std::cout << "1 - Feminino\n";
                std::cout << "2 - Masculino\n";

                int entrada = lerInteiro("\nDigite a sua escolha: ", 1, 2);
                char sexo = entrada == 1? 'F' : 'M';

                try{
                    this->setSexo(sexo);
                    break;
                }
                catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout<<"\nAlteracao bem sucedida.\n";
                enterParaContinuar();
                break;
            }

            case 6:// Mudança de plano de saúde
            {
                std::cout<<"================================================\n";
                std::cout<<"                       DADOS                    \n";
                std::cout<<"================================================\n";
                std::cout << "Escolha o seu novo plano\n";
                const std::vector<std::unique_ptr<Plano>>& planos = clinica->getPlanos();

                if(planos.size() == 0){
                    std::cout << "\nA clinica ainda nao possui parceria com nenhum convenio. \nTente novamente mais tarde\n";
                    enterParaContinuar();
                    break;
                }
                
                std::cout << std::endl;
                for(long unsigned int i=0; i<planos.size(); i++)
                    std::cout << i+1 << ".: " << planos[i].get()->getNome() << std::endl;

                std::cout << std::endl;

                int entrada = lerInteiro("Digite a opcao de plano desejada: ", 1, planos.size());
                Plano* plano = planos[entrada-1].get();

                try{
                    this->setPlano(plano);
                    std::cout << "\nPlano alterado com sucesso.\n";
                    break;
                }
                catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }

            case 7:
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

void Paciente :: VisualizaDados(){ // Sobreescrita do método da superclasse, além dos dados de pessoa

    // imprime também data de nascimento, sexo, as observações e plano de saúde
    std::cout << std::endl;
    Pessoa::VisualizaDados();
    
    std::cout << " | Data de nascimento: " << this->dataDeNascimento << std::endl;
    std::cout << " | Observacoes: " << this->observacoes << std::endl;
    std::cout << " | Sexo: " << this->getSexo() << std::endl;
    std::cout << " | Plano: " << plano->getNome() << std::endl << std::endl; //Remoção da validação com nullptr,para diminuir a chance de bugs 
                                                             //porque vamos ter um objeto "Nenhum" com desconto=0 
                                                             //para os clientes sem plano.
    
}

                                    
//Impressão dos agendamentos do paciente
void Paciente::VisualizaAgendamentos(Clinica *clinica){ 
    std::cout<<"================================================\n";
    std::cout<<"                  AGENDAMENTOS                  \n";
    std::cout<<"================================================\n\n";
    
    bool encontrou = false;
    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    
    int indexVisual = 1;
    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente()->getCpf() == this->cpf){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            encontrou = true;
        }
    }

    if(!encontrou)
        std::cout << "Nao existe nenhum agendamento\n";                
}

//Agenda
void Paciente::Agendar(Clinica *clinica){
    std::cout<<"================================================\n";
    std::cout<<"                  AGENDAMENTO                   \n";
    std::cout<<"================================================\n\n";
    std::cout << "Servicos:\n\n";

    const std::vector<std::unique_ptr<Servico>>& servicos = clinica->getServicos();

    if(servicos.empty()){
        std::cout << "\nInfelizmente ainda nao ofertamnos nenhum servico na clinica. Tente novamente depois\n";
        return;
    }

    for(long unsigned int i=0; i<servicos.size(); i++){
        std::cout << i+1 << ".: " << servicos[i].get()->getNome() << std::endl;
    }

    int escolhaServico = lerInteiro("\nDigite a sua escolha: ", 1, servicos.size());

    limparTela();

    std::cout<<"================================================\n";
    std::cout<<"                  AGENDAMENTO                   \n";
    std::cout<<"================================================\n\n";


    std::cout << "Escolha o medico:\n\n";
    int indexVisual = 1;
    std::vector<int> indexMedicosValidos;
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();
    for(long unsigned int i=0; i<medicos.size(); i++){
        if(servicos[escolhaServico-1].get()->getOcupacaoRequerida() == medicos[i].get()->getOcupacao()){
            std::cout << indexVisual << ".: Dr(a) " << medicos[i].get()->getNome() << std::endl;
            indexMedicosValidos.push_back(i);
            indexVisual++;
        }
    }   

    if(indexMedicosValidos.empty()){
        std::cout << "\nInfelizmente nao ha nenhum medico no momento que realiza esse servico. Tente novamente depois\n";
        return;
    }
    int escolhaMedico = lerInteiro("\nDigite a sua escolha: ", 1, indexMedicosValidos.size());

    Servico* servico = servicos[escolhaServico-1].get();
    Medico* medico = medicos[indexMedicosValidos[escolhaMedico-1]].get();
    
    std::string data;
    std::vector<std::string> horarios;

    limparTela();

    std::cout<<"================================================\n";
    std::cout<<"                  AGENDAMENTO                   \n";
    std::cout<<"================================================\n\n";

    while(true){
        std::cout << "\nDigite uma data para o agendamento: ";
        getline(std::cin, data);
        if(!validaData(data)){
            std::cout << "\nData de agendamento invalida, deve seguir o modelo XX/XX/XXXX\n";
            continue;
        }

        if(comparaData(data, Agendamento::getDateReference()) == -1){
            std::cout << "\nVoce nao pode agendar em uma data do passado\n";
            continue;
        }

        horarios = buscaHorarioValido(data, clinica, servico->getDuracao(), medico->getCrm());

        if(horarios.empty()){
            std::cout << "\n Nao ha nenhum horario disponivel nessa data. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::cout<<"================================================\n";
    std::cout<<"                  AGENDAMENTO                   \n";
    std::cout<<"================================================\n\n";

    //Imprime horarios disponíveis
    std::cout << "Horarios disponiveis\n";
    for(long unsigned int i=0; i<horarios.size(); i++)
        std::cout << i+1 << ". " << horarios[i] << std::endl;

    int escolhaHorario = lerInteiro("\nDigite a sua escolha: ", 1, horarios.size());
    

    try{
        clinica->adicionarAgendamento(std::make_unique<Agendamento>(data, horarios[escolhaHorario-1], (this) , medico, servico));

        limparTela();
        std::cout<<"================================================\n";
        std::cout<<"                  AGENDAMENTO                   \n";
        std::cout<<"================================================\n\n";
        std::cout << "Agendamento realizado com sucesso.\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

//Cancelar agendamento
void Paciente::CancelarAgendamento(Clinica *clinica){
    std::cout<<"================================================\n";
    std::cout<<"             AGENDAMENTOS PENDENTES             \n";
    std::cout<<"================================================\n\n";

    const std::vector<std::unique_ptr<Agendamento>>& agendamentos = clinica->getAgendamentos();
    int indexVisual=1;
    std::vector<int> agendamentosValidos;

    for(long unsigned int i=0; i<agendamentos.size(); i++){
        if(agendamentos[i].get()->getPaciente()->getCpf() == this->cpf && !agendamentos[i].get()->isConcluido()){
            std::cout << indexVisual << ".: ";
            indexVisual++;
            agendamentos[i].get()->imprimirResumido();
            agendamentosValidos.push_back(i);
        }
    }

    if(agendamentosValidos.empty()){
        std::cout << "Voce nao possui nenhum agendamento\n";
        return;
    }

    std::cout << indexVisual << ".: Voltar\n\n";

    int escolha = lerInteiro("Digite a sua escolha: ", 1, indexVisual);

    if(escolha == indexVisual){
        std::cout << "\nVoltando ao menur anterior\n";
        enterParaContinuar();
        return;
    }

    limparTela();

    //Acha e exclui o agaendamento escolhido
    try{
        Agendamento* ptr = agendamentos[agendamentosValidos[escolha-1]].get();
        clinica->removerAgendamento(ptr);
        std::cout << "\nAgendamento excluido com sucesso\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

//Checar notificacoes
void Paciente::checarNotificacoes(Clinica* clinica){
    limparTela();
    std::cout<<"================================================\n";
    std::cout<<"                  NOTIFICAÇÕES                  \n";
    std::cout<<"================================================\n\n";

    if(notificacoes.empty()){
        std::cout << "Voce nao tem nenhuma notificacao ainda\n";
        return;
    }

    for(unsigned int i=0; i<notificacoes.size(); i++){
        std::cout << i+1 << ".: ";
        notificacoes[i]->imprimirResumido();
    }

    int escolhaAgendamento = lerInteiro("\nDigite sua escolha: ", 1, notificacoes.size());
    std::cout << "\nVoce deseja confirmar ou cancelar esse agendamento?\n1.Confirmar\n2.Cancelar\n";
    int escolhaOpcao = lerInteiro("Digite a sua escolha: ", 1, 2);
    
    try{
        if(escolhaOpcao == 1){
        clinica->adicionarAgendamento(std::make_unique<Agendamento>(*notificacoes[escolhaOpcao-1]));
        delete notificacoes[escolhaAgendamento-1];
        notificacoes.erase(notificacoes.begin()+escolhaAgendamento-1);

        Medico *medico = notificacoes[escolhaOpcao-1]->getMedico();
        Servico *servico = notificacoes[escolhaOpcao-1]->getServico();

        medico->setSaldo(medico->getSaldo() + servico->getValor()*0.6);
        clinica->setSaldo(clinica->getSaldo() + servico->getValor()*0.4);

        std::cout << "\nAgendamento realizado com sucesso\n";
    }
    else{
        delete notificacoes[escolhaAgendamento-1];
        notificacoes.erase(notificacoes.begin()+escolhaAgendamento-1);
        std::cout << "\nAgendamento cancelado com sucesso\n";
    }
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

}

void Paciente::exibirHistoricoTransacoes(Clinica *clinica){
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
       if(agendamento->getPaciente()->getCpf() == this->cpf){
            std::cout << indexVisual << ".: ";
            std::cout << "Data: " << transacoes[i]->getData() << " | Horario: " << transacoes[i]->getHorario() << " | Medico: " << transacoes[i]->getAgendamento()->getMedico()->getNome() << " | Valor(R$): " << std::fixed << std::setprecision(2) << agendamento->getServico()->getValor()*(1-this->plano->getDesconto()) << " | Serviço: " << agendamento->getServico()->getNome() << std::endl;
            indexVisual++;
       }
    }

    if(indexVisual == 1){
        std::cout << "\nAinda nao há nenhuma transacao\n";
        return;
    }

}
