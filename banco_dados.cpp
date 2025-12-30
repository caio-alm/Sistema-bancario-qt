#include "banco_dados.hpp"
#include <fstream>
#include <sstream>

void Gerenciar::criarNovaConta(string nome, size_t idade, string data, string cpf, float renda, string chave, string senha, float saldo, size_t id)
{
    Conta_Corrente* nova_conta = nullptr;
    if(ver_ContaVIP(renda)) {
        nova_conta = new Conta_Vip(nome, idade, data, cpf, renda, chave, senha, saldo, id);
    }

    else {
        nova_conta = new Conta_Corrente(nome, idade, data, cpf, renda, chave, senha, saldo, id);
    }

    contas.push_back(nova_conta);

}

Conta_Corrente* Gerenciar::buscar_chave(string chave)
{
    for(size_t i = 0; i < contas.size(); i++)
    {
        Conta_Corrente* conta = contas.at(i);

        if (conta != nullptr) {
            if (conta->GetChave() == chave) {
                return conta;
            }
        }
    }

    return nullptr;
}

Conta_Corrente* Gerenciar::buscar_cpf(string cpf)
{
    for(size_t i = 0; i < contas.size(); i++)
    {
        Conta_Corrente* conta = contas.at(i);

        if(conta != nullptr) {
            if(conta->GetCpf() == cpf) {
                return conta;
            }
        }
    }
    return nullptr;
}


void Gerenciar::salvar_dados() 
{
    ofstream arquivo(arq);
    if (arquivo.is_open()) {
        for (size_t i = 0; i < contas.size(); i++) {
            Conta_Corrente* conta = contas.at(i); 

            arquivo << conta->GetNome() << ";" 
                    << conta->GetIdade() << ";" 
                    << conta->GetData() << ";"
                    << conta->GetCpf() << ";"
                    << conta->GetRenda() << ";"
                    << conta->GetChave() << ";" 
                    << conta->GetSenha() << ";"
                    << conta->GetSaldo() << ";"
                    << conta->GetId() << ";"
                    << conta->GetTipo();

            vector<string> historico = conta->GetHistorico();

            arquivo << ";";

            for (size_t j = 0; j < historico.size(); ++j) {
                arquivo << historico.at(j);
                if (j < historico.size() - 1) {
                    arquivo << "|";
                }
            }

            arquivo << "\n";
        }
        arquivo.close();
    }

}

void Gerenciar::carregar_dados()
{
    ifstream arquivo(arq);
    if (!arquivo.is_open()) {
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string item;
        vector<string> dados;
        
        while (getline(ss, item, ';')) {
            dados.push_back(item);
        }

        if (dados.size() >= 10) {
            

            string nome = dados.at(0);
            size_t idade = stoul(dados.at(1));
            string data = dados.at(2);
            string cpf = dados.at(3);
            float renda = stof(dados.at(4));
            string chave = dados.at(5);
            string senha = dados.at(6);
            float saldo = stof(dados.at(7));
            size_t id = stoul(dados.at(8));
            string tipo_conta = dados.at(9);

            Conta_Corrente* conta = nullptr;

            if(tipo_conta == "Vip") {
                conta = new Conta_Vip(nome, idade, data, cpf, renda, chave, senha, saldo, id);
            }

            else {
                conta = new Conta_Corrente(nome, idade, data, cpf, renda, chave, senha, saldo, id);
            }

            if (dados.size() > 10) {
                string historico = dados.at(10);
                stringstream hs(historico);
                string movimento;

                while (getline(hs, movimento, '|')) {
                    if (!movimento.empty()) {
                        conta->adicionarMovimento(movimento);
                    }
                }
            }

            contas.push_back(conta);
        }
    }
    arquivo.close();
}

bool Gerenciar::transferir(Conta_Corrente* origem, float valor, string chave_destino)
{
    Conta_Corrente* destino = nullptr;

    destino = buscar_chave(chave_destino);

    if (destino == nullptr || destino == origem) {
        return false;
    }

    string nome_destino = destino->GetNome();

    if (origem->sacar(valor)) {
        if(destino->depositar(valor)) {
            origem->adicionarMovimento("Você transferiu R$ " + to_string(valor) + " para " + nome_destino);

            destino->adicionarMovimento("Você recebeu R$ " + to_string(valor) + " de " + origem->GetNome());
            salvar_dados();
            return true;
        }
    }

    else {
        return false;
    }
}

bool Gerenciar::ver_ContaVIP(float renda)
{
    if (renda > 5000) {
        return true;
    }

    return false;
}

