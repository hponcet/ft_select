/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/05 18:57:54 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(t_conf *conf)
{
	char	buffer[5];

	tputs(tgetstr("sc", NULL), 0, ft_char);
	ft_signal();
	tputs(tgetstr("rc", NULL), 0, ft_char);
	ft_display_list(conf);
	while (1)
	{
		read(0, buffer, 4);
		ft_bzero(buffer, 5);
		//ft_key(conf, buffer);
	}
}

void	ft_display_list(t_conf *conf)
{
	int		i;
	int		vpos;
	int		hpos;
	t_link	*tmp;

	i = 0;
	vpos = 0;
	hpos = 0;
	tmp = conf->link;
	while (i < conf->nb_link)
	{
		if (vpos == conf->nb_row)
		{
			hpos += conf->len_link_max + 1;
			vpos = 0;
		}
		tputs(tgoto(tgetstr("cm", 0), hpos, vpos), 1, ft_char);
		tputs(tgetstr("ce", 0), 1, ft_char);
		ft_putendl_tc(tmp->value, 3, tmp->select, tmp->ison);
		i++;
		vpos++;
		tmp = tmp->next;
	}
	tputs(tgetstr("rc", NULL), 0, ft_char);
}

void	ft_putendl_tc(char *str, int fd, int sel, int ison)
{
	int		i;

	i = 0;
	if (sel == 1)
		tputs(tgetstr("mr", NULL), 0, ft_char);
	if (ison == 1)
	{
		tputs(tgetstr("us", NULL), 0, ft_char);
		tputs(tgetstr("sc", NULL), 0, ft_char);
	}
	while (str[i])
	{
		if (str[i] == ' ')
			tputs(tgetstr("me", NULL), 0, ft_char);
		write(fd, &str[i], 1);
		i++;
	}
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
