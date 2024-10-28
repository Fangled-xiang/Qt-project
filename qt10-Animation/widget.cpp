#include "widget.h"
#include "ui_widget.h"
#include<QGraphicsColorizeEffect>
#include<QGraphicsOpacityEffect>
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    animation1 = new QPropertyAnimation(ui->target, "geometry");
    animation1->setStartValue(QRect(0,0,100,100));
    animation1->setKeyValueAt(0.5,QRect(600,0,100,100));//中间位置
    animation1->setEndValue(QRect(600,400,200,200));
    animation1->setDuration(2000);
    animation1->setLoopCount(3);
    animation1->setEasingCurve(QEasingCurve::OutCubic);//设在曲线运动的速度曲线


    QGraphicsColorizeEffect *grapheffect = new QGraphicsColorizeEffect(this);
    ui->target->setGraphicsEffect(grapheffect);
    animation2 = new QPropertyAnimation(grapheffect, "color");
    animation2->setStartValue(QColor(Qt::blue));
    animation2->setKeyValueAt(0.5,QColor(Qt::darkGray));//中间位置
    animation2->setEndValue(QColor(Qt::black));
    animation2->setDuration(2000);

    QGraphicsOpacityEffect *grapheffect2 = new QGraphicsOpacityEffect(this);
    ui->target->setGraphicsEffect(grapheffect2);
    animation3 = new QPropertyAnimation(grapheffect2, "opacity");
    animation3->setStartValue(0.0);
    animation3->setEndValue(1.0);
    animation3->setDuration(5000);

    rich = new Rich(this);
    QPropertyAnimation *pro = new QPropertyAnimation(rich, "money",this);
    pro->setStartValue(100);
    pro->setEndValue(800);
    pro->setDuration(10000);
    pro->setEasingCurve(QEasingCurve::Linear);//设在曲线运动的速度曲线
    pro->start();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    animation1->start();
}

void Widget::on_pushButton_2_clicked()
{
    animation2->start();
}

void Widget::on_pushButton_3_clicked()
{
    animation3->start();
}
