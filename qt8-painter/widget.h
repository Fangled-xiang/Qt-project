#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QTimer>
#include<QFontMetrics>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *evernt) override;

private:
    Ui::Widget *ui;
    QFont font;
    int offset;
    QTimer *timer;
    int textWidth;


private slots:
    void onTimerTimeOut();
};
#endif // WIDGET_H





