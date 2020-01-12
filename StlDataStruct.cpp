#include "StlDataStruct.h"

#include <chrono>

using namespace std;

StlDataStruct::StlDataStruct()
{
    for(int i = 0; i < strlen(ALPHA); i++ )
    {
        _data[ALPHA[i]] = new vector<string>();
    }
}

StlDataStruct::~StlDataStruct()
{
    for(int i  = 0 ; i < strlen(ALPHA); i++)
    {
        delete _data[ALPHA[i]];
    }
}

bool StlDataStruct::find(const string& word)
{
    //look in coorect map
    //return find(_data[word[0]]->begin(),_data[word[0]]->end(),word) != _data[word[0]]->end();
    if(wordHasDigits(word))
        return false;
    return find(word,0,_data[word[0]]->size()-1);
}

bool StlDataStruct::find(const string& word ,int left, int right)
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

void StlDataStruct::insert(const string& word)
{
    _data[word[0]]->push_back(word);
}

void StlDataStruct::sort()
{
    for(int i = 0; i < strlen(ALPHA); i++ )
    {
        make_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
        sort_heap(_data[ALPHA[i]]->begin(),_data[ALPHA[i]]->end());
    }
}