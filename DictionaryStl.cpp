#include "DictionaryStl.h"

#include <chrono>

using namespace std;

DictionaryStl::DictionaryStl()
{
    for(int i = 0; i < strlen(ALPHA); i++ )
    {
        _data[ALPHA[i]] = new vector<string>();
    }
}

DictionaryStl::~DictionaryStl()
{
    for(int i  = 0 ; i < strlen(ALPHA); i++)
    {
        delete _data[ALPHA[i]];
    }
}

bool DictionaryStl::findWord(const string& word)
{
    //look in coorect map
    //return find(_data[word[0]]->begin(),_data[word[0]]->end(),word) != _data[word[0]]->end();
    if(wordHasDigits(word))
        return false;
    return dichotomicSearch(word,0,_data[word[0]]->size()-1);
}

bool DictionaryStl::dichotomicSearch(const string& word ,int left, int right)
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
void DictionaryStl::load_dictionary(string filename)
{
    int time = 0;
    ifstream file;
    string word;

    file.open(filename);

    chrono::high_resolution_clock::time_point t1 =  chrono::high_resolution_clock::now();

    if(file.is_open())
    {
        
        while(getline(file,word))
        {

            //formatWord(word);
            transform(word.begin(),word.end(),word.begin(),[](unsigned char c){return tolower(c);});
            _data[word[0]]->push_back(word);
        }
    }
    else
    {
        cout<<"could not open file "<<filename<<endl;
    }
    file.close();

    //sort
    for(int i = 0; i < strlen(ALPHA); i++ )
    {
        make_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
        sort_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
    }

    chrono::high_resolution_clock::time_point t2 =  chrono::high_resolution_clock::now();
    chrono::duration<double> time_span  = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    cout<<"Loading took "<<time_span.count()<<" seconds"<<endl; 

}