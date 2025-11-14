//Include da classe a ser implementada
#include "Headers/ClasseModelo.h"

//Construtor
//Deve ser feito usando a inicializer list, essencial para poder fazer herenca e padronizar o projeto
//Obs: No caso da composicao1, que se recebe um objeto como parametro, passa-se seu endereço, já que o atributo é do tipo ponteiro
Classe::Classe(int number, std::string string, bool ok, OutraClasse1 &composicao1, std::vector <OutraClasse2>* &composicao2) 
    :number(number), string(string), ok(ok), composicao1(&composicao1), composicao2(composicao2)
    {
        //Pode ser feita implementacao adicional no construtor se for necessario alguma ação na hora de inicializar a variável
    }

//Destrutor
//Nesse exemplo ele é vazio, pois não há nada alocado dinamicamnete pelo construtor
Classe::~Classe(){

}

//Getters
//Mantem o const da assinatura do metodo
int Classe::getNumber() const {return number;}
std::string Classe::getString() const {return string;}
bool Classe::isOk() const {return ok;}
OutraClasse1* Classe::getComposicao1() const {return composicao1;}
std::vector <OutraClasse2>* Classe::getComposicao2() const  {return composicao2;}

//Setters
//Uso do this para diferenciar o parametro do atributo
void Classe::setNumber(int number){
    this->number = number;
}

void Classe::setString(std::string string){
    this->string = string;
}

void Classe::setOk(bool ok){
    this->ok = ok;
}

//Novamente, o atributo é do tipo ponteiro, então tem que ser reatribuido o endereço do objeto que é recebido por referência
void Classe::setComposicao1(OutraClasse1 &composicao1){
    this->composicao1 = &composicao1;
}

void Classe::setComposicao2(std::vector <OutraClasse2>* &composicao2){
    this->composicao2 = composicao2;
}

//Demais métodos
//Nesse caso não há uma implementação exemplo, afinal cada método desse distoa muito
//A ideia é manter boas práticas e se possível, em partes onde o código não for muito óbvio, deixar comentários explicando brevemente
std::string Classe::metodo(int number, OutraClasse1 &composicao1, std::vector <OutraClasse2>* &composicao2){}