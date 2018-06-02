/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

char *my_sti(int nb)
{
	char	*str = malloc(sizeof(char) * 20);
	int	i = 0;

	if (nb == 0) {
		str[0] = '0';
		i = 1;
	}
	while (nb != 0) {
		str[i] = (nb % 10) + '0';
		++i;
		nb /= 10;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}

void window_display(sfRenderWindow *window)
{
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfBlack);
}

void reset(t_game *game, t_sounds *sounds)
{
	sfMusic_stop(sounds->music_boss);
	sfMusic_play(sounds->music1);
	game->score = 0;
	game->level = 0;
	game->boss_hit = 0;
}
