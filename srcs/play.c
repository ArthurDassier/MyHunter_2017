/*
** EPITECH PROJECT, 2018
** play.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

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

static void birds_event(sfRenderWindow *window, t_sprite **birds,
			t_sprite **cross, t_sounds *sounds)
{
	analyse_event(window, birds, sounds, cross);
	draw_birds(window, birds, cross);
}

static void window_open(sfRenderWindow *window,
			t_sprite **cross, t_sounds *sounds)
{
	t_sprite	*back = create_sprite("./textures/backg.png", 0, 0, 0);
	t_sprite	**birds = init_birds(15);
	t_sprite	*heart = create_sprite("./textures/heart.png", 1300,
								850, 0);
	int	win = -1;

	back->clock = sfClock_create();
	while (sfRenderWindow_isOpen(window)) {
		window_display(window);
		sfRenderWindow_drawSprite(window, back->sp, NULL);
		level(back, &win, birds, sounds);
		birds_event(window, birds, cross, sounds);
		clocking(back, birds);
		win = draw_life(window, heart, birds);
	}
	sfSprite_destroy(heart->sp);
	sfTexture_destroy(heart->texture);
	free(heart);
	destroyer(back, birds, cross, sounds);
}

int	play(void)
{
	sfRenderWindow	*window = init_window();
	t_sounds	*sounds = create_sounds();
	t_sprite	**cross = malloc(sizeof(t_sprite) * 2);

	cross[0] = create_sprite("./textures/crossahir1.png", 0, 0, 0);
	cross[1] = create_sprite("./textures/xplosion.png", 0, 0, 0);
	cross[1]->clock = sfClock_create();
	sfMusic_play(sounds->music1);
	window_open(window, cross, sounds);
	sfRenderWindow_destroy(window);
	return (0);
}
