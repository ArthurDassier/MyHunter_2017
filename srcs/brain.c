/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** centre_nevralgique
*/

#include "myhunter.h"

void game_init(game_s *game, graphs *graph)
{
	init_game(game);
	init_graph(graph);
	init_window(game, graph);
	sfSprite_setTexture(graph->sprite, graph->text_back, sfTrue);
	sfSprite_setTexture(graph->crosshair, graph->text_crsh, sfTrue);
}

int main ()
{
	game_s	game;
	graphs	*graph = malloc(sizeof(graphs));
	int	score = 0;

	game_init(&game, graph);
	while (sfRenderWindow_isOpen(game.window)) {
		score = score + textrs(&game, graph);
		anim(graph);
		if (movemts(&game, graph) == 300) {
			my_printf("You have killed %d birds, noob.\n", score);
			break;
		}
		sfRenderWindow_display(game.window);
		sfSleep(game.time_s);
	}
	destroyer(&game, graph);
	return (0);
}
