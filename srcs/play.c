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
	for (int nb = 0; birds[nb] != NULL; ++nb) {
		if (birds[nb]->alive == 1)
			birds[nb]->pos.x += birds[nb]->forward;
		else
			birds[nb]->pos.y += 5;
	}
}

static void clocking(t_sprite *back, t_sprite **birds)
{
	if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.045) {
		sfClock_restart(back->clock);
		for (int nb = 0; birds[nb] != NULL; ++nb)
			++birds[nb]->rec;
	}
	if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.001)
		move_birds(birds);
}

static void birds_event(sfRenderWindow *window, t_sprite **birds,
			t_sprite **cross, t_sounds *sounds)
{
	draw_birds(window, birds, cross);
	analyse_event(window, birds, sounds, cross);

}

static void window_open(sfRenderWindow *window,
			t_sprite **cross, t_sounds *sounds)
{
	t_sprite	*back = create_sprite("./textures/backg.png", 0, 0, 0);
	t_sprite	**birds = init_birds(25);

	back->clock = sfClock_create();
	while (sfRenderWindow_isOpen(window)) {
		window_display(window);
		sfRenderWindow_drawSprite(window, back->sp, NULL);
		birds_event(window, birds, cross, sounds);
		clocking(back, birds);
	}
	destroyer(back, birds, cross, sounds);
}

int	play(void)
{
	sfRenderWindow	*window = init_window();
	t_sounds	*sounds = create_sounds();
	t_sprite	**cross = malloc(sizeof(t_sprite) * 2);

	cross[0] = create_sprite("./textures/crossahir1.png", 0, 0, 0);
	cross[1] = create_sprite("./textures/xplosion.png", 0, 0, 0);
	sfMusic_play(sounds->music1);
	window_open(window, cross, sounds);
	sfRenderWindow_destroy(window);
	return (0);
}
