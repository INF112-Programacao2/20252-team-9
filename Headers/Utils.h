//Cabeçalho destinado a armazenar funções necessárias para o bom funcionamento das classes
//Ex:Função que valida um determinado tipo de entrada desejada pelo usuário

#ifndef PROJETO_FINAL_INF_112_UTILS_H
#define PROJETO_FINAL_INF_112_UTILS_H

//Includes
#include <string>

//Função que retorna se é uma string vazia(Sem nenhum caracter/Vários espaços/ tabs etc...)
bool stringVazia(const std::string& string);

//Funcao que checa se um string é composto só por letras(validação do nome)
bool somenteLetras(const std::string &palavra);

//Função para checar se uma string só tem números(validação do nº de telefone
bool somenteNumeros(const std::string& numero);

//Função que valida data(Obrigando-a a seguir o modelo XX/XX/XXXX dentro dos devidos limites quanto a dia e data)
bool validaData(const std::string& data);

//Função que valida o horário de agendamento(Obrigando-o a seguir o modelo XX:XX dentro dos devidos limites de minutos e hora)
bool validaHorario(const std::string& horario);

//Função que valida CPF(Obrigando-o a seguir o modelo XXX.XXX.XXX-XX)
bool validaCpf(const std::string& cpf);

//Função que valida telefone(Obrigando-o a seguir o modelo (XX) XXXX-XXXX ou (XX) XXXXX-XXXX)
bool validaTelefone(const std::string& telefone);

//Função que valida CRM(Obrigando-o a seguir o modelo SIGLA/UF NUMERO)
bool validaCrm(const std::string& crm);

//Função que valida uma escolha de um inteiro dentro de um intervalo
int lerInteiro(const std::string& mensagem, int min, int max);

//Função que valida uma escolha de um double dentro de um intervalo
//Tambem recebe a uma string, que se referem a mensagem que deve ficar repetindo nas tentativas de preenchimento
//Ex: Valor(R$): 
double lerDouble(const std::string& mensagem, double min, double max);

//Função para comparar data
//Retorna -1 se data1<data2
//Retorna 0 se data1 == data2
//Retorna 1 se data1 > data2
int comparaData(const std::string& data1, const std::string& data2);

//Função para achar os horarios disponiveis para um agendamento em uma determinada data
std::vector<std::string> buscaHorarioValido(const std::string& data);

#endif