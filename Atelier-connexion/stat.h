#ifndef STAT_H
#define STAT_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
namespace Ui {
class Stat;
}

class Stat : public QWidget
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = nullptr);
    ~Stat();
    void make();
private:
    Ui::Stat *ui;
};

#endif // STAT_H
