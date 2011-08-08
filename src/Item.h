/**
 * Projet tutoré. 2010-2011.
 * src/Item.h
 */
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <string>

const std::string ARME = "arme" , ARMURE = "armure" , POTION = "potion";

class Item
{
    public:
        enum TypeItem
        {
            AUCUN = -1,
            ARME = 0,
            ARMURE = 1,
            POTION = 2
        };
    private:

        TypeItem _type;
        int _degat;
        int _armure;
        std::string _nom;
        int _soin;
        int _mana;
        int _numeroZone;


    public:

        Item();
        Item(TypeItem type , std::string nom ,int numeroZone, int degatOuArmure , int soin = 0 , int mana = 0 );

/*
    getteur setteur, utilisation des popo de soins et mana
*/


};


#endif // ITEM_H_INCLUDED
