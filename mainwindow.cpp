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
QPointF Tri[3];
QPen pen;
bool isDrawing;
bool firstLoad;
QImage Tmp;

//int i = 0;
//int state1;//用于画多边形

//painterNode *painter;
//painterNode *painter_on_image;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isDrawing = false;

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

//     QPainter painter;
     //QPainter painter_on_image;
    if(firstLoad == false)
        image.load("Tmp.png");
    else firstLoad = false;
//    painter.begin(this);

    QImage nimage = image.scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPainter painter1(this);
    painter1.drawImage(offset,nimage);
//    QPainter painter_on_image(&nimage);
    QPainter painter(&nimage);

    pen.setColor(color_now);
    painter.setPen(pen);
//    painter_on_image.setPen(pen);
if(isDrawing)
{
    switch (state) {
    case PAINT_LINE :
//        if(isDrawing)
//        {
//            Tmp = nimage;
//            QPainter pp(&Tmp);
//            pp.drawLine(first_point,second_point);
//            painter.drawImage(offset, Tmp);
//        }else {
//            QPainter pp(&nimage);
//            pp.drawLine(first_point,second_point);
//            painter.drawImage(offset,nimage);
//        }
        painter.drawLine(first_point,second_point);

//        painter_on_image.drawLine((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                                  (first_point.y()-offset.y())*(1.0*image.height()/height()),
//                                  (second_point.x()-offset.x())*(1.0*image.width()/width()),
//                                  (second_point.y()-offset.y())*(1.0*image.height()/height())
//                                  );
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

//            painter_on_image.setFont(font_now);
//            painter_on_image.setPen(Qt::gray);
//           painter_on_image.drawText((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                                      (first_point.y()-offset.y())*(1.0*image.height()/height()),
//                                      target_string);
            state=0;
        break;
    case PAINT_POLYGON:

//        QPointF Tri[3] = {first_point, second_point, third_point};
//        QPointF Tri2[3] = {((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                           (first_point.y()-offset.y())*(1.0*image.height()/height())
//                        ),(second_point.x()-offset.x())*(1.0*image.width()/width()),
//                           (second_point.y()-offset.y())*(1.0*image.height()/height()),(third_point.x()-offset.x())*(1.0*image.width()/width()),
//                           (third_point.y()-offset.y())*(1.0*image.height()/height())};
        painter.drawPolygon(Tri,3);
//        painter.drawPolygon({first_point, second_point, third_point},3);
        //painter_on_image.drawPolygon(Tri2, 3);
//        painter_on_image.drawPolygon({((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                                      (first_point.y()-offset.y())*(1.0*image.height()/height())
//                                   ),(second_point.x()-offset.x())*(1.0*image.width()/width()),
//                                      (second_point.y()-offset.y())*(1.0*image.height()/height()),(third_point.x()-offset.x())*(1.0*image.width()/width()),
//                                      (third_point.y()-offset.y())*(1.0*image.height()/height())},3);
        break;
    case PAINT_ELLIPSE:
        painter.drawEllipse(first_point.x(),first_point.y(),second_point.x()-first_point.x(),second_point.y()-first_point.y());
//        painter_on_image.drawEllipse((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                                  (first_point.y()-offset.y())*(1.0*image.height()/height()),
//                                  (second_point.x()-first_point.x())*(1.0*image.width()/width()),
//                                  (second_point.y()-first_point.y())*(1.0*image.height()/height())
//                                  );
        break;
    case PAINT_RECTANGLE:
        painter.drawRect(first_point.x(),first_point.y(),second_point.x()-first_point.x(),second_point.y()-first_point.y());
//        painter_on_image.drawRect((first_point.x()-offset.x())*(1.0*image.width()/width()),
//                                  (first_point.y()-offset.y())*(1.0*image.height()/height()),
//                                  (second_point.x()-first_point.x())*(1.0*image.width()/width()),
//                                  (second_point.y()-first_point.y())*(1.0*image.height()/height())
//                                  );
        break;
        
    default:
        break;
    }
    }
