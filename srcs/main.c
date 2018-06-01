/*
** EPITECH PROJECT, 2018
** brain.c
** File description:
** blabla
*/

#include <time.h>
#include "my.h"
#include "config.h"
#include "printf.h"
#include "hunter.h"

static void help()
{
	my_printf("Help :\nMouse click on the birds to earn points !\n");
	my_printf("Then, you'll see your score on the screen.\n");
	my_printf("There is 3 levels in this game with one boss.\n");
	my_printf("Have fun playing My Hunter ! :)\n");

}

int main(int ac, char **av, char **env)
{
	if (env == NULL || env[0] == NULL)
		return (84);
	if (ac == 2 && my_strlen(av[1]) == 2
	&& av[1][0] == '-' && av[1][1] == 'h') {
		help();
		return (0);
	}
	srand(time(NULL));
	play();
	return (0);
}
