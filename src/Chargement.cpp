/**
 * Projet tutoré. 2010-2011.
 * src/Chargement.cpp
 */
#include "Chargement.h"
#include "../Random.h"

#include <fstream>

using namespace std;
/**
  * Constructeur
  */
Chargement::Chargement(Heros *h, const std::string &nomFichier) :
_h(h),
_nomFichier(nomFichier)
{

}
/**
  * Charge le fichier déjà enregistré
  */
void Chargement::charger() throw(std::string)
{
    charger(_nomFichier);
}
/**
  * Charge un fichier
  * @param nomFichier Chemin vers le fichier à charger
  */
void Chargement::charger(const std::string &nomFichier)
{
    _nomFichier = nomFichier;
    /* On ouvre le fichier */
    fstream f(nomFichier.c_str(), ios::in);
    //On teste le cas d'erreur
    if (!f)
    {
        throw(std::string("Le fichier n'existe pas !"));
    }
    //On recupère la seed
    int seed, state;
    f >> seed;
    f >> state;
    Random::init(seed,state);
    //On recupère les informations du héros
    std::string buffer;
    int bufferInt;

    f >> buffer;
    getline(f,buffer);
    f >> buffer;
    getline(f,buffer);
    f >> bufferInt;
    _h->setAgeHeros(bufferInt);
    f >> bufferInt;
    _h->setVieHeros(bufferInt);
    f >> bufferInt;
    _h->setManaHeros(bufferInt);
    f >> bufferInt;
    _h->setEnduranceHeros(bufferInt);
    getline(f,buffer);
    _h->setMonde(buffer);
    getline(f,buffer);
    _h->setZone(buffer);
    getline(f,buffer);
    _h->setQuestion(buffer);
    f >> bufferInt;
    _h->setPoints(bufferInt);
    /* On ferme le fichier */
    f.close();

}
