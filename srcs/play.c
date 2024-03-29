/*
** EPITECH PROJECT, 2018
** play.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"
#include "printf.h"

static void move_birds(t_sprite **birds)
{
	int	nb = 0;

	while (birds[nb] != NULL) {
		if (birds[nb]->alive == 1)
			birds[nb]->pos.x += birds[nb]->forward;
		else
			birds[nb]->pos.y += 5;
		++nb;
	}
}

static void clocking(t_sprite *back, t_sprite **birds)
{
	int	nb = 0;

	if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.045) {
		sfClock_restart(back->clock);
		while (birds[nb] != NULL) {
			++birds[nb]->rec;
			++nb;
		}
	}
	if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.001)
		move_birds(birds);
}

static void birds_event(t_game *game, t_sprite **birds, t_sprite **cross,
			t_sounds *sounds)
{
	analyse_event(game, birds, sounds, cross);
	draw_birds(game->window, birds, cross);
}

static void window_open(t_game *game, t_sprite **cross, t_sounds *sounds)
{
	t_sprite	*back = create_sprite("./textures/backg.png", 0, 0, 0);
	t_sprite	**birds = init_birds(game->nb_birds);
	t_sprite	*heart = create_sprite("./textures/heart.png", 1300,
								850, 0);

	game->win = -1;
	back->clock = sfClock_create();
	while (sfRenderWindow_isOpen(game->window) && game->state == 2) {
		window_display(game->window);
		sfRenderWindow_drawSprite(game->window, back->sp, NULL);
		sfRenderWindow_drawText(game->window, game->tx_sc->text, NULL);
		level(back, game, birds, sounds);
		birds_event(game, birds, cross, sounds);
		clocking(back, birds);
		game->win = draw_life(game, heart, birds);
	}
	sfSprite_destroy(heart->sp);
	sfTexture_destroy(heart->texture);
	free(heart);
	destroyer(back, birds);
}

int	play(void)
{
	t_game		*game = init_game();
	t_menu		*menu = init_menu();
	t_sounds	*sounds = create_sounds();
	t_sprite	**cross = malloc(sizeof(t_sprite) * 2);

	set_position_text(menu);
	cross[0] = create_sprite("./textures/crossahir1.png", 0, 0, 0);
	cross[1] = create_sprite("./textures/xplosion.png", 0, 0, 0);
	cross[1]->clock = sfClock_create();
	sfMusic_play(sounds->music1);
	while (sfRenderWindow_isOpen(game->window)) {
		menu_loop(game, menu);
		reset(game, sounds);
		sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
		if (sfRenderWindow_isOpen(game->window))
			window_open(game, cross, sounds);
		sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
	}
	destroy_game(game, menu, sounds, cross);
	return (0);
}
