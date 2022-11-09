#ifndef PRESENTATEUR_H
#define PRESENTATEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>


class presentateur
{
public:
    presentateur();
    presentateur (int,int,int,QString,QString);
    int getcinP() ;
    int getnum_tel();
    int getage() ;
      QString getnom() ;
      QString getprenom() ;
    void setcinP(int) ;
    void setnum_tel(int) ;
     void setage(int) ;
         void setnom(QString) ;
         void setprenom ( QString) ;
    bool ajouter() ;
         bool supprimer(int);
         QSqlQueryModel  * afficher() ;



         QSqlQueryModel* rechercher(int);
          QSqlQueryModel* trier();
          QSqlQueryModel* tri_CIN();
          QSqlQueryModel* tri_NOM();
          QSqlQueryModel* tri_AGE();
           QSqlQueryModel *Trier(QString croissance,QString critere);





    private:
         int cinP,age,num_tel ;
         QString nom,prenom ;


};
#endif // PRESENTATEUR_H
