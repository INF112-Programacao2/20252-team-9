# Sistema de Gestão para Clínicas de Saúde 
 Projeto final da disciplina de INF112-Programação II desenvolvido em C++ que visa aplicar os conceitos de POO(Programação Orientada à Objetos), gerenciamento de memória, tratamento de exceções e manipulação de arquivos, que foram abordados em sala de aula.

---

 ## Sumário:
- [Descrição](#descrição)
- [Integrantes do Grupo](#integrantes)
- [Funções e características de cada perfil de acesso](#funções-e-características-de-cada--perfil-de-acesso)
- [Como instalar e executar](#como-instalar-e-executar)


---
## Descrição:

 A ideia do projeto é um programa para administrar uma clínica médica, que oferece diferentes tipos de serviços(exames, consultas e cirurgias). Por meio dele, é possível realizar agendamentos, seja com um médico específico ou escolher uma especialidade, e escolher um profissional com a agenda disponível no dia e horários desejados.
 O sistema poderá ser acessado por 3 tipos de pessoas diferentes *(médico, cliente e paciente)*, cada um com suas particularidades e funções específicas.

---
 ## Integrantes:
 
Ana Carolina Costa Pereira (106355) 

Bruno Alexander Pinto Sette (120562) 

Eduardo Magesti Santiago (120568) 

Icaro Avelar Fernandes (120551)  

Joao Pedro Monteiro Nunes Silva (120552)   

---
## Funções e características de cada  perfil de acesso:

### 💁‍♂️💁‍♀️ Atendente:
A atendente é reponsável pelo gerenciamento da clínica, sendo capaz de marcar e desmarcar consultas (desde que com o aval do paciente), visualizar a agenda geral de serviços da clínica dentro de um certo período de tempo, realizar o cadastro de um novo médico, ou desligar algum dos já contratados da instituição.

### 👨‍⚕️👩‍⚕️Médicos:
O médico possui uma identificação e uma especialidade que permite que ele conduza agendamentos específicos. Suas funcionalidades incluem:  consultar sua própria agenda, cadastrar seus horários de trabalho, adicionar feedbacks/diagnósticos em procedimentos passados e até cancelar agendamentos já marcados desde que apresente uma justificativa.

### 🛌 Paciente: 
O paciente pode cadastrar próprios agendamentos buscando por um médico em específico ou escolhendo uma especialidade e selecionando entre os profissionais disponíveis, além disso confirmar os agendamentos feitos pela atendente, ou cancelar. Ele também pode consultar seu histórico de procedimentos na clínica, tendo acesso aos diagnósticos e feedbacks deixados pelos médicos que o atenderam anteriormente.

---
## Como instalar e executar:

### Requisitos:
-Compilador C++ (g++)
-Makefile instalado

1. Clone o repositório:
   ```bash
   git clone https://github.com/INF112-Programacao2/20252-team-9.git

2. Compile o projeto fazendo o uso do makefile:
   
         make

   **OBS:** Certifique-se de que o make está devidamente instalado na máquina.

4. Execute:
   
   ./clinica

