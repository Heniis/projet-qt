#ifndef GESTION_ETABLISSEMENT_H
#define GESTION_ETABLISSEMENT_H

#include <QDialog>
#include "etablissement.h"
namespace Ui {
class gestion_etablissement;
}

class gestion_etablissement : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_etablissement(QWidget *parent = nullptr);
    ~gestion_etablissement();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_statistique_clicked();

    void on_comboBox_tri_activated(const QString &arg1);
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_qrcodegen_clicked();

    void on_PDF_clicked();

private:
    Ui::gestion_etablissement *ui;
    Etablissement E;
};

#endif
