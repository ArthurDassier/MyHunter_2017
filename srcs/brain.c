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
	struct graphs	graph;

	init_game(&game);
	init_graph(&graph);
	game.time_s.microseconds = 30000;
	sfSound_setBuffer(game.sound, game.soundbuffer);
	sfSound_play(game.sound);
	game.video_mode.width = 1920;
	game.video_mode.height = 1080;
	game.video_mode.bitsPerPixel = 8;
	graph.position.x = 0;
	graph.position.y = 0;
	game.window = sfRenderWindow_create(game.video_mode, "MyWindow", sfDefaultStyle,
					NULL);
	while (sfRenderWindow_isOpen(game.window)) {
		if (graph.i == 10)
			graph.i = 0;
		graph.texture2 = sfTexture_createFromFile("./textures/OUASO.png",
							&graph.tableau_taille[graph.i]);
		graph.i++;
		call(&game, &graph);
		graph.position.x = graph.position.x + 8;
		if (graph.position.x >= 1900) {
			graph.position.x = 0;
			graph.position.y = rand()%790;
		}
		sfRenderWindow_display(game.window);
		sfSleep(game.time_s);
	}
	sfRenderWindow_destroy(game.window);
	sfSprite_destroy(graph.sprite);
	sfSprite_destroy(graph.sprite2);
	return (0);
}
