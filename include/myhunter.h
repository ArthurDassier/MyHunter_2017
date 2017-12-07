/*
** EPITECH PROJECT, 2017
** my_hunter.h
** File description:
** protots
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include "my.h"
#include "printf.h"
#include "config.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct game_s
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfEvent		event;
	sfTime		time_s;
	sfSoundBuffer	*soundbuffer;
	sfSound		*sound;
	sfMouseButton	*mouse;
} game_s;

typedef struct graphs
{
	sfTexture	*texture;
	sfTexture	*texture2;
	sfSprite	*sprite;
	sfSprite	*sprite2;
	sfVector2f	position;
	sfIntRect	animation[11];
	int		i;
	int		v;
} graphs;

int analys_ev(sfEvent event, sfRenderWindow *window, graphs *graph);
void my_init(graphs *graph);
graphs *init_graph(graphs *graph);
sfIntRect oiseau(int a, int b, int c, int d);
game_s *init_game(game_s *game);
int textrs(game_s *game, graphs *graph);
int movemts(graphs *graph);
void init_window(game_s *game, graphs *graph);
void anim(graphs *graph);
int handle_evt(sfEvent *event);
int kill(sfRenderWindow *window, graphs *graph);
void destroyer(game_s *game, graphs *graph);
void game_init(game_s *game, graphs *graph);

#endif
