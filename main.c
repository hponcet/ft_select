/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:02:50 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/15 20:58:42 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include "libft/includes/libft.h"

static int     voir_touche()
{
	char     buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
			printf("Ctlr+d, on quitte !\n");
	}
	return (0);
}

int              main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios term;

	ac = 0;
	av = NULL;
	name_term = ft_strdup("xterm-256color");
	if (tgetent(NULL, name_term) == ERR)
	{
		printf("51\n");
		return (-1);
	}
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
	{
		printf("55\n");
		return (-1);
	}
	voir_touche();
	return (0);
}


