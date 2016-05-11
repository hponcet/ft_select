/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 20:20:48 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/11 12:50:05 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

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
	if ((int)ft_strlen(path) + 12 > conf->nb_col)
	{
		ft_putstr_fd("\x1B[1m\x1B[44m ", 3);
		ft_putstr_fd(path, 3);
		ft_putstr_fd("\x1B[0m ", 3);
		return (1);
	}
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
	ft_putstr_fd(" | ", 3);
	ft_putstr_fd(path, 3);
	ft_putstr_fd("\x1B[0m ", 3);
	free(path);
}

void	ft_extension(char *str)
{
	int		i;
	int		o;

	o = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			o = i;
		if (str[i] == '/')
			o = -1;
		i++;
	}
	if (o != -1)
	{
		while (str[o])
		{
			write(3, &(str[o]), 1);
			o++;
		}
		ft_putstr_fd(" ", 3);
	}
	ft_putstr_fd("\x1B[0m", 3);
}

void	ft_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[47m FILE ", 3);
	if (S_ISCHR(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[41m CHR  \x1B[0m", 3);
	if (S_ISBLK(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[43m BLK  \x1B[0m", 3);
	if (S_ISFIFO(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[44m FIFO \x1B[0m", 3);
	if (S_ISLNK(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[45m LNK  \x1B[0m", 3);
	if (S_ISSOCK(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[46m SOCK \x1B[0m", 3);
	if (S_ISDIR(st_mode))
		ft_putstr_fd("\x1B[1m\x1B[42m DIR  \x1B[0m", 3);
}

void	ft_time(time_t tim)
{
	char	*buf;
	char	*ret;
	time_t	comp;

	comp = time(NULL);
	buf = ft_strdup(ctime(&tim));
	ret = ft_strnew(12);
	ft_time_parse(buf, ret);
	if (((long int)comp - (long int)tim) > 15638400)
	{
		ret[7] = ' ';
		ret[8] = buf[20];
		ret[9] = buf[21];
		ret[10] = buf[22];
		ret[11] = buf[23];
	}
	ft_putstr_fd(ret, 3);
	free(ret);
	free(buf);
}

void		ft_time_parse(char *buf, char *ret)
{
	ret[0] = buf[4];
	ret[1] = buf[5];
	ret[2] = buf[6];
	ret[3] = ' ';
	ret[4] = buf[8];
	ret[5] = buf[9];
	ret[6] = ' ';
	ret[7] = buf[11];
	ret[8] = buf[12];
	ret[9] = buf[13];
	ret[10] = buf[14];
	ret[11] = buf[15];
}
