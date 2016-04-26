/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:57:36 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/26 02:19:45 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static void		ft_display_one_row(void)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = g_config.link;
	while (i < g_config.nb_link)
	{
		if (tmp->ison == 1)
			ft_putstr("\e[4m");
		if (tmp->select == 1)
			ft_putstr("\e[7m");
		ft_putstr(tmp->value);
		ft_putendl("\e[0m");
		tmp = tmp->next;
		i++;
	}
}

void	ft_display_link(void)
{
	ft_display_one_row();
}
