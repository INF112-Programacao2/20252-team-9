//Includes
#include "../Headers/Utils.h"
#include <regex>

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