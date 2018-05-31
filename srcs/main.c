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

void	analyse_event(sfRenderWindow *window, t_sprite **birds, t_sounds *sounds, t_sprite **cross)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			sfSound_play(sounds->sound);
			++cross[1]->alive;
			for (int nb = 0; birds[nb] != NULL &&
				get_bird(window, birds[nb]) == 1; ++nb);
		}
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(window);
		}
	}
}

void help()
{
	my_printf("Help :\nMouse click on the birds to earn points !\n");
	my_printf("Then you'll see your score on the screen.\n");
	my_printf("Have fun playing My Hunter ! :)\n");

}

int main(int ac, char **av, char **env)
{
	if (env == NULL || env[0] == NULL)
		return (84);
	if (ac == 2 && my_strlen(av[1]) == 2
	&& av[1][0] == '-' && av[1][1] == 'h') {
		help();
		return (0);
	}
	srand(time(NULL));
	play();
	return (0);
}
