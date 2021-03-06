/**
 * Projet tutoré. 2010-2011.
 * src/UI/main.cpp
 * Contient le fichier main utilisé pour la gui sur desktop.
 */
#include <QApplication>
#include <QTextCodec>
#include "MainWindow.h"
int main(int argc, char *argv[])
{
    //On déclare l'objet d'application
    QApplication a(argc, argv);
    //On définit les paramètres de l'application (pour utiliser QSettings)
    QCoreApplication::setOrganizationName("GPASA");
    QCoreApplication::setApplicationName("GPASA");

    //On crée la fenêtre principale
    MainWindow m("../../data/Univers1");
#ifdef DEBUG
    m.setMinimumSize(640,480);
#else
    m.setMinimumSize(200,480);
#endif
    //On l'affiche
    m.show();
    //On execute l'application
    return a.exec();
}
