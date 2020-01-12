#ifndef TRIE_H
#define TRIE_H

#include "interface.h"
struct Node 
{
    struct Node* childs[26];
    bool end;
};

template<class keyType, class valueType>
class Trie : data_interface<keyType,valueType>
{
        Node* _root;

    public:

        Trie(){}
        ~Trie(){}
        

        void insert(const std::string& word) override{}
        void remove(const std::string& word) override{}

        bool find(const std::string& word) override{return false;}
};


#endif //TRIE_H