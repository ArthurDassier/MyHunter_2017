/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blarg
*/

#include "myhunter.h"

int main ()
{
	struct game_s	game;
	struct graphs	graph;

	init_game(&game);
	init_graph(&graph);
	init_window(&game, &graph);
	while (sfRenderWindow_isOpen(game.window)) {
		anim(&graph);
		textrs(&game, &graph);
		movemts(&graph);
		sfRenderWindow_display(game.window);
		sfSleep(game.time_s);
	}
	sfRenderWindow_destroy(game.window);
	sfSprite_destroy(graph.sprite);
	sfSprite_destroy(graph.sprite2);
	return (0);
}
