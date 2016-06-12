#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//支持中文

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
