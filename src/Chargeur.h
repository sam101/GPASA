/**
 * Projet tutoré. 2010-2011.
 * src/Chargeur.h
 */
#ifndef CHARGEUR_H_
#define CHARGEUR_H_
#include "Dossier.h"
#include "Univers.h"
#include <string>
/**
 * Classe s'occupant de charger les divers éléments de jeu
 * @brief S'occupe de charger les divers éléments de jeu
 * @author Samuel Lepetit / Alexandre Lopes-Meda
 */
class Chargeur
{
    private:
        /**
         * Nom de l'univers à charger
         */
        std::string _nom;
        /**
         * Chemin de base où chercher les univers
         */
         std::string _path;

         /**
          * Empêche de faire une copie de l'objet chargeur
          */
          Chargeur(const Chargeur&)
          {

          }
    public:
        /**
         * Constructeur par defaut
         */
        Chargeur();
        /**
         * Constructeur prenant en paramètre le nom de l'univers
         * @param nom Nom de l'univers à charger
         */
        Chargeur(std::string nom);

        /**
         * Charge les différantes informations de l'univers courant (stocké dans "nom").
         * @param u Objet univers dans lequel placer les informations.
         */
        void charger(Univers *u) throw(std::string);

        /**
         * Charge les différantes informations de l'univers passé en paramètre.
         * @param u Objet univers dans lequel placer les informations.
         */
        void charger(Univers *u, std::string nom) throw(std::string);


};
#endif
