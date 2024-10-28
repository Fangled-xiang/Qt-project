#include "widget.h"
#include "ui_widget.h"

#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    font.setPixelSize(50);
    offset = 0;
    timer = new QTimer(this);
    timer->start(100);
    QFontMetrics fontMetrics(font);
    textWidth = fontMetrics.width("你好11111");

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeOut()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *evernt)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor("#888888"));
    painter.setPen(pen);

    QBrush brush(QColor("#888888"));
    //painter.setBrush(brush);

    painter.drawRect(200,100,100,100);

    QPolygon polygon;
    polygon.setPoints(3,100,20,200,100,50,300);

    painter.drawPolygon(polygon);

    painter.drawLine(400,400,500,500);

//    QRectF rectF(0,0,200,100);
//    painter.drawText(rectF, Qt::AlignHCenter,"你好11111");

    painter.drawRect(this->rect());


    pen.setColor(QColor(Qt::red));
    painter.setPen(pen);
    painter.setFont(font);
    QRectF rectF = this->rect();
    rectF.setLeft(this->rect().width()-offset);

    qDebug()<< this->rect().width()<<endl;
    qDebug()<< rectF.width()<<endl;

    painter.drawText(rectF, Qt::AlignCenter,"你好11111");
}

void Widget::onTimerTimeOut()
{

    if(offset < this->width() + 4*textWidth)
    {
        offset += 50;
    }
    else{
        offset = 0;
    }
    this->update();
}

