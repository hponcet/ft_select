/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/28 19:28:49 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(t_conf *conf)
{
	char	buffer[5];

	ft_signal();
	ft_display_list(conf);
	while (1)
	{
		ft_display_list(conf);
		read(0, buffer, 4);
		ft_bzero(buffer, 5);
	}
}

void	ft_display_list(t_conf *conf)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = conf->link;
	tputs(tgetstr("cl", NULL), 0, ft_char);
	while (i < conf->nb_link)
	{
		if (tmp->ison == 1)
			tputs(tgetstr("us", NULL), 0, ft_char);
		if (tmp->select == 1)
			tputs(tgetstr("mr", NULL), 0, ft_char);
		tputs(tgoto(tgetstr("cm", NULL), 0, i), 0, ft_char);
		ft_putendl_fd(tmp->value, 3);
		tputs(tgetstr("me", NULL), 0, ft_char);
		tmp = tmp->next;
		i++;
	}
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, ft_char);
}

/*
me      Fin de tous les modes tels que so, us, mb, md et mr
us      Début de soulignement
md      Début de mode gras
mr      Début de mode inverse
*/
