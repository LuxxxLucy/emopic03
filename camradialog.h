#ifndef CAMRADIALOG_H
#define CAMRADIALOG_H
#include <QDialog>

namespace Ui {
class camraDialog;
}

class camraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit camraDialog(QWidget *parent = 0);
    ~camraDialog();

private:
    Ui::camraDialog *ui;
};

#endif // CAMRADIALOG_H
