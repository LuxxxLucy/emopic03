/********************************************************************************
** Form generated from reading UI file 'camradialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMRADIALOG_H
#define UI_CAMRADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_camraDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *camraDialog)
    {
        if (camraDialog->objectName().isEmpty())
            camraDialog->setObjectName(QStringLiteral("camraDialog"));
        camraDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(camraDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(camraDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), camraDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), camraDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(camraDialog);
    } // setupUi

    void retranslateUi(QDialog *camraDialog)
    {
        camraDialog->setWindowTitle(QApplication::translate("camraDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class camraDialog: public Ui_camraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMRADIALOG_H
