/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blarg
*/

#include "myhunter.h"

int main ()
{
	struct game_s	game;

	init_game(&game);
	game.time_s.microseconds = 30000;
	sfSound_setBuffer(game.sound, game.soundbuffer);
	sfSound_play(game.sound);
	game.video_mode.width = 1920;
	game.video_mode.height = 1080;
	game.video_mode.bitsPerPixel = 8;
	game.position.x = 0;
	game.position.y = 0;
	game.window = sfRenderWindow_create(game.video_mode, "MyWindow", sfDefaultStyle,
					NULL);
	while (sfRenderWindow_isOpen(game.window)) {
		if (game.i == 10)
			game.i = 0;
		game.texture2 = sfTexture_createFromFile("../../../../Pictures/OUASO.png",
							&game.tableau_taille[game.i]);
		game.i++;
		call(&game);
		game.position.x = game.position.x + 8;
		if (game.position.x >= 1900) {
			game.position.x = 0;
			game.position.y = rand()%790;
		}
		sfRenderWindow_display(game.window);
		sfSleep(game.time_s);
	}
	sfRenderWindow_destroy(game.window);
	sfSprite_destroy(game.sprite);
	sfSprite_destroy(game.sprite2);
	return (0);
}
