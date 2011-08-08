#ifndef DEBUGDOCK_H
#define DEBUGDOCK_H
#include "Config.h"
#ifdef DEBUG
#include <QtGui/QDockWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

#include "../Jeu.h"
/**
  * Classe gérant le dock
  * gérant les informations de debug
  * @brief Gère les informations de debug
  * @author Samuel Lepetit
  */
class DebugDock : public QDockWidget
{
    Q_OBJECT
    public:
        /**
          * Constructeur
          */
        explicit DebugDock(QWidget *parent = 0);
    signals:
        void aChange();
    public slots:
        /**
          * Met à jour les informations du dock
          */
        void mettreAJour();
        /**
          * Met à jour l'objet jeu actuel
          */
        void setJeu(Jeu *jeu);
        /**
          * Change les informations du jeu
          */
        void changer();
    protected:
        /**
          * Pointeur vers l'objet
          * contenant les données de jeu
          */
        Jeu *_jeu;
        /**
          * Prénom du héros
          */
        QLineEdit *_prenom;
        /**
          * Nom du héros
          */
        QLineEdit *_nom;
        /**
          * Age du héros
          */
        QSpinBox *_age;
        /**
          * Monde dans lequel se trouve le héros
          */
        QLineEdit *_monde;
        /**
          * Zone dans laquelle se trouve le héros
          */
        QLineEdit *_zone;
        /**
          * Question actuellement posée au héros
          */
        QLineEdit *_question;
        /**
          * Points actuels du héros
          */
        QSpinBox *_points;
        /**
          * Bouton pour modifier les valeurs
          */
        QPushButton *_modifier;
};
#endif
#endif //DEBUGDOCK_H
