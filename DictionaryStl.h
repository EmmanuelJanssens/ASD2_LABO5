#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

#include <iostream>
#include <fstream>

#include "utils.h"



class DictionaryStl
{
    private:

    std::map<char,std::vector<std::string>*> _data;
    public:

    DictionaryStl();
    ~DictionaryStl();


    std::map<char,std::vector<std::string>*> Data() { return _data; }
    
    /*
        reads a file and put data into our datastructure
        as a heap form
    */
    void load_dictionary(std::string filename);


    bool findWord(const std::string& word);

    bool dichotomicSearch(const std::string& word,int left, int right);

};

#endif