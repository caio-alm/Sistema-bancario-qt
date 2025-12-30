#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

using namespace std;

class Pessoa
{
protected:
    string m_nome;
    size_t m_idade;
    string m_data;
    string m_cpf;
    float m_renda;

public:
    Pessoa() {}
    Pessoa(string nome, size_t idade, string data, string cpf, float renda) : m_nome(nome), m_idade(idade), m_data(data), m_cpf(cpf), m_renda(renda) {}

    string GetNome();
    size_t GetIdade();
    string GetData();
    string GetCpf();
    float GetRenda();
};

#endif
