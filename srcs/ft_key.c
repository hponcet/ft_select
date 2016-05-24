/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 21:07:29 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/24 22:30:20 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_key(char **av, t_conf *conf, char *buffer)
{
	t_link		*tmp;

	tmp = conf->link;
	while (tmp->ison != 1)
		tmp = tmp->next;
	if (buffer[0] == 27 && buffer[2] == 65)
		ft_key_up(tmp);
	else if (buffer[0] == 27 && buffer[2] == 66)
		ft_key_down(tmp);
	else if (buffer[0] == 27 && buffer[2] == 67)
		ft_key_right(conf, tmp);
	else if (buffer[0] == 27 && buffer[2] == 68)
		ft_key_left(conf, tmp);
	else if ((buffer[0] == 27 && buffer[2] == 51) || buffer[0] == 127)
		ft_key_del(conf, tmp, av);
	else if ((buffer[0] == 27 && buffer[1] == 0) || conf->nb_link == 0)
		ft_key_esc(conf);
	else if (buffer[0] == 1)
		ft_key_ctrla(conf, tmp);
	else if (buffer[0] == 32)
		ft_key_space(tmp);
	else if (buffer[0] == 10)
		ft_key_enter(conf);
}
