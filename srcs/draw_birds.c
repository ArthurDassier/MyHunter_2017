/*
** EPITECH PROJECT, 2018
** draw_birds.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

static void	draw_cross(sfRenderWindow *window, t_sprite **cross)
{
	sfVector2f	pos;

	pos.x = sfMouse_getPositionRenderWindow(window).x - 50;
	pos.y = sfMouse_getPositionRenderWindow(window).y - 50;
	sfRenderWindow_drawSprite(window, cross[0]->sp, NULL);
	sfSprite_setPosition(cross[0]->sp, pos);
	if (cross[1]->alive != 0) {
		sfRenderWindow_drawSprite(window, cross[1]->sp, NULL);
		sfSprite_setPosition(cross[1]->sp, pos);
		++cross[1]->alive;
	}
	if (cross[1]->alive == 6)
		cross[1]->alive = 0;
}

void draw_birds(sfRenderWindow *window, t_sprite **birds, t_sprite **cross)
{
	int		i = 0;

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
	draw_cross(window, cross);
}
