#ifndef CLASSE_H
#define CLASSE_H
#include <QMainWindow>
#include <QHBoxLayout>
#include <QListWidget>
#include "../Chargeur.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:  QHBoxLayout *L;
              QListWidget *Monde;
              QListWidget *Zone;
              QListWidget *Question;
              QListWidget *Proposition;

              Chargeur *c;
              Univers *u;

public slots:

   void afficheZoneMonde(QModelIndex);



public: MainWindow();



};


#endif // CLASSE_H
