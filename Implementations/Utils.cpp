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