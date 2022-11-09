#ifndef EMISSION_H
#define EMISSION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QIntValidator>
using namespace std;
class Emission
{
private:
        QString nom,type,horaire;
        int duree;
public:
        Emission();
        Emission(int,QString,QString,QString);
        //getters
        QString getnom();
        QString gettype();
        QString gethoraire();
        int getduree();
        //setters
        void setnom(QString );
        void settype(QString );
        void sethoraire(QString );
        void setduree(int );
        //fonction de base
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(QString);
        QSqlQueryModel* Rechercher(QString value );
        QSqlQueryModel *Trier(QString croissance,QString critere);
};

#endif // EMISSION_H
