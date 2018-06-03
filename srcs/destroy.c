/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"

static void my_free(t_game *game, t_menu *menu,
					t_sounds *sounds, t_sprite **cross)
{
	free(menu->text_buttons);
	free(menu);
	free(game->tx_sc);
	free(game);
	free(cross);
	free(sounds);
}

void destroyer(t_sprite *back, t_sprite **birds)
{
	int	nb = 0;

	sfSprite_destroy(back->sp);
	sfTexture_destroy(back->texture);
	sfClock_destroy(back->clock);
	while (birds[nb] != NULL) {
		sfSprite_destroy(birds[nb]->sp);
		sfTexture_destroy(birds[nb]->texture);
		free(birds[nb]->rect);
		free(birds[nb]);
		++nb;
	}
	free(birds);
	free(back);
}

static void destroy_sounds_cross(t_sounds *sounds, t_sprite **cross)
{
	sfSound_destroy(sounds->sound);
	sfSoundBuffer_destroy(sounds->buf);
	sfMusic_destroy(sounds->music1);
	sfMusic_destroy(sounds->music_boss);
	sfSprite_destroy(cross[0]->sp);
	sfTexture_destroy(cross[0]->texture);
	sfSprite_destroy(cross[1]->sp);
	sfTexture_destroy(cross[1]->texture);
	sfClock_destroy(cross[1]->clock);
}

static void destroy_menu(t_menu *menu)
{
	int	i = 0;

	sfSprite_destroy(menu->back->sp);
	sfTexture_destroy(menu->back->texture);
	sfSprite_destroy(menu->button_play->sp);
	sfTexture_destroy(menu->button_play->texture);
	sfSprite_destroy(menu->button_quit->sp);
	sfTexture_destroy(menu->button_quit->texture);
	sfSprite_destroy(menu->button_easy->sp);
	sfTexture_destroy(menu->button_easy->texture);
	sfSprite_destroy(menu->button_normal->sp);
	sfTexture_destroy(menu->button_normal->texture);
	sfSprite_destroy(menu->button_hell->sp);
	sfTexture_destroy(menu->button_hell->texture);
	while (i != 6) {
		sfText_destroy(menu->text_buttons[i]->text);
		sfFont_destroy(menu->text_buttons[i]->font);
		++i;
	}
}

void destroy_game(t_game *game, t_menu *menu,
					t_sounds *sounds, t_sprite **cross)
{
	destroy_sounds_cross(sounds, cross);
	destroy_menu(menu);
	sfText_destroy(game->tx_sc->text);
	sfFont_destroy(game->tx_sc->font);
	sfRenderWindow_destroy(game->window);
	my_free(game, menu, sounds, cross);
}
