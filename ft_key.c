/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 21:07:29 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/11 13:09:21 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"


void	ft_key(char **av, t_conf *conf, char *buffer)
{
	t_link  *tmp;

	tmp = conf->link;
	while (tmp->ison != 1)
		tmp = tmp->next;
	if (buffer[0] == 27 && buffer[2] == 65)			/// Up
	{
		tmp->ison = 0;
		tmp = tmp->prev;
		tmp->ison = 1;
	}
	else if (buffer[0] == 27 && buffer[2] == 66)	/// down
	{
		tmp->ison = 0;
		tmp = tmp->next;
		tmp->ison = 1;
	}
	else if (buffer[0] == 27 && buffer[2] == 67)	/// Right
	{
		int		i;
		int		col;
		int		l;
		int		c;

		i = -1;
		l = (conf->nb_link / (conf->nb_row - 1));
		if (conf->nb_link % (conf->nb_row - 1) != 0)
			l += 1;
		c = -(l * conf->nb_row - conf->nb_link - conf->nb_row -((l - 1) * 1));
		col = conf->nb_row - 1;
		if (tmp->id[1] == l - 1)
			col = c;
		if (tmp->id[1] == l - 2 && tmp->id[0] > c - 1)
			col = conf->nb_row - tmp->id[0] + c - 2;
		tmp->ison = 0;
		while (++i < col)
			tmp = tmp->next;
		tmp->ison = 1;
	}
	else if (buffer[0] == 27 && buffer[2] == 68)	/// Left
	{
		int		i;
		int		col;
		int		l;
		int		c;

		i = 0;
		l = conf->nb_link / conf->nb_row;
		if (conf->nb_link % conf->nb_row != 0)
			l += 1;
		c = -(l * conf->nb_row - conf->nb_link - conf->nb_row -(l - 1));
		col = conf->nb_row - 1;
		if (tmp->id[1] == 0)
			col = c;
		if (tmp->id[1] == 0 && tmp->id[0] > c - 1)
			col = tmp->id[0] + c + conf->nb_row - tmp->id[0] - 1;
		tmp->ison = 0;
		while (i < col)
		{
			i++;
			tmp = tmp->prev;
		}
		tmp->ison = 1;
	}
	else if ((buffer[0] == 27 && buffer[2] == 51) || buffer[0] == 127)	/// Delete
	{
		t_link	*sel;

		if (tmp == conf->link)
			conf->link = conf->link->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		sel = tmp->next;
		free(tmp->value);
		tmp->prev = NULL;
		tmp->next = NULL;
		conf->nb_link -= 1;
		free(tmp);
		sel->ison = 1;
		ft_check_max_link_len(av, conf);
		ft_link_id(conf);
	}
	else if (buffer[0] == 27 && buffer[1] == 0)						/// ESC
	{
		ft_term_reset(conf);
		exit(0);
	}
	else if (buffer[0] == 1)						///  Ctrl-A
	{
		int		i;

		i = 0;
		while (i < conf->nb_link)
		{
			tmp->select = 1;
			i++;
			tmp = tmp->next;
		}
	}
	else if (buffer[0] == 32)						/// Espace
	{
		tmp->ison = 0;
		if (tmp->select == 1)
			tmp->select = 0;
		else
			tmp->select = 1;
		tmp = tmp->next;
		tmp->ison = 1;
	}
	else if (buffer[0] == 10)						/// Espace
	{
		int		i;
		t_link	*tmp;

		i = 0;
		tmp = conf->link;
		while (i < conf->nb_link)
		{
			if (tmp->select == 1)
			{
				ft_putstr(tmp->value);
				ft_putchar(' ');
			}
			i++;
			tmp = tmp->next;
		}
		ft_term_reset(conf);
		exit(0);
	}
	if (conf->nb_link == 0)
	{
		ft_term_reset(conf);
		exit(0);
	}
}
