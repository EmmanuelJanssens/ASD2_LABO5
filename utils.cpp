#include "utils.h"
#include <algorithm>
#include <cctype>

#include <iostream>
using namespace std;


bool isNotAlpha(char c)
{
    if(!isalpha(c))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void formatWord(string &word)
{
        transform(word.begin(),word.end(), word.begin(), [](unsigned char c){return tolower(c);});      
        word.erase(remove_if(word.begin(),word.end(),isNotAlpha),word.end()); 
}