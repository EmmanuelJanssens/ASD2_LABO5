/**
 * Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#ifndef DICTIONARY
#define DICTIONARY

#include "StlDataStruct.h"
#include <iostream>
#include <fstream>
#include <chrono>

/**
 * Classe permettant de représenter un dictionnaire sur lequel on s'appuiera pour vérifier l'orthographe des mots
 */

template<class T>
class Dictionary
{
    private:

        //Structure premettant de stocker les mots du dictionnaire depuis le ficier externe
        T* data_structure;

        //Nom du fichier contenant les mots à ajouter au dictionnaire
        std::string filename;
    public:

        /**
         * Constructeur
         */
        Dictionary(const std::string& filename)
        {
            data_structure = new T();
            this->filename = filename;
        }
        /**
         * Destructeur
         */
        ~Dictionary()
        {
            delete data_structure;
        }

        /**
         * Méthode permettant de remplir le dictionnaire avec
         * le fichier passer au constructeur
         */
        void load()
        {
            int time = 0;
            std::ifstream file;
            std::string word;

            file.open(filename);

            //Démarrage du timer
            std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();

            //On ouvre le fichier, et ajoute successivement les mots dans la structure
            if(file.is_open())
            {
                
                while(getline(file,word))
                {
                    //Parcout tout le string et applique la fonction passée en paramètre (ici pour mettre en minuscule)
                    transform(word.begin(),word.end(),word.begin(),[](unsigned char c){return tolower(c);});
                    data_structure->put(word);
                }
            }
            else
            {
                std::cout<<"could not open file "<<filename<<std::endl;
            }
            file.close();

            //Vérification du temps de chargement du dictionnaire et affichage dans le terminal
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span  = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout<<"Loading the dictionary took "<<time_span.count()<<" seconds"<<std::endl; 
        }


        /**
         * Méthode vérifiant la présence d'un mot dans le dictionnaire. Retourne true si le mot est trouvé
         */
        bool find(  std::string word)
        {
            return data_structure->get(word);
        }
};
#endif // DICTIONARY