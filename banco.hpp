#ifndef BANCO_HPP
#define BANCO_HPP

#include <iostream>
#include "pessoa.hpp"
#include <vector>

using namespace std;

class Conta_Corrente : public Pessoa
{
protected:
    size_t m_id;
    float m_saldo;
    string m_chave;
    string m_senha;
    string m_tipo = "Corrente";
    vector<string> m_historico;
public:
    Conta_Corrente(){}
    Conta_Corrente(string nome, size_t idade, string data, string cpf, float renda, string chave, string senha, float saldo, size_t id) : Pessoa(nome, idade, data, cpf, renda), m_chave(chave), m_senha(senha),  m_saldo(saldo), m_id(id){}
    virtual ~Conta_Corrente(){}

    size_t GetId();
    float GetSaldo();
    string GetChave();
    string GetSenha();
    string GetTipo();
    vector<string> GetHistorico();


    void SetSaldo(float s);
    void SetChave(string nova_chave);

    virtual bool depositar(float valor);
    virtual bool sacar(float valor);
    void adicionarMovimento(string movimento);
};

class Conta_Vip : public Conta_Corrente
{
private:
    float m_credito;

public:
    Conta_Vip(){}
    Conta_Vip(string nome, size_t idade, string data, string cpf, float renda, string chave, string senha, float saldo, size_t id);

    float GetCredito();
    string GetTipo();

    bool sacar(float valor);
    float GetCreditoDisponivel();

};

#endif



