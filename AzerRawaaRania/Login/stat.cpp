#include "stat.h"
#include "ui_stat.h"
#include <QString>
#include <QString>
#include <qsqlquery.h>

#include"benevol.h"


Stat::Stat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat)
{
    ui->setupUi(this);
}
Stat::~Stat()
{
    delete ui;
}


void Stat::make()
{

        int Passif;
        int Actif;
        int total;
        QString Actif1;
        QString Passif1;
        QSqlQuery q;

        q.prepare("SELECT COUNT(id_benevol) FROM BENEVOLS  ");
        q.exec();
        q.first() ;
        Actif=(q.value(0).toInt());

        q.prepare("SELECT COUNT(id_benevol) FROM BENEVOLS  ");
        q.exec();
        q.first() ;
        Passif=(q.value(0).toInt());
        q.prepare("SELECT COUNT(id_benevol) FROM BENEVOLS ");
        q.exec();
        q.first() ;
        total=(q.value(0).toInt());

        Actif=((double)Actif/(double)total)*100;
        Passif=100-Actif;

        Actif1= QString::number(Actif);
        Passif1=QString::number(Passif);
        QPieSeries *series;
         series= new  QPieSeries();
         series->append(" Actif"+Actif1+"%",Actif);
         series->append(" PAssif"+Passif1+"%",Passif);
         QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
             slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::darkRed, 2));
             slice1->setBrush(Qt::red);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistiques sur les BENEVOLS ");
              chart->legend()->show();
              QChartView *chartView = new QChartView(chart);
              chartView->setRenderHint(QPainter::Antialiasing);
              //ui->verticalLayout->addWidget(chartView);

}

