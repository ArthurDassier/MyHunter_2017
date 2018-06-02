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
	sfVector2f	pos;
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
	int		state;
	int		nb_birds;
} 			t_game;

typedef struct s_menu
{
	t_sprite	*back;
	t_sprite	*button_play;
	t_sprite	*button_quit;
	t_sprite	*button_easy;
	t_sprite	*button_normal;
	t_sprite	*button_hell;
	t_text		**text_buttons;
} 			t_menu;

t_menu 		*init_menu(void);
void		menu_loop(t_game *, t_menu *);
void		state_button(t_game *, t_sprite *);
void		trigger_button(t_game *, t_menu *);
void		trigger_choose(t_game *, t_menu *);
t_text		**init_text_menu(void);
sfIntRect 	pixel_tall(int, int, int, int);
t_game		*init_game(void);
t_sprite	*create_sprite(char *, int, int, int);
sfIntRect	*bird_rect(void);
void		window_display(sfRenderWindow *);
t_sprite	**init_birds(int);
void	analyse_event(t_game *, t_sprite **, t_sounds *, t_sprite **);
int		play(void);
t_sounds	*create_sounds(void);
t_text		*create_text(char *, int, int);
void		destroyer(t_sprite *, t_sprite **);
void		draw_birds(sfRenderWindow *, t_sprite **, t_sprite **);
int		draw_life(t_game *, t_sprite *, t_sprite **);
void		level(t_sprite *, t_game *, t_sprite **, t_sounds *);
char		*my_sti(int);
void		event_boss(t_game *);
void		destroy_game(t_game *, t_menu *, t_sounds *, t_sprite **);
void		reset(t_game *);

#endif
