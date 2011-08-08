/**
 * Projet tutoré. 2010-2011.
 * src/Question.h
 */

#ifndef QUESTION_H_
#define QUESTION_H_

#include "Proposition.h"
#include <vector>
#include <string>

/**
  * Gère les caractéristiques d'une question
  * @brief Gère les caractéristiques d'une question
  * @author Bonne question.
  */
class Question
{

	private:
        /**
          * Nom de la question
          */
        std::string _nom;
        /**
         * Contient l'intitulé de la question
         */
        std::string _intitule;

        /**
         * Contient l'ensemble des propositions
         */
        std::vector<Proposition> _tabProp;

        /**
        * Taille effective du tableau de propositions
        */
        int _nbProp;

	public:

        /**
        *Constructeur avec paramètres d'une question
        *Prend l'intitulé d'une question en paramètre
        */

        Question(std ::string _intitule="");
        /**
          * Renvoie le nom de la question
          */
        std::string getNom() const
        {
            return _nom;
        }
        /**
        * Renvoie l'intitulé de la question
        */
        inline std::string getIntituleQuest() const
        {
            return _intitule;
        }

        /**
         * Change l'intitulé dune question
         */
        inline void setIntituleQuest(std::string intitule){_intitule=intitule;}

        /**
        * Renvoie le nombre de proposition de la question
        */
        inline int getnbProp() const
        {
            return _nbProp;
        }
       /**
        * Renvoie la liste des propositions.
        */
        std::vector<Proposition>& getPropositions()
        {
            return _tabProp;
        }
        /**
        * Renvoie la liste des propositions.
        * Surchargé constant.
        */
        const std::vector<Proposition>& getPropositions() const
        {
            return _tabProp;
        }
        /**
          * Change le nom de la question
          */
        void setNom(std::string nom)
        {
            _nom = nom;
        }
        /**
         * Ajoute une proposition dans le tableau.
         */
         void addProp(const Proposition &prop)
         {
             _tabProp.push_back(prop);
             _nbProp+=1;
         }

        /**
        * Renvoie une proposition en fonction de son numéro. Surchargée constante
        */
        inline Proposition& getProp(int n) throw(std::string)
        {
            if (n < 0 || n >= (int)_tabProp.size() )
            {
                throw(std::string("Erreur, demande d'accès à une proposition non existante"));
            }
            return _tabProp[n];
        }




};

#endif
