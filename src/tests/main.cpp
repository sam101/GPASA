#include <iostream>
#include <stdlib.h>
#include "TestChargeur.h"
#include "TestJeu.h"
using namespace std;

int main()
{
    /*
     * TODO : Listes des différants tests unitaires de toutes les classes.
     */

    try
    {
        //Test de chargeur
        testChargeur();
        //Test de jeu
        testJeu();
    }
    catch(std::string e)
    {
        cerr << "Erreur dans les tests:" << e << endl;
    }

    return 0;
}
