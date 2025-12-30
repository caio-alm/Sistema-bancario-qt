#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconta.h"
#include "dialogsobre.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_login_clicked()
{
    string cpf = ui->lineEdit_cpf_login->text().toStdString();
    string senha = ui->lineEdit_senha_login->text().toStdString();
    string nome = ui->lineEdit_nome_login->text().toStdString();

    Conta_Corrente* conta_logada = nullptr;

    if (cpf.empty() || senha.empty() || nome.empty()) {
        QMessageBox::warning(this, "Erro de Login", "Por favor, preencha o NOME, CPF e a Senha.");
        return;
    }

    conta_logada = m_gerenciador.buscar_cpf(cpf);

    if (conta_logada != nullptr) {
        if (conta_logada->GetSenha() == senha && conta_logada->GetNome() == nome) {
            QMessageBox::information(this, "Sucesso", "Login realizado com sucesso!");
            DialogConta dialog(conta_logada, &m_gerenciador, this);

            this->hide();

            dialog.exec();

            this->show();

        } else {
            QMessageBox::warning(this, "Erro de Login", "Senha ou Nome incorretos.");
        }
    } else {
        QMessageBox::critical(this, "Erro de Login", "Conta não encontrada para o CPF informado.");
    }

    ui->lineEdit_senha_login->clear();
}


void MainWindow::on_pushButton_cadastrar_n_clicked()
{
    DialogCadastro dialog(&m_gerenciador, this);

    dialog.exec();
}


void MainWindow::on_pushButton_sobre_login_clicked()
{
    Dialogsobre dialog(this);

    dialog.exec();
}

