#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QDateTime>
#include <QFile>
#include <QDebug>


class Etablissement
{
    public:
        Etablissement();
        Etablissement(QString,QString,QString,QString,QString);

//getters
        QString getnumetab();
        QString getnom();
        QString getville();
        QString gettype();
        QString getntel();


        void setnumetab(QString);
        void setnom(QString);
        void setville(QString );
        void settype(QString);
        void setntel(QString );


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifier(QString);

        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);

private:
        QString idetab,nometab,ville,type,ntel;


};



#endif // ETABLISSEMENT_H
