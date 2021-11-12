/*
Nom du programme : Bataille Navale
But du programme : faire jouer une bataille navale
Auteur du programme : Arthur Le Menn / Matis Chabanat
Date de dernière modification : 10/11/2021
*/

#include<iostream>
using namespace std;

int main(void){
    //VARIABLES
    unsigned int const NB_COLONNES = 9; // Nombre de colonnes du plateau
    unsigned int const NB_LIGNES = 9; // Nombre de lignes du platea
    char plateau[NB_LIGNES][NB_COLONNES]{' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ','o',' ',' ',' ',' ',
                                        ' ',' ',' ',' ','.',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
                                        ' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
    cout << "  A B C D E F G H I" << endl;
    for(int i =0; i < NB_LIGNES; i++){
        cout << i+1 << " ";
        for(int y =0; y < NB_COLONNES; y++){
            cout << plateau[i][y] << " ";
        }
        cout << endl;
    }
}