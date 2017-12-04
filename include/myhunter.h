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
	sfTexture	*texture;
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfTexture	*texture2;
	sfEvent		event;
	sfSprite	*sprite;
	sfSprite	*sprite2;
	sfTime		time_s;
	sfSoundBuffer	*soundbuffer;
	sfVector2f	position;
	sfSound		*sound;
	sfIntRect	tableau_taille[10];
	int		i;
	int		j;
	int		u;
};

void close_window(sfRenderWindow *window);
int rand_a_b(int a, int b);
int close_ev(sfEvent event, sfRenderWindow *window);
void my_init(struct game_s *game);
sfIntRect oiseau(int a, int b, int c, int d);
struct game_s *init_game(struct game_s *game);
int call(struct game_s *game);

#endif
