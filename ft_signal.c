/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:48:20 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/10 18:43:48 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"


static void	ft_signal_cont(void)
{
	char			*terminfo;

	terminfo = getenv("TERM");
	tgetent(NULL, terminfo);
	tcgetattr(0, &(g_signal->term));
	g_signal->term.c_lflag &= ~(ICANON | ECHO);
	g_signal->term.c_cc[VMIN] = 1;
	g_signal->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(g_signal->term));
	tputs(tgetstr("ti", NULL), 1, ft_char);
	tputs(tgetstr("vi", NULL), 1, ft_char);
	signal(SIGCONT, SIG_DFL);
	ft_display_init(g_signal);
	ft_signal();
}
static void	ft_signal_susp(void)
{
	char	susp[2];

	tputs(tgetstr("me", NULL), 1, ft_char);
	susp[0] = g_signal->term.c_cc[VSUSP];
	susp[1] = 0;
	ioctl(0, TIOCSTI, susp);
	g_signal->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(g_signal->term));
	tputs(tgetstr("te", NULL), 1, ft_char);
	tputs(tgetstr("ve", NULL), 1, ft_char);
	signal(SIGTSTP, SIG_DFL);
}
static void	ft_signal_int(void)
{
	g_signal->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(g_signal->term)) == -1)
		return ;
	tputs(tgetstr("te", NULL), 1, ft_char);
	tputs(tgetstr("ve", NULL), 1, ft_char);
	close(g_signal->fd);
	signal(SIGINT, SIG_DFL);
	exit(0);
}

static void	ft_catch_signal(int signo)
{
	if (signo == SIGWINCH)
		ft_term_winsize(g_signal);
	if (signo == SIGTSTP)
		ft_signal_susp();
	if (signo == SIGCONT)
		ft_signal_cont();
	if (signo == SIGINT)
		ft_signal_int();
}

void		ft_signal(void)
{
	signal(SIGWINCH, ft_catch_signal);
	signal(SIGTSTP, ft_catch_signal);
	signal(SIGCONT, ft_catch_signal);
	signal(SIGINT, ft_catch_signal);
}
