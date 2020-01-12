

//liberte de choix dans les structures a utiliser


//devra pouvoir lire 2 formats de fichier différents
// possibilité de réutiliser du code des labos précédents
// commentaires


// si un mot du texte n'est pas présent dans le dictionnaire il sera considéré comme mal orthographié
// le logiciel devra générer 4 ensembles de propositions de corrections sur la base des 4 hypothèses suivante
//      - l'utilisateur a tapé une lettre supplémentaire
//      - l'utilisateur a oublié de tapper une lettre
//      - l'utilisateur a mal tapé une lettre
//      - l'utilisateur a échangé deux lettres consécutives
// ces propositions seront vérifié avec le dictionnaire et seules celles qui s'y trouvent seront proposé a l'utilisateur


//pour chaque documment pour lequel vous verifier l'orthographe, vous génerer un fichier dtexte comportant les mots mal orthographié( préfixées d'une étoile)
// suivie immédiatement des propositions de correction vérifiée(préfixées du numéro de l'hypotese), les mots doivent rester dans l'ordre dans lequel ils apparaissent
// dans le texte, en cas de répétition d'un mot les propositions de correction devront á nouveau être présentées

// afficher dans la console le temps de chargement du dictionnaire ainsi que le temps de correction du texte
// si le temps de chargement du dictionnaire en memoire est supérieur a une minute, alors il est suggéré d'utiliser une version prétraité du dictionnaire,
// dans ce cas on devra également remettre la version prétraité du ductionnaire




//need to access string length, length-1 length+1
//need to check if every letter is present in the word
//no hash tables -> because prefix search should be possible 



//possible data structures
// map with     key = each letter of the alphabet
//              value = list of each whose first letter is equivalent as its key



#include "StlDataStruct.h"
#include "SpellChecker.h"
#include "Dictionary.h"
#include "AVLTree.h"
#include "BinarySearchTree.h"
using namespace std;
int main()
{

   SpellChecker<StlDataStruct<char,string>> test("data/dictionary.txt","data/input_sh","txt");

    test.load_dictrionary();
    test.correct();

    




    return 0;

}