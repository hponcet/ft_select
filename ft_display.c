/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/22 02:31:56 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_display(void)
{
	char	buffer[5];

	while (42)
	{
		read(0, buffer, 5);
		ft_clear_screen();
		if (signal(SIGWINCH, ft_catch_wndw_mod) == SIG_ERR)
			return ;
		if (buffer[0] == 4)
			return ;
	}
}

void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_popopo);
}
