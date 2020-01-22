/**
 * Auteurs: Auteurs: Teo Ferrari, Emmanuel Janssens et Mathias Maillard
 */

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <cstring>
#include <string>

/**
 * les fichiers utils.cpp et utils.h définissent des méthodes utiles pour l'implémentation du laboratoire
 */

//Représente toutes les 26 lettres de l'alphabet
#define ALPHA "abcdefghijklmnopqrstuvwxyz"

/**
 * Méthode vérifiant si un mot contient un chiffre
 */
bool wordHasDigits(const std::string &str);

/**
 * Méthode vérifiant s'il ne s'agit pas d'un caractèr alphanumérique
 */
bool isNotAlpha(char c);

/**
 * Méthode suprimant les caractères non-alphanumériques d'un string
 */
void removeNonChar(std::string & str);

/**
 * Méthode permettant le formattage d'un motcomme demandé
 */
void formatWord(std::string &word);

/**
 * Méthode mettant en minuscule un string
 */
void toLower(std::string& word);
/**
 * Méthode supprimant les apostrophes, puisque nous travaillons sur un texte en Anglais
 */
void removeApostrophe(std::string& word);
#endif
