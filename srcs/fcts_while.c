/*
** EPITECH PROJECT, 2017
** fcts_while.c
** File description:
** lesplsss
*/

#include "myhunter.h"

void textrs(struct game_s *game, struct graphs *graph)
{
	close_ev(game->event, game->window);
	sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
	sfSprite_setTexture(graph->sprite2, graph->texture2, sfTrue);
	sfRenderWindow_drawSprite(game->window, graph->sprite, NULL);
	sfRenderWindow_drawSprite(game->window, graph->sprite2, NULL);
	sfSprite_setPosition(graph->sprite2, graph->position);
}

void movemts(struct graphs *graph)
{
	graph->position.x = graph->position.x + 8;
	if (graph->position.x >= 1900) {
		graph->position.x = 0;
		graph->position.y = rand()%790;
	}
}

void anim(struct graphs *graph)
{
	if (graph->i == 10)
		graph->i = 0;
	graph->texture2 = sfTexture_createFromFile("./textures/OUASO.png",
						&graph->animation[graph->i]);
	graph->i++;
}
