#include "camradialog.h"
#include "ui_camradialog.h"

camraDialog::camraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camraDialog)
{
    ui->setupUi(this);
}

camraDialog::~camraDialog()
{
    delete ui;
}
