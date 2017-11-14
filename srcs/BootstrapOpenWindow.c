/*
** EPITECH PROJECT, 2017
** <...>
** File description:
** <...>
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

struct Framebuffer
{
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
};

sfIntRect oiseau(int a, int b, int c, int d)
{
	sfIntRect taille;
	taille.height = a;//100
	taille.left = b;
	taille.top = c;
	taille.width = d;//77
	return(taille);
}

static void my_init(sfIntRect tableau_taille[9])
{
	tableau_taille[0] = oiseau(85, 0, 0, 75);
	tableau_taille[1] = oiseau(85, 76, 0, 75);
	tableau_taille[2] = oiseau(85, 152, 0, 75);
	tableau_taille[3] = oiseau(85, 228, 0, 75);
	tableau_taille[4] = oiseau(85, 304, 0, 75);
	tableau_taille[5] = oiseau(85, 380, 0, 75);
	tableau_taille[6] = oiseau(85, 456, 0, 75);
	tableau_taille[7] = oiseau(85, 0, 86, 75);
	tableau_taille[8] = oiseau(85, 228, 0, 75);
}

int main ()
{
	sfRenderWindow	*window;
	sfTexture	*texture;
	sfTexture	*texture2;
	sfSprite	*sprite;
	sfTime		time_s;
	sfSprite	*sprite2;
	sfVideoMode video_mode;
	sfSoundBuffer	*soundbuffer;
	sfSound	*sound;
	sfIntRect tableau_taille[9];
	my_init(tableau_taille);
	texture = sfTexture_createFromFile("../../../../Downloads/bfg.png",
						NULL);

	sprite = sfSprite_create();
	sprite2 = sfSprite_create();
	time_s.microseconds = 70000;

	soundbuffer = sfSoundBuffer_createFromFile("../../../../Downloads/Castlevania-_Vampire_Killer.wav");
	sound = sfSound_create();
	sfSound_setBuffer(sound, soundbuffer);
	sfSound_play(sound);

	video_mode.width = 1200;
	video_mode.height = 800;
	video_mode.bitsPerPixel = 8;



	window = sfRenderWindow_create(video_mode, "MyWindow", sfDefaultStyle,
					NULL);
	int	i = 0;
	while (sfRenderWindow_isOpen(window)) {
		if (i == 9)
			i = 0;
		texture2 = sfTexture_createFromFile("../../../../Pictures/OUASO.png",
							&tableau_taille[i]);
		i++;
		sfSprite_setTexture(sprite, texture, sfTrue);
		sfSprite_setTexture(sprite2, texture2, sfTrue);

		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_drawSprite(window, sprite2, NULL);
		sfRenderWindow_display(window);
		sfSleep(time_s);
	}
	return (0);
}
