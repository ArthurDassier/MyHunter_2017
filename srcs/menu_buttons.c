/*
** EPITECH PROJECT, 2018
** menu_buttons.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

void state_button(t_game *game, t_sprite *button)
{
	sfIntRect stand = pixel_tall(85, 35, 60, 200);
	sfIntRect press = pixel_tall(85, 35, 160, 200);

	if (sfMouse_getPositionRenderWindow(game->window).x
	>= button->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= button->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= button->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= button->pos.y + 70) {
			sfSprite_setTextureRect(button->sp, press);
		} else
			sfSprite_setTextureRect(button->sp, stand);
	} else
		sfSprite_setTextureRect(button->sp, stand);
}

void trigger_button(t_game *game, t_menu *menu)
{
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button_play->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button_play->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button_play->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button_play->pos.y + 70)
			game->state = 1;
	}
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button_quit->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button_quit->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button_quit->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button_quit->pos.y + 70)
			sfRenderWindow_close(game->window);
	}
}

void trigger_choose(t_game *game, t_menu *menu)
{
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button_easy->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button_easy->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button_easy->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button_easy->pos.y + 70) {
			game->nb_birds = 15;
			game->state = 2;
		}
	}
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button_normal->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button_normal->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button_normal->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button_normal->pos.y + 70) {
			game->nb_birds = 25;
			game->state = 2;
		}
	}
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button_hell->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button_hell->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button_hell->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button_hell->pos.y + 70) {
			game->nb_birds = 50;
			game->state = 2;
		}
	}
}
