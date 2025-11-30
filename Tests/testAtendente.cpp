#include <iostream>
#include "../Headers/Atendente.h"

int main(){
    Atendente atendente("Márcia", "10326821678", "123456", "32999682006", "0001");
    std::cout << atendente.getNome() << " " << atendente.getCpf() << " " << atendente.getSenha() << " " 
              << atendente.getTelefone() << " " << atendente.getMatricula() << std::endl;

    

}