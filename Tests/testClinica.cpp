//Arquivo para testes da classe clinca.h
//Includes
#include <iostream>
#include "../Headers/Clinica.h"

int main(){
    //Inicialização da variável e população
    Clinica clinica = Clinica("Centro odontologico");
    clinica.popularClinica("populacao.txt");

    

    return 0;
}