/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:48:20 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/25 20:21:40 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int ft_check_key(char *buffer)
{
	t_link  *tmp;

	tmp = NULL;
	if (buffer[0] == 27 && buffer[2] == 65)
	{
		g_selected->ison = 0;
		g_selected = g_selected->prev;
		g_selected->ison = 1;
	}
	else if (buffer[0] == 27 && buffer[2] == 66)
	{
		g_selected->ison = 0;
		g_selected = g_selected->next;
		g_selected->ison = 1;
	}
	else if (buffer[0] == 27 && buffer[2] == 51)
	{
		tmp = g_selected;
		if (g_selected == g_config.link)
			g_config.link = g_config.link->next;
		g_selected = g_selected->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp->value);
		tmp->prev = NULL;
		tmp->next = NULL;
		g_config.nb_link -= 1;
		free(tmp);
		g_selected->ison = 1;
		ft_check_max_link_len();
	}
	else if (buffer[0] == 27)
		return (0);
	else if (buffer[0] == 32)
	{
		g_selected->ison = 0;
		if (g_selected->select == 1)
			g_selected->select = 0;
		else
			g_selected->select = 1;
		g_selected = g_selected->next;
		g_selected->ison = 1;
	}
	else if (buffer[0] == 127)
	{
		tmp = g_selected;
		g_selected = g_selected->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp->value);
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		g_selected->ison = 1;
	}
	if (g_config.nb_link == 0)
		return (0);
	return (1);
}
