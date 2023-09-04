#ifndef ELEVE_H
#define ELEVE_H

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
class Eleve
{
    public:
        Eleve();
        Eleve(QString,QString,QString,QString,QString,QString);

//getters
        QString getNumInsc();
        QString getNom();
        QString getPrenom();
        QString getDateN();
        QString getSexe();
        QString getAge();


        void setNumInsc(QString);
        void setNom(QString);
        void setPrenom(QString );
        void setDateN(QString);
        void setSexe(QString );
        void setAge(QString);


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifier(QString);

        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);

private:
        QString NOM,PRENOM,SEXE;
        QString AGE;
        QString DATEN;
        QString NUMINSC;

};


#endif // ELEVE_H
