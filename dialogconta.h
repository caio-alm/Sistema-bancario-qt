#ifndef DIALOGCONTA_H
#define DIALOGCONTA_H

#include <QDialog>
#include "banco.hpp"
#include "banco_dados.hpp"

namespace Ui {
class DialogConta;
}

class DialogConta : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConta(Conta_Corrente* conta, Gerenciar* gerenciador, QWidget *parent = nullptr);
    ~DialogConta();

private slots:
    void carregarExtrato();

    void on_pushButton_depositar_clicked();

    void on_pushButton_sacar_clicked();

    void on_pushButton_transferir_clicked();

    void on_pushButton_sair_clicked();

    void on_pushButton_sobre_conta_clicked();

private:
    Ui::DialogConta *ui;
    Conta_Corrente* m_conta_atual;
    Gerenciar* m_gerenciador;
    void atualizarDadosNaTela();
};

#endif // DIALOGCONTA_H
