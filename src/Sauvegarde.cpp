/**
 * Projet tutoré. 2010-2011.
 * src/Sauvegarde.cpp
 */
#include "Sauvegarde.h"
#include "Random.h"

#include <fstream>

using namespace std;
/**
  * Constructeur
  */
Sauvegarde::Sauvegarde(Heros *h, const std::string &nomFichier) :
_h(h),
_nomFichier(nomFichier)
{

}
/**
  * Déclenche la sauvegarde.
  */
void Sauvegarde::sauvegarder() throw(std::string)
{
    sauvegarder(_nomFichier);
}

/**
  * Déclenche la sauvegarde éffective
  */
void Sauvegarde::sauvegarder(const std::string &nomFichier) throw(std::string)
{
    _nomFichier = nomFichier;
    /* On sauvegarde la seed */
    int seed = Random::getSeed();
    /* On sauvegarde le state */
    int state = Random::getState();
    /* On ouvre le fichier */
    fstream f(nomFichier.c_str(), ios::out | ios::trunc);

    if (!f)
    {
        throw(std::string("Erreur: Le fichier n'a pas pu être ouvert"));
    }
    /* On sauvegarde les informations sur Random */
    f << seed;
    f << state << "\n";
    /* On sauvegarde les informations sur le héros */
    f << _h->nomHeros() << '\n';
    f << _h->prenomHeros() << '\n';
    f << _h->ageHeros() << '\n';
    f << _h->vieHeros() << '\n';
    f << _h->manaHeros() << '\n';
    f << _h->enduranceHeros() << '\n';
    f << _h->getMonde() << '\n';
    f << _h->getZone() << '\n';
    f << _h->getQuestion()  << '\n';
    f << _h->getPoints()  << '\n';
    /* On ferme le fichier */
    f.close();

}
