#ifndef TRIE_H
#define TRIE_H

#include "interface.h"
struct Node {
	struct Node *left, *right, *middle;
	char character;
	bool end;
};

template<class keyType, class valueType>
class Trie: data_interface<keyType, valueType> {
	Node *_root;

	Node* get(Node *x, const valueType &word, int pos) {
		if (x == nullptr) {
			return nullptr;
		}
		char c = word[pos];
		if (c < x->character) {
			return get(x->left, word, pos);
		} else if (c > x->character) {
			return get(x->right, word, pos);
		} else if (pos < word.length() - 1) {
			return get(x->middle, word, pos + 1);
		} else {
			return x;
		}

	}

	Node* put(Node *x, const valueType &word, int pos) {

		char c = word[pos];


		if (x == nullptr) {
			x = new Node();
			x->character = c;
			x->end = false;
		}

		if (c < x->character) {
			x->left = put(x->left, word, pos);
		} else if (c > x->character) {
			std::cout << c <<x->character<< std::endl;
			x->right = put(x->right, word, pos);
		} else if (pos < word.length() - 1) {
			x->middle = put(x->middle, word, pos + 1);
		} else {
			x->end = true;

		}
		return x;
	}

public:

	Trie() {
	}
	~Trie() {
	}

	bool get(const valueType &word) override {
		Node *x = get(_root, word, 0);
		if (x == nullptr) {
			return false;
		}
		if (x->end == true) {
			return true;
		} else {
			return false;
		}
	}

	void put(const valueType &word) override {
		_root = put(_root, word, 0);
	}
};

#endif //TRIE_H
