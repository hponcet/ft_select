/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:48:20 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/24 19:12:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	ft_catch_signal(int signo)
{
	if (signo == SIGWINCH)
		;
	if (signo == SIGTSTP)
		ft_term_reset();
	if (signo == SIGCONT)
		ft_term_init();
	if (signo == SIGQUIT)
	{
		ft_term_reset();
		exit(0);
	}
}

void	ft_signal(void)
{
	signal(SIGWINCH, ft_catch_signal);
	signal(SIGTSTP, ft_catch_signal);
	signal(SIGCONT, ft_catch_signal);
	signal(SIGQUIT, ft_catch_signal);
}
