#include "dialogcadastro.h"
#include "ui_dialogcadastro.h"
#include "dialogsobre.h"
#include <QMessageBox>

DialogCadastro::DialogCadastro(Gerenciar* gerenciador, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCadastro)
    , m_gerenciador(gerenciador)
{
    ui->setupUi(this);
}

DialogCadastro::~DialogCadastro()
{
    delete ui;
}


void DialogCadastro::on_pushButton_cadastro_clicked()
{
    string nome = ui->lineEdit_nome_cadastro->text().toStdString();
    size_t idade = ui->spinBox_idade->value();
    string data = ui->dateEdit_data->date().toString("dd/mm/yyyy").toStdString();
    string cpf = ui->lineEdit_cpf_cadastro->text().toStdString();
    float renda = ui->lineEdit_renda->text().toFloat();
    string chave = ui->lineEdit_chave->text().toStdString();
    string senha = ui->lineEdit_senha_cadastro->text().toStdString();

    if (nome.empty() || cpf.empty() || senha.empty()) {
        QMessageBox::warning(this, "Erro", "Preencha todos os campos obrigatórios.");
        return;
    }

    if (senha.size() < 8) {
        QMessageBox::warning(this, "Erro", "Senha precisa ter 8 caracteres.");
        return;
    }

    if (idade < 18) {
        QMessageBox::warning(this, "Erro", "Banco exclusivo para maiores de 18 anos.");
        return;
    }

    if (cpf.size() < 11 || cpf.size() > 11) {
        QMessageBox::warning(this, "Erro", "CPF Inválido.");
        return;
    }

    float saldo_inicial = 0.0f;
    size_t id_conta = m_gerenciador->getContasSize() + 1000;
    m_gerenciador->criarNovaConta(nome, idade, data, cpf, renda, chave, senha, saldo_inicial, id_conta);
    m_gerenciador->salvar_dados();

    if(m_gerenciador->ver_ContaVIP(renda)) {
        QMessageBox::information(this, "Sucesso", "Conta VIP criada com sucesso! ID: " + QString::number(id_conta));
    }

    else {
        QMessageBox::information(this, "Sucesso", "Conta Corrente criada com sucesso! ID: " + QString::number(id_conta));
    }

    ui->lineEdit_nome_cadastro->clear();
    ui->lineEdit_cpf_cadastro->clear();
    ui->lineEdit_renda->clear();
    ui->lineEdit_chave->clear();
    ui->lineEdit_senha_cadastro->clear();
    ui->spinBox_idade->setValue(0);
    ui->dateEdit_data->setDate(QDate::currentDate());
    this->accept();
}


void DialogCadastro::on_pushButton_sobre_cadastro_clicked()
{
    Dialogsobre dialog(this);

    dialog.exec();
}

