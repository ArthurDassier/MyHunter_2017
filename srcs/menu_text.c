/*
** EPITECH PROJECT, 2018
** menu_text.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

void draw_play(t_game *game, t_menu *mn)
{
	sfRenderWindow_drawSprite(game->window, mn->back->sp, NULL);
	sfRenderWindow_drawSprite(game->window,
		mn->button_quit->sp, NULL);
	sfRenderWindow_drawSprite(game->window,
		mn->button_play->sp, NULL);
	sfRenderWindow_drawText(game->window,
		mn->text_buttons[0]->text, NULL);
	sfRenderWindow_drawText(game->window,
		mn->text_buttons[1]->text, NULL);
	if (game->score > 0)
		sfRenderWindow_drawText(game->window,
			mn->text_buttons[5]->text, NULL);
}

void set_position_text(t_menu *mn)
{
	sfText_setPosition(mn->text_buttons[0]->text,
		mn->text_buttons[0]->pos);
	sfText_setPosition(mn->text_buttons[1]->text,
		mn->text_buttons[1]->pos);
	sfSprite_setPosition(mn->button_play->sp,
		mn->button_play->pos);
	sfSprite_setPosition(mn->button_quit->sp,
		mn->button_quit->pos);
	sfText_setPosition(mn->text_buttons[2]->text,
		mn->text_buttons[2]->pos);
	sfText_setPosition(mn->text_buttons[3]->text,
		mn->text_buttons[3]->pos);
	sfText_setPosition(mn->text_buttons[4]->text,
		mn->text_buttons[4]->pos);
	sfSprite_setPosition(mn->button_easy->sp,
		mn->button_easy->pos);
	sfSprite_setPosition(mn->button_hell->sp,
		mn->button_hell->pos);
	sfSprite_setPosition(mn->button_normal->sp,
		mn->button_normal->pos);
}

t_text	**init_text_menu(void)
{
	t_text	**new = malloc(sizeof(t_text) * 6);

	new[0] = create_text("./textures/Kenney Mini Square.ttf", 850, 225);
	new[1] = create_text("./textures/Kenney Mini Square.ttf", 857, 425);
	new[2] = create_text("./textures/Kenney Mini Square.ttf", 850, 225);
	new[3] = create_text("./textures/Kenney Mini Square.ttf", 830, 425);
	new[4] = create_text("./textures/Kenney Mini Square.ttf", 857, 625);
	new[5] = create_text("./textures/Kenney Mini Square.ttf", 700, 50);
	sfText_setString(new[0]->text, "Play");
	sfText_setString(new[1]->text, "Quit");
	sfText_setString(new[2]->text, "Easy");
	sfText_setString(new[3]->text, "Normal");
	sfText_setString(new[4]->text, "HELL");
	return (new);
}
