#include "Selecteur.h"
#include <QtGui/QLabel>
#include <QtGui/QFormLayout>
#include <QtGui/QVBoxLayout>
/**
  * Constructeur.
  * Construit l'interface du widget
  */
Selecteur::Selecteur(QWidget *parent) :
QDialog(parent)
{
    setWindowTitle(tr("Entrez les détails du héros"));
    //On construit tout d'abord le layout
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    QLabel *label = new QLabel(tr("Entrez les détails du héros"));
    layout->addWidget(label);

    QFormLayout *form = new QFormLayout;
    layout->addLayout(form);


    //On crée et on ajoute les widget du nom et du prenom
    _nom = new QLineEdit;
    _prenom = new QLineEdit;
    form->addRow(tr("Prénom:"),_prenom);
    form->addRow(tr("Nom:"),_nom);

    _age = new QSpinBox;
    form->addRow(tr("Age:"),_age);
    //On ajoute le bouton valider
    _valider = new QPushButton(tr("Valider"));
    layout->addWidget(_valider);
    connect(_valider,SIGNAL(clicked()),this,SLOT(validation()));

}
/**
  * Ouvre le dialogue et permet la selection
  */
void Selecteur::selectionner(Jeu *jeu)
{
    _jeu = jeu;

    exec();
}
/**
  * Appelé au clic sur "valider".
  * Ferme le dialogue et remplit les informations du héros
  */
void Selecteur::validation()
{
    _jeu->setPrenomHeros(_prenom->text().toStdString());
    _jeu->setNomHeros(_nom->text().toStdString());
    _jeu->setAgeHeros(_age->value());

    done(QDialog::Accepted);
}
