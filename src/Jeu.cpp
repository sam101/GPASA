/**
 * Projet tutoré. 2010-2011.
 * src/Jeu.cpp
 */
#include "Jeu.h"
/**
  * Constructeur par défaut de l'objet
  */
Jeu::Jeu() :
_enCours(false),
_u(NULL),
_h(NULL),
_chargeur(NULL),
_selectionneur(NULL)
{

}
/**
 * Constructeur de l'objet avec un nom d'univers.
 * Lance une partie de l'univers donné en paramètres
 * @param nomUnivers Nom de l'univers à charger et à lancer
 */
Jeu::Jeu(const std::string &nomUnivers) :
_enCours(false),
_u(NULL),
_h(NULL),
_chargeur(NULL),
_selectionneur(NULL)

{
    load(nomUnivers);
}
/**
  * Destructeur
  */
Jeu::~Jeu()
{
    if (_u != NULL)
    {
        delete _u;
    }
    if (_h != NULL)
    {
        delete _h;
    }
    if (_chargeur != NULL)
    {
        delete _chargeur;
    }
    if (_selectionneur != NULL)
    {
        delete _selectionneur;
    }
}
/**
  * Charge un univers et crée une nouvelle partie,
  * vide.
  */
void Jeu::load(const std::string &nomUnivers)
{
    _enCours = true;
    //On crée l'objet univers
    _u = new Univers(nomUnivers);
    //On crée l'objet héros
    _h = new Heros;
    //On crée l'objet chargeur
    _chargeur = new Chargeur(nomUnivers);
    _chargeur->charger(_u);
    //On crée l'objet selectionneur
    _selectionneur = new Selectionneur(_u);
}
/**
  * Définis le nom du héros.
  * Ceci est généralement fait en début de partie, avant que la partie commence
  * @param nomHeros Nom à donner au héros.
  */
void Jeu::setNomHeros(const std::string &nomHeros) throw(std::string)
{
    if (_enCours)
    {
        _h->setNomHeros(nomHeros);
    }
    else
    {
        throw(std::string("Tentative de changer le nom du héros dans un jeu non commencé"));
    }
}
/**
  * Définit le prénom du héros
  */
void Jeu::setPrenomHeros(const std::string &prenomHeros) throw(std::string)
{
    if (_enCours)
    {
        _h->setPrenomHeros(prenomHeros);
    }
    else
    {
        throw(std::string("Tentative de changer le nom du héros dans un jeu non commencé"));
    }
}
/**
  * Définit l'age du héros
  */
void Jeu::setAgeHeros(int age) throw(std::string)
{
    if (_enCours)
    {
        _h->setAgeHeros(age);
    }
    else
    {
        throw(std::string("Tentative de changer l'age du héros dans un jeu non commencé"));
    }
}
/**
  * Commence la partie
  */
void Jeu::commencer()
{
    //On indique que la partie est commencée
    _commencee = true;
    //On définit les monde/zone/question de départ
    _h->setMonde(_u->getMondeDepart());
    _h->setZone(_u->getZoneDepart());
    _h->setQuestion(_u->getQuestionDepart());

}
/**
  * Renvoie l'objet héros
  */
Heros* Jeu::heros()
{
    return _h;
}
/**
  * Renvoie l'objet héros.
  * Surchargé constant
  */
const Heros* Jeu::heros() const
{
    return _h;
}
/**
  * Renvoie le nom du monde courant
  */
std::string Jeu::mondeCourant() const throw(std::string)
{
    if (!_enCours) throw(std::string("Partie non commencée"));
    return _h->getMonde();
}
/**
 * Renvoie le nom de la zone courante
 */
std::string Jeu::zoneCourante() const throw(std::string)
{
    if (!_enCours) throw(std::string("Partie non commencée"));
    return _h->getZone();
}
/**
  * Renvoie l'intitulé de la question courante
  */
std::string Jeu::questionIntCourante() const throw(std::string)
{
    if (!_enCours) throw(std::string("Partie non commencée"));
    Monde &m = _u->getMonde(_u->idMonde(_h->getMonde()));
    Zone &z = m.getZone(m.idZone(_h->getZone()));

    return z.getQuestion(z.idQuestion(_h->getQuestion())).getIntituleQuest();
}
/**
  * Renvoie les propositions courrantes
  */
std::vector<Proposition> Jeu::propositions() const throw(std::string)
{
    if (!_enCours) throw(std::string("Partie non commencée"));
    Monde &m = _u->getMonde(_u->idMonde(_h->getMonde()));
    Zone &z = m.getZone(m.idZone(_h->getZone()));

    return z.getQuestion(z.idQuestion(_h->getQuestion())).getPropositions();
}
/**
  * Répond à la question actuellement posée
  */
void Jeu::repondre(int numeroProposition) throw(std::string)
{
    if (!_enCours || !_commencee )
    {
        throw(std::string("La partie n'est pas commencée"));
    }
    _selectionneur->prochaine(numeroProposition,_h);
}
