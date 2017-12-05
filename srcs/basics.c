/*
** EPITECH PROJECT, 2017
** basics.c
** File description:
** jadorelessushis
*/

#include "myhunter.h"

void close_window(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

int rand_a_b(int a, int b)
{
	return (rand() % (b - a) + a);
}

int analys_ev(sfEvent event, sfRenderWindow *window, struct graphs *graph)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed)
			kill(window, graph);
		if (event.type == sfEvtClosed)
			close_window(window);
	}
}

struct game_s *init_game(struct game_s *game)
{

	game->video_mode;
	game->window;
	game->event;
	game->time_s;
	game->soundbuffer = sfSoundBuffer_createFromFile("./sounds/Castlevania-_Vampire_Killer.wav");
	game->sound = sfSound_create();
	return(game);
}

struct graphs *init_graph(struct graphs *graph)
{
	graph->texture = sfTexture_createFromFile("./textures/backg.png",
	NULL);
	graph->texture2;
	graph->sprite = sfSprite_create();
	graph->sprite2 = sfSprite_create();
	graph->position;
	my_init(graph);
	graph->i = 0;
	graph->v = 4;
	return(graph);
}
