#ifndef DICTIONARY
#define DICTIONARY

#include "StlDataStruct.h"
#include <iostream>
#include <fstream>
#include <chrono>

template<class T>
class Dictionary
{
    private:

        T* data;
        std::string filename;
    public:
        Dictionary(const std::string& filename)
        {
            data = new T();
            this->filename = filename;
        }

        ~Dictionary()
        {
            delete data;
        }

        void load()
        {
            int time = 0;
            std::ifstream file;
            std::string word;

            file.open(filename);

            std::chrono::high_resolution_clock::time_point t1 =  std::chrono::high_resolution_clock::now();

            if(file.is_open())
            {
                
                while(getline(file,word))
                {

                    //formatWord(word);
                    transform(word.begin(),word.end(),word.begin(),[](unsigned char c){return tolower(c);});
                    data->insert(word);
                }
            }
            else
            {
                std::cout<<"could not open file "<<filename<<std::endl;
            }
            file.close();

            data->sort();
            
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span  = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout<<"Loading the dictionary took "<<time_span.count()<<" seconds"<<std::endl; 
        }


        
        bool find(const std::string& word)
        {
            return data->find(word);
        }
};
#endif // DICTIONARY