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
	new->button_play = create_sprite("./textures/button.png", 800, 200, 0);
	new->button_quit = create_sprite("./textures/button.png", 800, 400, 0);
	new->button_easy = create_sprite("./textures/button.png", 800, 200, 0);
	new->button_normal = create_sprite("./textures/button.png",
								800, 400, 0);
	new->button_hell = create_sprite("./textures/button.png", 800, 600, 0);
	new->text_buttons = init_text_menu();
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

void event_choose(t_game *game, t_menu *menu)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(game->window, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			trigger_choose(game, menu);
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(game->window);
		}
	}
}

void choose_mode(t_game *game, t_menu *mn)
{
	window_display(game->window);
	event_choose(game, mn);
	state_button(game, mn->button_easy);
	state_button(game, mn->button_normal);
	state_button(game, mn->button_hell);
	sfRenderWindow_drawSprite(game->window, mn->back->sp, NULL);
	sfText_setPosition(mn->text_buttons[2]->text,
		mn->button_easy->pos);
	sfText_setPosition(mn->text_buttons[3]->text,
		mn->button_normal->pos);
	sfText_setPosition(mn->text_buttons[4]->text,
		mn->button_hell->pos);
	sfSprite_setPosition(mn->button_easy->sp,
		mn->button_easy->pos);
	sfSprite_setPosition(mn->button_hell->sp,
		mn->button_hell->pos);
	sfSprite_setPosition(mn->button_normal->sp,
		mn->button_normal->pos);
	sfRenderWindow_drawSprite(game->window,
		mn->button_easy->sp, NULL);
	sfRenderWindow_drawSprite(game->window,
		mn->button_normal->sp, NULL);
	sfRenderWindow_drawSprite(game->window,
		mn->button_hell->sp, NULL);
	sfRenderWindow_drawText(game->window, mn->text_buttons[2]->text, NULL);
	sfRenderWindow_drawText(game->window, mn->text_buttons[3]->text, NULL);
	sfRenderWindow_drawText(game->window, mn->text_buttons[4]->text, NULL);
}

void menu_loop(t_game *game, t_menu *mn)
{
	while (sfRenderWindow_isOpen(game->window) && game->state == 0) {
		window_display(game->window);
		event_menu(game, mn);
		state_button(game, mn->button_play);
		state_button(game, mn->button_quit);
		sfRenderWindow_drawSprite(game->window, mn->back->sp, NULL);
		sfText_setPosition(mn->text_buttons[0]->text,
			mn->button_play->pos);
		sfText_setPosition(mn->text_buttons[1]->text,
			mn->button_quit->pos);
		sfSprite_setPosition(mn->button_play->sp,
			mn->button_play->pos);
		sfSprite_setPosition(mn->button_quit->sp,
			mn->button_quit->pos);
		sfRenderWindow_drawSprite(game->window,
			mn->button_quit->sp, NULL);
		sfRenderWindow_drawSprite(game->window,
			mn->button_play->sp, NULL);
		sfRenderWindow_drawText(game->window, mn->text_buttons[0]->text, NULL);
		sfRenderWindow_drawText(game->window, mn->text_buttons[1]->text, NULL);
	}
	while (sfRenderWindow_isOpen(game->window) && game->state == 1)
		choose_mode(game, mn);
}
