#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>


#include "utils.h"
class data_interface
{
    public:

    virtual bool find(const std::string& word);
    virtual void insert(const std::string& word);
    virtual void remove(const std::string& word);

    virtual void sort();

};
#endif // INTERFACE_H