#include "etablissement.h"

#include "gestion_etablissement.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include<QDate>
#include<QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

Etablissement::Etablissement()
{

}

Etablissement::Etablissement(QString idetab,QString nometab,QString ville,QString type,QString ntel)
{this->idetab=idetab;
    this->nometab = nometab;
    this->ville = ville;
    this->type = type;
    this->ntel = ntel;

}

  QString Etablissement::getnumetab(){return idetab;}
  QString Etablissement::getnom(){return nometab;}
  QString Etablissement::getville(){return ville;}
  QString Etablissement::gettype(){return type;}
  QString Etablissement::getntel(){return ntel;}

  void Etablissement::setnumetab(QString idetab){this->idetab=idetab;}
  void Etablissement::setnom(QString nometab){this->nometab=nometab;}
  void Etablissement::setville(QString ville){this->ville=ville;}
  void Etablissement::settype(QString type){this->type=type;}
  void Etablissement::setntel(QString ntel ){this->ntel=ntel;}



bool Etablissement::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO etablissement (idetab,nometab,ville,type,ntel)"
                  "values(:idetab,:nometab,:ville,type,:ntel)");
    query.bindValue(":idetab",idetab);
        query.bindValue(":nometab",nometab);
         query.bindValue(":ville",ville);
         query.bindValue(":type",type);
         query.bindValue(":ntel",ntel);

          return query.exec();

   };



QSqlQueryModel * Etablissement::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from etablissement");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idetab"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nometab"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ntel"));


    return model;
}

bool Etablissement::supprimer(QString idetab)
{
    QSqlQuery query;
         QString res=idetab;
         query.prepare("Delete from Etablissement where idetab=:idetab");
         query.bindValue(":idetab",res);
         return query.exec();
}

bool Etablissement::modifier(QString idetab)
{
QSqlQuery query;
        QString res= idetab;


        query.prepare("UPDATE eleve SET NOM=:NOM,PRENOM=:PRENOM,DATEN=:DATEN,SEXE=:SEXE,AGE=:AGE where NUMINSC=:NUMINSC");
        query.bindValue(":idetab", idetab);
        query.bindValue(":nometab",nometab);
         query.bindValue(":ville",ville);
         query.bindValue(":type",type);
         query.bindValue(":ntel",ntel);
        return    query.exec();
}

QSqlQueryModel* Etablissement::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from Etablissement where (nometab like '%"+a+"%' or nometab like '"+a+"%' or  nometab like '%"+a+"' or ville like '%"+a+"%' or ville like '"+a+"%' or  ville like '%"+a+"'or idetab like '%"+a+"%' or idetab like '"+a+"%' or  idetab like '%"+a+"') ");



    query->setHeaderData(0,Qt::Horizontal,QObject::tr("idetab"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("nometab"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("ntel"));
    return query;
}
QSqlQueryModel *Etablissement::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;

    if(x=="nom (A->Z)")
        model->setQuery("select*  from Etablissement order by nometab");
    else if(x=="ntel (A->Z)")
        model->setQuery("select*  from Etablissement order by ntel");
    else if (x=="idetab (des)")
        model->setQuery("select*  from Etablissement order by idetab");
    else if (x=="Default")
            model->setQuery("select * from Etablissement");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idetab"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nometab"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ntel"));
        return model;
}
