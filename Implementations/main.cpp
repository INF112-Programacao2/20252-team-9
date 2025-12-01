#include <bits/stdc++.h>
#include "../Headers/Clinica.h"
#include "../Headers/Plano.h"
#include "../Headers/Utilsmain.h"
#include "../Headers/Utils.h"

int main(){
    Clinica clinica("Xulio Medicina");
    clinica.popularClinica("populacao.txt");

    unsigned int escolha;
    
    std::cout << "Você entrou na " << clinica.getNome() << "!\n";

    enterParaContinuar();
    while (true){
        exibirMenuInicial();
        escolha = lerInteiro("Digite o que deseja fazer: ", 1, 3);

        if(escolha == 1) {

        }

        else if(escolha == 2) {
            bool tentouNovamente;
            while(true){
                std::string cpf, senha;
                bool acertou = true;
                exibirMenuLogin(cpf, senha, acertou);

                int sucesso_login = clinica.validarMedico(cpf, senha);
                if(!acertou) {
                    std::cout << "Cpf incorreto, deve ser no formato XXX.XXX.XXX-XX\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) continue;
                    else break;
                }
                else if(sucesso_login == 1){
                    std::cout << "Login efetuado com sucesso!\n";
                    enterParaContinuar();
                    break;
                }
                else if (sucesso_login == 0) {
                    std::cout << "A senha está incorreta.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) continue;
                    else break;
                }
                else if(sucesso_login == -1) {
                    std::cout << "O cpf não foi encontrado no sistema.\n";
                    tentouNovamente = tentarNovamente();
                    if(tentouNovamente) continue;
                    else break;
                }
            }
            if(!tentouNovamente) {
                limparTela();
                continue;
            }

        }

        else if(escolha == 3) {

        }

    }
    

    return 0;
}