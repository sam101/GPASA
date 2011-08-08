/**
 * Projet tutoré. 2010-2011.
 * src/Zone.cpp
 */

#include "Zone.h"
#include "Random.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/**
* Constructeur de Zone avec en paramettre un numéro de Zone en int et un nom de Zone en string
*/
Zone::Zone (int idZone , string nomZone)
{
    _idZone = idZone;
    _nomZone = nomZone;
}

/**
* Methode addQuestion permettant d'ajouter une Question au tableau de Question _questions
*/
void Zone::addQuestion(const Question & question)
{
    _questions.push_back(question); // permet dajouter un element dans le tableau , pour connaitre la taille du tableau faire tableau.size();
    // le "chargeur" de question se débrouille pour trouver les questions adéquates a rajouté au tableau de Question

}
/**
* Retourne la question a l'indice i du tableau
*/
Question& Zone::getQuestion(int indice)throw(string )
{
    if(indice < 0 || indice >= (int)_questions.size())// on caste .size() en int car il renvoie un unsigned int
    {
        throw(string("indice en-dehors du tableau "));
    }
    return _questions[indice];
}
/**
  * Renvoie une question selectionnée aléatoirement
  */
int Zone::questionAleatoire() const throw(std::string)
{
    if (_questions.size() == 0)
    {
        throw(std::string("Pas de questions dans la zone"));
    }
    return Random::next(0,_questions.size());
}
