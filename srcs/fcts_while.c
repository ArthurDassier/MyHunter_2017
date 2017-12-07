/*
** EPITECH PROJECT, 2017
** fcts_while.c
** File description:
** fcts_boucle
*/

#include "myhunter.h"

int textrs(game_s *game, graphs *graph)
{
	sfSprite_setTexture(graph->sprite2, graph->texture2, sfTrue);
	sfRenderWindow_drawSprite(game->window, graph->sprite, NULL);
	sfRenderWindow_drawSprite(game->window, graph->sprite2, NULL);
	sfSprite_setPosition(graph->sprite2, graph->position);
	return(analys_ev(game->event, game->window, graph));
}

int movemts(graphs *graph)
{
	graph->position.x = graph->position.x + graph->v;
	if (graph->position.x >= 1900)
		return (300);
	return(0);
}

void anim(graphs *graph)
{
	if (graph->i == 11)
	graph->i = 0;
	graph->texture2 = sfTexture_createFromFile("./textures/OUASO.png",
						&graph->animation[graph->i]);
	graph->i++;
}
