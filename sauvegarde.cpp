#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

#include <header_creation_jeu.h>
#include <header_gestion_plateau.h>
#include <header_gestion_pieces.h>


char BitsToChar(int nb_bit, bool chaine[])
{
    int rien=0;
    for (int i=0;
        i!=nb_bit;
        i++)
    {
        if (chaine[i]==true)
        {
        	rien += pow (2, nb_bit-1-i);
            //std::cout << rien << std::endl;;
        }
    }
    //std::cout << rien;
    return rien;
}

void intToBits(int nb_bit, bool chaine[], int nombre, int depart)
{
    for (int i=0;
         i!=nb_bit;
         i++)
    {
        int puissance2=pow (2, nb_bit-1-i);
        if (nombre-puissance2>=0)
        {
            nombre-=puissance2;
            chaine[i+depart]=true;
        }
        else
        {
            chaine[i+depart]=false;
        }
    }
}

void CharToBits(int nb_bit, bool chaine[], char unChar)
{
    int a=unChar;
    //std::cout << a;
    for (int i=0;
         i!=nb_bit;
         i++)
    {
        int puissance2=pow(2, nb_bit-1-i);
        if (a-puissance2>=0)
        {
            a-=puissance2;
            chaine[i]=true;
        }
        else
        {
            chaine[i]=false;
        }
    }
}

int BitsToInt(int nb_bit, bool chaine[])
{
	int leInt=0;
    for (int i=0;
        i!=nb_bit;
        i++)
    {
        if (chaine[i])
        {
            leInt+=pow(2,((nb_bit-1))-i);
        }
    }
	return leInt;
}

void sauvegarde(Joueur tableau_joueur[], int nb_joueur)
{
    std::string sauvegarde="";
    bool tout[256];
    for (int i=0;
         i!=nb_joueur;
         i++)
    {
        for (int k=0;
             k!=21;
             k++)
        {
            tableau_joueur[i].rotations_pieces[k]=tableau_joueur[i].rotations_pieces[k]%4;
        }
    }

    //création de la chaine qui stockera TOUTES les informations pour recharger la partie

    for (int unjoueur=0;
         unjoueur!=nb_joueur;
         unjoueur++) //on sauvegarde pour n joueur
    {
        //sauvegarde du nom sur 11 caractères
        for (int k=0; k!=11; k++)
        {
            sauvegarde.push_back(tableau_joueur[unjoueur].pseudo[k]);
        }

        //sauvegarde de la position de toutes les pièces

        for (int piece=0; //on sauvegarde chaque pièce
             piece!=21;
             piece++)
        {
            //position x

            intToBits(5, tout, tableau_joueur[unjoueur].positions_x[piece], piece*12+0);

            //position y
            intToBits(5, tout, tableau_joueur[unjoueur].positions_y[piece], piece*12+5);

//            std::cout << "position y :" <<  tableau_joueur[unjoueur].positions_y[piece];
//            std::cout << tout[piece*12+5];
//            std::cout << tout[piece*12+1+5];
//            std::cout << tout[piece*12+2+5];
//            std::cout << tout[piece*12+3+5];
//            std::cout << tout[piece*12+4+5];
//            std::cout << std::endl;

            //rotation
            intToBits(2, tout, tableau_joueur[unjoueur].rotations_pieces[piece], piece*12+10);
        }

        //on convertit chaque 8 bits en UN caractère
        for (int byte=0; byte!=31; byte++)
        {
            bool chaine[8];
            for (int i=0; i!=8; i++) //on remplit un octet avant de le convertir
            {
                chaine[i]=tout[byte*8+i];
                std::cout << byte*8+i;
                //std::cout << chaine[i];
            }
            std::cout << std::endl;
            sauvegarde.push_back(BitsToChar(8, chaine));
        }

        //le 32ème octet étant coupé, on le traite séparrément
        bool chaine[8];

//        for (int i=0; i!=8; i++)
//        {
//            if (i<4)
//                chaine[i]=tout[31*8+i];

//            else
//                chaine[i]=false;
//        }

        sauvegarde.push_back(BitsToChar(8, chaine));


    }

    std::ofstream Fichier("data.txt", std::ios_base::binary);
    Fichier << sauvegarde;
    Fichier.close();
}

void charger(char tableau_des_pieces[21][5][5], Joueur tableau_joueurs[], char le_plateau_jeu[DIMENSION][DIMENSION])
{
    std::ifstream Fichier("data.txt", std::ios_base::binary);
    std::string Tout="";
    std::getline (Fichier, Tout);

    //on sait que chaque joueur est enregistré sur 43 octets, on peut donc assez simplement récupérer le nombre de joueur
    int nb_joueur = Tout.size()/43;
    init_tableau_joueurs_fixe(tableau_joueurs, nb_joueur);

    //on récupère toutes les informations pour tout les joueurs

    for (int joueur=0;
         joueur!=nb_joueur;
         joueur++)
    {
        // récupération du nom
        for (int i=0;
             i!=11;
             i++)
        {
            tableau_joueurs[joueur].pseudo.push_back(Tout[joueur*43+i]);
        }

        //on récupère les informations relatives au pièces pour le joueur
        //std::string infoPiece="";
        bool chaineBits[256];

        for (int i=0;
             i!=32;
             i++)
        {
            bool chaineTemp[8];
            //infoPiece.push_back(Tout[joueur*43+11+i]);
            CharToBits(8, chaineTemp, Tout[joueur*43+11+i]);
            for (int k=0;
                 k!=8;
                 k++)
            {
                chaineBits[i*8+k]=chaineTemp[k];
            }
        }


        // placement des pièces

        for (int piece=0;
             piece!=21;
             piece++)
        {
            bool chaineX[5];
            bool chaineY[5];
            bool chaineRotation[2];

            for (int i=0;
                 i!=5;
                 i++)
            {
                chaineX[i]=chaineBits[piece*12+i+0];
            }

            for (int i=0;
                 i!=5;
                 i++)
            {
                chaineX[i]=chaineBits[piece*12+i+5];
            }

            for (int i=0;
                 i!=2;
                 i++)
            {
                chaineX[i]=chaineBits[piece*12+i+10];
            }

            int position_x=BitsToInt(5, chaineX);
            int position_y=BitsToInt(5, chaineY);
            int rotation=BitsToInt(2, chaineRotation);

            if (position_x==21 || position_y==21)
                tableau_joueurs[joueur].Pieces_restantes[piece]=true;
            else
            {
                for (int i=0;
                     i!=rotation;
                     i++)
                    rotation_piece_horaire(tableau_des_pieces, piece);
                placement_reel(tableau_des_pieces, piece, le_plateau_jeu, position_x, position_y, tableau_joueurs, joueur);
            }

        }
    }

}

/*
int main()
{

    bool chaine[5];
    //intToBits(5, chaine, 24, 0);
    //std::cout << BitsToInt (5, chaine);
    char unC='A';
    CharToBits(8, chaine, unC);
    std::cout << BitsToChar (8, chaine);
    
    //chaine[0]=false;
    //chaine[1]=true;
    //chaine[2]=false;
    //chaine[3]=true;
    //chaine[4]=true;
    //char unC = BitsToChar(5, chaine);
    //CharToBits(5, chaine, unC);
//    chaine[5]=true;
//    chaine[6]=true;
//    chaine[7]=false;
	//std::cout << BitsToInt(5, chaine);
    
	for (int i=0;i!=8; i++)
    {
    	//std::cout << chaine[i];
    }

//    std::cout << '\n';

//    std::cout<<BitsToChar(chaine);
}
*/
