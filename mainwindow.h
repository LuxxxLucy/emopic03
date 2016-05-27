#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define PAINT_LINE 1
#define PAINT_TEXT 2

class QTime;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    int angle;
    void paint_on_screen();
    void paint_save(QString s);

    int state;

    QPointF first_point,second_point;
protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_open_image_dialog_clicked();
    void on_save_clicked();
    void on_save_a_new_clicked();
    void on_color_select_clicked();
    void on_font_select_clicked();
    void on_draw_line_button_clicked();
    void on_addtextbutton_clicked();
};

#endif // MAINWINDOW_H
