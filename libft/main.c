/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:08:43 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/03 15:36:23 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select/libft/includes/libft.h"

int		main(void)
{
	char buffer[5];
	int	i;

	i = 0;
	while (1)
	{
		read(0, buffer, 4);
		while (buffer[i])
		{
			ft_printf("%d\n", buffer[i]);
			i++;
		}
		i = 0;
		ft_bzero(buffer, 5);
	}
}
