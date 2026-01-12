# Sistema Bancário - Qt C++

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Qt](https://img.shields.io/badge/Qt-6.10.0-green)

Este é um projeto de **Sistema Bancário** com interface gráfica, desenvolvido como parte da avaliação da disciplina de Programação II na UFSC. O sistema utiliza Orientação a Objetos do C++ unido à robustez do framework Qt para criar uma aplicação funcional e intuitiva.

## Funcionalidades

O sistema simula as principais operações de um caixa eletrônico/internet banking:

- **Autenticação:** Sistema de Cadastro de novos usuários e Login seguro.
- **Operações Financeiras:** Realização de Saques, Depósitos e Transferências entre contas.
- **Gestão de Conta:** Consulta de saldo atualizado em tempo real.
- **Histórico:** Geração de extrato detalhado das movimentações.
- **Interface Gráfica:** GUI responsiva desenvolvida com Qt Widgets.

## Tecnologias Utilizadas

* **Linguagem:** C++ (Padrão moderno)
* **Framework:** Qt 6.10.0
* **IDE:** Qt Creator
* **Compilador:** MinGW 64-bit / MSVC
* **Interface:** Qt Widgets (.ui forms)

## Estrutura do Projeto

Sistema-bancario-qt

    
    CMakeLists.txt         - Arquivo de configuração de build (CMake)
    desenv.qrc             - Arquivo de recursos (imagens/ícones)
    main.cpp               - Ponto de entrada da aplicação
    
    Classes (Lógica):
    banco.cpp/hpp          - Lógica principal do sistema bancário
    banco_dados.cpp/hpp    - Gerenciamento de persistência de dados
    pessoa.cpp/hpp         - Classe base para usuários/clientes
    
    Interfaces (UI + Lógica):
    mainwindow.ui/cpp/hpp     - Janela Principal
    dialogcadastro.ui/cpp/hpp - Janela de Cadastro
    dialogconta.ui/cpp/hpp    - Janela de Gerenciamento da Conta
    dialogsobre.ui/cpp/hpp    - Janela "Sobre" com créditos


## Como Rodar o Projeto
[![Download Zip](https://img.shields.io/badge/Download-Baixar_ZIP-blue?style=for-the-badge&logo=windows)](https://github.com/caio-alm/Sistema-bancario-qt/releases/download/v1.0/TP_2qt.zip)

1. Baixe o arquivo **TP_2qt.zip**.
3. Após a instalação fazer a extração dos arquivos
4. Abra o Qt Creator.
5. Vá em Open Project, e procure a pasta com os arquivos extraidos.
6. Já dentro da pasta faça o seguinte caminho:
   - **TP_2qt > SistemaBancoQt > CMakeLists**
   - Após isso você terá o código aberto em seu Qt Creator.
