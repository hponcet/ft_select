/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:02:50 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/25 20:25:05 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int              main(int ac, char **av)
{
	if (ac <= 1)
		exit(0);
	ft_putstr("\033[?1049h\033[H");
	ft_term_init();
	ft_link(av);
	ft_display();
	ft_term_reset();
	return (0);
}
