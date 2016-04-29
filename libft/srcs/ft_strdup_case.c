/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:43:19 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/29 18:01:56 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_case(char *str, int i)
{
	char	*ret;
	int		j;

	j = -1;
	if (i <  1)
		i = ft_strlen(str);
	if(!(ret = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i] = '\0';
	while (++j < i)
		ret[j] = ' ';
	j = -1;
	while (str[++j])
		ret[j] = str[j];
	return (ret);
}
