/**
 * Projet tutoré. 2010-2011.
 * src/Univers.h
 */
#ifndef UNIVERS_H_
#define UNIVERS_H_
#include <string>
#include "Monde.h"
/**
 * Classe contenant tout le contenu d'un univers
 * @brief Contient tout le contenu d'un univers
 * @author Samuel Lepetit / Sarkis Mouradian
 */
class Univers
{
    private:
        /**
         * Nom de l'univers
         */
         std::string _nom;
        /**
         * Contient la liste des mondes
         */
        std::vector<Monde> _mondes;
        /**
          * Monde de départ
          */
        std::string _mondeDepart;
        /**
          * Zone de départ
          */
        std::string _zoneDepart;
        /**
          * Question de départ
          */
        std::string _questionDepart;
    public:
        /**
          * Constructeur, prend le nom de l'univers en paramètre
          */
        Univers(std::string nom = "");

        /**
        * Renvoie le nom de l'univers
        */
        inline std::string getNom() const
        {
            return _nom;
        }
        /**
         * Change le nom de l'univers
         */
         inline void setNom(const std::string &nom)
         {
             _nom = nom;
         }


        /**
        * Renvoie un monde en fonction de son numéro. Surchargée constante
        */
        inline Monde& getMonde(int n) throw(std::string)
        {
            if (n < 0 || n > (int)_mondes.size() )
            {
                throw(std::string("Erreur, demande d'accès à un monde non existant"));
            }
            return _mondes[n];
        }
        /**
        * Renvoie un monde en fonction de son numéro. Surchargée constante
        */
        inline const Monde& getMonde(int n) const throw(std::string)
        {
            if (n < 0 || n > (int)_mondes.size() )
            {
                throw(std::string("Erreur, demmnde d'accès à un monde non existant"));
            }
            return _mondes[n];
        }
        /**
         * Renvoie le dernier monde
         */
        inline Monde& dernier()
        {
            return _mondes.back();
        }
        /**
         * Ajoute un monde à la liste des mondes.
         */
         void addMonde(const Monde &monde)
         {
             _mondes.push_back(monde);
         }
         /**
          * Change le monde de départ
          */
          void setMondeDepart(std::string mondeDepart)
          {
              _mondeDepart = mondeDepart ;
          }
          /**
           * Renvoie le monde de départ.
           */
           const std::string& getMondeDepart() const
           {
               return _mondeDepart;
           }
           /**
             * Renvoie la zone de départ
             */
           const std::string& getZoneDepart() const
           {
               return _zoneDepart;
           }
           /**
             * Change la zone de départ
             */
           void setZoneDepart(const std::string &zoneDepart)
           {
               _zoneDepart = zoneDepart;
           }
           /**
             * Renvoie la question de départ
             */
           const std::string& getQuestionDepart() const
           {
                return _questionDepart;
           }
           /**
             * Change la question de départ
             */
           void setQuestionDepart(const std::string &questionDepart)
           {
               _questionDepart = questionDepart;
           }
            /**
             *Renvoie le nombre de monde present dans l'univers
             */
             inline int getNbMonde()
             {

                 return _mondes.size();

             }
            /**
             * Renvoie l'id du monde en fonction de son nom
             */
            inline int idMonde(std::string nom) const
            {
                for (unsigned int i = 0; i < _mondes.size(); i++)
                {
                    if (_mondes[i].getNomMonde() == nom)
                    {
                        return i;
                    }
                }
                return -1;
            }
};
#endif
