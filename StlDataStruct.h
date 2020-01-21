#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "utils.h"

#include <chrono>
#include <unordered_map>
#include <bitset>
#include <functional>





template<class stl_struct , class valueType>
class StlDataStruct 
{
    private:

    stl_struct _data;

    public:

    StlDataStruct()
    {}
    ~StlDataStruct()
    {}

    public:

    void put(const valueType& value) 
    {
        _data.insert(value);
    }

    bool get( const valueType& value) 
    {
        return !(_data.find(value) == _data.end());
    }

    void remove(const valueType& value) 
    {
        _data.erase(value);
    }

};

#endif