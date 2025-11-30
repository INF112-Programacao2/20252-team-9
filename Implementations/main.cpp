#include <bits/stdc++.h>
#include "../Headers/Clinica.h"
#include "../Headers/Plano.h"

int main(){
    Clinica clinica("Salle's medic clinic");
    Plano plano("UNIMED", 0.2);

    Paciente paciente("Icaro", "696.969.699-69", "senha123", "(31) 9999-9999", "15/02/1945", 'F', "Autista e primata", &plano);
    clinica.adicionarPaciente(std::make_unique<Paciente>(paciente));

    const std::vector<std::unique_ptr<Paciente>>& pacientes = clinica.getPacientes();
    for(long unsigned int i=0; i<pacientes.size(); i++){
        pacientes[i].get()->VizualizaDados();
    }

    return 0;
}