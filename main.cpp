/**
 *  Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#include "StlDataStruct.h"
#include "SpellChecker.h"
#include "Dictionary.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"

#include <unordered_set>
using namespace std;

#include "trie.h"

/**
 * Fonction de hachage utilisée pour l'unordered_set
 */
struct Hash
{
    size_t operator() (const std::string& word) const
    {
        int z = 33;
        int hashval = 0;
        for(int i = 0; i < word.length(); i++)
        {
            hashval += z * hashval + std::hash<char>()(word[i]);
        }
        return hashval;
    }
};

/**
 * Main method
 **/
int main()
{
    /**
     * L'utilisation d'un unordered_set convient parfaitement à nos besoins pour ce laboratoire.
     * Le fait de hacher les mots permet de les récupérer dans cette structure en temps constant. Ainsi, lorsque l'on
     * veut vérifier la présence d'un mot dans un dictionnaire, cette étape sera très rapide (beaucoup plus que si
     * l'on utilisait un set normal par exemple qui nécessiterait O(log(n)) à chque fois que l'on regarde dans le
     * dictionnaire
     */
    SpellChecker<StlDataStruct<unordered_set<string,Hash>,string>> spell("data/dictionary.txt","data/input_sh","txt");
    spell.load_dictrionary();
    spell.correct();

    /*
     * En utilisant un TST
    SpellChecker<Trie<string>> spell("data/dictionary.txt","data/input_lates","txt");
    spell.load_dictrionary();
    spell.correct(); */
   
    return 0;

}
