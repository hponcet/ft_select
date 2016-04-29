/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/29 20:08:25 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(t_conf *conf)
{
	char	buffer[5];

	tputs(tgetstr("sc", NULL), 0, ft_char);
	ft_signal();
	ft_display_list(conf);
	tputs(tgetstr("rc", NULL), 0, ft_char);
	while (1)
	{
		read(0, buffer, 4);
		ft_bzero(buffer, 5);
		tputs(tgoto(tgetstr("RI", NULL), 0, conf->len_link_max), 0, ft_char);
	}
}

void	ft_display_list(t_conf *conf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = conf->link;
	while (i < conf->nb_link)
	{
		if (tmp->ison == 1)
			tputs(tgetstr("us", NULL), 0, ft_char);
		if (tmp->select == 1)
			tputs(tgetstr("mr", NULL), 0, ft_char);
		ft_putendl_tc(tmp->value, 3, 1);
		tputs(tgetstr("me", NULL), 0, ft_char);
		tmp = tmp->next;
		i++;
	}
}

void	ft_putendl_tc(char *str, int fd, int j)
{
	int		i;
	char	r;

	r = '\n';
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			tputs(tgetstr("me", NULL), 0, ft_char);
		write(fd, &str[i], 1);
		i++;
	}
	if (j > 0)
		write(fd, &r, 1);
}


/*
   me      Fin de tous les modes tels que so, us, mb, md et mr
   us      Début de soulignement
   md      Début de mode gras
   mr      Début de mode inverse
   sc		save pos curs
   rc		restor pos curs
   cm		cursor move
   up		^
   do		v
   nd		>
   le		<
   */
