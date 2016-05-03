/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:05:47 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/03 15:43:16 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void		ft_select(t_conf *conf, char *buf)
{
	
	tputs(tgoto(tgetstr("cm", NULL), row, (conf->len_link_max * col)), 0, ft_char);
}
