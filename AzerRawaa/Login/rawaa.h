#ifndef RAWAA_H
#define RAWAA_H

#include <QDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTableView>
#include<Qprinter>
#include "enfant.h"
#include "ui_rawaa.h"

namespace Ui {
class Rawaa;
}

class Rawaa : public QDialog
{
    Q_OBJECT

public:
    explicit Rawaa(QWidget *parent = nullptr);

    ~Rawaa();

private slots:
    void on_pushButton_logout_clicked();
    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_label_2_linkActivated(const QString &link);

private:
    Ui::Rawaa *ui;
    enfant tmpenfant;
};

#endif // RAWAA_H
