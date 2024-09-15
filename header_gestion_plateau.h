#ifndef HEADER_GESTION_PLATEAU_H
#define HEADER_GESTION_PLATEAU_H

#include "header_creation_jeu.h"

bool case_pleine(char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y);
bool case_pleine(char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, char joueur);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      22 décembre 2017
 * \brief     vérifie qu'une case donnée est vide
 *
 * \details   renvoie true si la case est vide, si
 *            un joueur est passé en paramètre la fonction renvoie true si
 *            la case est de la même couleur que celle du joueur
 *
 */


bool placement_physique(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      08 décembre 2017
 * \brief     vérifie qu'il est possible physiquement de poser la pièce à un emplacement
 *
 * \details   renvoie true si le placement est possible
 *
 *
 */

bool placement_moral(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      08 décembre 2017
 * \brief     vérifie que le placement d'une pièce n'enfreint aucune règle du jeu
 *
 * \details   renvoie true si le placement est autorisé
 *
 *
 */

bool placement(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      08 décembre 2017
 * \brief     autorise le placement d'une pièce si il est possible
 *
 * \details   renvoie true si le placement est fonctionnel
 *            simple combinaison des vérifications physique et morale
 *
 */

void placement_reel(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      23 décembre 2017
 * \brief     place une pièce à un endroit donnée pour un joueur donné
 *
 * \details
 *
 */

bool test_char(char unC);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      23 décembre 2017
 * \brief     vérifie si un char donné est un nombre
 *
 * \details
 *
 *
 */

void jeu(char tableau_des_pieces[21][5][5], Joueur tableau_joueurs[], char le_plateau_jeu[DIMENSION][DIMENSION]);
/**
 * \file      gestion_plateau.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      19 décembre 2017
 * \brief     démarre le jeu
 *
 * \details
 *
 *
 */

#endif // HEADER_GESTION_PLATEAU_H
