#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"benevol.h"
#include"video.h"
#include"stat.h"
#include "arduino.h"
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


    void on_pushButton_afficher_clicked();//DONE

    void on_pushButton_Ajouter_clicked();//DONE

    void on_pushButton_supprimer_clicked();//DONE
    void on_lineEdit_4_textEdited();//done


    void on_TRIER_clicked();//DONE

    void on_IMPRIMER_clicked(); //DONE

    void on_MEMBRE_clicked(); //DONE

    void on_SATISTIQUES_clicked();

    void on_modifier_clicked();//DONE

    void on_tablebenevol_activated();//DONE

    void on_UPLOAD_clicked(); //DONE

    void on_rechercher_clicked();

    void on_stat_clicked();

    void on_pushButton_clicked();

    void update_label();
private:
    Ui::MainWindow *ui;
    benevol Ben;
      video *Video;
      QString data;
      QByteArray Pass;// variable contenant les données reçues

      Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
