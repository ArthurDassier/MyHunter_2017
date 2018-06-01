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

void window_display(sfRenderWindow *window)
{
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfBlack);
}
