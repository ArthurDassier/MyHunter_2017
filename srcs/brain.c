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

void play(game_s game, graphs *graph)
{
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
}

void help()
{
	my_printf("Help :\nMouse click on the birds to earn points !\n");
	my_printf("The game exit when a bird reach the right side of the ");
	my_printf("screen,\nthen you'll see your score on the shell.\n");
	my_printf("Have fun playing My Hunter ! :)\n");

}

int main (int argc, char *argv[])
{
	game_s	game;
	graphs	*graph = malloc(sizeof(graphs));

	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
		help();
		return(0);
	}
	else
		play(game, graph);
	return (0);
}
