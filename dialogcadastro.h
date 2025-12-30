#ifndef DIALOGCADASTRO_H
#define DIALOGCADASTRO_H

#include <QDialog>
#include "banco_dados.hpp"

namespace Ui {
class DialogCadastro;
}

class DialogCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCadastro(Gerenciar* gerenciador, QWidget *parent = nullptr);
    ~DialogCadastro();

private slots:

    void on_pushButton_cadastro_clicked();

    void on_pushButton_sobre_cadastro_clicked();

private:
    Ui::DialogCadastro *ui;
    Gerenciar* m_gerenciador;
};

#endif // DIALOGCADASTRO_H
