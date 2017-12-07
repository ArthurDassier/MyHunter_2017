/*
** EPITECH PROJECT, 2017
** basics.c
** File description:
** fcts_basiques
*/

#include "myhunter.h"

int analys_ev(sfEvent event, sfRenderWindow *window, graphs *graph)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			return(kill(window, graph));
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(window);
		}
	}
	return(0);
}

game_s *init_game(game_s *game)
{
	game->soundbuffer = sfSoundBuffer_createFromFile("./sounds/castel.wav");
	game->sound = sfSound_create();
	return(game);
}

graphs *init_graph(graphs *graph)
{
	graph->texture = sfTexture_createFromFile("./textures/backg.png",
	NULL);
	graph->sprite = sfSprite_create();
	graph->sprite2 = sfSprite_create();
	my_init(graph);
	graph->i = 0;
	graph->v = 4;
	return(graph);
}

void destroyer(game_s *game, graphs *graph)
{
	sfSprite_destroy(graph->sprite);
	sfSprite_destroy(graph->sprite2);
	sfTexture_destroy(graph->texture);
	sfTexture_destroy(graph->texture2);
	sfSoundBuffer_destroy(game->soundbuffer);
	sfSound_destroy(game->sound);
	sfRenderWindow_destroy(game->window);
	free(graph);
}
