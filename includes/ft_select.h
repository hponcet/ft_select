/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:05:35 by hponcet           #+#    #+#             */
/*   Updated: 2016/05/10 15:56:06 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <time.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# define t_term struct termios
# define t_win struct winsize
# define __COLOR__ "\x1B[1m"
# define __SELECTED__ "\x1B[44m"
# define __ISON__ "\x1B[34m"
typedef struct		s_link
{
	char			*value;
	int				select;
	int				ison;
	int				*id;
	struct s_link	*prev;
	struct s_link	*next;
}					t_link;

typedef struct		s_conf
{
	t_term			term;
	char			*terminfo;
	int				nb_col;
	int				nb_row;
	int				nb_link;
	int				hpos;
	int				vpos;
	int				len_link_max;
	int				fd;
	t_link			*link;
}					t_conf;

t_conf				*g_signal;

t_conf				*ft_link(t_conf *conf, char **av);
void				ft_check_max_link_len(char **av, t_conf *conf);
void				ft_link_id(t_conf *conf);

void				ft_term_reset(t_conf *conf);
void				ft_term_winsize(t_conf *conf);
t_conf				*ft_term_init(char **av);
void				ft_term_fd(t_conf *conf);

void				ft_signal(void);

void				ft_key(char **av, t_conf *conf, char *buf);

void				ft_display(char **av, t_conf *conf);
void				ft_display_list(t_conf *conf);
void				ft_putendl_tc(char *str, int fd, int sel, int ison);
void				ft_display_init(t_conf *conf);

int					ft_display_bar(t_conf *conf);
void				ft_make_info_bar(char *path, t_conf *conf);
void				ft_type(mode_t st_mode);
void				ft_time(time_t tim);
void				ft_time_parse(char *buf, char *ret);

int					ft_char(int i);

#endif
