#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "school.h"  //************1
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class School;    //***********2
class Student;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    School *school;  //***********3
    Student *student;

};
#endif // MAINWINDOW_H
