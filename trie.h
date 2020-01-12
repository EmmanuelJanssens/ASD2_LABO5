#ifndef TRIE_H
#define TRIE_H

#include "interface.h"
struct Node 
{
    struct Node* childs[26];
    bool end;
};

class Trie : data_interface
{
        Node* _root;

    public:

        Trie();
        ~Trie();
        

        void insert(const std::string& word) override;
        void remove(const std::string& word) override;

        bool find(const std::string& word) override;
};


#endif //TRIE_H