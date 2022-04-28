#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chefprotocol.h"
#include "fares.h"
#include "rawaa.h"
#include "rania.h"
#include "malek.h"
#include "employee.h"
#include "stat_categorie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();



private:
    Ui::MainWindow *ui;
    ChefProtocol *chefprotocol;

    Rania *rania ;
    Fares *fares;
    Rawaa *rawaa ;
    Malek *malek;
    stat_categorie *third;


};
#endif // MAINWINDOW_H
