#include "MainWindow.h"
#include "../Chargeur.h"
#include "../Univers.h"
#include <iostream>
#include <string.h>
#include <QListView>


using namespace std;

MainWindow::MainWindow()
{
     L=new QHBoxLayout;
     Monde=new QListWidget;
     Zone=new QListWidget;
     Question=new QListWidget;
     Proposition=new QListWidget;


    QWidget *w = new QWidget;

    setCentralWidget(w);

    w->setLayout(L);

    L->addWidget(Monde);
    L->addWidget(Zone);
    L->addWidget(Question);
    L->addWidget(Proposition);

    u=new Univers;
    c=new Chargeur;


    try{

        c->charger(u,"../../../data/Univers1");

        //affichage des mondes
        for (int i=0;i<u->getNbMonde();i++)
        {
            Monde->addItem(QString::fromStdString(u->getMonde(i).getNomMonde()));
        }

        //gestion du click sur un monde
        connect(Monde,SIGNAL(clicked(QModelIndex)),this,SLOT(afficheZoneMonde(QModelIndex)));

    }
    catch(std::string n){
        cerr << "Oula" << endl;
    }



}


void MainWindow::afficheZoneMonde(QModelIndex k){

   Zone->clear();

   for (int i=0;i<u->getMonde(k.row()).getNbZones();i++){

      Zone->addItem(QString::fromStdString(u->getMonde(k.row()).getZone(i).getNomZone()));
    }


}




