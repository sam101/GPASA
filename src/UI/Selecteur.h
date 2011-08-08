#ifndef SELECTEUR_H
#define SELECTEUR_H
#include <QtGui/QCloseEvent>
#include <QtGui/QDialog>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

#include "../Jeu.h"
/**
  * Permet de selectionner les divers caractériques
  * du héros.
  * @brief Permet de selectionner les caractéristiques du héros.
  * @author Samuel Lepetit
  */
class Selecteur : public QDialog
{
    Q_OBJECT
    protected:
        /**
          * Bouton "valider" pour valider
          * les caractéristiques du héros
          */
        QPushButton *_valider;
        /**
          * Champs de texte pour le nom et le prénom
          */
        QLineEdit *_nom, *_prenom;
        /**
          * Champ pour rentrer l'age
          */
        QSpinBox *_age;
        /**
          * Objet jeu actuel
          */
        Jeu *_jeu;
    public:
        explicit Selecteur(QWidget *parent = 0);
    public slots:
        void selectionner(Jeu *jeu);

        void validation();
};

#endif // SELECTEUR_H
