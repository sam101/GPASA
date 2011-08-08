/**
 * Projet tutoré. 2010-2011.
 * src/Dossier.cpp
 */
#include "Dossier.h"
#include <iostream>
using namespace std;

/**
  * Constructeur par defaut
  * n'ouvre pas de dossier
  */
Dossier::Dossier() :
_isOpen(false),
_dir(NULL),
_hasBeenRead(true)
{

}
/**
  * Constructeur prenant en paramètres le nom du dossier
  * à ouvrir. Envoie une exception si le chemin n'existe pas
  * @param path Nom du dossier à ouvrir
  */
Dossier::Dossier(const std::string &path) throw(std::string) :
_isOpen(false),
_dir(NULL),
_hasBeenRead(true)
{
    open(path);
}
/**
 * Destructeur
 */
Dossier::~Dossier()
{
    if (_isOpen)
    {
        close();
    }
}
/**
 * Tente d'ouvrir un dossier. Renvoie "false" si le dossier n'a pas pu être ouvert
 */
bool Dossier::open(const std::string &path)
{
    _dir = opendir(path.c_str());
    if (_dir != NULL)
    {
        _isOpen = true;
        _hasBeenRead = true;
        return true;
    }
    return false;
}
/**
 * Tente d'ouvrir un dossier. Lance une exception si le dossier n'a pas pu être ouvert.
 */
void Dossier::openT(const std::string &path) throw(std::string)
{
    _dir = opendir(path.c_str());
    if (_dir == NULL)
    {
        throw(std::string("Dossier::openT: Dossier" + path + " introuvable"));
    }
    _isOpen = true;
    _hasBeenRead = true;
}
/**
 * Renvoie si un dossier est actuellement ouvert
 */
 bool Dossier::isOpen() const
 {
     return _isOpen;
 }
/**
  * Ferme le dossier actuellement ouvert
  */
void Dossier::close()
{
    if (_isOpen)
    {
        closedir(_dir);
    }
}
/**
  * Renvoie si il y'a encore un fichier à lire
  */
bool Dossier::hasNext()
{
    if (!_hasBeenRead)
    {
        return true;
    }
    if ((_courrant = readdir(_dir)))
    {
        _hasBeenRead = false;
        return true;
    }
    return false;
}
/**
 * Renvoie le nom du prochain fichier contenu dans le dossier
 * Lance une exception si il n'y a pas de suivant.
 */
std::string Dossier::next() throw(std::string)
{
    if (!_hasBeenRead)
    {
        _hasBeenRead = true;
        return _courrant->d_name;
    }
    else
    {
        if ((_courrant = readdir(_dir)))
        {
            _hasBeenRead = true;
            return _courrant->d_name;
        }
        else
        {
            throw(std::string("Dossier::next: Erreur, pas de fichier dans le dossier"));
        }
    }
}
