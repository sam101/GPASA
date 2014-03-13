/**
 * Projet tutoré. 2010-2011.
 * src/UI/MainWindow.h
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QWidget>

#include "DebugDock.h"
#include "Selecteur.h"
#include "../Jeu.h"
#include "../Sauvegarde.h"
/**
  * Classe principale de l'interface graphique
  * @brief Classe principale de l'interface graphique
  * @author Samuel Lepetit
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        /**
          * Constructeur
          */
        explicit MainWindow(QString path, QWidget *parent = 0);
        /**
          * Initialise le jeu
          */
        void init();
    signals:
        void aUnChangement();
    public slots:
        void nouvellePartie();
        void repondre();
        void abandonnerPartie();

        void continuer();

        void aproposde();

        /**
          * Charge une question
          */
        void chargerQuestion();
    protected:
        /**
          * Appelé à la fermeture de la fenêtre.
          */
        void closeEvent(QCloseEvent *);
        /**
          * Affiche la réponse à la question actuelle
          */
        void afficherReponse(QString reponse);
        /**
          * Nombre maximal de propositions
          */
        static const int MAXPROP = 5;
        /**
          * Chemin vers les données
          */
        QString _path;
        /**
          * TextBrowser pour la question
          */
        QTextBrowser *_browser;
        /**
          * Label des propositions
          */
        QLabel *_prop[MAXPROP];
        /**
          * Boutons sur lequels on peut appuyer
          */
        QPushButton *_button[MAXPROP];
        /**
          * Bouton "Continuer"
          */
        QPushButton *_continuer;
        /**
          * Objet contenant le jeu
          */
        Jeu *_jeu;
        /**
          * Gère la sauvegarde
          */
        Sauvegarde *_sauvegarde;
        /**
          * Widget de selection des caractéristiques du héros
          */
        Selecteur *_selecteur;
        /**
          * Panel utilisé pour le debuggage
          */
        #ifdef DEBUG
        DebugDock *_debugdock;
        #endif
};

#endif // MAINWINDOW_H
