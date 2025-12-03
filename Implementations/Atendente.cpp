#include "../Headers/Atendente.h"
#include "../Headers/Utils.h"
#include "../Headers/Clinica.h"
#include "../Headers/Utilsmain.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <iomanip>

//Construtor e Destrutor
Atendente::Atendente(std::string nome, std::string cpf, std::string senha, std::string telefone, std::string matricula):
    Pessoa(nome, cpf, senha, telefone)
    {
        if(stringVazia(matricula))
            throw std::invalid_argument("Matricula inválida.\n");

        this->matricula = matricula;
    };

Atendente::~Atendente() {};

//Gets e Sets
std::string Atendente::getMatricula() const {return matricula;}

void Atendente::setMatricula(std::string nova_matricula) {
    if(stringVazia(nova_matricula))
        throw std::invalid_argument("Matricula Inválida");
    this->matricula = nova_matricula;
}

void Atendente::ConsultaSaldoDaClinica(Clinica* clinica){
    std::cout << "\n | Saldo da Clínica (R$): " << std::fixed << std::setprecision(2) << clinica->getSaldo() << "\n";
}


//Metodos

void Atendente::VisualizaDados(){
    std::cout << "\nDados do(a) Atendente:\n";
    Pessoa::VisualizaDados();

    std::cout << " | Matrícula: " << this->getMatricula() << "\n";
}


