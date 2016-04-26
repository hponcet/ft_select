/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:11:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/26 03:17:29 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_display(void)
{
	char	buffer[5];

	ft_clear_screen();
	while (42)
	{
		ft_display_link();
		read(0, buffer, 4);
		if (ft_check_key(buffer) == 0)
			break;
		ft_bzero(buffer, 5);
		ft_clear_screen();
		ft_signal();
	}
}

void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_char);
}
