/*
** EPITECH PROJECT, 2017
** fcts_while.c
** File description:
** lesplsss
*/

#include "myhunter.h"

int call(struct game_s *game)
{
	close_ev(game->event, game->window);
	sfSprite_setTexture(game->sprite, game->texture, sfTrue);
	sfSprite_setTexture(game->sprite2, game->texture2, sfTrue);
	sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
	sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
	sfSprite_setPosition(game->sprite2, game->position);
}
