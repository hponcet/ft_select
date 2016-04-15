/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modiftab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:06:14 by hponcet           #+#    #+#             */
/*   Updated: 2016/01/18 16:21:14 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_modiftab(char **tab, int newx, int newy)
{
	char	**newtab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newtab = ft_createtab(newx, newy);
	while (j < newx)
	{
		while (tab[i] && newtab[j])
		{
			newtab[j] = ft_strncpy(newtab[j], tab[i], newy);
			i++;
			j++;
		}
		if (!tab[i])
		{
			newtab[j] = ft_strnew(newy);
			j++;
		}
	}
	return (newtab);
}
