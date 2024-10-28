#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    school = new School(this);  //***************4
    student = new Student(this);

    connect(school, SIGNAL(sendmessage()), student, SLOT(timeToClass()));
    emit school->sendmessage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "buttom执行了" <<endl;
}
