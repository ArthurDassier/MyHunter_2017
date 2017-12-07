/*
** EPITECH PROJECT, 2017
** basics.c
** File description:
** jadorelessushis
*/

#include "myhunter.h"

int analys_ev(sfEvent event, sfRenderWindow *window, struct graphs *graph)
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

struct game_s *init_game(struct game_s *game)
{
	game->soundbuffer = sfSoundBuffer_createFromFile("./sounds/castel.wav");
	game->sound = sfSound_create();
	return(game);
}

struct graphs *init_graph(struct graphs *graph)
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

void destroyer(struct game_s *game, struct graphs *graph)
{
	sfSprite_destroy(graph->sprite);
	sfSprite_destroy(graph->sprite2);
	sfTexture_destroy(graph->texture);
	sfTexture_destroy(graph->texture2);
	sfRenderWindow_destroy(game->window);
}
