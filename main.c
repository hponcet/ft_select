/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:02:50 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/18 21:43:10 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int              main(void)
{
	char		*terminfo;
	t_term		term;

	if ((terminfo = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, terminfo) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	ft_shell_mod(term);
	voir_touche();
	ft_shell_init();
	return (0);
}

int     voir_touche(void)
{
	char	buffer[5];

	while (1)
	{
		read(0, buffer, 5);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		if (buffer[0] == 4)
			return (0);
	}
	return (0);
}

int		ft_shell_init(void)
{
	t_term		term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

int		ft_shell_mod(t_term term)
{
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int		ft_popopo(int i)
{
	write(1, &i, 1);
	return (0);
}
