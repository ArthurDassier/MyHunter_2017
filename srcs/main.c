/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
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
	my_printf("You'll have to shoot him a lot of times before he die\n");
	my_printf("Have fun playing My Hunter ! :)\n");

}

int main(int ac, char **av, char **env)
{
	if (env == NULL || env[0] == NULL) {
		my_puterror("Why do you want to break my game ? :(\n");
		return (84);
	}
	if (ac == 2 && my_strlen(av[1]) == 2
	&& av[1][0] == '-' && av[1][1] == 'h') {
		help();
		return (0);
	} else if (ac > 1) {
		my_puterror("Usage : [./my_hunter][-h]\n");
		return (84);
	}
	srand(time(NULL));
	play();
	return (0);
}
