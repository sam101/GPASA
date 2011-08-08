#include "TestChargeur.h"
#include "../Univers.h"
#include "../Chargeur.h"
#include <iostream>

using namespace std;
void testChargeur() throw(std::string)
{
    cout << "Test de la classe Chargeur" << endl;
    try
    {
         Univers u;
         Chargeur c;
         c.charger(&u,"../data/Univers1");


    }
    catch (std::string e)
    {
        cerr << "Erreur:" << e << endl;
        throw(std::string("Le test de testChargeur a échoué"));
    }
    cout << "Test de la classe Chargeur: OK" << endl;

}
