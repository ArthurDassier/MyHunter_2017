/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Arthur
*/

#include "my.h"
#include "hunter.h"
#include "config.h"

t_sprite	**init_birds(int nb)
{
	int		i = 0;
	t_sprite	**birds = malloc(sizeof(t_sprite) * (nb + 1));

	while (i != nb) {
		birds[i] = create_sprite("./textures/OUASO.png",
		(rand() % 2000 - 2000), rand() % 700, rand() % 10);
		birds[i]->rect = bird_rect();
		birds[i]->forward = rand() % 3 + 3;
		++i;
	}
	birds[i] = NULL;
	return (birds);
}

t_sprite *create_sprite(char *path, int x, int y, int rec)
{
	t_sprite	*new_sprite = malloc(sizeof(t_sprite));

	new_sprite->sp = sfSprite_create();
	new_sprite->texture = sfTexture_createFromFile(path, NULL);
	new_sprite->pos.x = x;
	new_sprite->pos.y = y;
	new_sprite->rec = rec;
	new_sprite->alive = 1;
	sfSprite_setTexture(new_sprite->sp, new_sprite->texture, sfTrue);
	return (new_sprite);
}

t_sounds *create_sounds(void)
{
	t_sounds *new_sounds = malloc(sizeof(t_sounds));

	new_sounds->music1 = sfMusic_createFromFile("./sounds/wow1.ogg");
	new_sounds->music_boss = sfMusic_createFromFile("./sounds/boss.ogg");
	new_sounds->buf = sfSoundBuffer_createFromFile("./sounds/kalash.ogg");
	new_sounds->sound = sfSound_create();
	sfSound_setBuffer(new_sounds->sound, new_sounds->buf);
	return (new_sounds);
}

sfRenderWindow *init_window(void)
{
	sfRenderWindow	*window;
	sfVideoMode	video_mode;

	video_mode.width = WIDTH_WID;
	video_mode.height = HEIGHT_WID;
	video_mode.bitsPerPixel = BPP;
	window = sfRenderWindow_create(video_mode, "MyWindow",
	sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	return (window);
}
