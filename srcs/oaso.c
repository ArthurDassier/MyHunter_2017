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

void my_init(graphs *graph)
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

int kill(sfRenderWindow *window, graphs *graph)
{
	if (sfMouse_getPositionRenderWindow(window).x >= graph->pstn.x &&
	sfMouse_getPositionRenderWindow(window).x <= graph->pstn.x + 75) {
		if (sfMouse_getPositionRenderWindow(window).y >= graph->pstn.y
		&& sfMouse_getPositionRenderWindow(window).y <= graph->pstn.y + 85) {
			graph->pstn.x = -100;
			graph->pstn.y = rand()%790;
			graph->v = graph->v + 2;
			return(1);
		}
	}
	return(0);
}
