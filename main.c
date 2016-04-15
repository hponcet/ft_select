/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:02:50 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/15 15:19:18 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include "ft_select.h"

int              main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios *term;

	ac = 0;
	av = NULL;
	term = NULL;
	env = NULL;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, term) == -1)
		return (-1);
	voir_touche();
	return (0);
}

int     voir_touche()
{
	char     buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			ft_printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}
