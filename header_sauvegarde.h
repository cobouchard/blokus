#ifndef HEADER_SAUVEGARDE_H
#define HEADER_SAUVEGARDE_H

char BitsToChar(int nb_bit, bool chaine[]);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      22 décembre 2017
 * \brief     code
 *
 * \details
 *
 *
 */

void intToBits(int nb_bit, bool chaine[], int nombre);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      22 décembre 2017
 * \brief     code un nombre avec un nombre de bits passés en paramètre
 *
 * \details
 *
 *
 */

void CharToBits(int nb_bit, bool chaine[], char unChar);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      22 décembre 2017
 * \brief
 *
 * \details
 *
 *
 */

int BitsToInt(int nb_bit, bool chaine[]);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      22 décembre 2017
 * \brief     décode un certain nombre de bits en un seul nombre
 *
 * \details
 *
 *
 */

void sauvegarde(Joueur tableau_joueur[], int nb_joueur);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      23 décembre 2017
 * \brief     sauvegarde la partie
 *
 * \details
 *
 *
 */

void charger(char tableau_des_pieces[21][5][5], Joueur tableau_joueurs[], char le_plateau_jeu[DIMENSION][DIMENSION]);
/**
 * \file      sauvegarde.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      23 décembre 2017
 * \brief     recharge la partie
 *
 * \details
 *
 *
 */

#endif // HEADER_SAUVEGARDE_H
