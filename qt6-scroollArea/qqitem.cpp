#include "qqitem.h"
#include "ui_qqitem.h"

QQItem::QQItem(QString icon,QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQItem)
{
    ui->setupUi(this);
    QImage image(icon);
    ui->icon->setPixmap(QPixmap::fromImage(image.scaled(ui->icon->width(), ui->icon->height())));
    ui->name->setText(name);
}

QQItem::~QQItem()
{
    delete ui;
}
