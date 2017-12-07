/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blarg
*/

#include "myhunter.h"

void game_init(struct game_s *game, struct graphs *graph)
{
	init_game(game);
	init_graph(graph);
	init_window(game, graph);
	sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
}

int main ()
{
	struct game_s	game;
	struct graphs	*graph = malloc(sizeof(struct graphs));
	int		score = 0;

	game_init(&game, graph);
	while (sfRenderWindow_isOpen(game.window)) {
		score = score + textrs(&game, graph);
		anim(graph);
		if (movemts(graph) == 300) {
			my_printf("You have killed %d birds, noob.\n", score);
			break;
		}
		sfRenderWindow_display(game.window);
		sfSleep(game.time_s);
	}

	destroyer(&game, graph);
	return (0);
}
