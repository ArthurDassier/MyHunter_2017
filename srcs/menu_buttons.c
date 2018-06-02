/*
** EPITECH PROJECT, 2018
** menu_buttons.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

static void state_button_two(t_game *game, t_menu *menu,
sfIntRect taille, sfIntRect taille2)
{
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button1->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button1->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button1->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button1->pos.y + 70) {
			sfSprite_setTextureRect(menu->button1->sp, taille2);
		} else
		sfSprite_setTextureRect(menu->button1->sp, taille);
	} else
	sfSprite_setTextureRect(menu->button1->sp, taille);
}

void state_button_one(t_game *game, t_menu *menu)
{
	sfIntRect taille = pixel_tall(85, 35, 60, 200);
	sfIntRect taille2 = pixel_tall(85, 35, 160, 200);

	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button2->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button2->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button2->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button2->pos.y + 70) {
			sfSprite_setTextureRect(menu->button2->sp, taille2);
		} else
			sfSprite_setTextureRect(menu->button2->sp, taille);
	} else
		sfSprite_setTextureRect(menu->button2->sp, taille);
	state_button_two(game, menu, taille, taille2);
}

void trigger_button(t_game *game, t_menu *menu)
{
	if (sfMouse_getPositionRenderWindow(game->window).x
	>= menu->button1->pos.x &&
	sfMouse_getPositionRenderWindow(game->window).x
	<= menu->button1->pos.x + 160) {
		if (sfMouse_getPositionRenderWindow(game->window).y
		>= menu->button1->pos.y
		&& sfMouse_getPositionRenderWindow(game->window).y
		<= menu->button1->pos.y + 70) {
			game->state = 1;
		}
	}
}
