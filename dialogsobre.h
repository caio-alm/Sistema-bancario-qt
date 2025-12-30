#ifndef DIALOGSOBRE_H
#define DIALOGSOBRE_H

#include <QDialog>

namespace Ui {
class Dialogsobre;
}

class Dialogsobre : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogsobre(QWidget *parent = nullptr);
    ~Dialogsobre();

private:
    Ui::Dialogsobre *ui;
};

#endif // DIALOGSOBRE_H
