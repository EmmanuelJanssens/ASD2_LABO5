/**
* Auteurs : Teo Ferrari, Emmanuel Janssens et Mathias Maillard
*/
#ifndef TRIE_H
#define TRIE_H

#include "utils.h"

/**
 * Classe représentant un ternary search tree
 */
template<class valueType>
class Trie {

	/**
	 * Structure node contenant un lien vers chaque enfant si il exister,
	 * un caractère et un boolean indiquant si le node est la fin d'un mot
	 */
	struct Node {
		struct Node *left, *right, *middle;
		char character;
		bool end;
		Node() {
			left = nullptr;
			right = nullptr;
			middle = nullptr;
			end = false;
			character = '\0';
		}
	};

	Node *_root;

	/**
	 * Récupère le dernier node d'un mot et le retourne
	 */
	Node* get(Node *x, const valueType &word, unsigned pos) {
		if (x == nullptr) { //si le sous arbre est vide ne retourn rien
			return nullptr;
		}
		char c = word[pos];
		if (c < x->character) { // continue a gauche
			return get(x->left, word, pos);
		} else if (c > x->character) { // continue a droite
			return get(x->right, word, pos);
		} else if (pos < word.length() - 1) { //continue au milieu et passe a la lettre suivante du mot
			return get(x->middle, word, pos + 1);
		} else {
			return x; // si la lettre est la dernière du mot et est égale a la lettre du node, le retourne
		}

	}

	/**
	 * Insère un mot dans l'arbre
	 */
	Node* put(Node *x, const valueType &word, unsigned pos) {

		char c = word[pos];
		if (x == nullptr) { //si le node est vide crée un nouveau node avec la lettre du mot
			x = new Node();
			x->character = c;
			x->end = false;
		}

		if (c < x->character) { //continue a gauche
			x->left = put(x->left, word, pos);
		} else if (c > x->character) { //continue a droite
			x->right = put(x->right, word, pos);
		} else if (pos < word.length() - 1) { // continue au milieu
			x->middle = put(x->middle, word, pos + 1);
		} else {
			x->end = true; //si derniere lettre du mot met le flag end a true dans le node
		}
		return x;

	}
public:

	/**
	 * Constructeur
	 */
	Trie() {
		_root = nullptr;
	}
	/**
	 * Destructeur
	 */
	~Trie() {
	}

	/**
	 * Cherche si un mot est contenu dans le TST
	 * Utilises la fonction get privée
	 */
	bool get(const valueType &word) {
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

	/**
	 * Ajoute un mot au TST
	 * Utilises la fonction put privée
	 */
	void put(const valueType &word) {
		_root = put(_root, word, 0);
	}
};

#endif //TRIE_H
