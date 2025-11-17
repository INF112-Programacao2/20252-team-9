#include "Headers/Atendente.h"
#include <string>




//Gets e Sets
std::string Atendente::getMatricula() const {return matricula;}

void Atendente::setMatricula(std::string nova_matricula) {
    this->matricula = nova_matricula;
}