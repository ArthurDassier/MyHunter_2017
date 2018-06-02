/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

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

void destroy_game(t_game *game, t_menu *menu)
{
	sfSprite_destroy(menu->back->sp);
	sfTexture_destroy(menu->back->texture);
	sfSprite_destroy(menu->button1->sp);
	sfTexture_destroy(menu->button1->texture);
	sfSprite_destroy(menu->button2->sp);
	sfTexture_destroy(menu->button2->texture);
	sfText_destroy(game->tx_sc->text);
	sfFont_destroy(game->tx_sc->font);
	sfRenderWindow_destroy(game->window);
	free(menu);
	free(game->tx_sc);
	free(game);
}
