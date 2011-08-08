/**
 * Projet tutoré. 2010-2011.
 * src/mobileUI/main.cpp
 * Contient le fichier main utilisé pour l'UI pour la version Android.
 */
#include <QtGui/QApplication>
#include <QTextCodec>
#include "../UI/MainWindow.h"
int main(int argc, char *argv[])
{
    //On déclare l'objet d'application
    QApplication a(argc, argv);
    //On définit les paramètres de l'application (pour utiliser QSettings)
    QCoreApplication::setOrganizationName("GPASA");
    QCoreApplication::setApplicationName("GPASA");






    //On selectionne le codec voulu (UTF-8) pour afficher les accents
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //On crée la fenêtre principale
    MainWindow m("/sdcard/data/Univers1");
    //On l'affiche
    m.show();
    //On execute l'application
    return a.exec();
}
