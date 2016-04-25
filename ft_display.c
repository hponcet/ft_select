/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/24 19:10:57 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(void)
{
	char	buffer[5];

	ft_clear_screen();
	while (42)
	{
		ft_signal();
		ft_display_link();
		read(0, buffer, 4);
		if (ft_check_key(buffer) == 0)
			break;
		ft_bzero(buffer, 5);
		ft_clear_screen();
	}
}

void	ft_display_link(void)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = g_config.link;
	ft_printf("%20s\n\n", "ft_select");
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

void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_char);
}
