/*
** EPITECH PROJECT, 2017
** <...>
** File description:
** <...>
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void close_window(sfRenderWindow *window);
int rand_a_b(int a, int b);
int analys_ev(sfEvent event, sfRenderWindow *window, struct graphs *graph);
void my_init(struct graphs *graph);
struct graphs *init_graph(struct graphs *graph);
sfIntRect oiseau(int a, int b, int c, int d);
struct game_s *init_game(struct game_s *game);
void textrs(struct game_s *game, struct graphs *graph);
void movemts(struct graphs *graph);
void init_window(struct game_s *game, struct graphs *graph);
void anim(struct graphs *graph);
int handle_evt(sfEvent *event);
void kill(sfRenderWindow *window, struct graphs *graph);

#endif
