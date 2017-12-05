/*
** EPITECH PROJECT, 2017
** fcts_while.c
** File description:
** lesplsss
*/

#include "myhunter.h"

int call(struct game_s *game, struct graphs *graph)
{
	close_ev(game->event, game->window);
	sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
	sfSprite_setTexture(graph->sprite2, graph->texture2, sfTrue);
	sfRenderWindow_drawSprite(game->window, graph->sprite, NULL);
	sfRenderWindow_drawSprite(game->window, graph->sprite2, NULL);
	sfSprite_setPosition(graph->sprite2, graph->position);
}
