//Includes
#include "../Headers/Utils.h"
#include "../Headers/Clinica.h"
#include <regex>
#include <iostream>

bool stringVazia(const std::string &string){
    if(string.size() == 0)
        return true;

    //Se achar algum caractere que não seja espaço, não é uma string vazia
    for(unsigned char i: string){
        if(!isspace(i))
            return false;
    }

    return true;
}

//Função auxiliar que checa se o string é composto só por letras
bool somenteLetras(const std::string &palavra){ 

    for( char c : palavra){ //Percorre o string caractere por caractere
        if(!std::isalpha(static_cast<unsigned char>(c)) && c!=' '){
            return false;
        }
    }

    return true;

}

//Outra funcção auxiliar que checa se o string só tem números:
bool somenteNumeros(const std::string& numero){

    for(char c : numero){
        if(!isdigit(static_cast<unsigned char>(c))){
            return false;
        }
    }

    return true;
}

bool validaData(const std::string& data){
    //Regex para validação da data
    std::regex padrao("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/[0-9]{4}$");

    if(!std::regex_match(data, padrao))
        return false;

    return true;
}

bool validaHorario(const std::string& horario){
    //Regex para validacao do horario
    std::regex padrao("^([01][0-9]|2[0-3]):[0-5][0-9]$");

    if(!std::regex_match(horario, padrao))
        return false;
    
    return true;
}

bool validaCpf(const std::string& cpf){
    //Regex para validacao do cpf
    std::regex padrao(R"(^\d{3}\.\d{3}\.\d{3}-\d{2}$)");

    if(!std::regex_match(cpf, padrao))
        return false;
    
    return true;
}

bool validaTelefone(const std::string& telefone){
    //Regex para validação do cpf
    std::regex padrao(R"(^\(\d{2}\) \d{4,5}-\d{4}$)");

    if(!std::regex_match(telefone, padrao))
        return false;
    
    return true;
}

bool validaCrm(const std::string& crm){
    //Regex para valicadação do crm
    std::regex padrao(R"(^(CRO|CRM)/[A-Z]{2} \d{4,6}$)");

    if(!std::regex_match(crm, padrao))
        return false;

    return true;
}

int lerInteiro(const std::string& mensagem, int min, int max){
    int numero=0;
    bool entradaValida = false;

    while(!entradaValida){
        std::string entrada;
        std::cout << mensagem;
        getline(std::cin, entrada);

        //Verifica se a entrada não é vazia
        if(stringVazia(entrada)){
            std::cout << "Entrada nao pode ser vazia. Tente novamente\n";
            continue;
        }

        //Varre a entrada vendo se tem algo que nao faz parte de um numero inteiro para validar a string
        bool stringOk = true;
        for(long unsigned int i=0; i<entrada.size(); i++){
            if(!isdigit((unsigned char)entrada[i])){
                stringOk = false;
                break;
            }
        }

        if(!stringOk){
            std::cout << "A entrada deve ser um numero inteiro positivo. Tente novamente\n";
            continue;
        }

        //Converte a string para numero inteiro e verifica se ela esta no intervalo correto passado por parametro
        try{
            numero = std::stoi(entrada);
            if(numero >= min && numero <= max)
                entradaValida = true;
            else
                std::cout << "Numero invalido, escolha algo entre " << min << " e " << max << std::endl;

        }catch(std::exception &e){
            std::cout << "Ocorreu um erro ao validar a entrada. Tente novamente\n";
        }
    }

    return numero;
}

double lerDouble(const std::string& mensagem, double min, double max){
    double numero= 0.0;
    bool entradaValida = false;

    while(!entradaValida){
        std::string entrada;
        std::cout << mensagem;
        getline(std::cin, entrada);

        //Verifica se a entrada é vazia
        if(stringVazia(entrada)){
            std::cout << "Entrada nao pode ser vazia. Tente novamente\n";
            continue;
        }

       //Valida a string em si
        bool stringOk = true;
        int numPontos = 0;
        for(long unsigned int i=0; i<entrada.size(); i++){
            unsigned char c = entrada[i];
            if(isdigit(c)){
                continue;
            }
            else if(c == '.' || c == ','){
                entrada[i] = '.';
                numPontos++;
            }
            else{
                //Se achou um digito que nao pertence a uma double, ele invalida a string
                stringOk = false;
                break; 
            }
        }

        if(!stringOk){
            std::cout << "A entrada deve ser no formato double, deve conter apenas numero positivo e ponto/virgula. Tente novamente\n";
            continue;
        }   

        if(numPontos>1){
            std::cout << "A entrada nao pode contar mais de um ponto/virgula. Tente novamente\n";
            continue;
        }

        //Converte a variavel e verifica se ela esta dentro dos limites passados por parametro
        try{
            numero = std::stod(entrada);
            if(numero >= min && numero <= max)
                entradaValida = true;
            else
                std::cout << "Numero invalida, escolha algo entre " << min << " e " << max << std::endl;

        }catch(std::exception &e){
            std::cout << "Ocorreu um erro ao validar a entrada. Tente novamente\n";
        }
    }

    return numero;
}

