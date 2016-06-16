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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSelect_color;
    QAction *actionSelect_font;
    QAction *actionSelect_brush_color;
    QAction *actionUse_brush;
    QAction *actionDon_t_use_brush;
    QAction *actionSet_pen_width;
    QAction *actionSet_brush_style;
    QWidget *centralWidget;
    QPushButton *draw_line_button;
    QPushButton *addtextbutton;
    QPushButton *draw_polygon_button;
    QPushButton *draw_ellipse_button;
    QPushButton *draw_rectangle_button;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(656, 502);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionSelect_color = new QAction(MainWindow);
        actionSelect_color->setObjectName(QStringLiteral("actionSelect_color"));
        actionSelect_font = new QAction(MainWindow);
        actionSelect_font->setObjectName(QStringLiteral("actionSelect_font"));
        actionSelect_brush_color = new QAction(MainWindow);
        actionSelect_brush_color->setObjectName(QStringLiteral("actionSelect_brush_color"));
        actionUse_brush = new QAction(MainWindow);
        actionUse_brush->setObjectName(QStringLiteral("actionUse_brush"));
        actionDon_t_use_brush = new QAction(MainWindow);
        actionDon_t_use_brush->setObjectName(QStringLiteral("actionDon_t_use_brush"));
        actionSet_pen_width = new QAction(MainWindow);
        actionSet_pen_width->setObjectName(QStringLiteral("actionSet_pen_width"));
        actionSet_brush_style = new QAction(MainWindow);
        actionSet_brush_style->setObjectName(QStringLiteral("actionSet_brush_style"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_color);
        menuEdit->addAction(actionSet_pen_width);
        menuEdit->addAction(actionSelect_brush_color);
        menuEdit->addAction(actionSet_brush_style);
        menuEdit->addAction(actionSelect_font);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open image", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionSelect_color->setText(QApplication::translate("MainWindow", "Set pen color", 0));
        actionSelect_font->setText(QApplication::translate("MainWindow", "Set font", 0));
        actionSelect_brush_color->setText(QApplication::translate("MainWindow", "Set brush color", 0));
        actionUse_brush->setText(QApplication::translate("MainWindow", "Use brush", 0));
        actionDon_t_use_brush->setText(QApplication::translate("MainWindow", "Don't use brush", 0));
        actionSet_pen_width->setText(QApplication::translate("MainWindow", "Set pen width", 0));
        actionSet_brush_style->setText(QApplication::translate("MainWindow", "Set brush style", 0));
        draw_line_button->setText(QApplication::translate("MainWindow", "draw one line", 0));
        addtextbutton->setText(QApplication::translate("MainWindow", "add text", 0));
        draw_polygon_button->setText(QApplication::translate("MainWindow", "draw triangle", 0));
        draw_ellipse_button->setText(QApplication::translate("MainWindow", "draw ellipse", 0));
        draw_rectangle_button->setText(QApplication::translate("MainWindow", "draw rectangle", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File(F)", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit(E)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
