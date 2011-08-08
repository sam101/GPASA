/**
 * Projet tutoré. 2010-2011.
 * src/Inventaire.cpp
 */
#include "Inventaire.h"

using namespace std;

Inventaire::Inventaire()
{
    _nom = "inventaire";
}

void Inventaire::addItem(const Item & item)
{
    _inventaire.push_back(item);
}

Item Inventaire::getItem(int indice)const throw(string)
{
    if(indice < 0 || indice > (int)_inventaire.size())
    {
        throw(string("indice en dehors de la taille de _inventaire"));
    }

    return _inventaire[indice];
}

/*void delItem(int indice)
{
    _inventaire.
} je ne vois pas comment utiliser l'indice pour supprimé juste la case de l'indice, jconnais pop-back() mais ca supprime le dernier élément mis
*/
