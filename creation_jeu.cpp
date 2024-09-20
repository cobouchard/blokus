#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

#include "constantes.h"
#include "header_creation_jeu.h"
#include <string>

void init_plateau(char plateau[DIMENSION][DIMENSION])
{

    for (int une_ligne=0; une_ligne!=DIMENSION; une_ligne++)
    {
        for (int une_colonne=0; une_colonne!=DIMENSION; une_colonne++)
        {
            plateau[une_ligne][une_colonne]=' '; //initialisation du plateau avec des '.' partout
        }
    }
}

void init_tableau_joueurs(Joueur tableau_joueurs[], int & nombre_joueur)
{
    //entrée du nombre de joueurs
    std::cout << "Entrez le nombre de joueurs" << '\n';
    do
    {
        std::cin >> nombre_joueur; //merci de ne pas rentrer une chaine de caractères
        if (nombre_joueur<2 || nombre_joueur>4)
        {
            std::cout << "Rentrez une autre valeur (il y a entre 2 et 4 joueurs)" << '\n';
        }
    }
    while(nombre_joueur<2 || nombre_joueur>4);
    init_tableau_joueurs_fixe(tableau_joueurs, nombre_joueur);

    //entrée des pseudos de chacun


    for (int i=0; i!=nombre_joueur; i++)
    {
        std::string prenom_joueur;
        std::cout << "Entrez le pseudo du joueur (11 caracteres de l'alphabet latin) : " << i+1 << '\n';
        //J'ai choisi de mettre la limite à 11 caractères car mon père 
        //n'était pas content de ne pas pouvoir mettre son nom en entier
        do
        {
            std::cin >> prenom_joueur;
            if (prenom_joueur.size()>11 || prenom_joueur.size()==0)
            {
                std::cout << "Le nom doit être compris entre 1 et 11 caractères !!" << '\n';
            }
            else
            {
                tableau_joueurs[i].pseudo=prenom_joueur;
            } 
        }
        while(prenom_joueur.size()>11 || prenom_joueur.size()==0);

        //pour la sauvegarde les pseudos doivent faire 11 caractères
        while (tableau_joueurs[i].pseudo.size()!=11)
        {
            tableau_joueurs[i].pseudo.push_back(' ');
        }
    }


    //initialisation des pièces des joueurs et des rotations (pour la sauvegarde)
    for (int i=0; //pour chaque joueur
         i!=nombre_joueur;
         i++)
    {
        for(int k=0; //pour chaque pièce de chaque joueur
            k!=21;
            k++)
        {
            tableau_joueurs[i].Pieces_restantes[k]=true;
            tableau_joueurs[i].rotations_pieces[k]=0;
            tableau_joueurs[i].positions_x[k]=21; //valeur impossible pour signifier que la pièce n'a pas été joué
            tableau_joueurs[i].positions_y[k]=21;
        }
    }


}

void init_tableau_joueurs_fixe(Joueur tableau_joueurs[], int & nombre_joueur)
{

    //initialisation des couleurs
    Couleur liste_couleur [4] = {Rouge, Bleu, Jaune, Vert};
    int liste_prise [3] = {5,5,5};

    Couleur une_couleur;

    srand (time(NULL));

    for (int i=0;
         i!=nombre_joueur;
         i++)
    {
        tableau_joueurs[i].sonChar=i+49;

        une_couleur = liste_couleur[rand()%4];

        if (!i)
        {
            tableau_joueurs[i].sacouleur = une_couleur;
            liste_prise[i] = une_couleur;
        }

        else
        {
            while (une_couleur==liste_prise [0] ||
                   une_couleur==liste_prise [1] ||
                   une_couleur==liste_prise [2])
            {
                une_couleur = liste_couleur[rand()%4];
                //std::cout << une_couleur << '\n';
            }

            tableau_joueurs[i].sacouleur = une_couleur;
            liste_prise[i] = une_couleur;

        }

    }

    //initialisation du premier placement d'origine de chaque joueur
    tableau_joueurs[0].position_x_origine=0;
    tableau_joueurs[0].position_y_origine=0;

    tableau_joueurs[1].position_x_origine=0;
    tableau_joueurs[1].position_y_origine=19;

    tableau_joueurs[2].position_x_origine=19;
    tableau_joueurs[2].position_y_origine=0;

    tableau_joueurs[3].position_x_origine=19;
    tableau_joueurs[3].position_y_origine=19;

}

/* for windows users
void affichage_espace_colore(Joueur tableau_joueurs[], int numero_joueur)
{
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    int i = tableau_joueurs[numero_joueur].sacouleur;
    SetConsoleTextAttribute(h,i);
    std::cout << ' ' ;
    SetConsoleTextAttribute(h,15);
} */

