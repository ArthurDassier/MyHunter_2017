/*
** EPITECH PROJECT, 2018
** play.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

void	draw_birds(sfRenderWindow *window, t_sprite **birds, t_sprite *cross)
{
	int	i = 0;
	sfVector2f	pos;

	while (birds[i] != NULL) {
		if (birds[i]->rec == 10)
			birds[i]->rec = 0;
		sfRenderWindow_drawSprite(window, birds[i]->sp, NULL);
		if (birds[i]->alive == 1) {
			sfSprite_setTextureRect(birds[i]->sp,
				birds[i]->rect[birds[i]->rec]);
			sfSprite_setPosition(birds[i]->sp, birds[i]->pos);
		} else {
			sfSprite_setTextureRect(birds[i]->sp,
				birds[i]->rect[10]);
			sfSprite_setPosition(birds[i]->sp, birds[i]->pos);
			}
		++i;
	}
	sfRenderWindow_drawSprite(window, cross->sp, NULL);
	pos.x = sfMouse_getPositionRenderWindow(window).x - 50;
	pos.y = sfMouse_getPositionRenderWindow(window).y - 50;
	sfSprite_setPosition(cross->sp, pos);
}

int	play(void)
{
	sfRenderWindow	*window = init_window();
	t_sprite	*back = create_sprite("./textures/backg.png", 0, 0, 0);
	t_sprite	**birds = init_birds(25);
	t_sprite	*cross = create_sprite("./textures/crossahir1.png", 0, 0, 0);
	t_sounds	*sounds = create_sounds();

	sfMusic_play(sounds->music1);
	back->clock = sfClock_create();
	while (sfRenderWindow_isOpen(window)) {
		window_display(window);
		sfRenderWindow_drawSprite(window, back->sp, NULL);
		draw_birds(window, birds, cross);
		analyse_event(window, birds, sounds);
		if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.001) {
			for (int nb = 0; birds[nb] != NULL; ++nb) {
				if (birds[nb]->alive == 1)
					birds[nb]->pos.x += birds[nb]->forward;
				else
					birds[nb]->pos.y += 5;
			}
		}
		if (sfTime_asSeconds(sfClock_getElapsedTime(back->clock)) > 0.045) {
			sfClock_restart(back->clock);
			for (int nb = 0; birds[nb] != NULL; ++nb)
				++birds[nb]->rec;
		}
	}
	sfRenderWindow_destroy(window);
	destroyer(back, birds, cross, sounds);
	return (0);
}
