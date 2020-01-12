#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "interface.h"

#include <chrono>


template<class keyType, class valueType>
class StlDataStruct :  data_interface<keyType,valueType>
{
    private:

    std::map<keyType,std::vector<valueType>*> _data;

   /**
     * Recherche dicotomique
     * */
    bool find(valueType word,int left, int right)
    {
        while (left <= right) { 
        int mid = left + (right - left) / 2; 
  
        if (_data[word[0]]->at(mid) == word) 
            return true; 
  
        if (_data[word[0]]->at(mid)  < word) 
            left = mid + 1; 
          else
            right = mid - 1; 
        } 
        return false; 
    }

    public:

    StlDataStruct()
    {
        for(int i = 0; i < strlen(ALPHA); i++ )
        {
            _data[ALPHA[i]] = new std::vector<valueType>();
        }
    }
    ~StlDataStruct()
    {
        for(int i  = 0 ; i < strlen(ALPHA); i++)
        {
            delete _data[ALPHA[i]];
        }
    }

    public:
    void put(const keyType& key, const valueType& value)
    {
        _data[key]->push_back(value);
    }
    /*
        reads a file and put data into our datastructure
        as a heap form
    */
   void put(const valueType& value)
   {
       put(value[0],value);
   }

 
    bool get(const keyType& key, const valueType& value) override
    {
        //look in coorect map
        if(wordHasDigits(value))
            return false;
        return find(value,0,_data[key]->size()-1);
    }
    bool get( const valueType& value) override
    {
        //look in coorect map
        return get(value[0],value);
    }

    void remove(const keyType& key, const valueType& value) override
    {

    }
    void remove(const valueType& value) override
    {

    }
    void sort() override
    {
        for(int i = 0; i < strlen(ALPHA); i++ )
        {
            make_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
            sort_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
        }
    }
};

#endif