#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trackline.h"

#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QDebug>
#include <QErrorMessage>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMouseEvent>
#include <QStringList>
#include <QString>

#define FILE_DEFAULT_PATH "/Users/lucy/Desktop/"

QImage image;
QString image_path=NULL;
QString default_save_file_path=NULL;
QString target_string;
QFont font_now;
QColor color_now, color_brush;
int point_size;
QPointF Tri[3];
QPen pen;
QBrush brush(Qt::SolidPattern);
bool useBrush;
bool isDrawing;
bool firstLoad;
bool isChanged;
bool RightClick;//是不是鼠标右键
//bool stateChanged = false;
int now = 1, undo_steps = 0,redo_steps = 0;//steps是已经撤销的步数


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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint_on_screen()
{
    QPoint offset(20,20);

    if(firstLoad == false )  //不是第一次加载
    {
        switch(now)   //now是上次保存的照片编号
        {
        case 1:
            image.load("Tmp1.png");
            qDebug()<<"Tmp1.png loaded"<<endl;
            break;
        case 2:
            image.load("Tmp2.png");
            qDebug()<<"Tmp2.png loaded"<<endl;
            break;
        case 3:
            image.load("Tmp3.png");
            qDebug()<<"Tmp3.png loaded"<<endl;
            break;
        case 4:
            image.load("Tmp4.png");
            qDebug()<<"Tmp4.png loaded"<<endl;
            break;
        case 5:
            image.load("Tmp5.png");
            qDebug()<<"Tmp5.png loaded"<<endl;
            break;
        }

    }
    else //第一次加载
    {
        isChanged = true;

        now = 1;
        undo_steps = redo_steps = 0;
        qDebug()<<"first load"<<endl;
    }

    QImage nimage = image.scaled(width(),height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPainter painter1(this);
    painter1.drawImage(offset,nimage);
    QPainter painter(&nimage);

    if(firstLoad)
    {
        nimage.save("Tmp1.png");
        firstLoad = false;
        qDebug()<<"save first load Tmp1.png"<<endl;
    }

//    pen.setColor(color_now);

    painter.setPen(pen);
//    if(true == useBrush)
        painter.setBrush(brush);

    isChanged = false;
    if(isDrawing)//画画
    {

        switch (state) {
        case PAINT_LINE :
            painter.drawLine(first_point,second_point);
            qDebug()<<"draw line"<<endl;
            state=0;
            isChanged = true;
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
            qDebug()<<"draw text"<<endl;
            state=0;
            isChanged = true;
            break;
        case PAINT_POLYGON:

            painter.drawPolygon(Tri,3);
            qDebug()<<"draw triangle"<<endl;
            isChanged = true;
            break;
        case PAINT_ELLIPSE:
            if(false == RightClick)//左键按的
            {
            painter.drawEllipse(first_point.x(),first_point.y(),second_point.x()-first_point.x(),second_point.y()-first_point.y());
            qDebug()<<"draw ellipse"<<endl;
            } else
            {
                painter.drawEllipse(first_point.x(),first_point.y(),MAX(second_point.x()-first_point.x(),second_point.y()-first_point.y()),MAX(second_point.x()-first_point.x(),second_point.y()-first_point.y()));
                qDebug()<<"draw circle"<<endl;
            }
            isChanged = true;
            break;
        case PAINT_RECTANGLE:
            if(false == RightClick)
            {
            painter.drawRect(first_point.x(),first_point.y(),second_point.x()-first_point.x(),second_point.y()-first_point.y());
            qDebug()<<"draw rectangle"<<endl;
            } else
            {
                painter.drawRect(first_point.x(),first_point.y(),MAX(second_point.x()-first_point.x(),second_point.y()-first_point.y()),MAX(second_point.x()-first_point.x(),second_point.y()-first_point.y()));
                qDebug()<<"draw square"<<endl;
            }
            isChanged = true;
            break;
//        case LARGER:
//            {
//                qreal width = pix.width();
//                qreal height = pix.height();
//                pix = pix.scaled(width*2,height*2,Qt::KeepAspectRatio);
//                painter1.drawPixmap(20,20,pix);
//            }
//            state = 0;
//            break;

        default:
            qDebug()<<"not draw"<<endl;
            isChanged = false;
            break;
        }//switch


        painter1.drawImage(offset,nimage);//画出改变后的图
        if(isChanged == true)
        {
            switch(++now)  //保存
            {
            case 6:
                nimage.save("Tmp1.png");//画一下保存一下，再重新load图片
                qDebug()<<"Tmp1.png saved"<<endl;
                now -= 5;
                break;
            case 2:
                nimage.save("Tmp2.png");
                qDebug()<<"Tmp2.png saved"<<endl;
                break;
            case 3:
                nimage.save("Tmp3.png");
                qDebug()<<"Tmp3.png saved"<<endl;
                break;
            case 4:
                nimage.save("Tmp4.png");
                qDebug()<<"Tmp4.png saved"<<endl;
                break;
            case 5:
                nimage.save("Tmp5.png");
                qDebug()<<"Tmp5.png saved"<<endl;
                break;
            default:
                qDebug()<<"something unexpacted happened"<<endl;
                break;
            }
            redo_steps = 0; //动过了，不能redo了
            if(undo_steps <4)
                undo_steps++;
        }
        qDebug()<<"undo "<< undo_steps <<"redo "<<redo_steps << endl;
    }//if (isDrawing)

    painter.end();
    isChanged = false;
    isDrawing = false;

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




void MainWindow::mousePressEvent(QMouseEvent* event)
{
    switch(state)
    {
    if(event->button() == Qt::LeftButton)
    {
        RightClick = false;
    }
    else if(event->button() == Qt::RightButton)
    {
        RightClick = true;
        qDebug()<<"right clicked"<<endl;
    }
    case PAINT_POLYGON: //画多边形（现在就设置成三角形好了）
        switch (state1++)
        {
        case 1:
            first_point = event->pos();
            qDebug()<<"get first point " <<second_point<<endl;
            isDrawing = false;
            break;
        case 2:
            isDrawing = false;
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

    default:

        if(hasMouseTracking())
        {
            isDrawing = true;
            setMouseTracking(false);
            second_point=event->pos();
            qDebug()<<"get second point " <<second_point<<endl;
            update();

        }
        else
        {
            isDrawing = false;
            first_point=event->pos();
            qDebug()<<"get first point " <<first_point<<endl;
            setMouseTracking(true);
        }
        break;

    }


}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::on_draw_line_button_clicked()
{

    state=PAINT_LINE;
    setMouseTracking(false);
    isDrawing = false;//避免一按键就画
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
    int point_size  = QInputDialog::getInt(this,"type in the size of font!",
                                       "range from -1000 ~ 1000",
                                       1,
                                       -1000,
                                       1000,
                                       10,
                                       &OK2);
    if(OK2) qDebug()<<"font size is "<< point_size <<endl;
    state=PAINT_TEXT;
}

void MainWindow::on_draw_polygon_button_clicked()
{

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

void MainWindow::on_actionRedo_triggered()
{
    isChanged = false;
    if(redo_steps == 0) //不能恢复了
    {
        qDebug()<<"cannot redo" <<endl;
        QErrorMessage errbox(this);
        errbox.setWindowTitle(tr("error"));
        errbox.showMessage(tr("Cannot redo!"));
    }
    else
    {
        if(undo_steps < 4)
            undo_steps++;
        redo_steps--;
        now++;
        if(now == 6) now -= 5;
        update();
    }
}

void MainWindow::on_actionUndo_triggered()
{
    isChanged = false;
    if(undo_steps == 0)
    {
        qDebug()<<"cannot undo" <<endl;
        QErrorMessage errbox(this);
        errbox.setWindowTitle(tr("error"));
        errbox.showMessage(tr("Cannot undo!"));
    }
    else
    {
        undo_steps--;
        redo_steps++;
        now--;
        if(now == 0) now += 5;
        update();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString new_save_path = QFileDialog::getSaveFileName(this,"file dialog",FILE_DEFAULT_PATH,"image file(* png * jpg)");
    qDebug()<<"file name is : "<<new_save_path<<endl;
    paint_save(new_save_path);
}

void MainWindow::on_actionSave_triggered()
{
    paint_save(default_save_file_path);
    qDebug()<<"default save in "<<default_save_file_path<<endl;
}

void MainWindow::on_actionOpen_triggered()
{
    image_path = QFileDialog::getOpenFileName(this,"file dialog",FILE_DEFAULT_PATH,"image file(* png * jpg)");
    qDebug()<<"file name is : "<<image_path<<endl;
    image.load(image_path);
    firstLoad = true;
    update();
}

void MainWindow::on_actionSelect_color_triggered()
{
    isDrawing = false;
    QColorDialog color_dia(Qt::red,this);
    color_dia.setOption(QColorDialog::ShowAlphaChannel);
    color_dia.exec();
    color_now = color_dia.currentColor();
    pen.setColor(color_now);

    qDebug()<<"current pen color is "<<color_now<<endl;
}

void MainWindow::on_actionSelect_font_triggered()
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

void MainWindow::on_actionSelect_brush_color_triggered()
{
    isDrawing = false;
    QColorDialog color_dia(Qt::red,this);
    color_dia.setOption(QColorDialog::ShowAlphaChannel);
    color_dia.exec();
    color_brush = color_dia.currentColor();
    brush.setColor(color_brush);

    qDebug()<<"current brush color is "<<color_now<<endl;
}

void MainWindow::on_actionUse_brush_triggered()
{
    useBrush = true;
    qDebug()<<"use brush"<<endl;
}

void MainWindow::on_actionDon_t_use_brush_triggered()
{
    useBrush = false;
    qDebug()<<"don't use brush"<<endl;
}



void MainWindow::on_actionSet_pen_width_triggered()
{
    bool OK;
    int width  = QInputDialog::getInt(this,"Type in the width of pen!",
                                       "Please type in the width of pen",
                                       1,
                                       1,
                                       1000,
                                       10,
                                       &OK);
    if(OK) qDebug() << "pen width is" << width << endl;
    pen.setWidth(width);
}

void MainWindow::on_actionSet_brush_style_triggered()
{
    QStringList list;
    list <<tr("NoBrush")<< tr("SolidPattern") <<tr("Dense1Pattern") <<tr("Dense2Pattern")<<tr("Dense3Pattern")
         <<tr("Dense4Pattern")<<tr("Dense5Pattern")<<tr("Dense6Pattern")<<tr("Dense7Pattern")<<tr("HorPattern")
           <<tr("VerPattern")<<tr("CrossPattern")<<tr("BDiagPattern")<<tr("FDiagPattern")<<tr("DiagCrossPattern");
    bool ok;
    QString style = QInputDialog::getItem(this,tr("Style"),  tr("Please choose a style."),list,0,false,&ok);
    std::string s = style.toStdString();
    if (ok)
    {
        if(0 == s.compare("NoBrush"))
            brush.setStyle(Qt::NoBrush);
        if(0 == s.compare("SolidPattern"))
            brush.setStyle(Qt::SolidPattern);
        if(0 == s.compare("Dense1Pattern"))
            brush.setStyle(Qt::Dense1Pattern);
        if(0 == s.compare("Dense2Pattern"))
            brush.setStyle(Qt::Dense2Pattern);
        if(0 == s.compare("Dense3Pattern"))
            brush.setStyle(Qt::Dense3Pattern);
        if(0 == s.compare("Dense4Pattern"))
            brush.setStyle(Qt::Dense4Pattern);
        if(0 == s.compare("Dense5Pattern"))
            brush.setStyle(Qt::Dense5Pattern);
        if(0 == s.compare("Dense6Pattern"))
            brush.setStyle(Qt::Dense6Pattern);
        if(0 == s.compare("Dense7Pattern"))
            brush.setStyle(Qt::Dense7Pattern);
        if(0 == s.compare("HorPattern"))
            brush.setStyle(Qt::HorPattern);
        if(0 == s.compare("VerPattern"))
            brush.setStyle(Qt::VerPattern);
        if(0 == s.compare("CrossPattern"))
            brush.setStyle(Qt::CrossPattern);
        if(0 == s.compare("BDiagPattern"))
            brush.setStyle(Qt::BDiagPattern);
        if(0 == s.compare("FDiagPattern"))
            brush.setStyle(Qt::FDiagPattern);
        if(0 == s.compare("DiagCrossPattern"))
            brush.setStyle(Qt::DiagCrossPattern);

//        qDebug() << "style is "<<s<<endl;
    }

}
