/**
 * Projet tutoré. 2010-2011.
 * src/Proposition.cpp
 */

#include "Proposition.h"
#include <string>

using namespace std;

/**
  * Constructeur
  */
Proposition::Proposition() :
    _libelleProposition(""),
    _pointProposition(0),
_nbPointsMin(0),
_nbPointsMax(0),
_lienMonde("")
{

}
/**
 * Constructeur avec paramètre d'une proposition
 * @param libelleProposition l'intitule de la proposition
 * @param pointProposition la valeur de la proposition
 * @param lienZone le numero de zone pointée par cette proposition
 * @param lienMonde le monde pointée par cette proposition
 */

/**
  * Destructeur
  */
Proposition::~Proposition()
{

}

/**
 * Renvoie le libellé de la proposition
 */
string Proposition::getLibelleProp()
{

    return _libelleProposition;
}

/**
 * Renvoie  la valeur en point de la proposition
 */
int Proposition::getPointProp()
{

    return _pointProposition;
}


/**
 * Renvoie le nom de zone pointée par n
 */
 const std::string& Proposition::getLienZone(int n) const
 {

    return _liensZones[n];
}

/**
 * Renvoie le nom du monde pointé par la proposition
 */
std::string Proposition::getLienMonde()
{
    return _lienMonde;
}

/**
 * renvoie le nombre de lien zone de la proposition
 */

int Proposition::nbliensZones()
{
    return _liensZones.size();
}
