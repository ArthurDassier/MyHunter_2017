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
}			t_sprite;

typedef struct s_text
{
	sfText		*text;
	sfFont		*font;
}			t_text;

typedef struct s_sounds
{
	sfSoundBuffer	*buf;
	sfSound		*sound;
	sfMusic		*music1;
	sfMusic		*music_boss;
}			t_sounds;

typedef struct s_game
{
	sfRenderWindow	*window;
	t_text		*tx_sc;
	int		score;
	int		win;
	int		boss_hit;
	int		level;
} 			t_game;

t_game		*init_game(void);
t_sprite	*create_sprite(char *, int, int, int);
sfIntRect	*bird_rect(void);
void		window_display(sfRenderWindow *);
t_sprite	**init_birds(int);
void		analyse_event(t_game *, t_sprite **, t_sounds *, t_sprite **);
int		play(void);
t_sounds	*create_sounds(void);
void		destroyer(t_sprite *, t_sprite **, t_sprite **, t_sounds *);
void		draw_birds(sfRenderWindow *, t_sprite **, t_sprite **);
int		draw_life(sfRenderWindow *, t_sprite *, t_sprite **);
void		level(t_sprite *, t_game *, t_sprite **, t_sounds *);
char		*my_sti(int);
void		event_boss(t_game *);

#endif
