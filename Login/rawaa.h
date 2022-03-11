#ifndef RAWAA_H
#define RAWAA_H

#include <QDialog>

namespace Ui {
class Rawaa;
}

class Rawaa : public QDialog
{
    Q_OBJECT

public:
    explicit Rawaa(QWidget *parent = nullptr);
    ~Rawaa();

private slots:
    void on_pushButton_logout_clicked();

private:
    Ui::Rawaa *ui;
};

#endif // RAWAA_H
