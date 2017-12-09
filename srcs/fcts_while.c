/*
** EPITECH PROJECT, 2017
** fcts_while.c
** File description:
** fcts_boucle
*/

#include "myhunter.h"

int textrs(game_s *game, graphs *graph)
{
	sfSprite_setTexture(graph->bird, graph->text_bird, sfTrue);
	sfRenderWindow_drawSprite(game->window, graph->sprite, NULL);
	sfRenderWindow_drawSprite(game->window, graph->bird, NULL);
	sfRenderWindow_drawSprite(game->window, graph->crosshair, NULL);
	sfSprite_setPosition(graph->bird, graph->pstn);
	sfSprite_setPosition(graph->crosshair, graph->hair);
	return(analys_ev(game->event, game->window, graph));
}

int movemts(game_s *game, graphs *graph)
{
	graph->pstn.x = graph->pstn.x + graph->v;
	if (graph->pstn.x >= 1900)
		return (300);
	graph->hair.x = sfMouse_getPositionRenderWindow(game->window).x - 50;
	graph->hair.y = sfMouse_getPositionRenderWindow(game->window).y - 50;
	return(0);
}

void anim(graphs *graph)
{
	if (graph->i == 11)
	graph->i = 0;
	graph->text_bird = sfTexture_createFromFile("./textures/OUASO.png",
						&graph->animation[graph->i]);
	graph->i++;
}
