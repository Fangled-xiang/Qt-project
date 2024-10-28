#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<qqitem.h>

class QQItem;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget_2->addItem("王心果");
    ui->listWidget_2->addItem("李见坤");
    ui->listWidget_2->addItem("郭临序");

    ui->listWidget_2->takeItem(0);

    ui->listWidget_2->insertItem(0,"张三");//是在0号前面插入


    QQItem *qq1 = new QQItem(":/icons/icon0.jpg","小火车");
    QListWidgetItem *item0 = new QListWidgetItem;
    ui->listWidget_3->addItem(item0);
    ui->listWidget_3->setItemWidget(item0, qq1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    ui->tabWidget->setCurrentIndex(currentRow);
}
