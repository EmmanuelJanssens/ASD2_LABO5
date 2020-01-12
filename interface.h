#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>


#include "utils.h"

template <class keyType, class valueType>
class data_interface
{

    protected:
    virtual bool get(const keyType& key,const valueType& word){return false;}
    virtual void put(const keyType& key,const valueType& word){}
    virtual void remove(const keyType& key,const valueType& word){}
    virtual void sort(){}

    public:
    virtual bool get(const valueType& word){return false;}
    virtual void put(const valueType& word){}
    virtual void remove(const valueType& word){}

};
#endif // INTERFACE_H