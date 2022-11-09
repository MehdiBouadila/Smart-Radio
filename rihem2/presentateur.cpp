#include "presentateur.h"
#include<QSqlQuery>
#include<QString>
#include<QSqlQueryModel>

presentateur::presentateur()
{
cinP=0 ;
num_tel=0;
age=0;
nom=" ";
prenom=" ";
}
presentateur::presentateur(int cinP,int age,int num_tel, QString nom, QString prenom)
{ this->cinP=cinP ;
    this->age=age;
   this->num_tel=num_tel ;
    this->nom=nom ;
    this->prenom=prenom;
}

int presentateur:: getcinP() {return cinP;}
int presentateur:: getage()  {return age;}
int presentateur::getnum_tel() {return num_tel;}
QString presentateur::getnom() {return nom;}
QString presentateur::getprenom()  {return prenom;}

void  presentateur:: setcinP(int cinP) {this->cinP=cinP;}
void  presentateur:: setage(int age) {this->age=age;}
void  presentateur::setnum_tel(int num_tel) {this->num_tel=num_tel;}
void  presentateur::setnom(QString nom) { this->nom=nom;}
void presentateur:: setprenom ( QString prenom) { this->prenom=prenom;}

bool presentateur::ajouter()
{
  QSqlQuery query;
  QString cinP_string= QString::number(cinP);
   QString age_string= QString::number(age);
  QString num_tel_string= QString::number(num_tel);



        query.prepare("INSERT INTO PRESENTATEURS (cinp,age,num_tel,nom,prenom) "
                      "VALUES (:cinp, :age, :num_tel,:nom,:prenom)");
        query.bindValue(":cinp", cinP_string);
        query.bindValue(":age", age_string);
        query.bindValue(":num_tel", num_tel_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
       return query.exec();


}

bool presentateur::supprimer(int cinP)
{
    QSqlQuery query;
    query.prepare("Delete from presentateurs where cinp= :cinp");
    query.bindValue(0 ,cinP) ;
      return query.exec();

}
QSqlQueryModel * presentateur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
          model->setQuery("SELECT* FROM PRESENTATEURS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINP"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));
          return model;

}
/*QSqlQueryModel *presentateur:: rechercher  (QString value )
{
    QSqlQueryModel *modal=new QSqlQueryModel();
         modal->setQuery("select * from presentateur where cinP like '%"+value+"%' or nom like '%"+value+"%' or prenom like '%"+value+"%'");
         return modal;

}
QSqlQueryModel *presentateur :: rechercher( int cinP)
 {
     QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from PRESENTATEUR where (cinP) like ('%"+n+"%')");

return model;
 }*/
/*QSqlQueryModel *presentateur ::Rechercher (QString value )
{
     QSqlQueryModel *modal=new QSqlQueryModel();
     modal->setQuery("select * from presentateur where NOM like '%"+value+"%' or PRENOM like '%"+value+"%' or CINP like '%"+value+"%'");
     return modal;
}*/
/*int presentateur :: rechercher(int cinP)
{
    QSqlQuery test;
    QString res=QString::number( cinP);
    int count=0;
    test.prepare("select count (*) from PRESENTATEURS where CINP=:cinp");
    test.bindValue(":cinp",res);
    test.exec();
    if(test.next())
    count=test.value(0).toInt();
    return count;
}*/


QSqlQueryModel* presentateur::rechercher(int cinP)
{

    QString res=QString::number( cinP);
    QSqlQueryModel* model = new QSqlQueryModel();

     model->setQuery("SELECT * FROM PRESENTATEURS WHERE CINP like '%"+res+"%' ");

   return model;
}

QSqlQueryModel *presentateur ::Trier (QString croissance,QString critere)
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    if(critere == "par cin" && croissance == "ASC")
        modal->setQuery("select * from presentateurs order by CINP ASC ");
    else if(critere == "par cin" && croissance == "DESC")
        modal->setQuery("select * from presentateurs order by CINP DESC ");

    else if(critere == "par nom" && croissance == "ASC")
        modal->setQuery("select * from presentateurs order by NOM ASC ");
    else if(critere == "par nom" && croissance == "DESC")
        modal->setQuery("select * from presentateurs order by NOM DESC ");

    else if(critere == "par prenom" && croissance == "ASC")
        modal->setQuery("select * from presentateurs order by PRENOM ASC ");
    else if(critere == "par prenom" && croissance == "DESC")
        modal->setQuery("select * from presentateurs order by PRENOM DESC ");

     else if(critere == "par prenom" && croissance == "")
        modal->setQuery("select * from presentateurs order by PRENOM");
    else if(critere == "par prenom" && croissance == "")
        modal->setQuery("select * from presentateurs order by PRENOM");




    else if(critere == "par cin" && croissance == "")
        modal->setQuery("select * from presentateurs order by CINP");
    else if(critere == "par cin" && croissance == "")
        modal->setQuery("select * from presentateurs order by CINP");

    else if(critere == "par nom" && croissance == "")
        modal->setQuery("select * from presentateurs order by NOM");
    else if(critere == "par nom" && croissance == "")
        modal->setQuery("select * from presentateurs order by NOM");



    return  modal;
}
