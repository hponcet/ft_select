/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:55:26 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/27 17:21:53 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int		main(int ac, char **av)
{
	t_conf	*conf;

	if (ac < 2)
		return (0);
	conf = ft_term_init(av);
	ft_display(conf);
	return (1);
}
