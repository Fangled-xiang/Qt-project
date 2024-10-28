#include "student.h"

#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::timeToClass()
{
       qDebug() << "class!!!"<<endl;
}
