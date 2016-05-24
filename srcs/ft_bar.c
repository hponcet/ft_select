/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 20:20:48 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/24 21:49:41 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_display_bar(t_conf *conf)
{
	int			i;
	char		*path;
	t_link		*tmp;
	char		*name;

	i = 0;
	tmp = conf->link;
	while (tmp->ison == 0)
		tmp = tmp->next;
	name = ft_delspace(tmp->value);
	tputs(tgoto(tgetstr("cm", 0), 0, 0), 0, ft_char);
	path = ft_joinf("%s/%s", getenv("PWD"), name);
	ft_putstr_fd("\x1B[1m\x1B[44m FT_SELECT \x1B[0m", 3);
	ft_make_info_bar(path, conf);
	return (1);
}

void	ft_make_info_bar(char *path, t_conf *conf)
{
	struct stat	s_stat;
	t_link		*tmp;

	lstat(path, &s_stat);
	tmp = conf->link;
	while (tmp->ison == 0)
		tmp = tmp->next;
	ft_type(s_stat.st_mode);
	ft_extension(path);
	free(path);
	path = ft_joinf("%s/%s", getenv("PWD"), tmp->value);
	ft_putstr_fd("\x1B[1m\x1B[44m ", 3);
	ft_time(s_stat.st_mtime);
	if ((int)ft_strlen(path) + 36 < conf->nb_col)
	{
		ft_putstr_fd("| ", 3);
		ft_putstr_fd(path, 3);
	}
	ft_putstr_fd("\x1B[0m ", 3);
	free(path);
}
