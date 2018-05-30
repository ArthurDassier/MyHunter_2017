/*
** EPITECH PROJECT, 2018
** hunter.h
** File description:
** hunter
*/

#ifndef HUNTER_H
#define HUNTER_H

typedef struct s_sprite
{
	sfSprite	*sp;
	sfTexture	*texture;
	sfVector2f	pos;
	sfIntRect	*rect;
	sfClock		*clock;
	int		rec;
	int		forward;
	int		alive;
} t_sprite;

sfRenderWindow	*init_window(void);
t_sprite	*create_sprite(char *, int, int, int);
sfIntRect	*bird_rect(void);
void		window_display(sfRenderWindow *);
t_sprite	**init_birds(int);
void		analyse_event(sfRenderWindow *, t_sprite **);
int		play(void);

#endif
