/*
** EPITECH PROJECT, 2018
** menu_text.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

t_text	**init_text_menu(void)
{
	t_text	**new = malloc(sizeof(t_text) * 6);

	new[0] = create_text("./textures/Kenney Mini Square.ttf");
	new[1] = create_text("./textures/Kenney Mini Square.ttf");
	new[2] = create_text("./textures/Kenney Mini Square.ttf");
	new[3] = create_text("./textures/Kenney Mini Square.ttf");
	new[4] = create_text("./textures/Kenney Mini Square.ttf");
	sfText_setString(new[0]->text, "Play");
	sfText_setString(new[1]->text, "Quit");
	sfText_setString(new[2]->text, "Easy");
	sfText_setString(new[3]->text, "Normal");
	sfText_setString(new[4]->text, "HELL");
	return (new);
}
