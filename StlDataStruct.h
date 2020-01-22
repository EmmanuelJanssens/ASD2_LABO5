/**
 * Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "utils.h"

#include <chrono>
#include <unordered_map>
#include <bitset>
#include <functional>

/**
 * Classe représentant la structure qui pourra ensuie être utilisée par le dictionnaire pour stocker les mots
 */


template<class stl_struct , class valueType>
class StlDataStruct 
{
    private:
    //Structure pour stocker les valeurs. Cette structure est de type stl_struct renseigné lors de la création d'un
    //StlDataStruct. Dans notre cas, il s'agira d'un unordered_set
    stl_struct _data;

    public:

    /**
     * Constructeur
     */
    StlDataStruct()
    {}

    /**
     * Destructeur
     */
    ~StlDataStruct()
    {}

    public:

    /**
     * Ajoute une valeur dans la structure
     */
    void put(const valueType& value) 
    {
        _data.insert(value);
    }

    /**
     * Vérifie la présence d'une valeur dans la strcture, retourne true le cas échéant
     */
    bool get( const valueType& value) 
    {
        return !(_data.find(value) == _data.end());
    }

    /**
     * Enlève une valeur dans la structure
     */
    void remove(const valueType& value) 
    {
        _data.erase(value);
    }

};

#endif