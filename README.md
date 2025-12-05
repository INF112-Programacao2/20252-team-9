# Sistema de Gestão para Clínicas de Saúde  

Projeto final da disciplina **INF112 – Programação II**, desenvolvido em **C++**, com foco na aplicação prática dos conceitos estudados em sala de aula:

- Programação Orientada a Objetos (POO)  
- Gerenciamento de memória  
- Tratamento de exceções  
- Manipulação de arquivos  

---

## Sumário
- [Descrição](#descrição)
- [Integrantes](#integrantes)
- [Perfis de acesso e funcionalidades](#perfis-de-acesso-e-funcionalidades)
- [Como instalar e executar](#como-instalar-e-executar)
- [Observações importantes](#observações-importantes)

---

## Descrição

Este sistema realiza o gerenciamento completo de uma clínica médica, permitindo administrar **agendamentos, profissionais, serviços, planos e histórico de atendimentos**.

O sistema contempla três tipos de usuários, sendo eles **Atendente, Médico e Paciente**, cada um com permissões e funcionalidades específicas.

As operações principais incluem:

- Criar, consultar, alterar e remover agendamentos  
- Consultar histórico de procedimentos  
- Gerenciar profissionais e planos  
- Visualizar agendas e extratos da clínica  

---

## Integrantes

- Ana Carolina Costa Pereira — *106355*  
- Bruno Alexander Pinto Sette — *120562*  
- Eduardo Magesti Santiago — *120568*  
- Icaro Avelar Fernandes — *120551*  
- Joao Pedro Monteiro Nunes Silva — *120552*

---

## Perfis de acesso e funcionalidades

### 💁‍♀️💁‍♂️ Atendente
Responsável pela administração geral da clínica. Pode:

- Marcar e desmarcar consultas (com confirmação do paciente)  
- Visualizar a agenda completa da clínica   
- Cadastrar novos médicos  
- Desligar médicos já contratados  
- Consultar saldo e extrato da clínica  
- Cadastrar e alterar planos e serviços disponibilizados  

---

### 👨‍⚕️👩‍⚕️ Médico
Cada médico possui uma especialidade e um identificador próprio. Suas funções incluem:

- Visualizar sua própria agenda  
- Registrar diagnósticos e feedbacks de atendimentos realizados  
- Cancelar agendamentos já marcados  

---

### 🛌 Paciente
O paciente pode:

- Agendar consultas com um médico específico  
- Confirmar ou cancelar agendamentos solicitados pela atendente  
- Consultar seu histórico de procedimentos  
- Visualizar diagnósticos e feedbacks de atendimentos anteriores  

---

## Como instalar e executar

### Requisitos

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

5. Ou complile e execute de uma só vez utilizando:

         make run

### Observações importantes

- O perfil Atendente representa a administração da clínica e possui login único.
   - Utilize:
      - CPF: 111.111.111-11
      - Senha: 123

- Novos perfis podem ser criados da seguinte forma:

   - Médicos: cadastrados pela atendente

   - Pacientes: cadastrados pelo próprio paciente ou pela atendente

- Perfis previamente criados podem ser consultados no arquivo população.txt.
