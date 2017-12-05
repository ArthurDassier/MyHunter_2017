/*
** EPITECH PROJECT, 2017
** init_wind.c
** File description:
** lafenetreee
*/

#include "myhunter.h"

void init_window(struct game_s *game, struct graphs *graph)
{
	game->time_s.microseconds = 20000;
	sfSound_setBuffer(game->sound, game->soundbuffer);
	sfSound_play(game->sound);
	game->video_mode.width = 1920;
	game->video_mode.height = 1080;
	game->video_mode.bitsPerPixel = 8;
	graph->position.x = 0;
	graph->position.y = 150;
	game->window = sfRenderWindow_create(game->video_mode, "MyWindow", sfDefaultStyle,
					NULL);
}
