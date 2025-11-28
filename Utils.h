//Cabeçalho destinado a armazenar funções necessárias para o bom funcionamento das classes
//Ex:Função que valida um determinado tipo de entrada desejada pelo usuário

//Includes
#include <string>

//Função que retorna se é uma string vazia(Sem nenhum caracter/Vários espaços/ tabs etc...)
bool stringVazia(const std::string &string);

//Funcao que checa se um string é composto só por letras(validação do nome)
bool somenteLetras(const std::string &palavra);

//Função para checar se uma string só tem números(validação do nº de telefone
bool somenteNumeros(const std::string& numero);