int comparaData(const std::string& data1, const std::string& data2){
    if(!validaData(data1) || !validaData(data2))
        throw std::invalid_argument("Datas devem estar no formato XX/XX/XX para serem comparadas");

    //Converte os anos, meses e dias em numeros e realiza comparacoes
    try{
        // Data 1
        int dia1 = std::stoi(data1.substr(0, 2));
        int mes1 = std::stoi(data1.substr(3, 2));
        int ano1 = std::stoi(data1.substr(6, 4));

        // Data 2
        int dia2 = std::stoi(data2.substr(0, 2));
        int mes2 = std::stoi(data2.substr(3, 2));
        int ano2 = std::stoi(data2.substr(6, 4));
        
        //Forma matematica de transformar uma data DDMMAA para AAMMDD, bastando comparar os valores
        if(ano1<ano2)
            return -1;
        else if(ano1>ano2)
            return 1;
        else if(ano1==ano2){
            if(mes1<mes2)
                return -1;
            else if(mes1>mes2)
                return 1;
            else if(mes1==mes2){
                if(dia1<dia2)
                    return -1;
                else if(dia1>dia2)
                    return 1;
            }
        }

    }catch(std::exception &e){
        std::cout << "Ocorreu um erro ao converter as dadas durante a comparacao. Tente novamente\n";
    }

    return 0;
}

std::vector<std::string> buscaHorarioValido(const std::string& data, Clinica* clinica, int duracao, std::string crm){

    std::vector<std::string> horariosValidos;

    std::vector<int> Agenda(20, 0);

    //Preenche a agenda do dia
    for(long unsigned int i = 0; i < clinica->getAgendamentos().size(); i++){
        if(clinica->getAgendamentos()[i]->getData() != data) continue; //Se o dia do atendimento não for igual ao dia que o paciente deseja marcar, não compara
        if(clinica->getAgendamentos()[i]->getMedico()->getCrm() != crm) continue;   //Se o medico não for o medico que o paciente deseja marcar, não compara 

        int horas = std::stoi(clinica->getAgendamentos()[i]->getHorario().substr(0,2));
        
        horas -= 8;
        horas *= 2;

        int duracaoMarcado = clinica->getAgendamentos()[i]->getServico()->getDuracao();

        if(duracaoMarcado % 30 != 0){
            duracaoMarcado -= duracaoMarcado % 30;
            duracaoMarcado += 30;
        }

        duracaoMarcado = duracaoMarcado / 30;

        for(int j = horas; j < horas+duracaoMarcado; j++){
            Agenda[j]++;
        }
    }

    for(long unsigned int i = 0, j = 8; j < 18; i += 30){
        if(i % 60 == 0 && i != 0){
            i = 0;
            j++;

            if(j == 18) break;
        }

        std::string horario = "";

        if(j < 10) horario += std::to_string(0) + std::to_string(j);
        else horario += std::to_string(j);

        horario += ':';

        if(i == 0) horario += std::to_string(0) + std::to_string(i);
        else horario += std::to_string(i);

        int horas = std::stoi(horario.substr(0,2));
        
        horas -= 8;
        horas *= 2;

        if(horario.substr(3, 2) == "30") horas++;

        if(duracao % 30 != 0){
            duracao -= duracao % 30;
            duracao += 30;
        }

        duracao = duracao / 30;

        bool valido = false;

        if(duracao + horas > 20) continue;

        for(long unsigned int k = horas; k < duracao+horas; k++){
            if(Agenda[k] == 1) break;
            
            if(k == (duracao+horas)-1) valido = true;
        }

        if(valido){
            horariosValidos.push_back(horario);
        }
    }

    return horariosValidos;

}