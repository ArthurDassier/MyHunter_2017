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

void my_init(struct graphs *graph)
{
	graph->animation[0] = oiseau(83, 0, 87, 75);
	graph->animation[1] = oiseau(85, 456, 0, 75);
	graph->animation[2] = oiseau(85, 380, 0, 75);
	graph->animation[3] = oiseau(85, 304, 0, 75);
	graph->animation[4] = oiseau(85, 228, 0, 75);
	graph->animation[5] = oiseau(85, 152, 0, 75);
	graph->animation[6] = oiseau(85, 76, 0, 75);
	graph->animation[7] = oiseau(85, 0, 0, 75);
	graph->animation[8] = oiseau(85, 152, 0, 75);
	graph->animation[9] = oiseau(85, 228, 0, 75);
	graph->animation[10] = oiseau(85, 380, 0, 75);
}

void kill(sfRenderWindow *window, struct graphs *graph)
{
	if (sfMouse_getPositionRenderWindow(window).x >= graph->position.x &&
	sfMouse_getPositionRenderWindow(window).x <= graph->position.x + 75) {
		if (sfMouse_getPositionRenderWindow(window).y >= graph->position.y &&
		sfMouse_getPositionRenderWindow(window).y <= graph->position.y + 85) {
			graph->position.x = 0;
			graph->position.y = rand()%790;
			graph->v = graph->v + 2;
		}
	}
}