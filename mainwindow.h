#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<arduino.h>
#include <QMainWindow>

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
void update_label();

void on_pushButton_clicked();

void on_label_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H
