#ifndef HEADER_GESTION_PIECES_H
#define HEADER_GESTION_PIECES_H

void remplissage_tableau_pieces(char tableau_des_pieces[21][5][5]);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     initialise le tableau_pieces
 *
 * \details   initialise le tableau_pieces, permet de stocker toutes les pièces dans l'ordre (l'indice permettra de récupérer le numéro)
 *            il y a 21 pièces chacune étant une matrice 5*5
 */


void affichage_piece(char tableau_des_pieces[21][5][5], int index);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     affiche une pièce
 *
 * \details   affiche une pièce dans le terminal
 *            cette fonction permet de tester le bon fonctionnement d'autres fonctions
 *            mais ne fais pas partie du programme final.
 */


void init_piece_temp(char tableau_des_pieces[21][5][5], int index, char piece_temp[5][5]);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     créer la copie d'une pièce
 *
 * \details   permet de récupérer une copie d'une pièce donnée
 *            pour appliquer des modifications sur celle ci
 *            sera utilisé dans la rotation de la pièce ainsi
 *            que le replacement de la pièce en haut a gauche de la matrice
 */


void rotation_piece_horaire(char tableau_des_pieces[21][5][5], int index);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     fais la rotation d'une pièce
 *
 * \details   permet d'effectuer une rotation d'une pièce de 90°
 *            voir le code source de la fonction pour un fonctionnement plus en détail
 */

//void mettreenhaut(char piece [5][5]);
void mettreenhaut(char tableau_des_pieces[21][5][5], int index);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      02 novembre 2017
 * \brief     repositionne une pièce après la rotation en haut du tableau
 *
 * \details   repositionne la pièce en haut en supprimant les lignes vides
 *            (en réalité intervertit les valeurs les
 *            tableaux étant statiques).
 */

//void mettreagauche(char piece [5][5]);
void mettreagauche(char tableau_des_pieces[21][5][5], int index);
/**
 * \file      gestion_pieces.cpp
 * \author    Bouchard Corentin
 * \version   1.0
 * \date      09 décembre 2017
 * \brief     repositionne une pièce après la rotation à gauche du tableau
 *
 * \details   repositionne la pièce à gauche
 *            en supprimant les colonnes vides (en réalité intervertit les valeurs les
 *            tableaux étant statiques.)
 */

#endif // HEADER_GESTION_PIECES_H
