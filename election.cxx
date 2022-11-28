#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>    // std::sort

#include "election.h"

using namespace std;

void election::initListeJeux (vector <Jeux> & ListeJeux) // Cette fonction modifie un tableau de struct <Jeux> de tel sort à ce qu'il contienne les 4 jeux sujets au vote : CS:GO, SFII, Civ6 et Mario Kart.
{
    ListeJeux.resize(4);
    ListeJeux[0].name = "Counter-Strike: Global Offensive";
    ListeJeux[1].name = "Street Fighter II";
    ListeJeux[2].name = "Civilisation VI";
    ListeJeux[3].name = "Mario Kart";
    for (unsigned i = 0; i < ListeJeux.size(); ++i)
    {
        ListeJeux[i].nbPoints = 0;
    }
}

void election::ajoutInfosDansVecteur(vector <InfoVotant> & ListeVotant) // Cette fonction injecte les informations de tout les votants à partir du fichier entrée dans un tableau de struct <InfoVotant>.
{
    int ligneParcourue = 0;
    int i = 0;
    while (true)
    {
        string str;
        getline(cin,str);
        ++ligneParcourue;
        if (ligneParcourue%3 == 1)
        {
            ListeVotant.resize(ListeVotant.size()+1);
            ListeVotant[i].NOM = str;
        }
        if (ligneParcourue%3 == 2)
        {
            ListeVotant[i].PRENOM = str;
        }
        if (ligneParcourue%3 == 0)
        {
            for (unsigned j = 0; j < str.size(); ++j)
            {
                ListeVotant[i].VOTES.push_back(int(str[j]-48));
            }
            ++i;
        }
    if (cin.eof ()) break;
    }
    ListeVotant.resize(ListeVotant.size()-1);
}

void election::comptabilisationVotes(vector <InfoVotant> & ListeVotant,vector <Jeux> & ListeJeux) // Cette fonction permet de comptabiliser les votes contenues dans le tableau ListeVotant et de les ajouter dans le tableau ListeJeux.
{
    for (unsigned i = 0; i < ListeVotant.size(); ++i)
    {
        for (unsigned j = 0; j < ListeVotant[i].VOTES.size(); ++j)
        {
                ListeJeux[ListeVotant[i].VOTES[j]-1].nbPoints = ListeJeux[ListeVotant[i].VOTES[j]-1].nbPoints+3-j;
        }
    }
}

bool election::orderBynbPoints (const Jeux & J1, const Jeux & J2) // Cette fonction renvoie un booléen permettant de trier (via la fonction sort()) le vecteur ListeJeux par le nombre de points reçus dans l'ordre décroissant.
{
    return J1.nbPoints >= J2.nbPoints;
}

void election::Sortie (vector <Jeux> & ListeJeux) // Cette fonction est dédié à envoyer sur la sortie standard cout les résultats des votes.
{
    if (ListeJeux[0].nbPoints > ListeJeux[1].nbPoints)
    {
        cout << "Le jeu préféré de la promo est : " << ListeJeux[0].name << " avec " << ListeJeux[0].nbPoints << " points !" << endl
             << "Suivi de " << ListeJeux[1].name << " avec " << ListeJeux[1].nbPoints << " points, de "
             << ListeJeux[2].name << " avec " << ListeJeux[2].nbPoints << " points, et enfin "
             << ListeJeux[3].name << " avec " << ListeJeux[3].nbPoints << " points, le jeu le moins aimé de la promo.";
    }
    else if (ListeJeux[0].nbPoints == ListeJeux[1].nbPoints)
    {
        if (ListeJeux[1].nbPoints > ListeJeux[2].nbPoints)
        {
            cout << "La promo a 2 jeux préférés ! " << ListeJeux[0].name << " et " << ListeJeux[1].name << " avec " << ListeJeux[0].nbPoints << " points chacun !" << endl
                 << "Suivi de " << ListeJeux[2].name << " avec " << ListeJeux[2].nbPoints << " points, et enfin "
                 << ListeJeux[3].name << " avec " << ListeJeux[3].nbPoints << " points, le jeu le moins aimé de la promo.";
        }
        else
        {
            if (ListeJeux[2].nbPoints > ListeJeux[3].nbPoints)
            {
                cout << "La promo a 3 jeux préférés ! " << ListeJeux[0].name << "," << ListeJeux[1].name << " et " << ListeJeux[2].name << " avec " << ListeJeux[0].nbPoints << " points chacun !" << endl
                     << "Le jeu le mons apprécié est " << ListeJeux[3].name << " avec " << ListeJeux[3].nbPoints << " points.";
            }
            else
            {
                cout << "La promo apprécie tout les jeux proposés de la même façon, en effet, tout les jeux ont " << ListeJeux[0].nbPoints << " points chacun ! Tout le monde est content !";
            }
        }
    }
}
