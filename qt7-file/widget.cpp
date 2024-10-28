#include "widget.h"
#include "ui_widget.h"

#include"filedialog.h"
#include<QFile>
#include<QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //文本读写流程




}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "选择文本", "/home/fangxiang");
    qDebug()<< filename;

    file.setFileName(filename);
    if( !file.open(QIODevice::ReadWrite) )
    {
        qDebug()<<"fail!!!!"<<endl;
        return;
    }

    ui->textEdit->setPlainText(  file.readAll()  );

    file.close();

}


void Widget::on_pushButton_2_clicked()
{
    if( file.fileName().isEmpty() )
    {
        return;
    }

    if( !file.open(QIODevice::ReadWrite) )
    {
        qDebug()<<"fail!!!!"<<endl;
        return;
    }

    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();

    ui->textEdit->clear();
}





void Widget::on_pushButton_3_clicked()
{
    QFile file;
    file.setFileName(QDateTime::currentDateTime().toString("MMddhhmmss")+".txt");
    file.open(QIODevice::ReadWrite);


    FileDialog *fileDialog = new FileDialog(this);
    fileDialog->resize(this->size());
    fileDialog->show();
    fileDialog->setModal(true);
    fileDialog->exec();

    QString temp = fileDialog->getTextEditContent();
    file.write(temp.toUtf8());
    file.close();

    if(temp.length()==0)
    {
        file.remove();
    }
    delete fileDialog;
}











