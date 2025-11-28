//Includes
#include "../Headers/Utils.h"

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