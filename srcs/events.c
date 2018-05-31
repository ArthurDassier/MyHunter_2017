/*
** EPITECH PROJECT, 2018
** events.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"
#include "printf.h"

static int get_bird(sfRenderWindow *wd, t_sprite *birds)
{
	if (sfMouse_getPositionRenderWindow(wd).x >= birds->pos.x &&
	sfMouse_getPositionRenderWindow(wd).x <= birds->pos.x + 75) {
		if (sfMouse_getPositionRenderWindow(wd).y >= birds->pos.y &&
		sfMouse_getPositionRenderWindow(wd).y <= birds->pos.y + 85) {
			birds->alive = 0;
			return (0);
		}
	}
	return (1);
}

static void kill(sfRenderWindow *window, t_sprite **birds)
{
	int	nb = 0;

	while (birds[nb] != NULL && get_bird(window, birds[nb]) == 1)
		++nb;
}

void	analyse_event(sfRenderWindow *window, t_sprite **birds,
	t_sounds *sounds, t_sprite **cross)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			sfSound_play(sounds->sound);
			++cross[1]->alive;
			kill(window, birds);
		}
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(window);
		}
	}
}
