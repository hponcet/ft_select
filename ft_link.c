/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:01:54 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/23 20:28:35 by hponcet          ###   ########.fr       */
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

void	ft_link(char **av)
{
	int		i;
	t_link	*prev;
	t_link	*tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_new_link();
		tmp->value = ft_strdup(av[i]);
		if (g_config.link == NULL)
		{
			g_config.link = tmp;
			prev = tmp;
			continue ;
		}
		tmp->prev = prev;
		prev->next = tmp;
		tmp->next = g_config.link;
		prev = tmp;
	}
	g_config.link->prev = tmp;
	g_config.link->ison = 1;
	g_config.nb_link = i - 1;
	g_selected = g_config.link;
}
