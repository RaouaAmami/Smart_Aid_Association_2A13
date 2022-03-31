#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include <QMainWindow>
#include "stat_categorie.h"
#include "maps.h"
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

private:


    Ui::MainWindow *ui;
    evenement e ;

    stat_categorie *third;

    //Map
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
};
#endif // MAINWINDOW_H
