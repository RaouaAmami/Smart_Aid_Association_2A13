#ifndef MAP_H
#define MAP_H

#include <QMainWindow>

namespace Ui {
class map;
}

class map : public QMainWindow
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    ~map();

private:
    Ui::map *ui;

    //Map
  public slots:
      void aller();
      void afficherPosition(QString latitude, QString longitude);
      void afficherInformations(QString adresse, QString coordonnee);

  private slots:
      void on_chercher_clicked();
  //endmap


      void on_pbgotomap_clicked();


};

#endif // MAP_H
