#ifndef BANCO_DADOS_HPP
#define BANCO_DADOS_HPP

#include "banco.hpp"
#include <vector>

class Gerenciar
{
private:
    vector<Conta_Corrente*> contas;
    string arq = "Contas.txt";

public:
    Gerenciar() { carregar_dados(); }
    ~Gerenciar()
    {
        salvar_dados();
        for (size_t i = 0; i < contas.size(); ++i)
        { 
            delete contas.at(i); 
        }
        contas.clear();
    }

    size_t getContasSize() { return contas.size(); }
    void criarNovaConta(string nome, size_t idade, string data, string cpf, float renda,string chave, string senha, float saldo, size_t id);
    Conta_Corrente* buscar_chave(string chave);
    Conta_Corrente* buscar_cpf(string cpf);

    void salvar_dados();
    void carregar_dados();
    bool transferir(Conta_Corrente* origem, float valor, string chave_destino);
    bool ver_ContaVIP(float renda);

};

#endif
