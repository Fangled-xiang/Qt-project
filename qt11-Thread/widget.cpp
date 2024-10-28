#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myThread = new MyThread(this);

    tcpServer = new QTcpServer(this);

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(mNewConnection()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    myThread->start();
}

void Widget::on_pushButton_2_clicked()
{
    if(! myThread->isFinished()){
       myThread->terminate();
    }
}

void Widget::mNewConnection()
{
    QTcpSocket *tempSocket = tcpServer->nextPendingConnection();

    ui->textBrowser->append("客户端ip：" + tempSocket->peerAddress().toString());
    ui->textBrowser->append("客户端端口：" + QString::number(tempSocket->peerPort()));

    connect(tempSocket,SIGNAL(readyRead()), this,SLOT(receiveMessage()));

    connect(tempSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(mstateChanged(QAbstractSocket::SocketState)));

}

void Widget::receiveMessage()
{
    QTcpSocket *tempSocket = (QTcpSocket *)sender();
    ui->textBrowser->append(tempSocket->readAll());
}

void Widget::mstateChanged(QAbstractSocket::SocketState state)
{
    QTcpSocket *tempSocket = (QTcpSocket *)sender();//不是new创建、只是一个指向的指针

    switch(state){

    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("客户端断开连接");
        tempSocket->deleteLater();
        break;

    case QAbstractSocket::ConnectingState:
        ui->textBrowser->append("客户端连接");
        break;

    default:
        break;
    }
}



void Widget::on_pushButton_3_clicked()
{
    tcpServer->listen(QHostAddress("192.168.88.130"),9999);
}

void Widget::on_pushButton_5_clicked()
{
    QList<QTcpSocket *> socketList = tcpServer->findChildren<QTcpSocket *>();

    foreach(QTcpSocket *tempSocket, socketList){
        tempSocket->write(ui->lineEdit->text().toUtf8());//每一个都发了
    }
}

void Widget::on_pushButton_4_clicked()
{
    tcpServer->close();
}
