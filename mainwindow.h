#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

#define PAINT_LINE 1
#define PAINT_TEXT 2
#define PAINT_POLYGON 3
#define PAINT_ELLIPSE 4
#define PAINT_RECTANGLE 5
#define LARGER 6
#define NORMAL 1
#define UNDO 2
#define REDO 3

#define MAX(a,b) ((a)>(b)? (a):(b))

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
//    QComboBox *brushStyle;

    int state;
    int state1;
    int state2;



    QPointF first_point,second_point,third_point;
protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private slots:
//    void on_open_image_dialog_clicked();
//    void on_save_clicked();
//    void on_save_a_new_clicked();
//    void on_color_select_clicked();
//    void on_font_select_clicked();
    void on_draw_line_button_clicked();
    void on_addtextbutton_clicked();
    void on_draw_polygon_button_clicked();
    void on_draw_ellipse_button_clicked();
    void on_draw_rectangle_button_clicked();
//    void on_undo_button_clicked();
//    void on_redo_button_clicked();
    void on_actionRedo_triggered();
    void on_actionUndo_triggered();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionSelect_color_triggered();
    void on_actionSelect_font_triggered();
    void on_actionSelect_brush_color_triggered();
    void on_actionUse_brush_triggered();
    void on_actionDon_t_use_brush_triggered();
    void on_actionSet_pen_width_triggered();
    void on_actionSet_brush_style_triggered();
};

#endif // MAINWINDOW_H
