/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/03 15:43:21 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(t_conf *conf)
{
	char	buffer[5];
	int		i;

	i = 1;
	tputs(tgetstr("sc", NULL), 0, ft_char);
	ft_signal();
	tputs(tgetstr("rc", NULL), 0, ft_char);
	if (conf->nb_row < conf->nb_link)
		i = conf->nb_link / conf->nb_row;
	ft_display_list(conf, i);
	while (1)
	{
		read(0, buffer, 4);
		ft_bzero(buffer, 5);
		ft_key(conf, buffer);
	}
}

void	ft_display_list(t_conf *conf, int nb)
{
	int		i;
	int		j;
	int		k;
	t_link	*tmp;

	i = 0;
	j = conf->nb_link / nb;
	k = 0;
	if (conf->nb_link % nb != 0)
		j += 1;
	tmp = conf->link;
	while (i < conf->nb_link)
	{
		k = 0;
		while (k < j)
		{
			if (tmp->ison == 1)
				tputs(tgetstr("us", NULL), 0, ft_char);
			if (tmp->select == 1)
				tputs(tgetstr("mr", NULL), 0, ft_char);
			ft_putendl_tc(tmp->value, 3, 1);
			tputs(tgetstr("me", NULL), 0, ft_char);
			tmp = tmp->next;
			i++;
			k++;
		}
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
   p
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
