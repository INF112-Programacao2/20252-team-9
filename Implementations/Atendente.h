#include "Headers/Atendente.h"
#include "Utils.h"
#include <stdexcept>


//Gets e Sets
std::string Atendente::getMatricula() const {return matricula;}

void Atendente::setMatricula(std::string nova_matricula) {
    if(stringVazia(nova_matricula))
        throw std::invalid_argument("Matricula Inválida");
    this->matricula = nova_matricula;
}