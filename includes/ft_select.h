/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:05:35 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/26 00:27:11 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <unistd.h>
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

typedef struct		s_config
{
	t_term			term;
	char			*terminfo;
	int				nb_col;
	int				nb_row;
	int				nb_link;
	int				len_link_max;
	t_link			*link;
}					t_config;

t_config			g_config;
t_link				*g_selected;
/*
** ft_term.c
*/
int					ft_term_init(void);
int					ft_term_reset(void);

/*
** ft_char.c
*/
int					ft_char(int i);

/*
** ft_display.c
*/
void	ft_catch_signal(int signo);
void	ft_signal(void);

/*
** ft_display.c
*/
void				ft_catch_signal(int signo);
void				ft_clear_screen(void);
void				ft_display(void);
void				ft_display_link(void);

int ft_check_key(char *buffer);
/*
** ft_link.c
*/
void	ft_link(char **av);
void	ft_check_max_link_len(void);

/*
** ft_display_mult_row.c
*/
void		ft_display_mult_row(void);

#endif

/*

Pour deplacer le curseur dans les colonnes et les lignes:
tputs
tgoto

pour trouver la taille de la fenetre :
ioctl

pour intercepter les signaux :
signal



*/
