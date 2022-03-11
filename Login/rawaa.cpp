#include "rawaa.h"
#include "ui_rawaa.h"
#include "mainwindow.h"

Rawaa::Rawaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rawaa)
{
    ui->setupUi(this);
}

Rawaa::~Rawaa()
{
    delete ui;
}

void Rawaa::on_pushButton_logout_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
