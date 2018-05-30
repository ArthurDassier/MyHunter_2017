/*
** EPITECH PROJECT, 2018
** oaso.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

sfIntRect pixel_tall(int a, int b, int c, int d)
{
	sfIntRect taille;

	taille.height = a;
	taille.left = b;
	taille.top = c;
	taille.width = d;
	return (taille);
}

sfIntRect *bird_rect(void)
{
	sfIntRect	*rect = malloc(sizeof(sfIntRect) * 10);

	rect[0] = pixel_tall(85, 228, 0, 75);
	rect[1] = pixel_tall(85, 0, 86, 75);
	rect[2] = pixel_tall(85, 456, 0, 75);
	rect[3] = pixel_tall(85, 380, 0, 75);
	rect[4] = pixel_tall(85, 304, 0, 75);
	rect[5] = pixel_tall(85, 228, 0, 75);
	rect[6] = pixel_tall(85, 152, 0, 75);
	rect[7] = pixel_tall(85, 76, 0, 75);
	rect[8] = pixel_tall(85, 0, 0, 75);
	rect[9] = pixel_tall(85, 152, 0, 75);
	return (rect);
}