void Atendente::alterarDados(Clinica* clinica){
    while(true){
        limparTela();
        std::cout <<"================================================\n";
        std::cout <<"                      DADOS                     \n";
        std::cout <<"================================================\n";

        std::cout << "Você deseja alterar os dados de: ";
        std::cout << "\n 1.: Paciente\n";
        std::cout << " 2.: Médico\n";
        std::cout << " 3.: Meus dados\n";
        std::cout << " 4.: Sair\n";
        std::cout << "---------------------------------------\n";
            
        int pessoa_escolhida = lerInteiro("Digite sua escolha: ", 1, 4);

        if(pessoa_escolhida == 4) {
            limparTela();
            return;
        }

        else if(pessoa_escolhida == 1) {
            limparTela();
            std::cout <<"================================================\n";
            std::cout <<"                      DADOS                     \n";
            std::cout <<"================================================\n";
            std::cout << "\nLista de Pacientes: \n\n";
            int cont = 0;
            for(auto &pac : clinica->getPacientes())
                std::cout << ++cont << ".: " << pac->getNome() << " | CPF: " << pac->getCpf() << "\n";
            
            int paciente_escolhido = lerInteiro("\nDigite sua escolha: ", 1, cont);
            clinica->getPacientes()[paciente_escolhido-1].get()->alterarDados(clinica);
        }

        else if(pessoa_escolhida == 2) {
            limparTela();
            std::cout <<"================================================\n";
            std::cout <<"                      DADOS                     \n";
            std::cout <<"================================================\n";
            std::cout << "\nLista de Médicos: \n\n";
            int cont = 0;
            for(auto &med : clinica->getMedicos())
                std::cout << ++cont << ".: " << med->getNome() << " | CRM: " << med->getCrm() << "\n";
            
            int medico_escolhido = lerInteiro("\nDigite sua escolha: ", 1, cont);
            clinica->getMedicos()[medico_escolhido-1].get()->alterarDados(clinica);

        }


        else if (pessoa_escolhida == 3)
            while (true){
                limparTela();
                std::cout <<"================================================\n";
                std::cout <<"                      DADOS                     \n";
                std::cout <<"================================================\n";

                this->VisualizaDados();

                std::cout << "\n 1.: Nome\n";
                std::cout << " 2.: Senha\n";
                std::cout << " 3.: Telefone\n";
                std::cout << " 4.: Sair\n";
                std::cout << "---------------------------------------\n";
                
                int escolha = lerInteiro("Digite sua escolha: ", 1, 4);

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

                    case 4: //sair do menu
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
}

void Atendente::VisualizaAgendamentos(Clinica* clinica){
    int n;
    
    while(true){
        limparTela();
        std::cout << "================================================\n";
        std::cout << "                      MENU                      \n";
        std::cout << "================================================\n";

        std::cout << "\nVocê deseja visualizar os agendamentos de: \n1.: Filtrar por Medico \n2.: Filtrar por Paciente\n3.: Todos agendamentos\n4.: Voltar\n";
        n = lerInteiro("Digite sua escolha: ", 1, 4);

        if(n == 1){
            limparTela();
            std::cout << "================================================\n";
            std::cout << "                    MEDICOS                     \n";
            std::cout << "================================================\n\n";
            const auto &listaMedicos = clinica->getMedicos();
            int cont = 0;
            for(auto &med : listaMedicos) {
                    cont++;
                    std::cout << cont << ".: " << med->getNome() << " CRM: " << med->getCrm() << "\n";
                }
                    std::cout << "\nDigite sua escolha: \n";
                    int escolha = lerInteiro("", 1, cont);

            listaMedicos[escolha-1]->VisualizaAgendamentos(clinica);
            enterParaContinuar();
            continue;
        }
        else if(n==2){
            limparTela();
            std::cout << "================================================\n";
            std::cout << "                  PACIENTES                     \n";
            std::cout << "================================================\n\n";
            const auto &listaPacientes = clinica->getPacientes();
            int cont = 0;
            for(auto &pac : listaPacientes){
                cont++;
                std::cout << cont << ".: " << pac->getNome() << " CPF: " << pac->getCpf() << "\n";
            }

            std::cout << "\nDigite o identificador do Paciente que deseja visualizar as consultas: \n";
            int escolha = lerInteiro("", 1, cont);

            listaPacientes[escolha-1]->VisualizaAgendamentos(clinica);
            enterParaContinuar();
            continue;
        }
        else if(n == 3){
            limparTela();
            std::cout << "================================================\n";
            std::cout << "                AGENDAMENTOS                    \n";
            std::cout << "================================================\n\n";
            const auto &listaAgendamentos = clinica->getAgendamentos();
            int cont = 0;
            for(auto &agendamento: listaAgendamentos){
                cont++;
                std::cout << cont << ".: ";
                agendamento->imprimirResumido();
            }
            enterParaContinuar();
            continue;
        }
        else if(n == 4){
            std::cout << "\nVoltando para o menu\n";
            break;
        }
    }
}

void Atendente::CadastrarPaciente(Clinica* clinica){
    limparTela();

    std::string nome;
    while (true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Nome do paciente: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome) || !somenteLetras(nome)){
            std::cout << "\nO nome do paciente nao pode ser vazio. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::string cpf;
    while(true) {
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "CPF do paciente: ";
        getline(std::cin, cpf);
        if(!validaCpf(cpf)){
            std::cout << "\nCPF invalido, deve seguir o modelo XXX.XXX.XXX-XX. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::string senha;
    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Senha do paciente: ";
        std::getline(std::cin, senha);
        if(stringVazia(senha)){
            std::cout << "\nSenha para criar paciente invalida, nao pode ser vazia. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::string telefone;
    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Telefone do paciente (XX) XXXXX-XXXX: ";
        std::getline(std::cin, telefone);
        if(!validaTelefone(telefone)){
            std::cout << "\nTelefone invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::string dataDeNascimento;
    while (true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Informe a data de nascimento do paciente: ";
        getline(std::cin, dataDeNascimento);
        if(!validaData(dataDeNascimento)){
            std::cout << "\nData inválida, deve seguir o modelo DD/MM/AAAA. Tente novamente\n";
            enterParaContinuar();
            continue; 
        }
        break;
    }

    limparTela();

    char sexo;
    std::string aux;
    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << " | (M) Masculino\n | (F) Feminino\n\nInforme o sexo do paciente: ";
        getline(std::cin ,aux);
        sexo = aux[0];

        if(sexo != 'M' && sexo != 'F'){
            std::cout << "\nSexo inválido, informe (F) ou (M)\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::string observacoes;
    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Informe observações importantes do paciente (Ex: Alergias, Comorbidades): ";
        getline(std::cin, observacoes);
        break;
    }

    limparTela();

    std::cout << "================================================\n";
    std::cout << "                    CADASTRO                    \n";
    std::cout << "================================================\n";

    int cont = 0;
    for(auto &plano : clinica->getPlanos()) {
        cont ++;
        std::cout << cont << ".: Nome: " << plano.get()->getNome() << " | Desconto(%): " << plano.get()->getDesconto()* 100 << "\n";
    }


    int escolha = lerInteiro("Digite sua escolha: ", 1, cont);

    Plano* plano_escolhido = clinica->getPlanos()[escolha - 1].get();

    clinica->adicionarPaciente(std::make_unique<Paciente>(nome, cpf, senha, telefone, dataDeNascimento, sexo, observacoes, plano_escolhido));

    std::cout << "\nPaciente cadastrado com sucesso!\n";
}

void Atendente::CadastrarMedico(Clinica* clinica) {
    limparTela();

    std::string nome, cpf, senha, telefone, crm, ocupacao;

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Nome do medico: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome) || !somenteLetras(nome)){
            std::cout << "\nNome para criar medico invalido, nao pode ser vazio. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "CPF do medico: ";
        std::getline(std::cin, cpf);
        if(!validaCpf(cpf)){
            std::cout << "\nCPF invalido, deve seguir o modelo XXX.XXX.XXX-XX. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Senha do medico: ";
        std::getline(std::cin, senha);
        if(stringVazia(senha)){
            std::cout << "\nSenha para criar medico invalido, nao pode ser vazia. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Telefone do medico: ";
        std::getline(std::cin, telefone);
        if(!validaTelefone(telefone)){
            std::cout << "\nTelefone invalido, deve seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "CRM do medico: ";
        std::getline(std::cin, crm);
        if(!validaCrm(crm)){
            std::cout << "\nCRM para criar medico invalido, tem de seguir o modelo SIGLA/UF NUMERO. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Ocupacao do medico: ";
        std::getline(std::cin, ocupacao);
        if(stringVazia(ocupacao) || !somenteLetras(ocupacao)){
            std::cout << "\nOcupacao para criar medico invalida, nao pode ser vazia. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    for(auto &medicos : clinica->getMedicos())
    {
       if(medicos->getCpf() == cpf)
       {
        std::cout << "Não é possível criar um médico com um cpf já cadastrado.\n";
        return;
       }

       if(medicos->getCrm() == crm)
       {
        std::cout << "Não é possível criar um médico com um crm já cadastrado.\n";
        return;
       }

    }
    try{
        clinica->adicionarMedico(std::make_unique<Medico>(nome, cpf, senha, telefone, crm, ocupacao));
        std::cout << "\nMédico adicionado com sucesso!\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::DesligarMedico(Clinica* clinica){
    //Recebe a lista de medicos
    limparTela();
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();

    std::cout << "================================================\n";
    std::cout << "                    MEDICOS                     \n";
    std::cout << "================================================\n";
    
    if(medicos.empty()){
        std::cout << "\nNao há nenhum medico cadastrado ainda. Cadastre pelo menos um antes de tentar excluir\n";
        return;
    }

    //Imprime a lista de medicos
    std::cout << std::endl;
    int lastIndex = 1;
    for(long unsigned int i=0; i<medicos.size(); i++){
        std::cout << i+1 << ".: Nome: " << medicos[i].get()->getNome() << " | CRM: " << medicos[i].get()->getCrm() << " | Ocupacao: " << medicos[i].get()->getOcupacao() << std::endl;
        lastIndex++;
    }

    std::cout << lastIndex << ".: Voltar\n\n";

    //Escolhe qual medico excluir
    int escolha = lerInteiro("Digite sua escolha: ", 1, lastIndex);
    
    if(escolha == lastIndex){
        std::cout << "\nVoltando para o menu anterior\n";
        return;
    }
    else if(escolha != lastIndex){
        std::cout << "\nVoce deseja realmente excluir?\n1.Sim\n2.Nao\n\n";
        int confirmacao = lerInteiro("Digite o que voce deseja fazer: ", 1, 2);
        if(confirmacao == 2){
            std::cout << "\nVoltando para o menu anterior\n";
            return;
        }
    }

    //Exclui o medico
    try{
        clinica->removerMedico(medicos[escolha-1].get());
        std::cout << "\nMedico removido com sucesso.\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::CriarServico(Clinica* clinica){
    limparTela();

    std::string nome, ocupacaoRequerida;
    double valor;
    int duracao;
    
    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Nome do servico: ";
        std::getline(std::cin, nome);
        if(stringVazia(nome)){
            std::cout << "\nNome para criar servico invalido, nao pode ser vazio. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    std::cout << "================================================\n";
    std::cout << "                    CADASTRO                    \n";
    std::cout << "================================================\n";

    valor = lerDouble("Valor(R$): ", 0, 1000000000);
    duracao = lerInteiro("Duracao(min): ", 1, 1000000000);

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                    CADASTRO                    \n";
        std::cout << "================================================\n";
        std::cout << "Ocupacao requerida: ";
        std::getline(std::cin, ocupacaoRequerida);
        if(stringVazia(ocupacaoRequerida)){
            std::cout << "\nOcupacao requerida para criar servico invalida, nao pode ser vazia. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    limparTela();

    try{
        Servico servico = Servico(nome, valor, duracao, ocupacaoRequerida);
        std::cout << "Dados no serviço:\n\n";
        servico.visualizarDados(); 

        clinica->adicionarServico(std::make_unique<Servico>(servico));
        std::cout << "\nServiço cadastrado com sucesso!\n";
    }catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::AlterarServico(Clinica *clinica){
    limparTela();

    std::cout << "================================================\n";
    std::cout << "                  SERVICOS                      \n";
    std::cout << "================================================\n";

    if(clinica->getServicos().size() == 0){
        std::cout << "Não há nenhum serviço para ser modificado.\n";
        return;
    }
    std::cout << std::endl;

    int cont = 0;
    for (auto &serv : clinica->getServicos()) {
        cont++;
        std::cout << cont << ".: Nome: " << serv.get()->getNome() << " ID: " << serv.get()->getId() << "\n";
    }
    
    std::cout << cont+1 << ".: Voltar\n";

    std::cout << std::endl;

    int escolha = lerInteiro("Escolha qual serviço deseja alterar: ", 1, cont+1);

    if(escolha == cont+1){
        std::cout << "\nVoltando para o menu anterior\n";
        return;
    }

    Servico *servico_alterar = clinica->getServicos()[escolha-1].get();
    limparTela();
    
    std::cout << "================================================\n";
    std::cout << "                   ALTERAR                      \n";
    std::cout << "================================================\n";

    std::cout << "Dados do servico:\n";
    servico_alterar->visualizarDados();

    
    std::cout << "\nEscolha qual deseja alterar: \n";
    std::cout << "1.: Nome\n";
    std::cout << "2.: Valor\n";
    std::cout << "3.: Duração\n";
    std::cout << "4.: Ocupação Requerida\n";
    std::cout << "5.: Voltar\n";

    int escolha_alterar = lerInteiro("Digite sua escolha: ", 1, 5);
    limparTela();

    if(escolha_alterar == 1)
    {
        std::string novo_nome;
        
        
        while (true){
            std::cout << "================================================\n";
            std::cout << "                   ALTERAR                      \n";
            std::cout << "================================================\n";
            std::cout << "Informe o novo nome do serviço: ";
            getline(std::cin, novo_nome);
            if(!stringVazia(novo_nome))
                break;
            std::cout << "\nO nome não pode ser vazio, Tente novamente\n"; 
            enterParaContinuar();
        }

        try {
            servico_alterar->setNome(novo_nome);
            std::cout << "\nNome do serviço alterado com sucesso!\n";
            enterParaContinuar();
        }
        catch(std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 2)
    {
        std::cout << "================================================\n";
        std::cout << "                   ALTERAR                      \n";
        std::cout << "================================================\n";
        double novo_valor = lerDouble("Informe o novo valor do serviço: ", 0.0, 100000.0);
        try{
            servico_alterar->setValor(novo_valor);
            std::cout << "\nValor do serviço alterado com sucesso!\n";
            enterParaContinuar();
        }
        catch(std::invalid_argument &e) {
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 3)
    {
        std::cout << "================================================\n";
        std::cout << "                   ALTERAR                      \n";
        std::cout << "================================================\n";
        int nova_duracao = lerInteiro("Informe a nova duração do serviço: ", 0, 10000);
        try{
            servico_alterar->setDuracao(nova_duracao);
            std::cout << "\nDuração do serviço alterado com sucesso!\n";
            enterParaContinuar();
        }
        catch (std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 4)
    {
        
        std::string nova_ocupcacao;
        
        while(true){
            std::cout << "================================================\n";
            std::cout << "                   ALTERAR                      \n";
            std::cout << "================================================\n";
            std::cout << "Digite a nova ocupação requerida: ";
            getline(std::cin, nova_ocupcacao);
            if(!stringVazia(nova_ocupcacao))
                break;
            std::cout << "\nA nova ocupação não pode ser vazia, digite uma ocupação válida: \n";
            enterParaContinuar();
        }

        try {
            servico_alterar->setOcupacaoRequerida(nova_ocupcacao);
            std::cout << "\nOcupação requerida do serviço alterado com sucesso!\n";
            enterParaContinuar();
        }
        catch (std::invalid_argument &e){
            std::cout << e.what() << "\n";
        }
    }
    else if(escolha_alterar == 5){
        std::cout << "\nVoltando para o menur anterior\n";
        return;
    }

    std::cout << "\nNovas Informações do Serviço: \n";
    servico_alterar->visualizarDados();
}

void Atendente::agendarParaPaciente(Clinica* clinica){
    limparTela();
    //Exibe todos os pacientes para que a atendente escolha qual
    const std::vector<std::unique_ptr<Paciente>>& pacientes = clinica->getPacientes();

    if(pacientes.empty()){
        std::cout << "\nA clinica ainda nao possui nenhum paciente. Tente novamente depois\n";
        return;
    }

    std::cout << "================================================\n";
    std::cout << "                  PACIENTES                     \n";
    std::cout << "================================================\n";

    for(long unsigned int i=0; i<pacientes.size(); i++){
        std::cout << i+1 << ". Nome: " << pacientes[i].get()->getNome() << " | CPF: " << pacientes[i].get()->getCpf() << " | Telefone: " << pacientes[i].get()->getTelefone() << std::endl;
    }

    std::cout << pacientes.size()+1 << ".: Voltar\n";

    long unsigned int escolhaPaciente = lerInteiro("Digite sua escolha: ", 1, pacientes.size()+1);

    if(escolhaPaciente == pacientes.size()+1){
        std::cout << "\nVoltando para o menu anterior\n";
        return;
    }

    Paciente* paciente = pacientes[escolhaPaciente-1].get();
    limparTela();

    //Agora pega os dados do agendamento em si
    std::cout << "================================================\n";
    std::cout << "                   SERVICOS                     \n";
    std::cout << "================================================\n";

    const std::vector<std::unique_ptr<Servico>>& servicos = clinica->getServicos();

    if(servicos.empty()){
        std::cout << "\nInfelizmente ainda nao ofertamnos nenhum servico na clinica. Tente novamente depois\n";
        return;
    }

    for(long unsigned int i=0; i<servicos.size(); i++){
        std::cout << i+1 << ". " << servicos[i].get()->getNome() << std::endl;
    }
    int escolhaServico = lerInteiro("Digite sua escolha: ", 1, servicos.size());

    limparTela();

    std::cout << "================================================\n";
    std::cout << "                   MEDICOS                      \n";
    std::cout << "================================================\n";

    int indexVisual = 1;
    std::vector<int> indexMedicosValidos;
    const std::vector<std::unique_ptr<Medico>>& medicos = clinica->getMedicos();
    for(long unsigned int i=0; i<medicos.size(); i++){
        if(servicos[escolhaServico].get()->getOcupacaoRequerida() == medicos[i].get()->getOcupacao()){
            std::cout << indexVisual << ". Dr(a) " << medicos[i].get()->getNome() << std::endl;
            indexMedicosValidos.push_back(i);
            indexVisual++;
        }
    }   

    if(indexMedicosValidos.empty()){
        std::cout << "\nInfelizmente nao ha nenhum medico no momento que realiza esse servico. Tente novamente depois\n";
        return;
    }
    int escolhaMedico = lerInteiro("Digite sua escolha: ", 1, indexMedicosValidos.size());

    Servico* servico = servicos[escolhaServico-1].get();
    Medico* medico = medicos[indexMedicosValidos[escolhaMedico-1]].get();
    
    std::string data;
    std::vector<std::string> horarios;

    limparTela();

    while(true){
        std::cout << "================================================\n";
        std::cout << "                     DATA                       \n";
        std::cout << "================================================\n";
        std::cout << "Digite uma data para o agendamento: ";
        getline(std::cin, data);
        if(!validaData(data)){
            std::cout << "\nData de agendamento invalida, deve seguir o modelo XX/XX/XXXX\n";
            enterParaContinuar();
            continue;
        }

        if(comparaData(data, Agendamento::getDateReference()) == -1){
            std::cout << "\nVoce nao pode agendar em uma data do passado\n";
            enterParaContinuar();
            continue;
        }

        horarios = buscaHorarioValido(data, clinica, servico->getDuracao(), medico->getCrm());

        if(horarios.empty()){
            std::cout << "Nao ha nenhum horario disponivel nessa data. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    //Imprime horarios disponíveis
    limparTela();
    std::cout << "================================================\n";
    std::cout << "                    HORARIOS                    \n";
    std::cout << "================================================\n";
    for(long unsigned int i=0; i<horarios.size(); i++)
        std::cout << i+1 << ". " << horarios[i] << std::endl;

    int escolhaHorario = lerInteiro("Digite o horario desejado: ", 1, horarios.size());
    limparTela();

    //Cria e adiciona o agendamento em si no vetor notificacoes do paciente
    try{
        Agendamento* agendamento = new Agendamento(data, horarios[escolhaHorario-1], paciente , medico, servico);
        std::cout << "\nVoce realmente deseja adicioar o agendamento: \n";
        agendamento->imprimirDetalhado();
        std::cout << "1.: Sim\n2.: Nao\n\n";
        int confirmacao = lerInteiro("Digite oque voce deseja fazer: ", 1, 2);

        if(confirmacao == 2){
            std::cout << "\nVoltando para o menu anterior\n";
            delete agendamento;
            return;
        }

        std::vector<Agendamento*>& notificacoes = paciente->getNotificacoes();
        notificacoes.push_back(agendamento);
        std::cout << "\nNotificação de agendamento enviada com sucesso!\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::visualizarMedicos(Clinica* clinica) {
    std::cout << "\nAqui está a lista com os detalhes de todos os médicos:\n";
    for(long unsigned int i = 0; i<clinica->getMedicos().size(); i++){
        clinica->getMedicos()[i].get()->VisualizaDados();
    }
}

void Atendente::visualizarPacientes(Clinica* clinica){
    std::cout << "\nAqui está a lista com os detalhes de todos os pacientes:\n";
    for(long unsigned int i = 0; i < clinica->getPacientes().size(); i++)
        clinica->getPacientes()[i].get()->VisualizaDados();
}

void Atendente::visualizarPlanos(Clinica *clinica){
    limparTela();
    std::cout << "================================================\n";
    std::cout << "                      PLANOS                    \n";
    std::cout << "================================================\n";
    int cont = 0;
    for(auto &plano : clinica->getPlanos()){
        cont++;
        if(plano.get()->getNome() == "Nenhum") continue;
        std::cout << cont-1 << ".: ";
        plano.get()->visualizarDados();
    }

    if(clinica->getPlanos().size() == 1){
        std::cout << "\nNão há nenhum plano disponível. Tente novamente mais tarde\n";
        return;
    }

    return;
}

void Atendente::removerPlano(Clinica* clinica){
    int cont = 0;
    limparTela();
    std::cout << "================================================\n";
    std::cout << "                      PLANOS                    \n";
    std::cout << "================================================\n";
    for(auto &plano : clinica->getPlanos()){
        cont++;
        if(plano->getNome() == "Nenhum") continue;

        std::cout << cont-1 << ".: ";
        plano.get()->visualizarDados();
    }
    if(clinica->getPlanos().size() == 1){
        std::cout << "\nNão há nenhum plano disponivel. Tente mais tarde\n";
        return;
    }
    
    std::cout << cont << ".: Voltar\n";

    int escolha = lerInteiro("\nDigite sua escolha: ", 1, cont+1);

    

    if(escolha == cont){
        std::cout << "\nVoltando para o menu\n";
        return;
    }

    Plano* plano_removido = clinica->getPlanos()[escolha].get();

    try{
        if(escolha == cont){
            std::cout << "\nVoltando para o menu\n";
            return;
        }

        clinica->removerPlano(plano_removido);
        std::cout << "\nPlano removido com sucesso!\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}

void Atendente::adicionarPlanos(Clinica* clinica){
    limparTela();

    std::string nome;
    while(true){
        std::cout << "================================================\n";
        std::cout << "                     PLANOS                     \n";
        std::cout << "================================================\n";

        std::cout << "Adição de Plano\n";
        std::cout << "Nome do Plano: ";
        std::getline(std::cin, nome);

        if(stringVazia(nome) || !somenteLetras(nome)){
            std::cout << "\nO nome do plano nao pode ser vazio. Tente novamente\n";
            enterParaContinuar();
            continue;
        }
        break;
    }

    std::cout << "Desconto do Plano: ";
    double desconto = lerDouble("", 0, 1);

    std::cout << "\nDeseja realmente adicionar o plano: \n";
    std::cout << " | Nome: " << nome << std::endl;
    std::cout << " | Desconto: " << desconto*100 << "%\n";

    std::cout << "\n1.: Sim\n2.: Nao\n";

    int confirmacao = lerInteiro("\nDigite o que voce deseja fazer: ", 1, 2);
    if(confirmacao == 2){
        std::cout << "\nVoltando para o menu anterior\n";
        return;
    }

    try{
        clinica->adicionarPlano(std::make_unique<Plano>(nome, desconto));
        std::cout << "\n Plano adicionado com sucesso.\n";
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }

}

void Atendente::visulizarServicos(Clinica* clinica){
    std::cout << "\nAqui está a lista com os detalhes de todos os médicos:\n\n";
    for(long unsigned int i = 0; i < clinica->getServicos().size(); i++){
        clinica->getServicos()[i]->visualizarDados();
        std::cout << std::endl;
    }
}