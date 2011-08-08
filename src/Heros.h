/**
 * Projet tutoré. 2010-2011.
 * src/Heros.h
 */
#ifndef HEROS_H_
#define HEROS_H_
#include <string>
/**
 * Classe gérant les caractéristiques du héros
 * @brief Gère les caractéristiques du héros.
 * @author Maxime Lefèvre
 */
class Heros
{
    private :

        /**
         * Nom et prénom du Héros.
         */
        std::string _nomHeros, _prenomHeros;

        /**
         * Âge, point de vie, de magie et endurance du Héros.
         */
        int _ageHeros, _vieHeros, _manaHeros, _enduranceHeros;
        /**
          * Monde dans laquel se trouve le héros
          */
        std::string _monde;
        /**
          * Zone dans laquelle se trouve le héros
          */
        std::string _zone;
        /**
          * Question actuellement posée au héros
          */
        std::string _question;
        /**
          * Points actuels du héros
          */
        int _points;


    public :
        /**
         * Constructeur sans paramètre du Héros.
         */
        Heros(std::string nomHeros = "");

        /**
        * Renvoie le nom du Héros
        */
        std::string nomHeros()const;

        /**
         * Renvoie le prénom du Héros.
         */
        std::string prenomHeros()const;

        /**
         * Renvoie l'âge du Héros.
         */
        int ageHeros()const;

        /**
         * Renvoie le nombre de points de vie du Héros.
         */
        int vieHeros()const;

        /**
         * Renvoie le nombre de points de magie du Héros.
         */
        int manaHeros()const;

        /**
         * Renvoie l'endurance du Héros.
         */
        int enduranceHeros()const;

        /**
         * Renvoie le monde où se trouve le Héros.
         */
        std::string getMonde()const;

        /**
         * Renvoie la zone où se trouve le Héros.
         */
        std::string getZone()const;

        /**
         * Renvoie la question.
         */
        std::string getQuestion()const;

        /**
          * Renvoie les points du héros
          */
        int getPoints() const
        {
            return _points;
        }

        /**
          * Remet à zéro les points du héros
          */
       void resetPoints()
       {
           _points = 0;
       }

        /**
         * Définit le nom du Héros.
         */
        void setNomHeros(const std::string &nomHeros);

        /**
         * Définit le prénom du Héros.
         */
        void setPrenomHeros(const std::string &prenomHeros);

        /**
         * Définit l'âge du Héros.
         */
        void setAgeHeros(const int &ageHeros);

        /**
         * Définit les points de vie du Héros.
         */
        void setVieHeros(const int &vieHeros);

        /**
         * Définit les points de mana du Héros.
         */
        void setManaHeros(const int &manaHeros);

		/**
         * Définit l'endurance du Héros.
         */
        void setEnduranceHeros(const int &enduranceHeros);

        /**
         * Définit le monde du Héros
         */
        void setMonde(const std::string &monde);

        /**
         * Définit la zone du Héros.
         */
        void setZone(const std::string &zone);

        /**
         * Définit la question.
         */
        void setQuestion(const std::string &question);

        /**
         * Définit les points du héros
         */
        void setPoints(int points)
        {
            _points = points;
        }
        /**
          * Ajoute des points au héros
          */
        void addPoints(int points)
        {
            _points += points;
        }
        /**
          * Enlève des points au héros
          */
        void delPoints(int points)
        {
            _points -= points;
        }
};

#endif
