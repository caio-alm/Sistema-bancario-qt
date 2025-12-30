#include "dialogconta.h"
#include "dialogsobre.h"
#include "ui_dialogconta.h"
#include <QMessageBox>


DialogConta::DialogConta(Conta_Corrente* conta, Gerenciar* gerenciador, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConta)
    , m_conta_atual(conta)
    , m_gerenciador(gerenciador)
{
    ui->setupUi(this);

    ui->label_nome_cliente->setText(QString::fromStdString(m_conta_atual->GetNome()));
    ui->label_conta_cliente->setText(QString::number(m_conta_atual->GetId()));
    ui->label_chave_cliente->setText(QString::fromStdString(m_conta_atual->GetChave()));
    carregarExtrato();
    atualizarDadosNaTela();
}
void DialogConta::atualizarDadosNaTela()
{
    float saldo = m_conta_atual->GetSaldo();
    float credito = 0.0f;

    Conta_Vip* conta_vip = dynamic_cast<Conta_Vip*>(m_conta_atual);

    if (conta_vip != nullptr) {
        credito = conta_vip->GetCreditoDisponivel();
    }

    ui->label_saldo_atual->setText(QString("R$ ").append(QString::number(saldo, 'f', 2)));
    ui->label_chave_cliente_2->setText((QString("R$ ").append(QString::number(credito, 'f', 2))));
}

DialogConta::~DialogConta()
{
    m_gerenciador->salvar_dados();
    delete ui;
}


void DialogConta::on_pushButton_depositar_clicked()
{
    float valor = ui->spinBox_valor_deposito->value();
    if (m_conta_atual->depositar(valor)) {
        QMessageBox::information(this, "Sucesso", "Depósito de R$ " + QString::number(valor, 'f', 2) + " realizado!");

        atualizarDadosNaTela();
        carregarExtrato();
        m_gerenciador->salvar_dados();
        ui->spinBox_valor_deposito->clear();
    }
}


void DialogConta::on_pushButton_sacar_clicked()
{
    float valor = ui->spinBox_Valor_saque->value();

    bool ok = m_conta_atual->sacar(valor);

    if (ok) {
        QMessageBox::information(this, "Sucesso", "Saque de R$ " + QString::number(valor, 'f', 2) + " realizado!");

        atualizarDadosNaTela();
        carregarExtrato();
        m_gerenciador->salvar_dados();
        ui->spinBox_Valor_saque->clear();
    } else {
        QMessageBox::warning(this, "Erro!", "Valor Inválido ou Saldo Insuficiente!");
    }
}


void DialogConta::on_pushButton_transferir_clicked()
{
    float valor = ui->spinBox_Valor_transferir->value();
    string chave_d = ui->lineEdit_chave_destino->text().toStdString();

    if (chave_d.empty()) {
        QMessageBox::warning(this, "Erro", "Informe a chave de destino (CPF/PIX).");
        return;
    }

    if (m_gerenciador->transferir(m_conta_atual, valor, chave_d)) {

        QMessageBox::information(this, "Sucesso", "Transferência de R$ " + QString::number(valor, 'f', 2) + " para " + QString::fromStdString(chave_d) + " realizada!");

        atualizarDadosNaTela();
        carregarExtrato();
        ui->spinBox_Valor_transferir->clear();
        ui->lineEdit_chave_destino->clear();

    } else {

        QMessageBox::critical(this, "Erro de Transferência", "Falha na transferência. Verifique o saldo e a chave de destino.");
    }
}


void DialogConta::on_pushButton_sair_clicked()
{
    QMessageBox::information(this, "Logout", "Sessão encerrada. Os dados foram salvos.");
    m_gerenciador->salvar_dados();
    this->reject();
}

void DialogConta::carregarExtrato()
{
    ui->tableWidget_extrato->setRowCount(0);

    vector<string> historico = m_conta_atual->GetHistorico();

    ui->tableWidget_extrato->setColumnCount(1);
    QHeaderView *header = ui->tableWidget_extrato->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Stretch);

    int linha_atual = 0;

    for (size_t i = 0; i < historico.size(); ++i) {

        string movimento = historico.at(i);

        ui->tableWidget_extrato->insertRow(linha_atual);

        QTableWidgetItem *item_descricao = new QTableWidgetItem(QString::fromStdString(movimento));
        ui->tableWidget_extrato->setItem(linha_atual, 0, item_descricao);

        linha_atual++;
    }
}


void DialogConta::on_pushButton_sobre_conta_clicked()
{
    Dialogsobre dialog(this);

    dialog.exec();
}

