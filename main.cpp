#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>    // std::sort

#include "election.h"

using namespace std;
using namespace election;

int main()
{
    vector <Jeux> ListeJeux;
    initListeJeux(ListeJeux); // Cette fonction modifie un tableau de struct <Jeux> de tel sorte à ce qu'il contienne les 4 jeux sujets au vote : CS:GO, SFII, Civ6 et Mario Kart.
    vector <InfoVotant> ListeVotant; // initialisation d'un tableau à deux dimensions contenant dans chaque case les infos du votant (Nom, Prénom ,Votes)
    ajoutInfosDansVecteur(ListeVotant); // Cette fonction injecte les informations de tout les votants à partir du fichier entrée dans un tableau de struct <InfoVotant>.
    comptabilisationVotes(ListeVotant,ListeJeux); // Cette fonction permet de comptabiliser les votes contenues dans le tableau ListeVotant et de les ajouter dans le tableau ListeJeux.
    sort (ListeJeux.begin(), ListeJeux.end(), orderBynbPoints); // permet de trier le tableau ListeJeux par le Nombre de points dans un ordre décroissant.
    Sortie(ListeJeux); // Cette fonction est dédié à envoyer sur la sortie standard cout les résultats des votes.
}
