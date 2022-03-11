#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"benevol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_TRIER_clicked();

    void on_pushButton_clicked();

    void on_RECHERCHER_clicked();

    void on_IMPRIMER_clicked();

    void on_NOTIFIER_clicked();

    void on_MEMBRE_clicked();

    void on_SATISTIQUES_clicked();

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    benevol Ben;
};

#endif // MAINWINDOW_H
