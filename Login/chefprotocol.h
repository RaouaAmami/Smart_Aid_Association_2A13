#ifndef CHEFPROTOCOL_H
#define CHEFPROTOCOL_H

#include <QDialog>
#include "employee.h"

namespace Ui {
class ChefProtocol;
}

class ChefProtocol : public QDialog
{
    Q_OBJECT

public:
    explicit ChefProtocol(QWidget *parent = nullptr);
    ~ChefProtocol();

private slots:
    void on_pushButton_logout1_clicked();

    void on_Ajouter_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

private:
    Ui::ChefProtocol *ui;
    employee E ;
};

#endif // CHEFPROTOCOL_H
