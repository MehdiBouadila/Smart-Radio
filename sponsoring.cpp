#include "Sponsoring.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include "Sponsoring.h"
#include <QMessageBox>
#include <QIntValidator>

/*
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLegend>

#include <QChart>
#include <QtCharts>
#include <QGraphicsView>
#include <QChart>
#include <QtCharts>
#include <QMessageBox>
#include <QIntValidator>
#include <QPieSeries>
#include <QChartView>
#include <QGraphicsView>
*/


Sponsoring::Sponsoring()
{
    id=0;
    nom=" ";
    domaine=" ";
    duree=0;
    budget=0;
}

Sponsoring::Sponsoring(int id,QString nom ,QString domaine ,int duree , int budget)
{
     this->id=id;
     this->nom=nom;
     this->domaine=domaine;
     this->duree=duree;
     this->budget=budget;

}

int Sponsoring::getid(){return id;}
QString Sponsoring::getnom(){return nom;}
QString Sponsoring::getdomaine(){return domaine;}
int Sponsoring::getduree(){return duree;}
int Sponsoring::getbudget(){return budget;}

void Sponsoring::setid(int id){this->id=id;}
void Sponsoring::setnom(QString nom){this->nom=nom;}
void Sponsoring::setdomaine(QString domaine){this->domaine=domaine;}
void Sponsoring::setduree(int duree){this->duree=duree;}
void Sponsoring::setbudget(int budget){this->budget=budget;}



bool Sponsoring::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
         query.prepare("INSERT INTO SPONSORING (ID, NOM, DOMAINE,DUREE , BUDGET) "
                       "VALUES (:id, :nom, :domaine, :duree , :budget)");
         query.bindValue(":id",id_string);
         query.bindValue(":nom",nom);
         query.bindValue(":domaine", domaine);
         query.bindValue(":duree", duree);
         query.bindValue(":budget", budget);
         return query.exec();
}

QSqlQueryModel* Sponsoring::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;

          model->setQuery("SELECT* FROM SPONSORING");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("domaine"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("Duree"));
          model->setHeaderData(4, Qt::Horizontal,  QObject::tr("budget"));
    return model;
}
bool Sponsoring::supprimer(int)
{
    QSqlQuery query;
      query.prepare("Delete from Sponsoring where id=:id");
       query.bindValue(0, id);

         return query.exec();
}


QSqlQueryModel *Sponsoring::Rechercher(QString value )
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        modal->setQuery("select * from SPONSORING where id like '%"+value+"%' or nom like '%"+value+"%' or domaine like '%"+value+"%' or duree like '%"+value+"%' or budget like '%"+value+"%' ");
        return modal;
        }



QSqlQueryModel *Sponsoring::Trier(QString croissance,QString critere)
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    if(critere == "Par id" && croissance == "ASC")
            modal->setQuery("select * from SPONSORING order by ID ASC ");

    else if(critere == "Par id" && croissance == "DESC")
           modal->setQuery("select * from SPONSORING  order by ID DESC ");

    else if(critere == "Par nom" && croissance == "ASC")
            modal->setQuery("select * from SPONSORING  order by NOM ASC ");

    else if(critere == "Par nom" && croissance == "DESC")
           modal->setQuery("select * from SPONSORING order by NOM DESC ");

    else if(critere == " Par domaine" && croissance == "ASC")
            modal->setQuery("select * from SPONSORING order by DOMAINE ASC ");

    else if(critere == "Par domaine" && croissance == "DESC")
            modal->setQuery("select * from SPONSORING  order by DOMAINE DESC ");

    else if(critere == "Par Duree" && croissance == "ASC")
            modal->setQuery("select * from SPONSORING  order by DUREE ASC ");

    else if(critere == "Par duree" && croissance == "DESC")
            modal->setQuery("select * from SPONSORING  order by DUREE DESC ");

    else if(critere == "Par budget" && croissance == "ASC")
            modal->setQuery("select * from SPONSORING  order by BUDGET ASC ");

    else if(critere == "Par budget" && croissance == "DESC")
            modal->setQuery("select * from SPONSORING  order by BUDGET DESC ");




    else if(critere == "Par id" && croissance == "")
           modal->setQuery("select * from SPONSORING order by ID");

    else if(critere == "Par id" && croissance == "")
           modal->setQuery("select * from SPONSORING order by ID");


    else if(critere == "Par nom" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by NOM");
        else if(critere == "Par nom" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by NOM");



    else if(critere == "Par domaine" && croissance == "")
           modal->setQuery("select * from SPONSORING  order by DOMAINE");
       else if(critere == "Par domaine" && croissance == "")
           modal->setQuery("select * from SPONSORING order by DOMAINE");


    else if(critere == "Par duree" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by DUREE");
        else if(critere == "Par Duree" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by DUREE");



    else if(critere == "Par budget" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by BUDGET");
        else if(critere == "Par budget" && croissance == "")
            modal->setQuery("select * from SPONSORING  order by BUDGET");


    return  modal;
   }






QSqlQuery Sponsoring::stat()
{
    QSqlQuery query;
        query.prepare("select *from client ");
        query.exec();
        return query;
}

