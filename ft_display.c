/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/11 11:10:36 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(char **av, t_conf *conf)
{
	char	buffer[5];

	ft_signal();
	ft_display_init(conf);
	while (1)
	{
		read(0, buffer, 4);
		ft_key(av, conf, buffer);
		ft_bzero(buffer, 5);
		ft_display_init(conf);
	}
}

void	ft_display_init(t_conf *conf)
{
	int		nbcol;

	nbcol = (conf->nb_link / (conf->nb_row - 1));
	if (conf->nb_link % (conf->nb_row - 1) != 0)
		nbcol += 1;
	if (conf->nb_row * (conf->nb_col / conf->len_link_max) < conf->nb_link ||
			nbcol * (conf->len_link_max + 1) > conf->nb_col)
	{
		tputs(tgetstr("cl", 0), 1, ft_char);
		ft_putstr_fd("\x1B[41m\x1B[1m Window too small \x1B[0m", 3);
		return ;
	}
	ft_display_list(conf);
}

void	ft_display_list(t_conf *conf)
{
	int		i;
	t_link	*tmp;

	i = -1;
	tmp = conf->link;
	tputs(tgetstr("cl", 0), 1, ft_char);
	conf->hpos = 0;
	conf->vpos = ft_display_bar(conf);
	while (++i < conf->nb_link)
	{
		if (conf->vpos == conf->nb_row)
		{
			conf->hpos += conf->len_link_max + 1;
			conf->vpos = 1;
		}
		tputs(tgoto(tgetstr("cm", 0), conf->hpos, conf->vpos), 1, ft_char);
		tputs(tgetstr("ce", 0), 1, ft_char);
		ft_putendl_tc(tmp->value, 3, tmp->select, tmp->ison);
		conf->vpos++;
		tmp = tmp->next;
	}
}

void	ft_putendl_tc(char *str, int fd, int sel, int ison)
{
	int		i;

	i = 0;
	ft_putstr_fd(__COLOR__, 3);
	if (sel == 1)
	{
		tputs(tgetstr("mr", NULL), 0, ft_char);
		ft_putstr_fd(__SELECTED__, 3);
	}
	if (ison == 1)
	{
		ft_putstr_fd(__ISON__, 3);
		tputs(tgetstr("us", NULL), 0, ft_char);
	}
	while (str[i])
	{
		if (str[i] == ' ')
			tputs(tgetstr("me", NULL), 0, ft_char);
		write(fd, &str[i], 1);
		i++;
	}
	tputs(tgetstr("me", NULL), 0, ft_char);
	ft_putstr_fd("\x1B[0m", 3);
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
   do      Descendre le curseur d'une ligne
   ll	   Déplacer le curseur au coin inférieur gauche
*/
