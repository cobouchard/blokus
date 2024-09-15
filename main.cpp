#include "header_gestion_plateau.h"
#include "constantes.h"
int main()
{
    char le_plateau_jeu[DIMENSION][DIMENSION]={};
    char tableau_des_pieces[21][5][5]={' '};
    Joueur le_tableau_joueurs [4];
    jeu(tableau_des_pieces, le_tableau_joueurs, le_plateau_jeu);
    return 0;
}
