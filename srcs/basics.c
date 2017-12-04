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

int close_ev(sfEvent event, sfRenderWindow *window)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			close_window(window);
	}
}

struct game_s *init_game(struct game_s *game)
{
	game->texture = sfTexture_createFromFile("../../../../Pictures/backg.png",
	NULL);
	game->video_mode;
	game->window;
	game->texture2;
	game->event;
	game->sprite = sfSprite_create();
	game->sprite2 = sfSprite_create();
	game->time_s;
	game->soundbuffer = sfSoundBuffer_createFromFile("../../../../Downloads/Castlevania-_Vampire_Killer.wav");
	game->position;
	game->sound = sfSound_create();
	my_init(game);
	game->i = 0;
	game->j = 0;
	game->u = 0;
	return(game);
}
