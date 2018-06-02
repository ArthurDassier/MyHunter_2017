/*
** EPITECH PROJECT, 2018
** life.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

static int count_birds(t_sprite **birds, int *passed)
{
	int	nb = 0;
	int	win = -1;

	while (birds[nb] != NULL) {
		if (birds[nb]->pos.x > 1900) {
			birds[nb]->pos.x = 2000;
			--*passed;
			birds[nb]->alive = 0;
		}
		if (birds[nb]->alive == 1)
		win += 2;
		++nb;
	}
	return (win);
}

int draw_life(t_game *game, t_sprite *heart, t_sprite **birds)
{
	int	i = 0;
	int	passed = 3;
	int	win = -1;

	win = count_birds(birds, &passed);
	if (passed <= 0) {
		game->state = 0;
		return (0);
	}
	while (i != passed) {
		sfSprite_setPosition(heart->sp, heart->pos);
		sfRenderWindow_drawSprite(game->window, heart->sp, NULL);
		heart->pos.x += 150;
		++i;
	}
	heart->pos.x -= (150 * passed);
	if (win == -1)
		return (0);
	return (win);
}
