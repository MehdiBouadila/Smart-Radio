#include "emission.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include "emission.h"
#include <QMessageBox>
#include <QIntValidator>

Emission::Emission()
{
    nom=" ";type=" ";horaire=" ";duree=0;

}
Emission::Emission(int duree,QString nom ,QString type ,QString horaire)
{
     this->duree=duree;
     this->nom=nom;
     this->type=type;
     this->horaire=horaire;

}
QString Emission::getnom(){return nom;}
QString Emission::gettype(){return type;}
QString Emission::gethoraire(){return horaire;}
int Emission::getduree(){return duree;}

void Emission::setnom(QString nom){this->nom=nom;}
void Emission::settype(QString type){this->type=type;}
void Emission::sethoraire(QString horaire){this->horaire=horaire;}
void Emission::setduree(int duree){this->duree=duree;}

bool Emission::ajouter()
{

    QSqlQuery query;
    QString duree_string=QString::number(duree);
         query.prepare("INSERT INTO EMISSION (DUREE, NOM, TYPE,HORAIRE) "
                       "VALUES (:duree, :nom, :type, :hor)");
         query.bindValue(":duree",duree_string);
         query.bindValue(":nom",nom);
         query.bindValue(":type", type);
         query.bindValue(":hor", horaire);
         return query.exec();

}
QSqlQueryModel* Emission::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel;

          model->setQuery("SELECT* FROM EMISSION");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(1, Qt::Horizontal,  QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal,  QObject::tr("Horaire"));
          model->setHeaderData(3, Qt::Horizontal,  QObject::tr("Duree"));
    return model;
}
bool Emission::supprimer(QString)
{
    QSqlQuery query;
      query.prepare("Delete from Emission where nom=:nom");
       query.bindValue(0, nom);

         return query.exec();
}
QSqlQueryModel *Emission::Rechercher(QString value )
{
     QSqlQueryModel *modal=new QSqlQueryModel();
     modal->setQuery("select * from EMISSION where nom like '%"+value+"%' or type like '%"+value+"%' or horaire like '%"+value+"%' or duree like '%"+value+"%'");
     return modal;
}
QSqlQueryModel *Emission::Trier(QString croissance,QString critere)
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    if(critere == "Par Nom" && croissance == "ASC")
        modal->setQuery("select * from EMISSION order by NOM ASC ");
    else if(critere == "Par Nom" && croissance == "DESC")
        modal->setQuery("select * from EMISSION  order by NOM DESC ");

    else if(critere == "Par Type" && croissance == "ASC")
        modal->setQuery("select * from EMISSION  order by TYPE ASC ");
    else if(critere == "Par Type" && croissance == "DESC")
        modal->setQuery("select * from EMISSION order by TYPE DESC ");

    else if(critere == " Par Horaire" && croissance == "ASC")
        modal->setQuery("select * from EMISSION order by HORAIRE ASC ");
    else if(critere == "Par Horaire" && croissance == "DESC")
        modal->setQuery("select * from EMISSION  order by HORAIRE DESC ");

    else if(critere == "Par Duree" && croissance == "ASC")
        modal->setQuery("select * from EMISSION  order by DUREE ASC ");
    else if(critere == "Par Duree" && croissance == "DESC")
        modal->setQuery("select * from EMISSION  order by DUREE DESC ");


    else if(critere == "Par Nom" && croissance == "")
        modal->setQuery("select * from EMISSION order by NOM");
    else if(critere == "Par Nom" && croissance == "")
        modal->setQuery("select * from EMISSION order by NOM");

    else if(critere == "Par Type" && croissance == "")
        modal->setQuery("select * from EMISSION  order by TYPE");
    else if(critere == "Par Type" && croissance == "")
        modal->setQuery("select * from EMISSION  order by TYPE");

    else if(critere == "Par Horaire" && croissance == "")
        modal->setQuery("select * from EMISSION  order by HORAIRE");
    else if(critere == "Par Horaire" && croissance == "")
        modal->setQuery("select * from EMISSION order by HORAIRE");

    else if(critere == "Par Duree" && croissance == "")
        modal->setQuery("select * from EMISSION  order by DUREE");
    else if(critere == "Par Duree" && croissance == "")
        modal->setQuery("select * from EMISSION  order by DUREE");




    return  modal;
}
