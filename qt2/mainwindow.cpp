#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);


    button = new QPushButton(this);
    button->show();

    button->setText("按钮");
    button->setGeometry(50,150,100,50);
    this->resize(800,480);

    QLabel *label = new QLabel(this);
    label->setGeometry(500,300,100,100);
//    label->setStyleSheet("QLabel {background-color:red}");


    this->resize(800,480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

