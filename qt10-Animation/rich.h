#ifndef RICH_H
#define RICH_H

#include <QWidget>

namespace Ui {
class Rich;
}

class Rich : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(double money READ money WRITE setMoney);

public:
    explicit Rich(QWidget *parent = nullptr);
    ~Rich();

    double money() const;
    void setMoney(double m);

private:
    Ui::Rich *ui;
    double richmoney;
};

#endif // RICH_H
