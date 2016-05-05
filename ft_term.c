/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:28:47 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/05 18:52:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void		ft_term_reset(t_conf *conf)
{
	conf->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(conf->term)) == -1)
		return ;
	tputs(tgetstr("te", NULL), 1, ft_char);
	tputs(tgetstr("ve", NULL), 1, ft_char);
	close(conf->fd);
}

void		ft_term_winsize(t_conf *conf)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	conf->nb_col = win.ws_col;
	conf->nb_row = win.ws_row;
	ft_display_list(conf);
}


t_conf		*ft_term_init(char **av)
{
	t_conf			*conf;

	conf = (t_conf*)malloc(sizeof(t_conf));
	conf->terminfo = getenv("TERM");
	if (tgetent(NULL, conf->terminfo) < 1)
		return (NULL);
	if (tcgetattr(0, &(conf->term)) == -1)
		return (NULL);
	conf->term.c_lflag &= ~(ICANON | ECHO);
	conf->term.c_cc[VMIN] = 1;
	conf->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &(conf->term)) == -1)
		return (NULL);
	ft_check_max_link_len(av, conf);
	conf = ft_link(conf, av);
	ft_term_winsize(conf);
	ft_term_fd(conf);
	tputs(tgetstr("ti", NULL), 1, ft_char);
	//tputs(tgetstr("vi", NULL), 1, ft_char);
	g_signal = conf;
	conf->link->ison = 1;
	return (conf);
}

void		ft_term_fd(t_conf *conf)
{
	int		fd;
	char	*path;

	fd = 3;
	conf->fd = 3;
	path = ttyname(2);
	fd = open(path, O_WRONLY | TIOCNOTTY);
	if (isatty(fd) != 0 && fd > 0)
		conf->fd = fd;
}
