#ifndef ELECTION_H
#define ELECTION_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>    // std::sort

struct Jeux // Struct contenant le nom et le nombre de votes d'un jeu.
{
    std::string name;
    unsigned nbPoints;
};
struct InfoVotant //Struct contenant le nom, le prénom et les votes de l'élève/votant.
{
    std::string NOM;
    std::string PRENOM;
    std::vector <unsigned> VOTES;
};

namespace election
{

void initListeJeux (std::vector <Jeux> & ListeJeux);
// Cette fonction modifie un tableau de struct <Jeux> de tel sorte à ce qu'il contienne les 4 jeux sujets au vote : CS:GO, SFII, Civ6 et Mario Kart.

void ajoutInfosDansVecteur (std::vector <InfoVotant> & ListeVotant);
// Cette fonction injecte les informations de tout les votants à partir du fichier entrée dans un tableau de struct <InfoVotant>.

void comptabilisationVotes(std::vector <InfoVotant> & ListeVotant,std::vector <Jeux> & ListeJeux);
// Cette fonction permet de comptabiliser les votes contenues dans le tableau ListeVotant et de les ajouter dans le tableau ListeJeux.

bool orderBynbPoints (const Jeux & J1, const Jeux & J2);
// Cette fonction renvoie un booléen permettant de trier (via la fonction sort()) le vecteur ListeJeux par le nombre de points reçus dans l'ordre décroissant.

void Sortie (std::vector <Jeux> & ListeJeux);
// Cette fonction est dédié à envoyer sur la sortie standard cout les résultats des votes.

}
#endif // ELECTION_H
