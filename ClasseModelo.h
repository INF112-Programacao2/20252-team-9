//Protecao contra multiplas compilacoes
#ifndef PROJETO_FINAL_INF_112_NOME_CLASSE
#define PROJETO_FINAL_INF_112_NOME_CLASSE

//Includes
#include <string>
#include <vector>

//Nao se deve usar o comando "using namespace std"

class Classe{
    //Atributos
    //Para os atributos, busque usar nomes mais curtos e claros possiveis(em Portugues)
    //Atributos que possuem tipo referente as outras classe(agregação) devem estar separados por uma quebra de linha(Como pode ser visto no exemplo)
    private:
        //Parametros declarados sem o _ (usa-se o this quando for necessario diferenciar o atributo da classe dentro do metodo)
        int number;
        std::string string;
        bool ok;

        //Atributos de outras classes da composicao devem ser ponteiros
        //No caso de atributos que armazenem multiplos objetos de uma outra classe, usa-se um vector de ponteiros
        //Essas duas práticase serve para "armazenar" um objeto já existente de outra classe e nao criar uma copia dele
        OutraClasse1* composicao1;
        std::vector <OutraClasse2>* composicao2;

    //Metodos
    public:
        //Construtor(s)
        //Se a classe possui atributos com tipo de outra classe e eles sao atribuidos ao construtor, os parametros devem ser referencias(Necessario para interacao obter o endereço do objeto que já existe, ao invez da cópia gerado no parâmetro)
        Classe(int number, std::string string, bool ok, OutraClasse1 &composicao1, std::vector <OutraClasse2>* &composicao2);

        //Destrutor
        ~Classe();

        //Getters
        //Devem conter o const, alem do prefixo "get" no nome do metodo(ou "is" caso seja referente a um atributo booleano)
        int getNumber() const;
        std::string getString() const;
        bool isOk() const;

        //Setters  
        //Devem conter o prefixo set e ser do tipo void e receber um parametro com mesmo nome do atributo a ser alterado(Usando o this dentro da sua implementacao para diferencia-los)
        void setNumber(int number);
        void setString(std::string string);
        void setComposicao1(OutraClasse1 &composicao1);
        void setComposicao2(std::vector <OutraClasse2>* &composicao2);

        //Metodos
        ///Abaixo ficariam os demais metodos
        //Devem conter virtual se forem metodos a serem reescritos em classes derivadas ou override se estiverem reescrevendo um metodo de uma super classe
        //Um coomentario adicional é bem vindo se for necessario para entender o que o metodo faz ou o que sao exatamente seus parametros
        //Uso das praticas citadas acima se a situacao for adequada
        virtual std::string metodo(int number, OutraClasse1 &composicao1, std::vector <OutraClasse2>* &composicao2);
        
};


//Classes declaradas apenas para demonstrar o exemplo de composicao, cada arquivo .h deve conter somente uma classe!
class OutraClasse1{
    //Atributos
    private:
        int number;

    //Metodos
    public:

};

class OutraClasse2{
    //Atributos
    private:
        int number;

    //Metodos
    public:

};

#endif