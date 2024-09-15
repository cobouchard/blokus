/* Vérification de la possibilité d'un coup :
 * -La pièce est entièrement dans le plateau (physique)
 * -La pièce peut être entièrement posé, aucune case n'est prise (physique)
 * -Un coin de la pièce touche le coin d'une pièce alliée
 * -Aucun morceau touche le morceau d'une pièce alliée
 *
 *  Informations nécéssaires : numéro de pièce, position, joueur, matrice du jeu
 *
 */


/* Que faire :
 * Faire la fonction de remplissage du tableau quand la pièce peut être placé
 * Vérifier que le placement physique et le remplissage fonctionne
 * Faire la fonction placement_moral()
 * Check encore
 *
*/

#include <iostream>
#include <string>

#include "constantes.h"
#include "header_gestion_plateau.h"
#include "header_creation_jeu.h"
#include "header_gestion_pieces.h"
#include "header_sauvegarde.h"

bool case_pleine(char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y)
{
    bool test=false;
    //la position est en dehors du plateau, c'est donc forcément vide
    if (position_x<0 || position_x >19 || position_y<0 || position_y >19)
    {
        test=true;
    }

    else if (le_plateau_jeu[position_x][position_y]!=' ')
    {
        test=true;
    }

    return test;
}

bool case_pleine(char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, char joueur)
{
    bool test=false;
    //la position est en dehors du plateau, c'est donc forcément vide
    if (position_x<0 || position_x >19 || position_y<0 || position_y >19)
    {
        test=false;
    }

    else if (le_plateau_jeu[position_x][position_y]==joueur)
    {
        test=true;
    }

    return test;
}

bool placement_physique(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y)
{
    bool test=true; //le test est vrai est si le programme se rend compte
                    //qu'il y a un problème physique alors il retournera faux

    for (int ligne=0;
         ligne!=5;
         ligne++)
    {
        for (int colonne=0;
             colonne!=5;
             colonne++)
        {
            char position_temp=tableau_des_pieces[index_piece][ligne][colonne];


            if (position_temp!=' ')
            {
                //deuxième test : un emplacement est déjà pris par une autre pièce (doit être faux)
                if (case_pleine(le_plateau_jeu,position_x,position_y))
                {
                    test=false;
                }
            }

        }
    }

    return test;
}

bool placement_moral(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif)
{
    bool test1=false; //la pièce est rattaché à un coin (doit être vraie)
    bool test2=true;  //la pièce n'est pas collée à un morceau de pièce amie (doit être faux)
    bool test1_ultime=false; //la pièce est attaché à son coin du plateau

    for (int ligne=0;
         ligne!=5;
         ligne++)
    {
        for (int colonne=0;
             colonne!=5;
             colonne++)
        {

            char position_temp=tableau_des_pieces[index_piece][ligne][colonne];
            //std::cout << position_temp;

            if (position_temp!=' ')
            {
                //std::cout << ligne << colonne ;
//                position_x_var=position_x+ligne;
//                position_y_var=position_y+ligne;
                //test 1 :
                if (case_pleine(le_plateau_jeu,position_x+ligne+1,position_y+colonne+1,tableau_joueurs[joueur_actif].sonChar) || //coin en haut à droite
                    case_pleine(le_plateau_jeu,position_x+ligne+1,position_y+colonne-1,tableau_joueurs[joueur_actif].sonChar) || //coin en haut à gauche
                    case_pleine(le_plateau_jeu,position_x+ligne-1,position_y+colonne+1,tableau_joueurs[joueur_actif].sonChar) || //coin en bas à droite
                    case_pleine(le_plateau_jeu,position_x+ligne-1,position_y+colonne-1,tableau_joueurs[joueur_actif].sonChar))   //coin en bas à gauche
                {
                    test1=true;
                }
                else if (position_x+ligne==tableau_joueurs[joueur_actif].position_x_origine && position_y+colonne==tableau_joueurs[joueur_actif].position_y_origine)
                {
                    test1_ultime=true;
                }
                //test 2 :
                if (case_pleine(le_plateau_jeu,position_x+ligne+1,position_y+colonne,tableau_joueurs[joueur_actif].sonChar) || //décalé vers le haut
                    case_pleine(le_plateau_jeu,position_x+ligne+1,position_y+colonne,tableau_joueurs[joueur_actif].sonChar) || //décalé vers le bas
                    case_pleine(le_plateau_jeu,position_x+ligne,position_y+colonne+1,tableau_joueurs[joueur_actif].sonChar) || //décalé vers la droite
                    case_pleine(le_plateau_jeu,position_x+ligne,position_y+colonne-1,tableau_joueurs[joueur_actif].sonChar))   //décalé vers la gauche
                {
                    //std::cout <<le_plateau_jeu[position_x+1][position_y] << '\n';
//                    std::cout << position_x+ligne-1 << position_y+colonne;
//                    std::cout <<le_plateau_jeu[position_x+ligne-1][position_y+colonne] << '\n';
//                    std::cout <<le_plateau_jeu[position_x][position_y+1] << '\n';
//                    std::cout <<"test" << '\n';
                    test2=false;
                }
            }

        }
    }
//    if (position_x==tableau_joueurs[joueur_actif].position_x_origine && position_y==tableau_joueurs[joueur_actif].position_y_origine)
//    {
//        test1=true;
//    }

    if(test1_ultime)
        test1=true;

    return test1 && test2;
}

