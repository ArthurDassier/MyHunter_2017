/*
** EPITECH PROJECT, 2017
** init_wind.c
** File description:
** lafenetre
*/

#include "myhunter.h"

void init_window(game_s *game, graphs *graph)
{
	game->time_s.microseconds = FRAMERATE;
	sfSound_setBuffer(game->sound, game->soundbuffer);
	sfSound_play(game->sound);
	game->video_mode.width = WIDTH_WID;
	game->video_mode.height = HEIGHT_WID;
	game->video_mode.bitsPerPixel = BPP;
	graph->pstn.x = -100;
	graph->pstn.y = 150;
	game->window = sfRenderWindow_create(game->video_mode, "MyWindow",
	sfDefaultStyle, NULL);
	sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}
