/*
** EPITECH PROJECT, 2017
** oaso.c
** File description:
** cuicui
*/

#include "myhunter.h"

sfIntRect oiseau(int a, int b, int c, int d)
{
	sfIntRect taille;
	taille.height = a;
	taille.left = b;
	taille.top = c;
	taille.width = d;
	return(taille);
}

void my_init(struct game_s *game)
{
	game->tableau_taille[0] = oiseau(85, 228, 0, 75);
	game->tableau_taille[1] = oiseau(85, 0, 86, 75);
	game->tableau_taille[2] = oiseau(85, 456, 0, 75);
	game->tableau_taille[3] = oiseau(85, 380, 0, 75);
	game->tableau_taille[4] = oiseau(85, 304, 0, 75);
	game->tableau_taille[5] = oiseau(85, 228, 0, 75);
	game->tableau_taille[6] = oiseau(85, 152, 0, 75);
	game->tableau_taille[7] = oiseau(85, 76, 0, 75);
	game->tableau_taille[8] = oiseau(85, 0, 0, 75);
	game->tableau_taille[9] = oiseau(85, 152, 0, 75);
}
