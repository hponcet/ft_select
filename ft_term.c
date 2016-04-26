/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:28:47 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/26 18:06:00 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

t_conf		*ft_term_reset(t_conf *conf)
{
		conf->term.c_lflag |= (ICANON | ECHO);
		if (tcsetattr(0, 0, &(conf->term)) == -1)
			return (-1);
		close(conf->fd);
		tputs(tgetstr("te", NULL), 1, ft_char);
		tputs(tgetstr("ve", NULL), 1, ft_char);
		ft_putstr("\033[?1049l");
		return (conf);
}

void		ft_term_winsize(t_conf *conf)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	conf->nb_col = win.ws_col;
	conf->nb_row = win.ws_row;
}


t_conf		*ft_term_init(char **av)
{
	t_conf			*conf;

	conf = (t_conf*)malloc(sizeof(t_conf));
	ft_putstr("\033[?1049h\033[H");
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
	conf = ft_link(conf, av);
	conf = ft_check_max_link_len(conf);
	ft_term_winsize(conf);
	conf->fd = open(ttyname(2), O_NOCTTY);
	tputs(tgetstr("ti", NULL), 1, ft_char);
	tputs(tgetstr("vi", NULL), 1, ft_char);
	return (conf);
}
