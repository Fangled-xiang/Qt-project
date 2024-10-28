#ifndef WIDGET_H
#define WIDGET_H
#include<QDebug>
#include <QWidget>
#include <QThread>
class MyThread;

#include<QTcpServer>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyThread *myThread;

    QTcpServer *tcpServer;

private slots:
    void mNewConnection();

    void receiveMessage();

    void mstateChanged(QAbstractSocket::SocketState state);


    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
};



class MyThread : public QThread
{
    Q_OBJECT


public:
    MyThread(QWidget *parent = nullptr)
    {
        Q_UNUSED(parent);
    }

    ~MyThread()
    {}

public:
    //只有run()方法会在新的线程里面
    void run()
    {
        qDebug()<<"现存开启！！！"<<endl;
        sleep(2); //sleep只能在线程里使用
        qDebug()<<"end！！！"<<endl;

        deleteLater();
    }

};





#endif // WIDGET_H
