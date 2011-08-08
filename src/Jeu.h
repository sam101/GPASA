/**
 * Projet tutoré. 2010-2011.
 * src/Jeu.h
 */
#ifndef JEU_H_
#define JEU_H_
#include "Univers.h"
#include "Heros.h"
#include "Chargeur.h"
#include "Selectionneur.h"
/**
 * Classe gérant et contenant toutes les données de jeu,
 * faisant la glue entre toutes les classes
 * @brief Classe gérant les donnes de jeu
 * @author Samuel Lepetit / Maxime Lefèvre / Alexandre Lopes-Meda / Sarkis Mouradian
 */
class Jeu
{
    private:
        /**
          * Indique si une partie est en cours
          */
        bool _enCours;
        /**
          * Indique si une partie est actuellement commencée
          */
        bool _commencee;
        /**
          * Univers actuel dans la partie
          */
        Univers *_u;
        /**
         * Heros actuel
         */
         Heros *_h;
         /**
          * Chargeur actuel
          */
          Chargeur *_chargeur;
          /**
           * Selectionneur actuel
           */
           Selectionneur *_selectionneur;
           /**
            * Empêche la copie d'un objet jeu
            */
            Jeu(const Jeu&)
            {

            }
    public:
    /**
      * Constructeur par défaut de l'objet
      */
        Jeu();
        /**
         * Constructeur de l'objet avec un nom d'univers.
         * Lance une partie de l'univers donné en paramètres
         * @param nomUnivers Nom de l'univers à charger et à lancer
         */
        Jeu(const std::string &nomUnivers);
        /**
          * Destructeur
          */
        ~Jeu();
        /**
          * Charge un univers et crée une nouvelle partie,
          * vide.
          */
        void load(const std::string &nomUnivers);
        /**
          * Définis le nom du héros.
          * Ceci est généralement fait en début de partie, avant que la partie commence
          * @param nomHeros Nom à donner au héros.
          */
        void setNomHeros(const std::string &nomHeros) throw(std::string);
        /**
          * Définit le prénom du héros
          */
        void setPrenomHeros(const std::string &nomHeros) throw(std::string);
        /**
          * Définit l'age du héros
          */
        void setAgeHeros(int age) throw(std::string);

        /**
          * Commence la partie
          */
        void commencer();
        /**
          * Renvoie l'objet héros
          */
        Heros* heros();
        /**
          * Renvoie l'objet héros.
          * Surchargé constant
          */
        const Heros* heros() const;
        /**
          * Renvoie le nom du monde courrant
          */
        std::string mondeCourant() const throw(std::string);
        /**
          * Renvoie le nom de la zone courante
          */
        std::string zoneCourante() const throw(std::string);
        /**
          * Renvoie l'intitulé de la question courante
          */
        std::string questionIntCourante() const throw(std::string);
        /**
          * Renvoie les propositions courrantes
          */
        std::vector<Proposition> propositions() const throw(std::string);

        /**
          * Répond à la question actuellement posée
          */
        void repondre(int numeroProposition) throw(std::string);
};
#endif
