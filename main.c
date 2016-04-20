/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:02:50 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/20 18:19:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int              main(int ac, char **av)
{
	char		*terminfo;
	t_term		term;

	ac = 0;
	av = NULL;
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

void	ft_catch_wndw_mod(int signo)
{
	ft_clear_screen();
	if (signo == SIGWINCH)
		ft_printf("La fenetre a ete modifiee\n");
	// Le code pour afficher en collonne se trouvera ici grace a ioctl.
}

void	ft_clear_screen(void)
{
		tputs(tgetstr("cl", NULL), 1, ft_popopo);
}

int     voir_touche(void)
{
	char	buffer[5];

	ft_clear_screen();
	while (1)
	{
		read(0, buffer, 5);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		if (buffer[0] == 4)
			return (0);
		if (signal(SIGWINCH, ft_catch_wndw_mod) == SIG_ERR)
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
