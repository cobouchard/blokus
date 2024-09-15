#include <fstream>
#include <iostream>
#include <string>

#include "constantes.h"
#include "header_gestion_pieces.h"

void remplissage_tableau_pieces(char tableau_des_pieces[21][5][5])
{

    std::ifstream fichier_piece("pieces.txt");
    std::string ligne;

    for (int numero_piece=0;
         numero_piece!=21;
         numero_piece++)
    {
        for (int ligne=0;
            ligne!=5;
            ligne++)
        {
            for (int colonne=0;
            colonne!=5;
            colonne++)
            {
                tableau_des_pieces[numero_piece][ligne][colonne]=' ';
            }

        }
    }

    for (int numero_piece=0;
        !fichier_piece.eof();
        numero_piece++)
    {

        for (int m=0, taille=2;
            taille!=0; //si la ligne est vidé c'est que l'on passe à la pièce suivante, la première ligne est non vide
            m++)
        {

            std::getline (fichier_piece, ligne);
            taille=ligne.size();
            for (int n=0;
                n!=taille;
                n++) //à chaque fois que l'on trouve un charactère on  rajoute un nombre à la pièce
            {

                if (ligne[n]!=' ')
                {
                    tableau_des_pieces[numero_piece][m][n]='2'; //valeur arbitraire
                }
            }
        }
    }


    //tout les caractères qui ne sont pas égaux à 2 doivent être des espaces

}

void affichage_piece(char tableau_des_pieces[21][5][5], int index)
{

    for (int ligne=0;
        ligne!=5;
        ligne++)
    {
        for (int colonne=0;
        colonne!=5;
        colonne++)
        {
            std::cout << tableau_des_pieces[index][ligne][colonne];
        }
        std::cout << '\n';
    }
}

void affichage_piece(char piece[5][5])
{

    for (int ligne=0;
        ligne!=5;
        ligne++)
    {
        for (int colonne=0;
        colonne!=5;
        colonne++)
        {
            std::cout << piece[ligne][colonne];
        }
        std::cout << '\n';
    }
}

void init_piece_temp(char tableau_des_pieces[21][5][5], int index, char piece_temp[5][5])
{

    for (int m=0;
        m!=5;
        m++)
    {
        for (int n=0;
            n!=5;
            n++)
        {

            piece_temp[m][n]=tableau_des_pieces[index][m][n];
            //std::cout << tableau_des_pieces[index][m][n];
        }
    }


}

void rotation_piece_horaire(char tableau_des_pieces[21][5][5], int index)
{

    char piece_temp [5][5];


    init_piece_temp(tableau_des_pieces, index, piece_temp);

    /* une rotation équivaut à ce qui ressemble à une transposée (cf cours sur les matrices Algèbre linéaire)
    cependant les colonnes sont en en réalités inversés
    Exemple pour illuster

    Avec une figure : A (1,1,1,0,0 		donnera la matrice B suivante (0,0,0,0,0
                         0,1,0,0,0									   0,0,0,0,0
                         0,1,0,0,0									   1,0,0,0,0
                         0,0,0,0,0									   1,1,1,0,0
                         0,0,0,0,0)									   1,0,0,0,0)

    La première ligne devient la première colonne à l'envers
    La deuxieme ligne devient la deuxieme colonne à l'envers
    D'une manière générale :

    La n'ème ligne devient la n'ème colonne à l'envers

    Nous allons donc exactement utiliser ces opérations, la pièce sera directement changé en utilisant tableau_temp comme rappel de la figure de départ
    */

    for (int ligne=0;
        ligne!=5;
        ligne++)
    {
        for (int colonne=0;
        colonne!=5;
        colonne++)
        {
            tableau_des_pieces[index][colonne][ligne]=piece_temp[ligne][4-colonne];
        }
    }


    mettreenhaut(tableau_des_pieces, index);
}

void mettreenhaut(char tableau_des_pieces[21][5][5], int index)
{
    /*on cherche la ligne vide la plus basse (maximu 4ème ligne)
    une fois que cette ligne est trouvée on passe toutes les lignes
    sous celle ci une ligne au dessus
    On répète jusqu'à que la première ligne ne soit pas entièrement vide
    */
    //affichage_piece(piece);
    char premiere_ligne[5];
    //affichage_piece(tableau_des_pieces, index);
    for (int i=0; i!=5; i++)
    {
        premiere_ligne[i]=tableau_des_pieces[index][0][i];
    }



    for (int m=0; //on parcoure toutes les premières lignes
         premiere_ligne[0]==' ' && premiere_ligne[1]==' ' && premiere_ligne[2]==' ' && premiere_ligne[3]==' ' && premiere_ligne[4]==' '; //Valeur arbitraire
         //tant qu'il n'y a pas un seul '2' dans la première ligne
        m++)
    {

        // la première ligne est vide donc on monte toutes les lignes d'un cran
        for (int ligne=0;
            ligne!=4;
            ligne++)
        {
            for (int colonne=0;
                colonne!=5;
                colonne++)
            {
                tableau_des_pieces[index][ligne][colonne]=tableau_des_pieces[index][ligne+1][colonne]; //la ligne active prend les valeurs de la ligne du dessous

            }
        }

        for (int colonne=0;
            colonne!=5;
            colonne++)
        {
            //la dernière ligne devient vide
            //c'est comme si elle prenait les valeurs de la première ligne (cela forme un cycle)
            tableau_des_pieces[index][4-m][colonne]=' '; //
        }

        for (int i=0; i!=5; i++)
        {
            premiere_ligne[i]=tableau_des_pieces[index][0][i];
        }


    }

    mettreagauche(tableau_des_pieces, index);
}

void mettreagauche(char tableau_des_pieces[21][5][5], int index)
{
    //affichage_piece(tableau_des_pieces, index);
    char premiere_colonne[5];
    for (int i=0; i!=5; i++)
    {
        premiere_colonne[i]=tableau_des_pieces[index][i][0];

    }

    for (int m=0; //on parcoure toutes les premières colonnes
         premiere_colonne[0]==' ' && premiere_colonne[1]==' ' && premiere_colonne[2]==' '&& premiere_colonne[3]==' ' && premiere_colonne[4]==' ';
         //premiere_colonne.find('2')==std::string::npos; // pour d'obscures raisons, cette boucle est infini
         m++)
    {
        std::cout << "jambon";
        for (int ligne=0;
            ligne!=4;
            ligne++)
        {
            for (int colonne=0;
                colonne!=5;
                colonne++)
            {
                tableau_des_pieces[index][ligne][colonne]=tableau_des_pieces[index][ligne][colonne+1]; //la ligne active prend les valeurs de la ligne du dessous

            }
        }

        for (int ligne=0;
            ligne!=5;
            ligne++)
        {
            //la dernière ligne devient vide
            //c'est comme si elle prenait les valeurs de la première ligne (cela forme un cycle)
            tableau_des_pieces[index][ligne][4-m]=' '; //
        }

        for (int i=0; i!=5; i++)
        {
            premiere_colonne[i]=tableau_des_pieces[index][i][0];
        }


    }

}
