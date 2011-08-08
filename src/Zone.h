/**
 * Projet tutoré. 2010-2011.
 * src/Zone.h
 */

#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED
#include <string>
#include <vector>
#include "Question.h"

/**
 * Classe délimitant les différentes partie de la classe Monde
 * @brief Classe gérant les différentes Zones d'un Monde
 * @author Sarkis Mouradian
 */

class Zone
{
    private:

        /**
        * Numéro d'identité unique à chaque zone.
        */
        int _idZone;

        /**
        * Nom de la zone.
        */

        std::string _nomZone;

        /**
        * Tableau de Question
        */

        std::vector<Question> _questions;

    public:

        /**
        * Constructeur de Zone avec en paramettre un numéro de Zone en int et un nom de Zone en string
        */
        Zone (int idZone , std::string nomZone);

        /**
        * Methode addQuestion permettant d'ajouter une Question au tableau de Question _questions
        */
        void addQuestion(const Question & question);

        /**
        * Retourner le numéro d'identité de la zone
        */
        int getIdZone() { return _idZone;}

        /**
        * Modifie le numéro d'identité de la zone
        */
        void setIdZone(int idZone) { _idZone = idZone;}

        /**
        * Retourne le nom de la Zone
        */

        std::string getNomZone() { return _nomZone;}

        /**
        * Modifie le nom de la Zone
        */
        void setNomZone(std::string nomZone) { _nomZone = nomZone;}

        /**
        * Retourne la question a l'indice i du tableau
        */
         Question& getQuestion(int indice) throw(std::string);

         /**
           *Retourne le nombre de question dans la zone
           */
         inline int getNbQuestion(){

             return _questions.size();
         }
        /**
          * Renvoie l'id d'une question en fonction de son nom
          * TODO: changer le vector par un std::map.
          */
        int idQuestion(std::string nom)
        {
            for (unsigned int i = 0; i < _questions.size(); i++)
            {
                if (_questions[i].getNom() == nom)
                {
                    return i;
                }
            }
            return -1;
        }
        /**
          * Renvoie une question selectionnée aléatoirement
          */
        int questionAleatoire() const throw(std::string);

};


#endif // ZONE_H_INCLUDED
