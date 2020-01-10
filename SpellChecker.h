#ifndef SPELLCHECKER
#define SPELLCHECKER

#include "utils.h"
#include <fstream>
#include <iostream>
#include <chrono>

/// T must implement find function
template <class T>
class SpellChecker
{
    private:


    T dictionary;  
    std::string filename;
    std::string extension;

    std::vector<std::string>* words;

    public:

    SpellChecker(const std::string& filename, const T& dict, const std::string& extension)
    {
        this->filename = filename;
        this->extension = extension;

        words = new std::vector<std::string>();
        dictionary = dict;
    }
    ~SpellChecker()
    {
        delete words;
    }

    void readFile()
    {
        std::ifstream file;
        std::string word;

        file.open(filename +"."+extension);
        if(file.is_open())
        {
            
            while(file >> word)
            {
                formatWord(word);
                words->push_back(word);
            }
        }
        else
        {
            std::cout<<"could not open file "<<filename<<std::endl;
        }
        file.close();
    }


    bool isTypo(const std::string& dic, const std::string& text)
    {
        return missOneLetter(dic,text) || oneLetterTooMuch(dic,text)||switchedLetters(dic,text)||oneWrongLetter(dic,text);
    }

    bool missOneLetter(const std::string& dic, const std::string& text)
    {

        
        return false;
    }

    bool oneLetterTooMuch(const std::string& dic, const std::string& text)
    {
        return false;
    }
    bool switchedLetters(const std::string& dic, const std::string& text)
    {
        return false;
    }
    bool oneWrongLetter(const std::string& dic, const std::string& text)
    {
        return false;
    }


    void findSimilarWords(const std::string& word)
    {

    }
    void correct()
    {
        std::ofstream file;

        std::string correction = this->filename + "_correction.txt";
        file.open(correction);
        std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();
        readFile();
        for(int i = 0; i  < words->size(); i++)
        {
            if((*words)[i] != "")
            {
                if(!dictionary.findWord((*words)[i]))
                {
                    file<<"*"<<(*words)[i]<<std::endl;
                }
            }            
        }

        std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span  = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout<<"Correcting took "<<time_span.count()<<" seconds"<<std::endl; 

        file.close();

    }

};

#endif