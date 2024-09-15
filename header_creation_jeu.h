#ifndef HEADER_H
#define HEADER_H

#include "constantes.h"
#include <string>
enum Couleur{Rouge=204, Bleu=238, Jaune=170, Vert=153}; //les différentes couleurs des 4 joueurs

struct Joueur
{
    Couleur sacouleur;
    char sonChar;
    std::string pseudo;
    bool Pieces_restantes [21];
    short rotations_pieces [21];
    int positions_x[21];
    int positions_y[21];
    short position_x_origine;
    short position_y_origine;
};

/**
 * \file      creation_jeu.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     enregistrement des données relatives à un joueur
 *
 * \details   Couleur, la couleur du joueur
 *            sonnumero pour l'initialisation aléatoire des couleurs
 *            Pieces_restantes permet de garder en mémoire quelles pièces il reste à un joueur (bool car seulement deux possibilités)
 */

void init_plateau(char plateau[DIMENSION][DIMENSION]);
/**
 * \file      creation_jeu.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     initialise le plateau
 *
 * \details   initialise le plateau et remplit toutes les cases de '.'
 *            pour commencer la partie
 */


void affichage_plateau(char plateau[DIMENSION][DIMENSION], Joueur tableau_joueurs[], char tableau_des_pieces[21][5][5], int joueur_actif);
/**
 * \file      creation_jeu.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     affiche le plateau
 *
 * \details   affiche toutes les cases du plateau et
 *            affiche les repères à gauche et en haut du plateau
 *           (lettre de A à T en ordonnée et nombre de 1 à 20 en abscisse
 */


void init_tableau_joueurs(Joueur tableau_joueurs[], int & nombre_joueur);
/**
 * \file      creation_jeu.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     initialise les joueurs
 *
 * \details   initialise toutes les données relatives aux joueurs
 *
 */

void init_tableau_joueurs_fixe(Joueur tableau_joueurs[], int & nombre_joueur);
/**
 * \file      creation_jeu.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      23 décembre 2017
 * \brief     initialise les joueurs
 *
 * \details   est appelé même si le chargement a lieu
 *
 */

void ClearScreen();
/**
 * \file      creation_jeu.cpp
 * \author    cplusplus.com
 * \version   1.0
 * \date
 * \brief     efface le contenu du terminal
 *
 * \details   http://www.cplusplus.com/articles/j3wTURfi/
 *
 */


#endif // HEADER_H

