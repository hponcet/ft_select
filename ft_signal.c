/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:48:20 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/25 21:09:04 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"


static void	ft_signal_cont(void)
{
	struct winsize win;

	ft_putstr("\033[?1049h\033[H");
	g_config.terminfo = getenv("TERM");
	tgetent(NULL, g_config.terminfo);
	tcgetattr(0, &(g_config.term));
	g_config.term.c_lflag &= ~(ICANON | ECHO);
	g_config.term.c_cc[VMIN] = 1;
	g_config.term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	g_config.nb_col = win.ws_col;
	g_config.nb_row = win.ws_row;
	tcsetattr(0, 0, &(g_config.term));
	tputs(tgetstr("ti", NULL), 1, ft_char);
	tputs(tgetstr("vi", NULL), 1, ft_char);
}
static void	ft_signal_susp(void)
{
	char	susp[2];

	susp[0] = g_config.term.c_cc[VSUSP];
	susp[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, susp);
	ft_term_reset();
}

static void	ft_signal_win(void)
{
	t_win win;

	ioctl(0, TIOCGWINSZ, &win);
	g_config.nb_col = win.ws_col;
	g_config.nb_row = win.ws_row;
	ft_clear_screen();
	ft_display_link();
}

void	ft_signal(void)
{
	signal(SIGWINCH, ft_catch_signal);
	signal(SIGTSTP, ft_catch_signal);
	signal(SIGCONT, ft_catch_signal);
	signal(SIGINT, ft_catch_signal);
}

void	ft_catch_signal(int signo)
{
	if (signo == SIGWINCH)
		ft_signal_win();
	if (signo == SIGTSTP)
		ft_signal_susp();
	if (signo == SIGCONT)
		ft_signal_cont();
	if (signo == SIGINT)
	{
		ft_term_reset();
		exit(0);
	}
}

