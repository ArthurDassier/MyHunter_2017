/*
** EPITECH PROJECT, 2018
** level.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

static void reset_birds(t_sprite **birds)
{
	int	nb = 0;

	while (birds[nb] != NULL) {
		birds[nb]->pos.x = rand() % 2000 - 2000;
		birds[nb]->pos.y = rand() % 700;
		birds[nb]->alive = 1;
		birds[nb]->forward += 2;
		++nb;
	}
}

static void spawn_boss(t_sprite **birds, t_sounds *sounds)
{
	sfVector2f	new_scl;

	sfMusic_stop(sounds->music1);
	sfMusic_play(sounds->music_boss);
	new_scl.x = 20;
	new_scl.y = 20;
	birds[0]->pos.x = -1500;
	birds[0]->pos.y = -400;
	birds[0]->alive = 1;
	birds[0]->forward = 2;
	birds[0]->clock = sfClock_create();
	sfSprite_setScale(birds[0]->sp, new_scl);
}

void level(t_sprite *back, t_game *game, t_sprite **birds, t_sounds *sounds)
{
	if (game->win == 0) {
		++game->level;
		game->win = -1;
		if (game->level == 1)
			reset_birds(birds);
		if (game->level == 2)
			spawn_boss(birds, sounds);
	}
	if (game->level == 1)
		sfSprite_setColor(back->sp, sfYellow);
	if (game->level >= 2)
		sfSprite_setColor(back->sp, sfRed);
}
