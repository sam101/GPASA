/**
 * Projet tutoré. 2010-2011.
 * src/Selectionneur.h
 */
#ifndef SELECTIONNEUR_H_
#define SELECTIONNEUR_H_
#include "Univers.h"
#include "Heros.h"
/**
 * Classe s'occupant de selectionner les mondes/zones dans lequel le joueur va se trouver,
 * ainsi que les questions qui vont lui être posées
 * @brief Selectionne la prochaine question posée au héros.jjju
 * @author Samuel Lepetit
 */
class Selectionneur
{
    private:
        /**
         * Univers dans lequel sélectionner
         */
        Univers *_u;

    public:
        /**
          * Constructeur, prend en paramètre l'univers que le selectionneur
          * devra utiliser
          * @param u Univers à utiliser.
          */
        Selectionneur(Univers *u);

        /**
          * Selectionne la prochaine question posée au héros
          */
        void prochaine(int indiceReponse, Heros *h) throw(std::string);

        /**
          * Selectionne la prochaine question posée au héros.
          * Surchargé, demande l'univers.
          */
        void prochaine(int indiceReponse, Heros *h, Univers *u) throw(std::string);


};
#endif
