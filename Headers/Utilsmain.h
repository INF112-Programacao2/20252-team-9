#ifndef PROJETO_FINAL_INF112_UTILS_MAIN_H
#define PROJETO_FINAL_INF112_UTILS_MAIN_H

#include <string>


void exibirMenuInicial();
void exibirMenuLogin(std::string &cpf, std::string &senha, bool &acertou);
bool tentarNovamente();
void exibirMenuMedico();
void exibirMenuPaciente();
void exibirMenuAtendente();
void enterParaContinuar();
void limparTela();


#endif