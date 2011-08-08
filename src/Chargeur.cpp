/**
 * Projet tutoré. 2010-2011.
 * src/Chargeur.cpp
 */
#include "Chargeur.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
/**
 * Constructeur par defaut
 */
Chargeur::Chargeur()
{

}
/**
 * Constructeur prenant en paramètre le nom de l'univers
 * @param nom Nom de l'univers à charger
 */
Chargeur::Chargeur(std::string nom) :
_nom(nom)
{

}
/**
 * Charge les différantes informations de l'univers courant (stocké dans "nom").
 * @param u Objet univers dans lequel placer les informations.
 */
void Chargeur::charger(Univers *u) throw(std::string)
{
    charger(u,_nom);
}
/**
 * Charge les différantes informations de l'univers passé en paramètre.
 * @param u Objet univers dans lequel placer les informations.
 */
void Chargeur::charger(Univers *u, std::string nom) throw(std::string)
{
    std::string buffer;
    std::string worldName;
    std::string zoneName;
    std::string questionName;
    //On déclare/ouvre le dossier de base.
    Dossier d;
    d.openT(nom);
    //On ouvre le fichier de propriétés
    ifstream proprioF((nom + "/.Proprietes").c_str(), ios::in);

    if (!proprioF)
    {
        throw(std::string("Impossible de trouver le fichier de propriétés"));
    }
    //On recupère le monde de départ
    getline(proprioF,buffer);
    u->setMondeDepart(buffer);
    //On recupère la zone de départ
    getline(proprioF,buffer);
    u->setZoneDepart(buffer);
    //On recupère la question de départ
    getline(proprioF,buffer);
    u->setQuestionDepart(buffer);
    //On ferme le fichier
    proprioF.close();
    //On itère sur le contenu du dossier
    while (d.hasNext())
    {
        worldName = d.next();

        /* On enlève de la liste des dossiers cachés
         * qui pourraient poser problème (par exemple, .svn)
         */
        if (worldName[0] != '.')
        {
            //On ajoute le monde à la liste des mondes
            u->addMonde(Monde());

            Monde &m = u->dernier();
            m.setNomMonde(worldName);
            /*
             * On ouvre le monde
             */
            Dossier dworld;
            dworld.openT(nom + "/" + worldName);
            while (dworld.hasNext())
            {
                //On ouvre la zone
                zoneName = dworld.next();
                if (zoneName[0] != '.')
                {
                    //On ajoute la zone
                    m.addZone(Zone(m.nbZones(),zoneName));
                    //On ouvre la zone
                    Dossier dzone;
                    dzone.openT(nom + "/" + worldName + "/" + zoneName);
                    while (dzone.hasNext())
                    {
                        questionName = dzone.next();
                        //On recupère le nom de la question.

                        if (questionName[0] != '.')
                        {
                            Zone &z = m.dernier();

                            std::string chemin = nom + "/" + worldName + "/" + zoneName + "/" + questionName;

                            //On ouvre le fichier de question en lecture
                            ifstream fichier(chemin.c_str(), ios::in);

                            if(fichier)  // si l'ouverture a réussi
                            {

                                //On déclare une question
                                Question Q;
                                //On change son nom
                                Q.setNom(questionName);
                                //On déclare une proposition
                                Proposition P;
                                //on recupere la ligne courante du fichier
                                getline(fichier,buffer);
                                //on met en place l'intitulé de la question
                                Q.setIntituleQuest(buffer);

                                //On recupere le libelle de la proposition
                                getline(fichier,buffer);

                                //On recupere l'ensemble des proposition
                                while( buffer != "" )
                                {
                                    P = Proposition();

                                    //On met en place le libelle de la proposition
                                    P.setLibelleProp(buffer);

                                    //On recupere nombre de point de proposition
                                    getline(fichier,buffer);
                                    //On met en place le nombre de points de la proposition
                                    P.setPointProp(atof(buffer.c_str()));

                                    //on recupere la reponse à la proposition
                                    getline(fichier,buffer);
                                    //on met en place la reponse a la proposition
                                    P.setReponse(buffer);


                                    //On recupere nombre de point minimum de la proposition
                                    getline(fichier,buffer);
                                    //On met en place le nombre de points minimum de la proposition
                                    P.setPointMin(atof(buffer.c_str()));

                                    //On recupere le nombre de point maximum de proposition
                                    getline(fichier,buffer);
                                    //On met en place le nombre de points maximum de la proposition
                                    P.setPointMax(atof(buffer.c_str()));

                                    //On recupere l'eventuel lien vers un autre monde
                                    getline(fichier,buffer);
                                    //Onmet en place le lien vers le monde
                                    P.setLienMonde(buffer);


                                    getline(fichier,buffer);

                                    while(buffer != "")
                                    {

                                        //on ajout les lien vers les zones
                                        P.addLienZone(buffer);
                                        getline(fichier,buffer);


                                    }

                                    //On ajoute la proposition à la liste de question
                                    Q.addProp(P);
                                    //On recupère la proposition de la nouvelle question
                                    getline(fichier,buffer);

                                }


                                //On ajoute la question à la dernière zone
                                z.addQuestion(Q);


                            }
                            else
                            {
                                throw(std::string("Impossible de charger le fichier !"));
                            }


                        }

                    }

                }
            }
        }
    }
}
