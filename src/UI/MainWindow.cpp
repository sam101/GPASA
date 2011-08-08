/**
 * Projet tutoré. 2010-2011.
 * src/UI/MainWindow.cpp
 */
#include "MainWindow.h"
#include <QtCore/QDebug>
#include <QtCore/QSettings>
#include <QtGui/QAction>
#include <QtGui/QFileDialog>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QMessageBox>
#include <QtGui/QScrollArea>
/**
  * Constructeur
  */
MainWindow::MainWindow(QString path,QWidget *parent) :
QMainWindow(parent),
_path(path),
_jeu(NULL),
_sauvegarde(NULL),
_selecteur(NULL)
{
    //On crée le widget principal
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    //On déclare le layout
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    //On déclare l'objet stockant le texte.
    _browser = new QTextBrowser;
    QSizePolicy policy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    policy.setVerticalStretch(2);
    _browser->setSizePolicy(policy);
    layout->addWidget(_browser);
    //On ajoute le bouton continuer
    _continuer = new QPushButton(tr("Continuer"));
    layout->addWidget(_continuer);
    _continuer->hide();
    connect(_continuer,SIGNAL(clicked()),this,SLOT(continuer()));
    /*
     * On crée les boutons et les labels pour les réponses
     */
    for (int i = 0; i < MAXPROP; i++ )
    {
        //On déclare d'abord le layout qui servira pour afficher le bouton et le label
        QHBoxLayout *hbox = new QHBoxLayout;
        layout->addLayout(hbox);
        //Ensuite, on alloue le bouton
        _button[i] = new QPushButton(QString(QString::number(i + 1)));
        hbox->addWidget(_button[i]);
        _button[i]->hide();
        /*
         * On connecte le bouton au signal "repondre" pour
         * répondre à une question
         */
        connect(_button[i],SIGNAL(clicked()),this,SLOT(repondre()));

        //On crée ensuite le label
        _prop[i] = new QLabel();
        _prop[i]->setWordWrap(true);
        _prop[i]->setSizeIncrement(1,1);
        _prop[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        hbox->addWidget(_prop[i]);
        _prop[i]->hide();

    }
    //On ajoute le menu
    QMenu *fichier = menuBar()->addMenu(tr("Fichier"));
        QAction *nouvelle = fichier->addAction(tr("Nouvelle partie"));
        nouvelle->setShortcut(QKeySequence(tr("Ctrl+N")));
        connect(nouvelle,SIGNAL(triggered()),this,SLOT(nouvellePartie()));

        QAction *charger = fichier->addAction(tr("Charger une partie"));
        charger->setShortcut(QKeySequence(tr("Ctrl+O")));

        QAction *sauver = fichier->addAction(tr("Sauvegarder la partie"));
        sauver->setShortcut(QKeySequence(tr("Ctrl+S")));

        fichier->addSeparator();

        QAction *abandonner = fichier->addAction(tr("Abandonner la partie"));
        abandonner->setShortcut(QKeySequence(tr("Ctrl+W")));
        connect(abandonner,SIGNAL(triggered()),this,SLOT(abandonnerPartie()));

        fichier->addSeparator();

        QAction *quitter = fichier->addAction(tr("Quitter"));
        quitter->setShortcut(QKeySequence(tr("Ctrl+Q")));
        connect(quitter,SIGNAL(triggered()),this,SLOT(close()));
    QMenu *aide = menuBar()->addMenu(tr("Aide"));

        QAction *apropos = aide->addAction(tr("A propos de"));
        connect(apropos,SIGNAL(triggered()),this,SLOT(aproposde()));
    //On crée le widget selecteur
    _selecteur = new Selecteur(this);
    //On crée le dock de deboggage
#ifdef DEBUG
    _debugdock = new DebugDock;
    this->addDockWidget(Qt::LeftDockWidgetArea, _debugdock);
    _debugdock->hide();
    connect(this,SIGNAL(aUnChangement()),_debugdock,SLOT(mettreAJour()));
    connect(_debugdock,SIGNAL(aChange()),this,SLOT(chargerQuestion()));
#endif
    //On restaure la taille de la fenêtre
    QSettings settings;
    this->restoreState(settings.value("geometry").toByteArray()  );
}
/**
  * Initialise le jeu
  */
void MainWindow::init()
{
    try
    {
        //On crée l'objet jeu

        _jeu = new Jeu(_path.toStdString());
        //On affiche le selecteur
        _selecteur->selectionner(_jeu);

        if (_selecteur->result() == QDialog::Rejected)
        {
            QMessageBox::critical(this,tr("Erreur: Vous n'avez pas entré les carctéristiques du héros"),tr("Erreur: Vous n'avez pas entré les caractéristiques du héros"));
            return;
        }
        //On commence le jeu
        _jeu->commencer();
        //On change l'objet "Jeu" du DebugDock
#ifdef DEBUG
        _debugdock->setJeu(_jeu);
#endif
        emit aUnChangement();

    }
    catch (std::string e)
    {
        QMessageBox::critical(this, tr("Une erreur est aparue"), tr("Erreur:") +  QString::fromStdString(e));
        this->close();
    }

    chargerQuestion();
}
/**
  * Lance une nouvelle partie
  */
void MainWindow::nouvellePartie()
{
    if (_jeu != NULL)
    {
        delete _jeu;
    }
#ifdef DEBUG
    _debugdock->show();
#endif
    init();
}

/**
  * Appelé lors de l'appui sur un des boutons
  * répond à une question
  */
void MainWindow::repondre()
{
    int prop;
    try
    {
        //On recupère l'objet ayant envoyé le message
        for (int i = 0; i < MAXPROP; i++)
        {
            if (qobject_cast<QPushButton*>(sender()) == _button[i])
            {
                prop = i;
                break;
            }
        }
        //On recupère la reponse à la question actuelle pour
        //l'afficher
        QString reponse = QString::fromStdString(_jeu->propositions().at(prop).getReponse());
        _jeu->repondre(prop);
        //On indique qu'il y'a eu un changement dans les données de jeu
        emit aUnChangement();

        //On affiche la réponse à la question
        afficherReponse(reponse);
    }
    catch (std::string e)
    {
        QMessageBox::critical(this, tr("Une erreur est aparue"), tr("Erreur:") +  QString::fromStdString(e));
    }
}
/**
  * Appelé lors du clic sur "Abandonner Partie"
  * Abandonne la partie en cours
  */
void MainWindow::abandonnerPartie()
{
    //On cache les boutons.
    for (int i = 0; i <  MAXPROP; i++)
    {
        _prop[i]->hide();
        _button[i]->hide();
    }
    //On vide le textBrowser
    _browser->clear();
    //On détruit l'objet de jeu
    delete _jeu;
    _jeu = NULL;
}
/**
  * Appelé lors de l'appel sur le bouton "continuer"
  * ou par afficherReponse
  * Continue la partie, affiche la prochaine question
  */
void MainWindow::continuer()
{
    try
    {
        chargerQuestion();
    }
    catch (std::string e)
    {
        QMessageBox::critical(this, tr("Une erreur est aparue"), tr("Erreur:") +  QString::fromStdString(e));
        close();
    }
}

/**
 * Charge une question
 */
void MainWindow::chargerQuestion()
{
    try
    {
        //On cache le bouton continuer
        _continuer->hide();
        //TODO: Gestion des points
        //On affiche le texte de la question
        _browser->setText(QString::fromStdString(_jeu->questionIntCourante()));


        //On affiche les boutons "utiles"
        for (int i = 0; i < (int)_jeu->propositions().size(); i++)
        {
            _prop[i]->show();
            _button[i]->show();

        }
        //On cache les boutons inutilisés
        for (int i = (int)_jeu->propositions().size(); i < MAXPROP; i++)
        {
            _prop[i]->hide();
            _button[i]->hide();
        }
        //On cache les réponses impossibles.
        for (unsigned int i = 0; i < _jeu->propositions().size(); i++)
        {
            if (_jeu->heros()->getPoints() > _jeu->propositions().at(i).getPointMax() ||
                _jeu->heros()->getPoints() < _jeu->propositions().at(i).getPointMin())
            {
                _prop[i]->hide();
                _button[i]->hide();
            }
        }
        //On donne les bons numéros aux boutons.
        int k = 1;
        for (int i = 0; i < MAXPROP; i++)
        {
            if (_button[i]->isVisible())
            {
                _button[i]->setText(QString::number(k));
                k++;
            }
        }
        //On affiche les propositions
        for (int i = 0; i < (int)_jeu->propositions().size(); i++)
        {
            _prop[i]->setText(QString::fromStdString(_jeu->propositions().at(i).getLibelleProp()));
        }
        //On indique qu'il y'a eu un changement dans les données de jeu
        emit aUnChangement();

    }
    /*
     * On affiche une boite de dialogue et on quitte si il y'a eu un problème
     */
    catch (std::string e)
    {
        QMessageBox::critical(this, tr("Une erreur est aparue"), tr("Erreur:") +  QString::fromStdString(e));
        close();
    }
}
/**
  * Appelé à la fermeture de la fenêtre.
  * Sauvegarde l'état de la fenêtre et ferme la fenêtre.
  */
void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings settings;
    settings.setValue("geometry",this->saveState());
}

/**
  * Affiche la réponse à la question actuelle
  */
void MainWindow::afficherReponse(QString reponse)
{
    //On cache les propositions
    for (int i = 0; i < MAXPROP; i++)
    {
        _prop[i]->hide();
        _button[i]->hide();
    }
    //On affiche le bouton continuer
    _continuer->show();
    //On affiche la réponse

    if (reponse == "")
    {
        chargerQuestion();
    }
    else
    {
        _browser->setText(reponse);
    }
}
/**
  * Affiche la boite de dialogue "A propos de"
  */
void MainWindow::aproposde()
{
    QMessageBox::information(this, tr("GPASA v0.42 "), tr("Par: \n Samuel Lepetit \n Alexandre Meda \n Maxime Lefevre \n Sarkis Mouradian \n \n IUT Informatique - Orsay - 2011"));
}
