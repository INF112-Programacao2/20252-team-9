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

//Função que valida data(Obrigando-as a seguir o modelo XX/XX/XXXX dentro dos devidos limites quanto a dia e data)
bool validaData(const std::string& data);

//Função que valida o horário de agendamento(Obrigando-os a seguir o modelo XX:XX dentro dos devidos limites de minutos e hora)
bool validaHorario(const std::string& horario);

#endif