//#include <QcharView>
#ifndef SPONSORING_H
#define SPONSORING_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QIntValidator>


/*
#include <QChartView>

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

using namespace std;

class Sponsoring
{
private:
    int id , duree , budget ;
    QString nom , domaine ;
public:
    Sponsoring();
    Sponsoring(int,QString,QString,int , int);
    //getters
            int getid();
            QString getnom();
            QString getdomaine();
            int getduree();
            int getbudget();
     //setters
             void setid(int );
             void setnom(QString );
             void setdomaine(QString );
             void setduree(int );
             void setbudget(int );
     //fonction de base
             bool ajouter();
             QSqlQueryModel* afficher();
             bool supprimer(int);
             QSqlQueryModel* Rechercher(QString value );
             QSqlQueryModel *Trier(QString croissance,QString critere);
             QSqlQuery stat();
            // QChartView *stat_type();
};

#endif // SPONSORING_H
