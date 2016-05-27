#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trackline.h"
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMouseEvent>

#define FILE_DEFAULT_PATH "/Users/lucy/Desktop/"

QImage image;
QString image_path=NULL;
QString default_save_file_path=NULL;
QString target_string;
QFont font_now;
QColor color_now;
int point_size;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QTimer * timer = new QTimer(this);

//    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
//     timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint_on_screen()
{
     QPoint offset(20,20);
    QPainter painter;
    QPainter painter_on_image;
    painter.begin(this);

    QImage nimage = image.scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    painter.drawImage(offset,nimage);

    switch (state) {
    case PAINT_LINE :
        painter.drawLine(first_point,second_point);

        painter_on_image.drawLine((first_point.x()-offset.x())*(1.0*image.width()/width()),
                                  (first_point.y()-offset.y())*(1.0*image.height()/height()),
                                  (second_point.x()-offset.x())*(1.0*image.width()/width()),
                                  (second_point.y()-offset.y())*(1.0*image.height()/height())
                                  );
        state=0;
        break;
     case PAINT_TEXT:

            font_now.setUnderline(false);
            font_now.setOverline(false);
            font_now.setCapitalization(QFont::SmallCaps);
            font_now.setLetterSpacing(QFont::AbsoluteSpacing,10);
            font_now.setPointSize(point_size);
            qDebug()<<"font size"<<point_size<<endl;
            painter.setFont(font_now);
            painter.setPen(Qt::gray);
            painter.drawText(first_point,target_string);

            painter_on_image.setFont(font_now);
            painter_on_image.setPen(Qt::gray);
            painter_on_image.drawText((first_point.x()-offset.x())*(1.0*image.width()/width()),
                                      (first_point.y()-offset.y())*(1.0*image.height()/height()),
                                      target_string);
            state=0;
        break;
    default:
        break;
    }


    painter.end();


}

void MainWindow::paint_save(QString s)
{
    image.save(s);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(image_path!=NULL)
 {
    default_save_file_path=image_path;
    paint_on_screen();
    }
}

void MainWindow::on_open_image_dialog_clicked()
{
    image_path = QFileDialog::getOpenFileName(this,"file dialog",FILE_DEFAULT_PATH,"image file(* png * jpg)");
     qDebug()<<"file name is : "<<image_path<<endl;
    image.load(image_path);
    update();
}

void MainWindow::on_save_clicked()
{
    paint_save(default_save_file_path);
    qDebug()<<"default save in "<<default_save_file_path<<endl;
}


void MainWindow::on_save_a_new_clicked()
{
    QString new_save_path = QFileDialog::getSaveFileName(this,"file dialog",FILE_DEFAULT_PATH,"image file(* png * jpg)");
     qDebug()<<"file name is : "<<new_save_path<<endl;
    paint_save(new_save_path);
}

void MainWindow::on_color_select_clicked()
{
    QColorDialog color_dia(Qt::red,this);
      color_dia.setOption(QColorDialog::ShowAlphaChannel);
      color_dia.exec();
      color_now = color_dia.currentColor();
      qDebug()<<"current color is "<<color_now<<endl;
}

void MainWindow::on_font_select_clicked()
{
    bool OK;
    font_now = QFontDialog::getFont(&OK,this);
     if(OK)
     {
         qDebug()<<"current font is "<< font_now <<endl;
     }
     else
     {
         qDebug()<<"no font select!!!"<< endl;
     }

}


void MainWindow::mousePressEvent(QMouseEvent* event)
  {

//    if(event->button() == Qt::LeftButton)
//    {
//        switch(state)
//        {

//        case 0 :    point=event->pos();
//                    state=1;
//                    qDebug()<<"get first point " <<point<<endl;

//                    setMouseTracking(false);
//            break;
//            case 1: point=event->pos();
//            qDebug()<<"get  second point " <<point<<endl;
//                    state=2;
//            break;
//        case 2:break;
//        default:break;


//        }


        if(hasMouseTracking())
        {
            setMouseTracking(false);
            second_point=event->pos();
            qDebug()<<"get second point " <<second_point<<endl;

        }
        else
        {
            first_point=event->pos();
            qDebug()<<"get first point " <<first_point<<endl;
            setMouseTracking(true);
        }


  }
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::on_draw_line_button_clicked()
{
    state=PAINT_LINE;
    update();
}

void MainWindow::on_addtextbutton_clicked()
{

    bool OK1;
    // to get a string
    target_string = QInputDialog::getText(this,"tpye text dialog!",
                                                  "type text now!",
                                                   QLineEdit::Normal,
                                                   "type here",
                                                   &OK1);
    if(OK1) qDebug()<<"string is "<<target_string <<endl;

    bool OK2;
      // to get a int
      point_size  = QInputDialog::getInt(this,"tpye in the size of font!",
                                             "range from -1000 ~ 1000",
                                             1,
                                              -1000,
                                              1000,
                                             10,
                                             &OK2);
      if(OK2) qDebug()<<"font size is "<< point_size <<endl;
    state=PAINT_TEXT;
    update();
}