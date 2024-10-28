#include "widget.h"
#include "ui_widget.h"
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setCheckable(true);//设置可选中
    ui->pushButton_2->setCheckable(true);//设置可选中
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<< "click!!"<<endl;
}


void Widget::on_pushButton_pressed()
{
    qDebug()<< "pressed!!"<<endl;
}

void Widget::on_pushButton_released()
{
    qDebug()<< "released!!"<<endl;
}


void Widget::on_pushButton_toggled(bool checked)
{
    qDebug()<< "toggle!!"<< checked <<endl;
}
