/*
** EPITECH PROJECT, 2018
** brain.c
** File description:
** blabla
*/

#include <time.h>
#include "my.h"
#include "config.h"
#include "printf.h"
#include "hunter.h"

int get_bird(sfRenderWindow *window, t_sprite *birds)
{
	if (sfMouse_getPositionRenderWindow(window).x >= birds->pos.x &&
	sfMouse_getPositionRenderWindow(window).x <= birds->pos.x + 75) {
		if (sfMouse_getPositionRenderWindow(window).y >= birds->pos.y
		&& sfMouse_getPositionRenderWindow(window).y <= birds->pos.y + 85) {
			birds->alive = 0;
			return (0);
		}
	}
	return (1);
}

void	analyse_event(sfRenderWindow *window, t_sprite **birds, t_sounds *sounds)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			sfSound_play(sounds->sound);
			for (int nb = 0; birds[nb] != NULL &&
				get_bird(window, birds[nb]) == 1; ++nb);
		}
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(window);
		}
	}
}

int main(void)
{
	srand(time(NULL));
	play();
	return (0);
}
