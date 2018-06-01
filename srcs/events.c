/*
** EPITECH PROJECT, 2018
** events.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"
#include "printf.h"

static int get_bird(t_game *game, t_sprite *birds)
{
	if (sfMouse_getPositionRenderWindow(game->window).x >= birds->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x <= birds->pos.x + 75) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= birds->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= birds->pos.y + 85) {
			game->score += 10;
			sfText_setString(game->tx_sc->text,
				my_strcat("Score : ", my_sti(game->score)));
			birds->alive = 0;
			return (0);
		}
	}
	return (1);
}

static void kill(t_game *game, t_sprite **birds)
{
	int	nb = 0;

	while (birds[nb] != NULL) {
		if (get_bird(game, birds[nb]) == 0)
			return;
		++nb;
	}
	if (game->level == 2) {
		++game->boss_hit;
		sfClock_restart(birds[0]->clock);
	}
}

void	analyse_event(t_game *game, t_sprite **birds,
	t_sounds *sounds, t_sprite **cross)
{
	sfEvent	event;

	if (game->boss_hit >= 6) {
		birds[0]->alive = 0;
		if (sfTime_asSeconds(sfClock_getElapsedTime(birds[0]->clock))
			> 8.5)
			sfRenderWindow_close(game->window);
	}
	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			sfSound_play(sounds->sound);
			sfClock_restart(cross[1]->clock);
			kill(game, birds);
		}
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(game->window);
		}
	}
}