bool placement(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif )
{
    //std::cout << "jambon";
    bool test=false;
    if ( placement_physique(tableau_des_pieces, index_piece, le_plateau_jeu, position_x, position_y)
         &&
         placement_moral(tableau_des_pieces, index_piece, le_plateau_jeu, position_x, position_y, tableau_joueurs, joueur_actif) )
    {
        //std::cout << "jambon";
        test=true;
        //fait le placement
        placement_reel(tableau_des_pieces, index_piece, le_plateau_jeu, position_x, position_y, tableau_joueurs, joueur_actif);

    }
    return test;
}

void placement_reel(char tableau_des_pieces[21][5][5], int index_piece, char le_plateau_jeu[DIMENSION][DIMENSION], int position_x, int position_y, Joueur tableau_joueurs[], short joueur_actif)
{
    for (int ligne=0;
         ligne!=5;
         ligne++)
    {
        for (int colonne=0;
             colonne!=5;
             colonne++)
        {
            if (tableau_des_pieces[index_piece][ligne][colonne]!=' ')
            {
                le_plateau_jeu[position_x+ligne][position_y+colonne]=tableau_joueurs[joueur_actif].sonChar;
            }

        }
    }
    tableau_joueurs[joueur_actif].Pieces_restantes[index_piece]=false;
}

bool test_char(char unC)
{
    bool retour=false;
    if (unC>47 && unC <58) //le caractère est un chiffre
    {
        retour=true;
    }

    return retour;
}

void jeu(char tableau_des_pieces[21][5][5], Joueur tableau_joueurs[], char le_plateau_jeu[DIMENSION][DIMENSION])
{
    std::cout << "Bienvenu au jeu du Blokus !" << std::endl;

    remplissage_tableau_pieces(tableau_des_pieces);
    init_plateau(le_plateau_jeu);

    int nb_joueur;
    char recharge;

    std::cout << "Souhaitez vous recharger la dernière partie (o/n) ?" << std::endl;
    std::cin >> recharge;

    if (recharge=='o' || recharge=='O')
    {
        //recharge l'ancienne partie
        charger(tableau_des_pieces, tableau_joueurs, le_plateau_jeu);

    }
    else
    {
        init_tableau_joueurs(tableau_joueurs, nb_joueur);
    }


    while (1)
    {
        for (int joueur_actif=0;
            joueur_actif!=nb_joueur;
            joueur_actif++)
        {
            affichage_plateau(le_plateau_jeu, tableau_joueurs, tableau_des_pieces, joueur_actif);
            std::string reponse;
            int num_piece;
            int position_x;
            int position_y=-1;

            std::cout << "C'est a " << tableau_joueurs[joueur_actif].pseudo << " de jouer !" << '\n';
            std::cout << "Entrez la piece a modifier et jouer" << '\n';
            do
            {
                std::cin >> num_piece;
                std::cin.ignore();

                if ( num_piece<1 || num_piece > 21 || (!(tableau_joueurs[joueur_actif].Pieces_restantes[num_piece-1]) ))
                    std::cout << "Cette piece n'existe pas ou vous l'avez deja joue" << '\n';
            }
            while( num_piece<1 || num_piece > 21 || (!(tableau_joueurs[joueur_actif].Pieces_restantes[num_piece-1]) ));

            std::cout << "entrez n 'r' pour n rotations puis entrez les coordoonées pour votre pièce 'D15' ou entrez 's' pour sauvegarder la partie" << std::endl;
            std::getline(std::cin, reponse);

            if (reponse[0]=='s')
            {
                sauvegarde(tableau_joueurs, nb_joueur);
                return;
            }

            else
            {
                for (unsigned int i=0;
                     i!=reponse.size();
                     i++)
                {
                    if (reponse[i]=='r')
                    {
                        rotation_piece_horaire(tableau_des_pieces, num_piece-1);
                        tableau_joueurs[joueur_actif].rotations_pieces[num_piece]++;
                    }

                    if (reponse[i]>64 && reponse[i]<85) //entrée d'une lettre majuscule de A à T
                    {
                        position_x=reponse[i]-65;
                    }

                    if (test_char(reponse[i]) && position_y==-1)
                    {
                        int bar = reponse[i];

                        if (test_char(reponse[i+1]) && i+1<reponse.size())
                        {
                            int bar2 = reponse[i+1];
                            position_y= (bar-48)*10 + (bar2-48)-1;
                        }
                        else
                        {
                            position_y=(bar-48)-1;
                        }
                    }

                }

                if (placement(tableau_des_pieces, num_piece-1, le_plateau_jeu, position_x, position_y, tableau_joueurs, joueur_actif))
                {
                    tableau_joueurs[joueur_actif].positions_x[num_piece]=position_x;
                    tableau_joueurs[joueur_actif].positions_y[num_piece]=position_y;
                }

                //ClearScreen();
            }


        }
    }

}
