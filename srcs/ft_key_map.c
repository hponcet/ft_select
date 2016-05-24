/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 22:26:14 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/24 22:26:55 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_key_enter(t_conf *conf)
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

void		ft_key_del(t_conf *conf, t_link *tmp, char **av)
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

void		ft_key_space(t_link *tmp)
{
	tmp->ison = 0;
	if (tmp->select == 1)
		tmp->select = 0;
	else
		tmp->select = 1;
	tmp = tmp->next;
	tmp->ison = 1;
}

void		ft_key_ctrla(t_conf *conf, t_link *tmp)
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

void		ft_key_esc(t_conf *conf)
{
	ft_term_reset(conf);
	exit(0);
}
