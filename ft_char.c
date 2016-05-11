/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:18:18 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/11 12:03:49 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int		ft_char(int i)
{
	return (write(3, &i, 1));
}

char	*ft_delspace(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	ret = (char*)malloc(sizeof(char) * i + 1);
	ret[i] = '\0';
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
