/**
 * Projet tutoré. 2010-2011.
 * src/Inventaire.h
 */
#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include "Item.h"
#include <vector>
#include <string>

class Inventaire
{

  private :

    std::vector<Item> _inventaire;
    std::string _nom;


  public:

    Inventaire();
    void addItem(const Item & item);
    /**
    * Retourne un Item du tableau d'Item de la classe Inventaire
    */

    Item getItem(int indice)const throw(std::string);
    //void delItem(int indice);  lire le .cpp de la méthode



};


#endif // INVENTAIRE_H_INCLUDED
