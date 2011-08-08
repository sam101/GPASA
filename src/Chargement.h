/**
 * Projet tutoré. 2010-2011.
 * src/Chargement.h
 */
#ifndef CHARGEMENT_H
#define CHARGEMENT_H
#include <string>

#include "Heros.h"

/**
  * Gère le chargement d'une sauvegarde
  * @brief Gère le chargement d'une sauvegarde
  * @author Samuel Lepetit
  */
class Chargement
{
    protected:
        /**
          * Pointeur vers le héros
          */
        Heros *_h;
        /**
          * Nom du fichier
          */
        std::string _nomFichier;
    public:
        Chargement(Heros *h, const std::string &nomFichier);

        void charger() throw(std::string);
        void charger(const std::string &nomFichier);
};

#endif // CHARGEMENT_H
