#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);

    connect(udpSocket, SIGNAL(readyRead()),
                 this, SLOT(readPendingDatagrams()) );

    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::readPendingDatagrams()
{
    QByteArray tempByteArray;
    tempByteArray.resize(udpSocket->pendingDatagramSize());
    QHostAddress ipaddr;
    quint16 port;//发送者的地址

    while(udpSocket->hasPendingDatagrams()){
        udpSocket->readDatagram(tempByteArray.data(),tempByteArray.size(), &ipaddr,&port);
    }

    ui->textBrowser->append(ipaddr.toString() +"--"+QString::number(port)+  " :  "+tempByteArray);
}


void Widget::on_pushButton_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress("192.168.88.130"), 8888);
}



void Widget::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);

    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

    udpSocket->bind(QHostAddress("192.168.88.130"), 8888);//0-65535
    //udpSocket->bind(8888);//IP可能会变，也可以直接绑定接收的端口
}

void Widget::on_pushButton_3_clicked()
{
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

    udpSocket->abort();
}

void Widget::on_pushButton_4_clicked()
{
    ui->textBrowser->append("发送：" + ui->lineEdit->text());
    // 广播消息
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::Broadcast, 8888);
}
