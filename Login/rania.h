#ifndef RANIA_H
#define RANIA_H


#include <QDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTableView>
#include <QDialog>
#include "ui_rania.h"
#include"benevol.h"
#include"video.h"
#include"stat.h"
#include"arduino.h"

namespace Ui {
class Rania;
}

class Rania : public QDialog
{
    Q_OBJECT

public:
    explicit Rania(QWidget *parent = nullptr);
    ~Rania();

private slots:
    void on_pushButton_logout_clicked();

    void on_logout_clicked();

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


    void on_Modiffier_clicked();

    void on_suppprimer_clicked();

    void on_TRITRI_clicked();

    void on_rechrech_clicked();


    void on_stattt_clicked();

    void on_pushButton_Ajoutter_clicked();

    void on_pushButton_clicked();

private:
    Ui::Rania *ui;
    benevol Ben;
      video *Video;
        Arduino A;
        QString data;
};

#endif // RAWAA_H
