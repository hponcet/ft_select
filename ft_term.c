	/* ************************************************************************** */
	/*                                                                            */
	/*:                                                        :::      ::::::::   */
	/*   ft_term.c                                          :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2016/04/23 15:28:47 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/25 20:27:05 by hponcet          ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "includes/ft_select.h"

	int		ft_term_reset(void)
{
		g_config.term.c_lflag |= (ICANON | ECHO);
		if (tcsetattr(0, 0, &(g_config.term)) == -1)
			return (-1);
		tputs(tgetstr("te", NULL), 1, ft_char);
		tputs(tgetstr("ve", NULL), 1, ft_char);
		ft_putstr("\033[?1049l");
		return (0);
}

int		ft_term_init(void)
{
	struct winsize win;

	ft_putstr("\033[?1049h\033[H");
	g_config.terminfo = getenv("TERM");
	if (tgetent(NULL, g_config.terminfo) < 1)
		return (-1);
	if (tcgetattr(0, &(g_config.term)) == -1)
		return (-1);
	g_config.link = NULL;
	g_config.term.c_lflag &= ~(ICANON | ECHO);
	g_config.term.c_cc[VMIN] = 1;
	g_config.term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	g_config.nb_col = win.ws_col;
	g_config.nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(g_config.term)) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_char);
	tputs(tgetstr("vi", NULL), 1, ft_char);
	return (0);
}
