//Includes
#include "../Headers/Utils.h"
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
        if(!std::isalpha(static_cast<unsigned char>(c))){
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

int lerInteiro(int min, int max){
    int numero=0;
    bool entradaValida = false;

    while(!entradaValida){
        std::string entrada;
        getline(std::cin, entrada);

        if(stringVazia(entrada)){
            std::cout << "Entrada nao pode ser vazia. Tente novamente\n";
            continue;
        }

        for(int i=0; i<entrada.size(); i++){
            if(!isdigit(entrada[i])){
                std::cout << "A entrada deve ser um numero inteiro. Tente novamente\n";
                continue;
            }
        }

        try{
            numero = std::stoi(entrada);
            if(numero >= min && numero <= max)
                entradaValida = true;
            else
                std::cout << "Escolha invalida, escolha algo entre " << min << " e " << max << std::endl;

        }catch(std::exception &e){
            std::cout << "Ocorreu um erro ao validar a entrada. Tente novamente\n";
        }
    }

    return numero;
}

int comparaData(std::string& data1, std::string& data2){
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
        long int valor1 = (ano1 * 10000) + (mes1 * 100) + dia1;
        long int valor2 = (ano2 * 10000) + (mes2 * 100) + dia2;

        if(valor1>valor2) return 1;
        if(valor2<valor1) return -1;

        return 0;
    }catch(std::exception &e){
        std::cout << "Ocorreu um erro ao converter as dadas durante a comparacao. Tente novamente\n";
    }
}