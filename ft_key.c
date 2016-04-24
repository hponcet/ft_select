/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:48:20 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/23 20:25:45 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int ft_check_key(char *buffer)
{
  t_link  *tmp;

  if (buffer[0] == 27)
    return (0);
  if (buffer[0] == 32)
  {
    g_selected->ison = 0;
    if (g_selected->select == 1)
      g_selected->select = 0;
    else
      g_selected->select = 1;
    g_selected = g_selected->next;
    g_selected->ison = 1;
  }
  if (buffer[0] == 127)
  {
    tmp = g_selected;
    g_selected = g_selected->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp->value);
    tmp->prev = NULL;
    tmp->next = NULL;
    free(tmp);
    g_selected->ison = 1;
  }
  return (1);
}
