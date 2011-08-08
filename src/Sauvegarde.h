/**
 * Projet tutoré. 2010-2011.
 * src/Sauvegarde.h
 */
#ifndef SAUVEGARDE_H_
#define SAUVEGARDE_H_
#include <string>

#include "Heros.h"
/**
  * Classe permettant la sauvegarde de l'état actuel d'une partie
  * @brief Permet la sauvegarde de l'état actuel d'une partie
  * @author ?
  */
class Sauvegarde
{
    private:
        /**
          * Pointeur vers le héros
          */
        Heros *_h;
        /**
          * Nom du fichier
          */
        std::string _nomFichier;

    public:
        Sauvegarde(Heros *h, const std::string &nomFichier);

        void sauvegarder() throw(std::string);
        void sauvegarder(const std::string &nomFichier) throw(std::string);
};
#endif
