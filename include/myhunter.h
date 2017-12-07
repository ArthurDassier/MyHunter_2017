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
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FRAMERATE 20000

struct game_s
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfEvent		event;
	sfTime		time_s;
	sfSoundBuffer	*soundbuffer;
	sfSound		*sound;
	sfMouseButton	*mouse;
};

struct graphs
{
	sfTexture	*texture;
	sfTexture	*texture2;
	sfSprite	*sprite;
	sfSprite	*sprite2;
	sfVector2f	position;
	sfIntRect	animation[11];
	int		i;
	int		v;
};

int analys_ev(sfEvent event, sfRenderWindow *window, struct graphs *graph);
void my_init(struct graphs *graph);
struct graphs *init_graph(struct graphs *graph);
sfIntRect oiseau(int a, int b, int c, int d);
struct game_s *init_game(struct game_s *game);
int textrs(struct game_s *game, struct graphs *graph);
int movemts(struct graphs *graph);
void init_window(struct game_s *game, struct graphs *graph);
void anim(struct graphs *graph);
int handle_evt(sfEvent *event);
int kill(sfRenderWindow *window, struct graphs *graph);
void destroyer(struct game_s *game, struct graphs *graph);
void game_init(struct game_s *game, struct graphs *graph);

#endif
