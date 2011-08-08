/**
 * Projet tutoré. 2010-2011.
 * src/Selectionneur.cpp
 */
#include "Selectionneur.h"
#include "Random.h"

#include <iostream>

using namespace std;
/**
  * Constructeur, prend en paramètre l'univers que le selectionneur
  * devra utiliser
  * @param u Univers à utiliser.
  */
Selectionneur::Selectionneur(Univers *u)
{
    _u = u;
}

/**
  * Selectionne la prochaine question posée au héros en fonction
  * de la réponse donnée
  */
void Selectionneur::prochaine(int indiceReponse, Heros *h) throw(std::string)
{
    prochaine(indiceReponse, h,_u);
}

/**
  * Selectionne la prochaine question posée au héros.
  * Surchargé, demande l'univers.
  */
void Selectionneur::prochaine(int indiceReponse, Heros *h, Univers *u) throw(std::string)
{
    int mondeActuel, zoneActuelle, questionActuelle;
    int mondeEnsuite, zoneEnsuite, questionEnsuite;
    //On recupère d'abord les éléments actuels.
    mondeActuel = u->idMonde(h->getMonde());
    if (mondeActuel == -1)
    {
        throw(std::string("Selectionneur::prochaine: Erreur de cohérence"));
    }
    zoneActuelle = u->getMonde(mondeActuel).idZone(h->getZone());
    if (zoneActuelle == -1)
    {
        throw(std::string("Selectionneur::prochaine: Erreur de cohérence"));
    }
    questionActuelle = u->getMonde(mondeActuel).getZone(zoneActuelle).idQuestion(h->getQuestion());

    //On recupère l'objet vers la question actuelle
    Question &q = u->getMonde(mondeActuel).getZone(zoneActuelle).getQuestion(questionActuelle);
    //On recupère les propositions possibles.
    std::vector<Proposition>& p = q.getPropositions();
    //On traite le cas où la réponse répondue est complètement incohérente
    if (indiceReponse < 0 || indiceReponse >= (int)p.size())
    {
        throw(std::string("Selectionneur::prochaine:  Reponse répondue complètement incohérente"));
    }
    //On vérifie qu'on à bien le bon nombre de points pour chosir cette proposition.
    if ((h->getPoints() < p[indiceReponse].getPointMin() && p[indiceReponse].getPointMin() != 0)  ||  (h->getPoints() > p[indiceReponse].getPointMax() &&  p[indiceReponse].getPointMax() != 0))
    {
        cout << p[indiceReponse].getPointMin() << " " << p[indiceReponse].getPointMax() << " " << h->getPoints() << endl;
        throw(std::string("Selectionneur::prochaine: Le nombre de points requis n'est pas atteint ou est dépassé"));
    }
    //On regarde si il y'a un lien vers un autre monde. Si oui, le mondeEnsuite change.
    if (p[indiceReponse].getLienMonde() != "-1" && p[indiceReponse].getLienMonde() != "" )
    {
        //On change le monde actuel
        mondeEnsuite = u->idMonde(p[indiceReponse].getLienMonde());
        h->setMonde(p[indiceReponse].getLienMonde());
        if (mondeEnsuite == -1)
        {
            throw(std::string("Selectionneur::prochaine:Lienmonde incorrect"));
        }
        //On remet les points à zéro
        h->resetPoints();
    }
    else
    {
        mondeEnsuite = mondeActuel;
    }
    //On recupère les liens possibles vers les zones
    std::vector<std::string>& liens = p[indiceReponse].getLiensZones();

    //On gère le cas où la liste des liens est vide
    if (liens.size() == 0)
    {
        zoneEnsuite = zoneActuelle;
    }
    else
    {
        //On selectionne la prochaine zone
        h->setZone(liens[Random::next(0,liens.size())]);

        zoneEnsuite = u->getMonde(mondeEnsuite).idZone(h->getZone());
    }
    //On ajoute les points
    h->addPoints(p[indiceReponse].getPointProp());
    //On selectionne la prochaine question.
    questionEnsuite = u->getMonde(mondeEnsuite).getZone(zoneEnsuite).questionAleatoire();
    //On met à jour la question dans l'objet héros.
    h->setQuestion(u->getMonde(mondeEnsuite).getZone(zoneEnsuite).getQuestion(questionEnsuite).getNom());

}



