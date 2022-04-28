#ifndef MALEK_H
#define MALEK_H

#include<arduino.h>


#include <QDialog>
#include "evenement.h"
#include <QMainWindow>
#include "stat_categorie.h"
//#include "maps.h"
namespace Ui {
class Malek;
}

class Malek : public QDialog
{
    Q_OBJECT

public:
    explicit Malek(QWidget *parent = nullptr);
    ~Malek();

private slots:
    void on_pushButton_logout_clicked();

    void on_logout_clicked();
    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_afficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_supp_clicked();

    void on_event_activated(const QModelIndex &index);

    void on_pushButton_modif_clicked();

    void on_line_recherche_textEdited(const QString &arg1);

    void on_combotri_activated(const QString &arg1);

    void on_button_pdf_clicked();

    void on_button_stat_clicked();

    void on_aller_clicked();

    void on_pushButton_2_clicked();
void update_label();

private:
    Ui::Malek *ui;
    evenement e ;
    QString data;
    Arduino A;
    stat_categorie *third;

   // stat_categorie *third;
public slots:
    void aller();
    void afficherPosition(QString latitude, QString longitude);
    void afficherInformations(QString adresse, QString coordonnee);

private slots:
    void on_chercher_clicked();
//endmap


    void on_pbgotomap_clicked();


    void on_calendarWidget_activated(const QDate &date);
    void on_pushButton_stat_clicked();
    void on_line_recherche_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_3_clicked();
    void on_pushButton_pdf_clicked();



    void on_pushButton_2_released();

    void on_pushButton_2_pressed();

    void on_line_libelle_editingFinished();

    void on_stat_clicked();

signals:
   void setCenter(QVariant, QVariant);
   void addMarker(QVariant, QVariant);


};

#endif // RAWAA_H
