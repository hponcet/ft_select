/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:05:35 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/27 16:32:47 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# define t_term struct termios
# define t_win struct winsize

typedef struct		s_link
{
	char			*value;
	int				select;
	int				ison;
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
	int				len_link_max;
	int				fd;
	t_link			*link;
}					t_conf;

t_conf				*g_signal;

t_conf				*ft_link(t_conf *conf, char **av);
t_conf				*ft_check_max_link_len(t_conf *conf);


void				ft_term_reset(t_conf *conf);
void				ft_term_winsize(t_conf *conf);
t_conf				*ft_term_init(char **av);
void				ft_term_fd(t_conf *conf);

void				ft_signal(void);

void				ft_display(t_conf *conf);
void				ft_display_list(t_conf *conf);

int					ft_char(int i);

#endif
