#ifndef PROJETO_FINAL_INF112_UTILS_MAIN_H
#define PROJETO_FINAL_INF112_UTILS_MAIN_H

#include <string>
#include "../Headers/Clinica.h"

void exibirMenuInicial();
void exibirMenuLogin(std::string &cpf, std::string &senha, bool &acertou);
bool tentarNovamente();
bool dadosValidos(std::string &nome, std::string &cpf, std::string &senha, std::string &telefone, std::string &dataDeNascimento, char &sexo, std::string &observacoes, Plano*& plano, Clinica* clinica);
void exibirMenuMedico();
void exibirMenuPaciente();
void exibirMenuAtendente();
void enterParaContinuar();
void limparTela();


#endif