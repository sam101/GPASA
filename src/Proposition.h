/**
 * Projet tutoré. 2010-2011.
 * src/Proposition.h
 */

#ifndef PROPOSITION_H_
#define PROPOSITION_H_

#include <string>
#include <vector>

/**
 * Définit les propositions des questions
 * @brief Gère les caractéristiques des propositions.
 * @author Alexandre LOPES MEDA
 */

class Proposition
{

	private:
        /**
         * l'intitulé de la proposition
         */
        std::string _libelleProposition;

        /**
         * la valeur de la proposition
         */
        int _pointProposition;

        /**
         * Point minimum pour avoir cette proposition
         */
        int _nbPointsMin;

        /**
         * Point minimum pour avoir cette proposition
         */
        int _nbPointsMax;

        /**
         * numero du monde pointée par la proposition
         */
        std::string _lienMonde;


        /**
         * noms des zones pointée par la proposition
         */
        std::vector<std::string> _liensZones;

        /**
          * Reponse à la question
          */
        std::string _reponse;

	public:
        /**
          * Constructeur
          */
        Proposition();
        /**
        * Constructeur avec paramètre d'une proposition
        * @param libelleProposition l'intitule de la proposition
        * @param pointProposition la valeur de la proposition
        * @param lienMonde le monde pointée par cette proposition
        */
        Proposition(std::string libelleProposition, int pointProposition = 0, std::string lienMonde = "", std::string reponse = "") :
        _libelleProposition(libelleProposition),
        _pointProposition(pointProposition),
         _lienMonde(lienMonde),
        _reponse(reponse)
        {

        }

        /**
          * Destructeur
          */
        virtual ~Proposition();

        /**
         * retourne l'intitulé de la proposition
         */
       std::string getLibelleProp();

        /**
         * retourne la valeur en point de la proposition
         */
        int getPointProp();
        /**
          * Retourne la liste des zones
          */
        std::vector<std::string>& getLiensZones()
        {
            return _liensZones;
        }
        /**
         * Retourne le lien zone d'indice n
         */
        const std::string& getLienZone(int n) const;

        /**
         * retourne le nom du monde pointé par la proposition
         */
        std::string getLienMonde();

        /**
         * change l'intitulé de la proposition
         */
        void setLibelleProp(std::string libelleProposition)
        {
            _libelleProposition = libelleProposition ;
        }

        /**
         * change la valeur en point de la proposition
         */
        void setPointProp(int point)
        {
            _pointProposition = point;
        }

        /**
         * ajoute un lien vers une zone
         */

        void addLienZone(std::string lienZone)
        {
            _liensZones.push_back(lienZone);
        }

        /**
         * change la valeur du lien vers le monde
         */
        void setLienMonde(std::string lienMonde)
        {
            _lienMonde = lienMonde;
        }

        /**
         *Mise en place du nombre de point minimum
         */
        void setPointMin(int n)
        {
            _nbPointsMin=n;

        }

        /**
         *Mise en place du nombre de point maximum
         */
        void setPointMax(int n)
        {
            int tmp;
            if (n < _nbPointsMin)
            {
                tmp = _nbPointsMin;
                _nbPointsMin = n;
                _nbPointsMax = tmp;
            }
            else
            {
                _nbPointsMax=n;
            }
        }

        /**
         *retourne le  nombre de point minimum
         */
        int getPointMin()
        {
           return  _nbPointsMin;

        }

        /**
         *retourne le  nombre de point maximum
         */
        int getPointMax()
        {
           return  _nbPointsMax;
        }

        /**
         * renvoie le nombre de lien zone de la proposition
         */
        int nbliensZones();
        /**
          * Renvoie la réponse donnée quand on a choisi la proposition.
          */
        std::string getReponse() const
        {
            return _reponse;
        }
        /**
          * Définit la réponse donnée quand on a choisi la proposition.
          */
        void setReponse(const std::string &rep)
        {
            _reponse = rep;
        }


};
#endif
