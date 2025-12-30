#include "banco.hpp"

size_t Conta_Corrente::GetId() { return m_id; }
float Conta_Corrente::GetSaldo() { return m_saldo; }
string Conta_Corrente::GetChave() { return m_chave; }
string Conta_Corrente::GetSenha() { return m_senha; }
string Conta_Corrente::GetTipo() { return m_tipo; }

vector<string> Conta_Corrente::GetHistorico(){ return m_historico; }


void Conta_Corrente::SetSaldo(float s) {  m_saldo = s; }
void Conta_Corrente::SetChave(string nova_chave) { m_chave = nova_chave; }

bool Conta_Corrente::depositar(float valor)
{
    float saldo_final = m_saldo + valor;
    m_saldo = saldo_final;
    adicionarMovimento("Você depositou R$ " + to_string(valor));
    return true;
}

bool Conta_Corrente::sacar(float valor)
{
    if(m_saldo <= valor) {
        return false;
    }
    else {
        m_saldo -= valor;
        adicionarMovimento("Você sacou R$ " + to_string(valor));
        return true;
    }
}
void Conta_Corrente::adicionarMovimento(string movimento)
{
    m_historico.push_back(movimento);
}

Conta_Vip::Conta_Vip(string nome, size_t idade, string data, string cpf, float renda, string chave, string senha, float saldo, size_t id) : Conta_Corrente(nome, idade, data, cpf, renda, chave, senha, saldo, id)
{
    m_credito = renda * 0.5;
    m_tipo = "Vip";
}

float Conta_Vip::GetCredito() { return m_credito; }
string Conta_Vip::GetTipo() { return "Vip"; }


bool Conta_Vip::sacar(float valor)
{
    if (m_saldo + m_credito >= valor) {
        m_saldo -= valor;
        adicionarMovimento("Você sacou R$ " + to_string(valor));

        return true;
    }
    return false;
}

float Conta_Vip::GetCreditoDisponivel()
{
    if (m_saldo >= 0) {
        return m_credito;
    } else {
        return m_credito + m_saldo;
    }
}
