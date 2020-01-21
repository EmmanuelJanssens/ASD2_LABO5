#ifndef TRIE_H
#define TRIE_H

#include "utils.h"

template<class valueType>
class Trie{

	struct Node  {
		struct Node *left, *right, *middle;
		char character;
		bool end;
		Node()
		{ 
			left = nullptr;
			right = nullptr; 
			middle = nullptr;
			end = false; 
		}
	};
	
	Node *_root;

	Node *get(Node *x, const valueType& word, int pos) {
		if (x == nullptr) {
			return nullptr;
		}
		char c = word[pos];
		if (c < x->character) {
			return get(x->left, word, pos);
		}
		else if (c > x->character) {
			return get(x->right, word, pos);
		}
		else if (pos < word.length() - 1) {
			return get(x->middle, word, pos + 1);
		}
		else {
			return x;
		}

	}

	Node *put(Node *x,  const valueType& word, int pos) {

		char c = word[pos];
		if (x == nullptr) {
			x = new Node();
			x->character = c;
			x->end = false;
		}

		if (c < x->character) {
			x->left = put(x->left, word, pos);
		}
		else if (c > x->character) {
			x->right = put(x->right, word, pos);
		}
		else if (pos < word.length() - 1) {
			x->middle = put(x->middle, word, pos + 1);
		}
		else {
			x->end = true;
		}
			return x;

	}


	Node* remove(Node *x, const valueType& word, int pos)
	{
		/*if(x == nullptr)
		{
			return nullptr;
		}

		if(pos == word.size())
		{
			if(x->end)
			{
				x->end = false;
			}
			if(isEmpty(x))
			{
				delete x;
				x = nullptr;
			}
			return x;
		}*/

		return x;
	}
public:

	Trie() {
		_root = nullptr;
	}
	~Trie() {
	}

	bool get( const valueType& word) 
	 {
		Node* x = get(_root, word, 0);
		if (x == nullptr) {
			return false;
		}
		if (x->end == true) {
			return true;
		}
		else {
			return false;
		}
	}

	void put( const valueType& word)  {
		_root = put(_root, word, 0);
	}

	void remove(const valueType& word) 
	{
		_root = remove(_root,word,0);
	}
};

#endif //TRIE_H