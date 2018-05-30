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

typedef struct s_sounds
{
	sfSoundBuffer	*buf;
	sfSound		*sound;
	sfMusic		*music1;
} t_sounds;

sfRenderWindow	*init_window(void);
t_sprite	*create_sprite(char *, int, int, int);
sfIntRect	*bird_rect(void);
void		window_display(sfRenderWindow *);
t_sprite	**init_birds(int);
void		analyse_event(sfRenderWindow *, t_sprite **, t_sounds *);
int		play(void);
t_sounds	*create_sounds(void);
void destroyer(t_sprite *, t_sprite **,
	t_sprite *, t_sounds *);

#endif
