#include "rawaa.h"
#include "ui_rawaa.h"
#include "mainwindow.h"

Rawaa::Rawaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rawaa)
{
    ui->setupUi(this);
     ui->tableView1->setModel(tmpenfant.afficher());
}

Rawaa::~Rawaa()
{
    delete ui;
}

void Rawaa::on_pushButton_logout_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void Rawaa::on_pushButton_clicked()
{  QString id,nom,prenom,genre,photo;
    QDate date_n,date_ins;



    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty() )
    {
        //QMessageBox::warning(nullptr, QObject::tr("Attention"),
                            // QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else{
        id=ui->lineEdit->text();
        nom=ui->lineEdit_2->text();
        prenom=ui->lineEdit_3->text();
        date_n=ui->dateEdit->date();
      date_ins=ui->dateEdit_2->date() ;
   //   photo=ui->lineEdit_5->text();


           if (ui->comboBox->currentIndex()==0)
               genre="garcon";
        else {
            genre="fille";
        }


        enfant e(id,nom,prenom,genre,date_n,date_ins,photo) ;
        bool test=e.ajouter();

        if (test)
        {
            //QMessageBox::information(nullptr, QObject::tr("Ajouter un   enfant"),
                                     //QObject::tr("  enfant ajouté.\n"
                                                // "Click Cancel to exit."));
           // ui->tableView->setModel(tmpenfant.afficher());
        }
        else
        {
            //QMessageBox::critical(nullptr, QObject::tr("Ajouter un  enfant"),
                                  //QObject::tr("Erreur !.\n"
                                             // "Click Cancel to exit."));
        }
    }

     ui->tableView1->setModel(tmpenfant.afficher());

}

void Rawaa::on_pushButton_4_clicked()
{

    QString id,nom,prenom,genre,photo;
    QDate   date_n,date_ins;

    id=ui->lineEdit->text();
    nom=ui->lineEdit_2->text();
    prenom=ui->lineEdit_3->text();
    date_n=ui->dateEdit->date();
    date_ins=ui->dateEdit_2->date() ;
   // photo=ui->lineEdit_5->text();



    if (ui->comboBox->currentIndex()==0)

        genre="garcon";
    else {
        genre="fille";
    }



    enfant e( id, nom , prenom , genre, date_n, date_ins,photo );
    bool test= e.modifier(id);

    if (test)
    {
        //QMessageBox::information(nullptr, QObject::tr("Modifier un   enfant"),
                                // QObject::tr("  enfant Modifié.\n"
                                           //  "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView1->setModel(tmpenfant.afficher());//refresh
    }
    else
    {
        //QMessageBox::critical(nullptr, QObject::tr("Modifier un enfant"),
                             // QObject::tr("Erreur !.\n"
                                          //"Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Rawaa::on_pushButton_3_clicked()
{
    QString id=ui->lineEdit->text();
    enfant e;
    bool test=e.supprimer(id);
    ui->tableView1->setModel(tmpenfant.afficher());//refresh
    if(test)
    {
        //QMessageBox::information(nullptr, QObject::tr("Supprimer enfant"),
                                // QObject::tr("enfant supprimé.\n"
                                            // "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        //QMessageBox::critical(nullptr, QObject::tr("enfant un categorie"),
                             // QObject::tr("Erreur !.\n"
                                         // "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Rawaa::on_pushButton_8_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from ENFANTS where genre= 'garcon'");
        float dispo1=model->rowCount();

        model->setQuery("select * from ENFANTS where genre= 'fille'");
        float dispo=model->rowCount();

        float total=dispo1+dispo;
        QString a=QString("garcon . " +QString::number((dispo1*100)/total,'f',2)+"%" );
        QString b=QString("fille .  "+QString::number((dispo*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,dispo1);
        series->append(b,dispo);
        if (dispo1!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( dispo!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();


        chart->addSeries(series);
        chart->setTitle("genre "+ QString::number(total));
        chart->legend()->hide();


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}

void Rawaa::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tableView1->setModel(tmpenfant.recherche(arg1));
}

void Rawaa::on_pushButton_7_clicked()
{
    ui->tableView1->setModel(tmpenfant.tri());
}

void Rawaa::on_pushButton_6_clicked()
{
    QTableView *table;

        table = ui->tableView1;


        QString filters("Excel Files (.xlsx)");

        QString defaultFilter("Excel Files (*.xlsx)");

        QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                                        filters, &defaultFilter);

        QFile file(fileName);


        QAbstractItemModel *model =  table->model();

        if (file.open(QFile::WriteOnly | QFile::Truncate)) {

            QTextStream data(&file);

            QStringList strList;

            for (int i = 0; i < model->columnCount(); i++) {

                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                else

                    strList.append("");

            }

            data << strList.join("  ") << "\n";

            for (int i = 0; i < model->rowCount(); i++) {

                strList.clear();

                for (int j = 0; j < model->columnCount(); j++) {


                    if (model->data(model->index(i, j)).toString().length() > 0)

                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                    else

                        strList.append("");

                }

                data << strList.join("  ") + "\n";

            }

            file.close();

            QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                     QObject::tr("Export avec succes .\n"

                                                 "Click OK to exit."), QMessageBox::Ok);
        }
}

void Rawaa::on_pushButton_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView1->model()->rowCount();
        const int columnCount = ui->tableView1->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>Liste des enfants </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView1->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView1->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView1->isColumnHidden(column)) {
                    QString data = ui->tableView1->model()->data(ui->tableView1->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
               "</body>\n"
               "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void Rawaa::on_pushButton_5_clicked()
{


    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.bmp *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/RAOUA/OneDrive/Desktop/photo", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        image=image.scaledToWidth(ui->label_3->width(),Qt::SmoothTransformation);
            ui->label_3->setPixmap(QPixmap::fromImage(image));



}
}

