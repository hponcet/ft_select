/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/09 02:21:15 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(char **av, t_conf *conf)
{
	char	buffer[5];

	ft_signal();
	ft_display_list(conf);
	while (1)
	{
		read(0, buffer, 4);
		ft_key(av, conf, buffer);
		ft_bzero(buffer, 5);
		ft_display_list(conf);
	}
}

void	ft_display_list(t_conf *conf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = conf->link;
	conf->hpos = 0;
	conf->vpos = 0;
	tputs(tgetstr("cl", 0), 1, ft_char);
	while (i < conf->nb_link)
	{
		if (tmp->ison == 1)
			tputs(tgetstr("sc", NULL), 0, ft_char);
		if (conf->vpos == conf->nb_row)
		{
			conf->hpos += conf->len_link_max + 1;
			conf->vpos = 0;
		}
		tputs(tgoto(tgetstr("cm", 0), conf->hpos, conf->vpos), 1, ft_char);
		tputs(tgetstr("ce", 0), 1, ft_char);
		ft_putendl_tc(tmp->value, 3, tmp->select, tmp->ison);
		i++;
		conf->vpos++;
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
		tputs(tgetstr("us", NULL), 0, ft_char);
	while (str[i])
	{
		if (str[i] == ' ')
			tputs(tgetstr("me", NULL), 0, ft_char);
		write(fd, &str[i], 1);
		i++;
	}
	tputs(tgetstr("me", NULL), 0, ft_char);
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
   cb      Effacer depuis le début de la ligne jusqu'au curseur
   DC      Effacer %1 caractères
   hd      Déplacer le curseur d'une ligne vers le bas
   do      Descendre le curseur d'une ligne
*/
