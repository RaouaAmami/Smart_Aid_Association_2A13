#include "maps.h"
#include "ui_maps.h"
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlListProperty>

#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEvent>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QQmlEngine>
#include <QQuickItem>
//include lang
#include <QFontDialog>



map::map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);




}

map::~map()
{
    delete ui;
}

void map::on_chercher_clicked()
{
    QString part1="https://nominatim.openstreetmap.org/search?q=";
    QString part2=ui->le_adresspart2->text();
    QString part3="&format=json&polygon=1&addressdetails=1&fbclid=IwAR2r_qtxdov_4zZdVKfy6Xx2UXmJd5rR1XddpqCogBeZ_7nv0srbxa9OOW8";
        QUrl ava_url(part1+part2+part3);
        QNetworkRequest ava_request(ava_url);

        QNetworkAccessManager *manager = new QNetworkAccessManager();
        QEventLoop loop;

        QObject::connect(manager,
                         SIGNAL(finished(QNetworkReply*)),
                         &loop,
                         SLOT(quit()));

        QNetworkReply* reply = manager->get(ava_request);
        loop.exec();

        QString response = (QString)reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
        QJsonObject obj = doc.object();

 // get lat et lon from the array
        QString x=doc.array()[0].toObject()["lat"].toString();
        QString y=doc.array()[0].toObject()["lon"].toString();

         qDebug() <<x;
         qDebug() <<y;

         ui->editLatitude->setText(x);
         ui->editLongitude->setText(y);
}
void map::aller()
{
    QQuickItem *item = ui->quickWidget->rootObject();
    QObject *object = item->findChild<QObject *>("indicateurPosition");
    QVariant latitude = ui->editLatitude->text(); //QVariant(43.8);
    QVariant longitude = ui->editLongitude->text(); //QVariant(4.8167);



    if(object != nullptr)
    {
        qDebug() << Q_FUNC_INFO << latitude << longitude;
        QMetaObject::invokeMethod(object, "aller", Q_ARG(QVariant, latitude), Q_ARG(QVariant, longitude));
    }
}

void map::afficherPosition(QString latitude, QString longitude)
{
    qDebug() << Q_FUNC_INFO << latitude << longitude;
    ui->positionLatitude_2->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->positionLongitude_2->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
    ui->editLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->editLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
}

void map::afficherInformations(QString adresse, QString coordonnee)
{
    qDebug() << Q_FUNC_INFO << adresse << coordonnee;
    ui->labelInformations_2->setText("Informations : " + adresse);
}

void map::on_pbgotomap_clicked()
{

   // ui->tabWidget->setCurrentIndex(7);

    //QString loc=ui->le_lieumap->text();
    //ui->le_adresspart2->setText(loc);
}
