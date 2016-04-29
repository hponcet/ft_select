/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:01:54 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/29 18:20:18 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static t_link	*ft_new_link(void)
{
	t_link	*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	link->value = NULL;
	link->select = 0;
	link->ison = 0;
	link->prev = link;
	link->next = link;
	return (link);
}

t_conf			*ft_link(t_conf *conf, char **av)
{
	int		i;
	t_link	*prev;
	t_link	*tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_new_link();
		tmp->value = ft_strdup_case(av[i], conf->len_link_max + 1);
		if (conf->link == NULL)
		{
			conf->link = tmp;
			prev = tmp;
			continue ;
		}
		tmp->prev = prev;
		prev->next = tmp;
		tmp->next = conf->link;
		prev = tmp;
	}
	conf->link->prev = tmp;
	conf->nb_link = i - 1;
	return (conf);
}

void			ft_check_max_link_len(char **av, t_conf *conf)
{
	int		i;

	i = 0;
	conf->len_link_max = 0;
	while (av[i])
	{
		if (conf->len_link_max < (int)ft_strlen(av[i]))
			conf->len_link_max = ft_strlen(av[i]);
		i++;
	}
}
