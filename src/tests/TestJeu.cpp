#include "TestJeu.h"
#include "../Jeu.h"

#include <iostream>
#include <stdio.h>
using namespace std;
void testJeu() throw(std::string)
{
    int test;
    cout << "Test de la classe Jeu" << endl;
    try
    {
        Jeu *j = new Jeu("../data/Univers1");

        j->setNomHeros("Heros de test");
        j->setPrenomHeros("Heros de test");

        j->setAgeHeros(42);

        j->commencer();

        while (1)
        {

            cout <<  j->questionIntCourante() << endl << endl;
            for (int i = 0; i < (int)j->propositions().size(); i++)
            {
                cout << i << ")" << j->propositions()[i].getLibelleProp() << endl << endl;
            }
            cin >> test;
            j->repondre(test);
            getchar();
        }

        delete j;
    }
    catch (std::string e)
    {
        cerr << "Erreur:" << e << endl;
        throw(std::string("Le test de testJeu a échoué"));
    }
    cout << "Test de la classe Jeu: OK" << endl;

}
