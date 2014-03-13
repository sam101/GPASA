#include "DebugDock.h"
#ifdef DEBUG
#include <QFormLayout>
#include <QVBoxLayout>
/**
  * Constructeur
  */
DebugDock::DebugDock(QWidget *parent) :
QDockWidget(parent),
_jeu(NULL)
{
    setObjectName("DockDebug");
    setWindowTitle(tr("Debug"));
    //On crée le widget et le layout
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QFormLayout *form = new QFormLayout;


    setWidget(widget);

    widget->setLayout(layout);
    layout->addLayout(form);

    //On ajoute les widgets
    _prenom = new QLineEdit;
    _nom = new QLineEdit;
    _age = new QSpinBox;
    _monde = new QLineEdit;
    _zone = new QLineEdit;
    _question = new QLineEdit;
    _points = new QSpinBox;
    _points->setMaximum(99999);
    _points->setMinimum(-99999);

    form->addRow(tr("Prénom:"),_prenom);
    form->addRow(tr("Nom:"),_nom);
    form->addRow(tr("Age:"),_age);
    form->addRow(tr("Monde:"),_monde);
    form->addRow(tr("Zone:"),_zone);
    form->addRow(tr("Question:"),_question);
    form->addRow(tr("Points:"),_points);

    //On ajoute le bouton modifier
    _modifier = new QPushButton(tr("Modifier"));
    layout->addWidget(_modifier);
    connect(_modifier,SIGNAL(clicked()),this,SLOT(changer()));

}
/**
  * Met à jour les informations du dock
  */
void DebugDock::mettreAJour()
{
    if (_jeu == NULL)
    {
        return;
    }
    _prenom->setText(QString::fromStdString(_jeu->heros()->prenomHeros()));
    _nom->setText(QString::fromStdString(_jeu->heros()->nomHeros()));
    _age->setValue(_jeu->heros()->ageHeros());
    _monde->setText(QString::fromStdString(_jeu->heros()->getMonde()));
    _zone->setText(QString::fromStdString(_jeu->heros()->getZone()));
    _question->setText(QString::fromStdString(_jeu->heros()->getQuestion()));
    _points->setValue(_jeu->heros()->getPoints());
}
/**
  * Change l'objet de jeu actuel
  */
void DebugDock::setJeu(Jeu *jeu)
{
    _jeu = jeu;
}
/**
  * Change les informations du jeu
  */
void DebugDock::changer()
{
    if (_jeu == NULL)
    {
        return;
    }
    bool changer = false;
    if (_question->text() != QString::fromStdString(_jeu->heros()->getQuestion()) ||
         _monde->text() != QString::fromStdString(_jeu->heros()->getMonde()) ||
         _zone->text() != QString::fromStdString(_jeu->heros()->getZone()) )
    {
        changer = true;
    }

    Heros *h = _jeu->heros();

    h->setPrenomHeros(_prenom->text().toStdString());
    h->setNomHeros(_nom->text().toStdString());
    h->setAgeHeros(_age->value());
    h->setMonde(_monde->text().toStdString());
    h->setZone(_zone->text().toStdString());
    h->setQuestion(_question->text().toStdString());
    h->setPoints(_points->value());



    if (changer)
    {
        emit aChange();
    }

}
#endif
