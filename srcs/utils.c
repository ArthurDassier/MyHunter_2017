/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

void window_display(sfRenderWindow *window)
{
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfBlack);
}
