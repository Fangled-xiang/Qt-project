#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QChart *chart = new QChart();

    QValueAxis *AxisX = new QValueAxis();
    QValueAxis *AxisY = new QValueAxis();

    AxisX->setRange(0,5000);
    AxisY->setRange(0,100);

    AxisX->setTitleText("时间/ms");
    AxisY->setTitleText("温度/C");

    AxisX->setLabelFormat("%d");
    AxisY->setLabelFormat("%d");

    AxisX->setTickCount(10);
    AxisY->setTickCount(10);

    chart->createDefaultAxes();
    chart->addAxis(AxisX, Qt::AlignBottom);
    chart->addAxis(AxisY, Qt::AlignLeft);

    chart->setTitle("温度与时间曲线");
    chart->legend()->setVisible(true);

    QSplineSeries *splineSeries = new QSplineSeries();

    splineSeries->append(0,50);
    splineSeries->append(1000,60);
    splineSeries->append(2000,80);
    splineSeries->append(3000,50);
    splineSeries->append(4000,30);
    splineSeries->append(5000,80);

    QPen pen(QColor("#888888"));
    splineSeries->setPen(pen);

    chart->addSeries(splineSeries);
    splineSeries->attachAxis(AxisX);
    splineSeries->attachAxis(AxisY);

    ui->graphicsView->setChart(chart);
}

Widget::~Widget()
{
    delete ui;
}

