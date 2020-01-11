#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <cstring>
#include <string>

#define ALPHA "abcdefghijklmnopqrstuvwxyz"
bool wordHasDigits(const std::string &str);
bool isNotAlpha(char c);
void removeNonChar(std::string & str);
void formatWord(std::string &word);
void toLower(std::string& word);
void removeApostrophe(std::string& word);
#endif
