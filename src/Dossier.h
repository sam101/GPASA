/**
 * Projet tutoré. 2010-2011.
 * src/Dossier.h
 */
#ifndef DOSSIER_H_
#define DOSSIER_H_
#include <string>
#include <dirent.h>
/**
 * Gère la gestion des dossiers de façon portable et orientée objet.
 * @brief Gère la gestion des dossiers
 * Necessaire pour l'utilisation de "Chargeur".
 * Il est a noter que cette implémentation ne supporte que les compilateurs supportant la norme
 * POSIX "dirent.h".
 * @author Samuel Lepetit
 */
class Dossier
{
    private:
        /**
          * Indique si un dossier est actuellement ouvert
          */
        bool _isOpen;
        /**
          * Pointeur vers le répertoire actuel
          */
        DIR *_dir;
        /**
          * Indique si le fichier actuel a déjà été lu
          */
        bool _hasBeenRead;
        /**
          * Fichier courrant
          */
          struct dirent *_courrant;
        /**
          * Empêche de faire une copie de l'objet Dossier
          */
          Dossier(const Dossier&)
          {
          }
    public:
        /**
          * Constructeur par defaut
          * n'ouvre pas de dossier
          */
        Dossier();
        /**
          * Constructeur prenant en paramètres le nom du dossier
          * à ouvrir. Envoie une exception si le chemin n'existe pas
          * @param path Nom du dossier à ouvrir
          */
        Dossier(const std::string &path) throw(std::string);
        /**
          * Destructeur
          */
        virtual ~Dossier();
        /**
         * Tente d'ouvrir un dossier. Renvoie "false" si le dossier n'a pas pu être ouvert
         */
        bool open(const std::string &path);
        /**
         * Tente d'ouvrir un dossier. Lance une exception si le dossier n'a pas pu être ouvert.
         */
        void openT(const std::string &path) throw(std::string);
        /**
         * Renvoie si un dossier est actuellement ouvert
         */
        bool isOpen() const;
        /**
          * Ferme le dossier actuellement ouvert
          */
        void close();
        /**
          * Renvoie si il y'a encore un fichier à lire
          */
        bool hasNext();
        /**
         * Renvoie le nom du prochain fichier contenu dans le dossier
         * Lance une exception si il n'y a pas de suivant.
         */
        std::string next() throw(std::string);
};
#endif
