/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:51:43 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/24 22:32:29 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_key_right(t_conf *conf, t_link *tmp)
{
	int		i;
	int		col;
	int		l;
	int		c;

	i = -1;
	l = (conf->nb_link / (conf->nb_row - 1));
	if (conf->nb_link % (conf->nb_row - 1) != 0)
		l += 1;
	c = -(l * conf->nb_row - conf->nb_link - conf->nb_row - ((l - 1) * 1));
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

void	ft_key_left(t_conf *conf, t_link *tmp)
{
	int		i;
	int		col;
	int		l;
	int		c;

	i = 0;
	l = conf->nb_link / conf->nb_row;
	if (conf->nb_link % conf->nb_row != 0)
		l += 1;
	c = -(l * conf->nb_row - conf->nb_link - conf->nb_row - (l - 1));
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

void	ft_key_up(t_link *tmp)
{
	tmp->ison = 0;
	tmp = tmp->prev;
	tmp->ison = 1;
}

void	ft_key_down(t_link *tmp)
{
	tmp->ison = 0;
	tmp = tmp->next;
	tmp->ison = 1;
}
