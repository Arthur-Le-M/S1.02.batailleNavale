#include "sousProgrammes.h"

void afficherRegles()
{
    afficherTexteEnCouleur("B A T A I L L E  N A V A L E",bleu,true);
    cout << endl;
    cout << "Vous devez couler un bateau de 4 cases" << endl;
    cout << "(vertical ou horizontal ou diagonal)." << endl;
    cout << endl;
}


void afficherGrille(char tableau[][9], unsigned int nbLigne, unsigned int nbColonne)
{
    // Declaration des indices des boucles 
    unsigned int i;
    unsigned int j;

    cout << "  A B C D E F G H I" << endl;

    for (i = 0; i <= (nbLigne-1) ; i++)
    {
        cout << i+1 << " ";
        
        for (j = 0; j <= (nbColonne-1); j++)
        {
            cout << tableau[i][j] << " ";
        }

        // Passage à la ligne
        cout << endl;
    }
    

}


void placerBateau(coordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau)
{
    // VARIABLES
    coordonnee coordBateau;
    bool erreur = true; // condition d'arrêt
    unsigned short int sensBateau; // Sens dans lequel sera le bateau (compris entre 1 et 4)

    while(erreur == true)
    {
        cout << "Début de la boucle" << endl;
        // INITIALISATION
        // Déterminer la coordonnée de base du bateau
        coordBateau.coordX = random(0, largeurPlateau-1);
        cout << "Minimum = " << 0 << " Maximum = " << largeurPlateau-1 << " Random(min, max) = " << random(0, largeurPlateau-1) << endl;
        coordBateau.coordY = random(0, largeurPlateau-1);
        tableau[0] = coordBateau;
        cout << "Coordonnées de base : " << tableau[0].coordX << tableau[0].coordY << endl;
        // Mettre erreur a true
        erreur=true;
        // Determiner dans quel sens sera le bateau
        sensBateau = random(1,4);
        cout << "Coordonnées de base : " << tableau[0].coordX << tableau[0].coordY << endl;

        // PLACEMENT DU BATEAU
        for(unsigned int i=0; i < longueurBateau; i++){
            cout << "Début de la boucle" << endl;
            switch (sensBateau)
            {
            case 1:
                if(tableau[0].coordX + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    coordBateau.coordX = tableau[i-1].coordX+1;
                    coordBateau.coordY = tableau[i-1].coordY;
                    tableau[i] = coordBateau;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 2:
                if(tableau[0].coordY + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    coordBateau.coordX = tableau[i-1].coordX;
                    coordBateau.coordY = tableau[i-1].coordY+1;
                    tableau[i] = coordBateau;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 3:
                if(tableau[0].coordY + longueurBateau < largeurPlateau && tableau[0].coordY + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    coordBateau.coordX = tableau[i-1].coordX+1;
                    coordBateau.coordY = tableau[i-1].coordY+1;
                    tableau[i] = coordBateau;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 4:
                if(tableau[0].coordY - longueurBateau > largeurPlateau && tableau[0].coordY - longueurBateau > largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    coordBateau.coordX = tableau[i-1].coordX-1;
                    coordBateau.coordY = tableau[i-1].coordY-1;
                    tableau[i] = coordBateau;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            default:
                break;
            }
            }
    }
}    