//    paint_save(default_save_file_path);

    painter1.drawImage(offset,nimage);
    nimage.save("Tmp.png");//画一下保存一下，再重新load图片
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
    //QPainter(this).drawLine(first_point, second_point );
}

void MainWindow::on_open_image_dialog_clicked()
{
    image_path = QFileDialog::getOpenFileName(this,"file dialog",FILE_DEFAULT_PATH,"image file(* png * jpg)");
     qDebug()<<"file name is : "<<image_path<<endl;
    image.load(image_path);
    firstLoad = true;
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
    isDrawing = false;
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

switch(state)
{
    case PAINT_POLYGON: //画多边形（现在就设置成三角形好了）
        switch (state1++)
        {
        case 1:
            first_point = event->pos();
             qDebug()<<"get first point " <<second_point<<endl;
             isDrawing = true;
            break;
        case 2:
            isDrawing = true;
            second_point = event->pos();
            qDebug()<<"get second point " <<second_point<<endl;
            break;
        case 3:
            isDrawing = true;
            third_point = event->pos();
            Tri[0] = first_point;
            Tri[1] = second_point;
            Tri[2] = third_point;
            qDebug()<<"get third point " <<second_point<<endl;
            update();
            state1 -= 3;
//            i++;    //画下一个
            break;

        }
    break;

case PAINT_TEXT:
    isDrawing = true;
    first_point=event->pos();
    qDebug()<<"get first point " <<first_point<<endl;
    update();
    break;
//case PAINT_LINE:
//    if(event->button()==Qt::LeftButton) //鼠标左键按下
//        {
//            first_point = event->pos();
//            isDrawing = true;   //正在绘图
//        }
//    break;
default:
        if(hasMouseTracking())
        {
            isDrawing = true;
            setMouseTracking(false);
            second_point=event->pos();
            qDebug()<<"get second point " <<second_point<<endl;
            update();
//            i++;

        }
        else
        {
            isDrawing = true;
            first_point=event->pos();
            qDebug()<<"get first point " <<first_point<<endl;
            setMouseTracking(true);
            //update();
        }
    break;

}
  }
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
//    second_point = event->pos();
//    update();
//    if(state == PAINT_LINE && event->buttons()&Qt::LeftButton)//如果鼠标左键按着的同时移动鼠标
//    {
//        second_point = event->pos();
//        update();
//    }
//    switch(state)
//    {
//    case PAINT_LINE:
//        if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
//            {
//                second_point = event->pos();
//                update(); //进行绘制
//            }
//    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
//    if(event->button() == Qt::LeftButton)   //如果鼠标左键释放
//    {
//        second_point = event->pos();
//        isDrawing = false;
//        update();
//        qDebug()<<"Line drawing finished"<<endl;
//    }
}

void MainWindow::on_draw_line_button_clicked()
{
//    painter->pNext = new painterNode();
//    painter = painter->pNext;


    state=PAINT_LINE;
    setMouseTracking(false);
    isDrawing = false;//避免一按键就画
    //update(); //我改的
}



void MainWindow::on_addtextbutton_clicked()
{


//    painter->pNext = new painterNode();
//    painter = painter->pNext;

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
    //update();
}

void MainWindow::on_draw_polygon_button_clicked()
{
//    painter->pNext = new painterNode();
//    painter = painter->pNext;

    state=PAINT_POLYGON;//画多边形状态
    state1 = 1;//开始算第一次点
    isDrawing = false;//避免一按键就画

}

void MainWindow::on_draw_ellipse_button_clicked()
{
    state = PAINT_ELLIPSE;
    setMouseTracking(false);
    isDrawing = false;//避免一按键就画
}

void MainWindow::on_draw_rectangle_button_clicked()
{
    state = PAINT_RECTANGLE;
    setMouseTracking(false);
    isDrawing = false;//避免一按键就画
}
