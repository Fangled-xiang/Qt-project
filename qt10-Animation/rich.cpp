#include "rich.h"
#include "ui_rich.h"

Rich::Rich(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rich)
{
    ui->setupUi(this);
    richmoney = 500;
}

Rich::~Rich()
{
    delete ui;
}

double Rich::money() const
{
    return richmoney;
}

void Rich::setMoney(double m)
{
    richmoney = m;
    ui->Lab->setText(QString::number(m));
}
