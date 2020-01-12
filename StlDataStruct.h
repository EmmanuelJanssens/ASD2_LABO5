#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "interface.h"



class StlDataStruct :  data_interface
{
    private:

    std::map<char,std::vector<std::string>*> _data;

    bool find(const std::string& word,int left, int right);

    public:

    StlDataStruct();
    ~StlDataStruct();

    /*
        reads a file and put data into our datastructure
        as a heap form
    */
    void insert(const std::string& filename) override;

    /**
     * Recherche dicotomique
     * */
    bool find(const std::string& word) override;

    
    void remove(const std::string& word) override;

    void sort() override;
};

#endif