#ifndef FARES_H
#define FARES_H
#include<arduino.h>
#include <QDialog>
#include "dons.h"
#include <QMainWindow>

namespace Ui {
class Fares;
}

class Fares : public QDialog
{
    Q_OBJECT

public:
    explicit Fares(QWidget *parent = nullptr);
    ~Fares();

private slots:
    void on_pushButton_4_clicked();



    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_pdf_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();
    void update_label();

    void on_Logout_clicked();

    void on_logout_clicked();

private:
    Ui::Fares *ui;
        Arduino A;
        QString data;
    Dons D;

};

#endif // FARES_H