void setTextColor(int color)
{
    std::cout << "\033[" << color << "m";
}

// Function to reset the text color to default
void resetTextColor()
{
    std::cout << "\033[0m";
}

void affichage_espace_colore(Joueur tableau_joueurs[], int numero_joueur)
{
    // Map sacouleur to appropriate ANSI color code
    int color_code;
    int sacouleur = tableau_joueurs[numero_joueur].sacouleur;

    switch (sacouleur)
    {
        case 1: color_code = 31; break; // Red
        case 2: color_code = 32; break; // Green
        case 3: color_code = 33; break; // Yellow
        case 4: color_code = 34; break; // Blue
        case 5: color_code = 35; break; // Magenta
        case 6: color_code = 36; break; // Cyan
        case 7: color_code = 37; break; // White
        default: color_code = 37; break; // Default to white if unknown color
    }

    setTextColor(color_code);   // Set the specified color
    std::cout << ' ';           // Output a colored space
    resetTextColor();           // Reset color to default
}

void affichage_plateau(char plateau[DIMENSION][DIMENSION], Joueur tableau_joueurs[], char tableau_des_pieces[21][5][5], int joueur_actif)
{

    //affichage des coordonées x en haut du plateau de jeu :
    for (int i=0; i!=20; i++)
        std::cout << ' '; //placement des dizaines à partir de 10


    for (int i=0; i!=11; i++) //affichage des dizaines
    {
        if (i==10) //si on arrive à la vingtaine
        {
            std::cout << '2' << '\n';
        }

        else //chiffre des dizaines
        {
            std::cout << '1' << ' ';
        }
    }

    affichage_espace_colore(tableau_joueurs, 0);
    std::cout << ' ' ;

    for (int i=1; i!=21; i++)
    {
        std::cout << i%10 << ' '; // chiffre des unités donc modulo 10
    }

    affichage_espace_colore(tableau_joueurs, 1);

    //ici affichage du numéro des pièces
    for (int i=1; i!=22; i++)
    {
        std::cout << i;
        for (int i =0; i!=5; i++)
            std::cout << ' ';
    }
    std::cout << '\n';




    for (int une_ligne=0; une_ligne!=DIMENSION; une_ligne++)
    {

        char une_lettre= 'A' + une_ligne;
        std::cout << une_lettre << ' '; //affichage des coordonées y (letre de A à T)

        for (int une_colonne=0; une_colonne!=20; une_colonne++)
        {
            char var = plateau[une_ligne][une_colonne];
            switch(var)
            {
            case ' ': std::cout << '.'; break;
            case '1': affichage_espace_colore(tableau_joueurs,0); break;
            case '2': affichage_espace_colore(tableau_joueurs,1); break;
            case '3': affichage_espace_colore(tableau_joueurs,2); break;
            case '4': affichage_espace_colore(tableau_joueurs,3); break;
            }
            std::cout << ' '; // affiche toutes les cases du jeu
        }



        if (une_ligne<5) //ici on va afficher toutes les pièces à droite
        {
            for (int numero_piece=0; numero_piece!=21; numero_piece++)
            {
                for (int une_colonne=0; une_colonne!=5; une_colonne++)
                {
                    //std::cout << tableau_joueurs[joueur_actif].Pieces_restantes[numero_piece];
                    if(tableau_joueurs[joueur_actif].Pieces_restantes[numero_piece])
                    {
                        if (tableau_des_pieces[numero_piece][une_ligne][une_colonne]!=' ')
                        {
                            affichage_espace_colore(tableau_joueurs, joueur_actif);
                        }

                        else
                        {
                            std::cout << ' ';
                        }
                    }



                }

                std::cout << ' ';
            }
        }


        std::cout << '\n'; //on saute une ligne dès que l'on affiché une ligne en entière
    }
    affichage_espace_colore(tableau_joueurs, 2);

    for (int i=0; i!=DIMENSION*2+1; i++) //pour décaler le dernier coin tout à droite
    {
        std::cout << ' ';
    }


    affichage_espace_colore(tableau_joueurs, 3);
    std::cout << std::endl;
}

/* for windows users
void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  // Get the number of cells in the current buffer //
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  // Fill the entire buffer with spaces //
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  // Fill the entire buffer with the current colors and attributes //
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  // Move the cursor home //
  SetConsoleCursorPosition( hStdOut, homeCoords );
}
*/

void ClearScreen(){
    system("clear");
}
