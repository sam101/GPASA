/**
 * Projet tutoré. 2010-2011.
 * src/Item.cpp
 */
#include "Item.h"

using namespace std;

Item::Item()
{
    _type = AUCUN;
    _degat = 0;
    _armure = 0;
    _nom = "non-defini";
    _soin = 0;
    _mana = 0;
    _numeroZone = 0;

}

Item::Item(TypeItem type , std::string nom ,int numeroZone, int degatOuArmure , int soin , int mana)
{
    if (type == ARME)
    {
        _nom = nom;
        _numeroZone = numeroZone;
        _degat = degatOuArmure;
        _armure = 0;
        _soin = 0;
        _mana = 0;
    }
    else if (type == ARMURE)
    {
        _nom = nom;
        _numeroZone = numeroZone;
        _armure = degatOuArmure;
        _degat = 0;
        _soin = 0;
        _mana = 0;
    }
    else if( type == POTION)
    {
        _nom = nom;
        _numeroZone = numeroZone;
        _soin = soin;
        _mana = mana;
        _degat = 0;
        _armure = 0;
    }
}
