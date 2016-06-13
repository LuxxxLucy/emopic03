/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *open_image_dialog;
    QPushButton *save;
    QPushButton *save_a_new;
    QPushButton *color_select;
    QPushButton *font_select;
    QPushButton *draw_line_button;
    QPushButton *addtextbutton;
    QPushButton *draw_polygon_button;
    QPushButton *draw_ellipse_button;
    QPushButton *draw_rectangle_button;
    QPushButton *undo_button;
    QPushButton *redo_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(656, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        open_image_dialog = new QPushButton(centralWidget);
        open_image_dialog->setObjectName(QStringLiteral("open_image_dialog"));
        open_image_dialog->setGeometry(QRect(510, 10, 113, 32));
        save = new QPushButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(510, 40, 113, 32));
        save_a_new = new QPushButton(centralWidget);
        save_a_new->setObjectName(QStringLiteral("save_a_new"));
        save_a_new->setGeometry(QRect(510, 70, 113, 32));
        color_select = new QPushButton(centralWidget);
        color_select->setObjectName(QStringLiteral("color_select"));
        color_select->setGeometry(QRect(510, 100, 113, 32));
        font_select = new QPushButton(centralWidget);
        font_select->setObjectName(QStringLiteral("font_select"));
        font_select->setGeometry(QRect(510, 130, 113, 32));
        draw_line_button = new QPushButton(centralWidget);
        draw_line_button->setObjectName(QStringLiteral("draw_line_button"));
        draw_line_button->setGeometry(QRect(510, 160, 113, 32));
        addtextbutton = new QPushButton(centralWidget);
        addtextbutton->setObjectName(QStringLiteral("addtextbutton"));
        addtextbutton->setGeometry(QRect(510, 280, 113, 32));
        draw_polygon_button = new QPushButton(centralWidget);
        draw_polygon_button->setObjectName(QStringLiteral("draw_polygon_button"));
        draw_polygon_button->setEnabled(true);
        draw_polygon_button->setGeometry(QRect(510, 190, 113, 32));
        draw_polygon_button->setContextMenuPolicy(Qt::DefaultContextMenu);
        draw_ellipse_button = new QPushButton(centralWidget);
        draw_ellipse_button->setObjectName(QStringLiteral("draw_ellipse_button"));
        draw_ellipse_button->setGeometry(QRect(510, 220, 113, 32));
        draw_rectangle_button = new QPushButton(centralWidget);
        draw_rectangle_button->setObjectName(QStringLiteral("draw_rectangle_button"));
        draw_rectangle_button->setGeometry(QRect(510, 250, 113, 32));
        undo_button = new QPushButton(centralWidget);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        undo_button->setGeometry(QRect(510, 310, 113, 32));
        redo_button = new QPushButton(centralWidget);
        redo_button->setObjectName(QStringLiteral("redo_button"));
        redo_button->setGeometry(QRect(510, 340, 113, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(draw_rectangle_button, SIGNAL(clicked()), MainWindow, SLOT(update()));
        QObject::connect(draw_ellipse_button, SIGNAL(clicked()), MainWindow, SLOT(update()));
        QObject::connect(draw_polygon_button, SIGNAL(clicked()), MainWindow, SLOT(update()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        open_image_dialog->setText(QApplication::translate("MainWindow", "open image", 0));
        save->setText(QApplication::translate("MainWindow", "save ", 0));
        save_a_new->setText(QApplication::translate("MainWindow", "save as", 0));
        color_select->setText(QApplication::translate("MainWindow", "select color", 0));
        font_select->setText(QApplication::translate("MainWindow", "select font", 0));
        draw_line_button->setText(QApplication::translate("MainWindow", "draw one line", 0));
        addtextbutton->setText(QApplication::translate("MainWindow", "add text", 0));
        draw_polygon_button->setText(QApplication::translate("MainWindow", "draw triangle", 0));
        draw_ellipse_button->setText(QApplication::translate("MainWindow", "draw ellipse", 0));
        draw_rectangle_button->setText(QApplication::translate("MainWindow", "draw rectangle", 0));
        undo_button->setText(QApplication::translate("MainWindow", "undo", 0));
        redo_button->setText(QApplication::translate("MainWindow", "redo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
