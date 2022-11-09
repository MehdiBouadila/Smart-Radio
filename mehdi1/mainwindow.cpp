#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emission.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QValidator>
#include<QSqlQueryModel>
#include<QSqlError>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     ui->le_duree->setValidator( new QIntValidator(15, 999, this));
     //ui->le_nom.toINT->setValidator( new QIntValidator(0, 999, this));
     ui->tab_emi->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int duree=ui->le_duree->text().toInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->text();
    QString horaire=ui->le_horaire->text();
    Emission e(duree,nom,type,horaire);
    bool test=e.ajouter();
    QMessageBox msgBox;

      if(test)
      {
          ui->tab_emi->setModel(E.afficher());
           msgBox.setText("ajout avec succes.");
            ui->le_duree->clear();
            ui->le_nom->clear();
            ui->le_type->clear();
            ui->le_horaire->clear();
      }

    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

}



void MainWindow::on_pb_supp_clicked()
{
    Emission e1;
    e1.setnom(ui->le_nomsupp->text());
    bool test=e1.supprimer(e1.getnom());
    QMessageBox msgBox;
    if(test)
    {
        ui->tab_emi->setModel(E.afficher());
        msgBox.setText("Suppression avec succes.");
        ui->le_duree->clear();
        ui->le_nom->clear();
        ui->le_type->clear();
        ui->le_horaire->clear();
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}
void MainWindow::on_tab_emi_activated(const QModelIndex &index)
{
 QString val=ui->tab_emi->model()->data(index).toString();
 QSqlQuery qry;
 qry.prepare("select * from EMISSION where nom='"+val+"'");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->le_nom->setText(qry.value(0).toString());
   ui->le_horaire->setText(qry.value(1).toString());
   ui->le_type->setText(qry.value(2).toString());
   ui->le_duree->setText(qry.value(3).toString());

  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}

void MainWindow::on_bt_modif_clicked()
{

        QString nom=ui->le_nom->text();
        QString type=ui->le_type->text();
        QString horaire=ui->le_horaire->text();
        int duree=ui->le_duree->text().toInt();
        QString res = QString::number(duree);
        QSqlQuery quer;
        quer.prepare("update EMISSION set duree='"+res+"' ,nom='"+nom+"', type='"+type+"', horaire='"+horaire+"' where nom='"+nom+"'");
          if(quer.exec())
          {

              ui->tab_emi->setModel(E.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("modification effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
          }
          else
              QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                    QObject::tr("modification non effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::on_rech_textChanged(const QString &arg1)
{
    QString search=arg1;
        ui->tab_emi->setModel(E.Rechercher(search));
}
//tri combobox
void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    Emission e;
    QString type="";

    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(arg1 != "Choisir")
        ui->tab_emi->setModel(e.Trier(type,arg1));

    else  ui->tab_emi->setModel(e.afficher());

}

//choisir radio button ascendant
void MainWindow::on_radioButton_clicked()
{
    Emission e;
    QString type="";


    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
        ui->tab_emi->setModel(e.Trier(type,ui->comboBox->currentText()));

    else  ui->tab_emi->setModel(e.afficher());
}


//choisir radio button descendant
void MainWindow::on_radioButton_2_clicked()
{
    Emission e;
    QString type="";

    if(ui->radioButton->isChecked())
        type="ASC";
    else if(ui->radioButton_2->isChecked())
        type="DESC";

    if(ui->comboBox->currentText() != "Choisir")
        ui->tab_emi->setModel(e.Trier(type,ui->comboBox->currentText()));


    else  ui->tab_emi->setModel(e.afficher());
}



