#include "dialogsobre.h"
#include "ui_dialogsobre.h"

Dialogsobre::Dialogsobre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogsobre)
{
    ui->setupUi(this);
}

Dialogsobre::~Dialogsobre()
{
    delete ui;
}
