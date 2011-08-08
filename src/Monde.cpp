/**
 * Projet tutoré. 2010-2011.
 * src/Monde.cpp
 */


#include "Monde.h"

using namespace std;

/**
  * Ajoute une zone au monde
  * @param zone Zone à ajouter au monde
  */
void Monde::addZone(const Zone &zone)
{
    _zone.push_back(zone);
}
