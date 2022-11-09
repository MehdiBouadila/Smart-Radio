#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>

#include "presentateur.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QIntValidator>
#include <QtDebug>
#include <QObject>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ presentateur p;
    ui->setupUi(this);
   ui->tab_P->setModel(p.afficher());

    ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
       ui->le_age->setValidator(new QIntValidator(0,99,this));
    ui->le_tel->setValidator(new QIntValidator(0,99999999,this));
     ui->tab_P->setModel(p.afficher());
     ui->rechercher->setValidator(new QIntValidator(0,99999999,this));


}


MainWindow::~MainWindow()
{


    delete ui;

}

 void MainWindow::on_pb_ajouter_clicked()
{

    if(controlSaisie())
    {int cinP=ui->le_cin->text().toInt() ;
       int age=ui->le_age->text().toInt() ;
       int num_tel=ui->le_tel->text().toInt() ;
       QString nom=ui->le_nom->text() ;
       QString prenom=ui->le_prenom->text() ;
       /*ui->tab_P->setModel(p.afficher()) ;*/

    presentateur p(cinP,age,num_tel,nom,prenom);

       bool test=p.ajouter(); //etablir la connexion
       QMessageBox msgBOX;
    if(test)
      {

        QMessageBox::information(nullptr, QObject::tr("Ok"),

                     QObject::tr("Ajout effectue.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_P->setModel(p.afficher()) ;
}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Okay") ,
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit .") , QMessageBox::Cancel) ;
}
else

        { QMessageBox::critical(nullptr, QObject::tr("not ok"),

                                    QObject::tr("veuiller remplir tous les champs correctement.\n"

                                                "Click cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pb_supprimer_clicked()
{

presentateur p ;

       // int cinP=ui->cinsup->text().toInt() ;
        p.setcinP(ui->cinsup->text().toInt()) ;
        bool test=p.supprimer(p.getcinP()) ;
        QMessageBox msgBox ;
        if(test)
           { msgBox.setText("suppression avec succes") ;
             ui->tab_P->setModel(p.afficher()) ; }
                    else
                msgBox.setText("suppression echoué");
                msgBox.exec() ;
   //refresh maj
}




bool MainWindow::controlSaisie(){



    if (

           ! (ui->le_nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

           ! (ui->le_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

            ui->le_cin->text().isEmpty() ||

            ui->le_cin->text().toInt() == 0 ||

            ui->le_age->text().isEmpty() ||

            ui->le_age->text().toInt() == 0 ||
            ui->le_tel->text().isEmpty() ||

            ui->le_tel->text().toInt() == 0 )

        return 0;

    else

        return 1;

}



 /*void MainWindow::on_lineEdit_rechercher_textChanged(const QString &arg1)
{
    QString search=arg1;
    ui->tab_P->setModel(p.rechercher(search)) ;
}*/

/*void MainWindow::on_pb_ajouter_clicked()
{
    int cinP=ui->le_cin->text().toInt() ;
           int age=ui->le_age->text().toInt() ;
           int num_tel=ui->le_tel->text().toInt() ;
           QString nom=ui->le_nom->text() ;
           QString prenom=ui->le_prenom->text() ;

       presentateur p(cinP,age,num_tel,nom,prenom);
      bool test=p.ajouter();
      QMessageBox msgBox;

            if(test)
            {
                  ui->tab_P->setModel(p.afficher());
                  msgBox.setText("ajout avec succès !");

                }


                 else
                           msgBox.setText("Echec d'ajout ");
                           msgBox.exec();
                 }*/

void MainWindow::on_ok_clicked()
{
    int cinP=ui->rechercher->text().toInt();

             ui->tab_P->setModel(p.rechercher(cinP));
    }
void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    presentateur p;
    QString type="";

    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(arg1 != "Choisir")
        ui->tab_P->setModel(p.Trier(type,arg1));

    else  ui->tab_P->setModel(p.afficher());

}
void MainWindow::on_up_clicked()
{
    presentateur p;
    QString type="";


    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
        ui->tab_P->setModel(p.Trier(type,ui->comboBox->currentText()));

    else  ui->tab_P->setModel(p.afficher());
}
void MainWindow::on_down_clicked()
{
    presentateur p;
    QString type="";

    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
        ui->tab_P->setModel(p.Trier(type,ui->comboBox->currentText()));


    else  ui->tab_P->setModel(p.afficher());
}

void MainWindow::on_tab_P_activated(const QModelIndex &index)
{
 QString val=ui->tab_P->model()->data(index).toString();
 QSqlQuery qry;
 qry.prepare("select * from PRESENTATEURS where nom='"+val+"'");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->le_cin->setText(qry.value(0).toString());
   ui->le_nom->setText(qry.value(1).toString());
   ui->le_prenom->setText(qry.value(2).toString());
   ui->le_age->setText(qry.value(3).toString());
   ui->le_tel->setText(qry.value(4).toString());


  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}
void MainWindow::on_modifier_clicked()
{

        int cinP=ui->le_cin->text().toInt();
        QString nom=ui->le_nom->text();
        QString prenom=ui->le_prenom->text();
        int age=ui->le_age->text().toInt();
         int num_tel=ui->le_tel->text().toInt();

        QString res1 = QString::number(cinP);
        QString res2 = QString::number(age);

        QString res3 = QString::number(num_tel);

        QSqlQuery quer;
        quer.prepare("update PRESENTATEURS set CINP='"+res1+"' ,nom='"+nom+"', age='"+res2+"', num_tel='"+res3+"' where nom='"+nom+"'");
          if(quer.exec())
          {

              ui->tab_P->setModel(p.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("modification effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
          }
          else
              QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                    QObject::tr("modification non effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);

}
