/**
 * Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#ifndef SPELLCHECKER
#define SPELLCHECKER

#include "Dictionary.h"

#include <fstream>
#include <iostream>
#include <chrono>
#include <sstream>
#include <vector>

/**
 * Classe représentant le correcteur orthograpique.
 * Le correcteur a besoin d'un dictionnaire ainsi que d'une liste de mots à corriger
 */

template <class T>
class SpellChecker
{
    private:

    //Dictionnaire contenant les mots orthographiés correctement
    Dictionary<T> *dictionary;
    //Nom du fichier à corriger
    std::string output_file;
    //Extension du fichier
    std::string extension;
    //Liste des mots dont on veut vérifier l'orthographe
    std::vector<std::string>* words;

    public:

    /**
     * Constructeur
     */
    SpellChecker(const std::string& dictionary, const std::string& output, const std::string& extension)
    {
        this->output_file = output;
        this->extension = extension;

        words = new std::vector<std::string>();
        this->dictionary = new Dictionary<T>(dictionary);
    }

    /**
     * Destructeur
     */
    ~SpellChecker()
    {
        delete words;
        delete dictionary;
    }

    /**
     * Méthode permettant d'initialiser le dictionnaire
     */
    void load_dictionary()
    {
        dictionary->load();
    }    

    /**
     * Méthode permettant de lire le fichier à corriger et d'appliquer les différents formatages avant de pouvoir
     * vérifier la correction. Les mots à corriger sont enregistrés dans la structure words
     */
    void readFile()
    {
        std::ifstream file;
        std::string word;

        file.open(output_file +"."+extension);
        if(file.is_open())
        {         
            while(file >> word)
            {
                formatWord(word);
                std::stringstream ss(word);
                std::string str;
                while(ss>>str)
                {
                    removeApostrophe(str);
                    words->push_back(str);
                }
            }
        }
        else
        {
            std::cout<<"could not open file "<<output_file<<std::endl;
        }
        file.close();
    }


    /**
     * Retourne les variantes possibles d'un mot en partant du principe qu'il manque une lettre
     */
    std::vector<std::string> missOneLetter(const std::string& text)
    {
        std::vector<std::string>variants;
        std::string back = text;
        if(text.length() > 1)
        {
            for(int i = 0; i < back.length(); i++)
            {
                back.erase((back.begin()+i));
                if(*back.begin() != '\'')
                    variants.push_back(back);
                back = text;
            }
        }

        return variants;
    }

    /**
     * Retourne les variantes possibles d'un mot en partant du principe qu'il y a une lettre en trop
     */
    std::vector<std::string> oneLetterTooMuch(const std::string& text)
    {
        std::vector<std::string>variants;
        std::string back = text;

        for(int i = 0; i < back.length(); i++)
        {
            back.insert(back.begin()+i,'a');
            for(char j = 'a'; j <= 'z' ; j++)
            {
                back.replace(back.begin()+i,back.begin()+i+1,1,j);
                variants.push_back(back);
            }
            back = text;
        }
        return variants;
    }

    /**
     * Retourne les variantes possibles d'un mot en partant du principe que deux lettres ont été inversées
     */
    std::vector<std::string> switchedLetters( const std::string& text)
    {
        std::vector<std::string>variants;
        std::string back = text;

        if(text.length() > 1)
        {
            for(int i = 0; i < back.length(); i++)
            {
                if(i+1 < back.length())
                {
                    std::swap(back[i],back[i+1]);
                    if(*back.begin() != '\'')
                        variants.push_back(back); 
                    back = text;
                }
            }
        }
         return variants;
    }

    /**
     * Retourne les variantes possibles d'un mot en partant du principe qu'une lettre est erronée
     */
    std::vector<std::string> oneWrongLetter( const std::string& text)
    {
        std::vector<std::string>variants;
        std::string back = text;
        for(int i = 0; i < back.length(); i++)
        {
            for(char j = 'a'; j <= 'z' ; j++)
            {
                back.replace(back.begin()+i,back.begin()+i+1,1,j);
                variants.push_back(back);
                back = text;

            }
        }

        return variants;
    }

    /**
     * Retourne le mot à vérifier à l'indexe i
     */
    std::string getWord(int i)
    {
        return (*words)[i];
    }

    /**
     * Méthode permettant d'appliquer la correction sur le fichier d'entrée. Les prépositions de corrections seront
     * enregistrées dans un un autre fichier de la façon dont il nous a été demandé de faire dans la consigne
     */
    void correct()
    {
        std::ofstream file;

        //Fichier qui contiendra les variantes de correction
        std::string correction = this->output_file + "_correction.txt";
        file.open(correction);

        //Démarage du timer
        std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();

        readFile();

        //Itère sur chaque mots pour vérifier l'orthographe
        for(int i = 0; i  < words->size(); i++)
        {
            if(getWord(i) != "")
            {
                if(!wordHasDigits(getWord(i)))
                {
                    //Si le mot courrant n'est pas dans le dictionnaire, on essaie les variantes possibles d'erreurs
                    if(!dictionary->find(getWord(i)))
                    {
                        file<<"*"<<getWord(i)<<std::endl;
                        //gééerer et rechercher les variantes possibles.On les ajoute dans le fichier de sortie s'il
                        //y a des variantes possibles
                        std::vector<std::string>  variants = missOneLetter(getWord(i));
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary->find(variants[i]))
                            {
                                file<<"1"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants = oneLetterTooMuch(getWord(i));
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary->find(variants[i]))
                            {
                                file<<"2"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants  = oneWrongLetter(getWord(i));
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary->find(variants[i]))
                            {
                                file<<"3"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants  = switchedLetters(getWord(i));
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary->find(variants[i]))
                            {
                                file<<"4"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                    }
                    
                }

            }            
        }

        //Vérification du temps nécessaire à la correction et affichage dans le terminal
        std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span  = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout<<"Correcting took "<<time_span.count()<<" seconds"<<std::endl; 

        file.close();

    }

};

#endif