#ifndef SPELLCHECKER
#define SPELLCHECKER

#include "utils.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <sstream>
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
            std::cout<<"could not open file "<<filename<<std::endl;
        }
        file.close();
    }


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
                if(!wordHasDigits((*words)[i]))
                {
                    if(!dictionary.findWord((*words)[i]))
                    {
                        file<<"*"<<(*words)[i]<<std::endl;
                        //generer et rechercher les variantes possibles
                        std::vector<std::string>  variants = missOneLetter((*words)[i]);
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary.findWord(variants[i]))
                            {
                                file<<"1"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants = oneLetterTooMuch((*words)[i]);
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary.findWord(variants[i]))
                            {
                                file<<"2"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants  = oneWrongLetter((*words)[i]);
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary.findWord(variants[i]))
                            {
                                file<<"3"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                        variants  = switchedLetters((*words)[i]);
                        for(int i = 0; i <variants.size(); i++)
                        {
                            if(dictionary.findWord(variants[i]))
                            {
                                file<<"4"<<":"<<variants[i]<<std::endl;
                            }                           
                        }
                    }
                    
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