#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");
    ui->pushButton_2->setEnabled(false);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(reciveMessage()));

    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(mstateChanged(QAbstractSocket::SocketState)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::reciveMessage()
{
    ui->textBrowser->append("服务端："+ tcpSocket->readAll());
}

void Widget::mstateChanged(QAbstractSocket::SocketState state)
{
    switch(state){

    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("与服务端断开连接");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        break;

    case QAbstractSocket::ConnectingState:
        ui->textBrowser->append("连接服务端");
        ui->pushButton->setEnabled(false);
         ui->pushButton_2->setEnabled(true);
        break;

    default:
        break;
    }
}


void Widget::on_pushButton_3_clicked()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(ui->lineEdit->text().toUtf8());
    }
    else{
        ui->textBrowser->append("未连接服务端");
    }

}

void Widget::on_pushButton_clicked()
{
    tcpSocket->connectToHost(QHostAddress("192.168.88.130"), 9999);
}

void Widget::on_pushButton_2_clicked()
{
    tcpSocket->disconnectFromHost();
}
