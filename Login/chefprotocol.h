#ifndef CHEFPROTOCOL_H
#define CHEFPROTOCOL_H

#include <QDialog>
#include "employee.h"
#include <QTextBrowser>
#include <QPrinter>

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

    void on_pushButton_3_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_line_recherche_textEdited(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    //void on_pushButton_clicked();
    void sendMail();
     void mailSent(QString) ;


     void on_envoyer_clicked();


     void on_generer_clicked();

private:
    Ui::ChefProtocol *ui;
    employee E ;
};

#endif // CHEFPROTOCOL_H
