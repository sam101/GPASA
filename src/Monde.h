/**
 * Projet tutoré. 2010-2011.
 * src/Monde.h
 */

#ifndef MONDE_H_INCLUDED
#define MONDE_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
using namespace std;


#include "Zone.h"

/**
 * Classe délimitant les différentes partie de l'Univers
 * @brief Classe gérant les différents Mondes d'un Univers.
 * @author Sarkis Mouradian
 */

class Monde
{
    private:

        /**
        * Numéro du Monde
        */

        int _idMonde;

        /**
        * Nom du Monde
        */

        std::string _nomMonde;

        /**
        * Tableau de Zone
        */
        std::vector <Zone> _zone;


    public:
        /**
        * Retourner le numéro d'identité du Monde
        */

        int getIdMonde() { return _idMonde;}

        /**
        * Modifie le numéro d'identité du Monde
        */

        void setIdMonde(int idMonde) { _idMonde = idMonde;}

        /**
        * Retourne le nom du Monde
        */

        std::string getNomMonde() const { return _nomMonde;}

        /**
        * Modifie le nom du Monde
        */

        void setNomMonde(std::string nomMonde) { _nomMonde = nomMonde;}

        /**
        * Ajoute une Zone
        */
        void addZone(const Zone &zone);
        /**
         * Renvoie le nombre de zones
         */
         int nbZones() const
         {
             return _zone.size();
         }

        /**
         * Renvoie la derniere zone
         */
        inline Zone& dernier()
        {
            return _zone.back();
        }


        /**
        * Renvoie une zone en fonction de son numéro. Surchargée constante
        */
        inline Zone& getZone(int n) throw(std::string)
        {
            if (n < 0 || n >= (int)_zone.size() )
            {
                throw(std::string("Erreur, demande d'accès à une zone non existant"));
            }
            return _zone[n];
        }

        /**
          *Renvoie le nombre de zone present dans le monde (MAJ alexandre 10/05)
          */
        inline int getNbZones(){

            return _zone.size();
        }
        /**
          * Renvoie l'id d'une zone en fonction de son nom
          * TODO: changer le vector par un std::map.
          */
        int idZone(std::string nom)
        {
            for (unsigned int i = 0; i < _zone.size(); i++)
            {
                if (_zone[i].getNomZone() == nom)
                {
                    return i;
                }
            }
            return -1;
        }
};


#endif // MONDE_H_INCLUDED
