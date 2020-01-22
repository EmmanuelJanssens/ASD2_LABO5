/**
 * Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#include "utils.h"
#include <algorithm>
#include <cctype>

#include <iostream>
using namespace std;

bool wordHasDigits(const string &str)
{
    for(string::const_iterator it = str.cbegin(); it != str.cend();it++)
    {
        if(isdigit(*it))
            return true;
    }
    return false;
}

void removeApostrophe(string& str)
{
    if(*str.begin() == '\'')
    {
        str.erase(str.begin());
    }

    if(*(str.begin()+str.length()-1)== '\'')
    {
       str.erase(str.begin()+str.length()-1);
    }
}
void removeNonChar(string & str)
{
    str.erase(remove_if(str.begin(),str.end(),isNotAlpha),str.end());   
} 
bool isNotAlpha(char c)
{
    //Le caractère doit être soit un caractère alphanumérique, soit une apostrophe, soit un espace
    if(!isalpha(c) && !isdigit(c) && c != '\'' && c != ' ')
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

        replace(word.begin(),word.end(),'-',' ');

        removeNonChar(word);
   
}