/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"
#include "printf.h"

t_menu *init_menu()
{
	t_menu *new = malloc(sizeof(t_menu));

	new->back = create_sprite("./textures/menu.png", 0, 0, 0);
	new->button1 = create_sprite("./textures/buttons.png", 800, 200, 0);
	new->button2 = create_sprite("./textures/buttons.png", 800, 400, 0);
	return (new);
}

void event_menu(t_game *game, t_menu *menu)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			trigger_button(game, menu);
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(game->window);
		}
	}
}

void menu_loop(t_game *game, t_menu *mn)
{

	while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
		window_display(game->window);
		event_menu(game, mn);
		sfRenderWindow_drawSprite(game->window, mn->back->sp, NULL);
		sfRenderWindow_drawSprite(game->window, mn->button1->sp, NULL);
		sfSprite_setPosition(mn->button1->sp, mn->button1->pos);
		sfRenderWindow_drawSprite(game->window, mn->button2->sp, NULL);
		sfSprite_setPosition(mn->button2->sp, mn->button2->pos);
		state_button_one(game, mn);
	}
}
