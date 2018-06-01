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
	str = my_strcat(str, " : erocS");
	my_revstr(str);
	return (str);
}

static void my_free(t_sprite *back, t_sprite **birds,
	t_sprite **cross, t_sounds *sounds)
{
	free(cross);
	free(birds);
	free(sounds);
	free(back);
}

void destroyer(t_sprite *back, t_sprite **birds,
	t_sprite **cross, t_sounds *sounds)
{
	sfSprite_destroy(back->sp);
	sfTexture_destroy(back->texture);
	sfSprite_destroy(cross[0]->sp);
	sfTexture_destroy(cross[0]->texture);
	sfSprite_destroy(cross[1]->sp);
	sfTexture_destroy(cross[1]->texture);
	sfClock_destroy(back->clock);
	for (int nb = 0; birds[nb] != NULL; ++nb) {
		sfSprite_destroy(birds[nb]->sp);
		sfTexture_destroy(birds[nb]->texture);
		free(birds[nb]->rect);
		free(birds[nb]);
	}
	sfSound_destroy(sounds->sound);
	sfSoundBuffer_destroy(sounds->buf);
	sfMusic_destroy(sounds->music1);
	sfMusic_destroy(sounds->music_boss);
	my_free(back, birds, cross, sounds);
}

void window_display(sfRenderWindow *window)
{
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfBlack);
}
