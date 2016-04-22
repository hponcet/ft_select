/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:05:35 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/22 02:31:55 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
#include <sys/ioctl.h>
#include <signal.h>
# include "../libft/includes/libft.h"
# define t_term struct termios
# define t_win struct winsize

t_term	orig;

void    ft_catch_wndw_mod(int signo);
int     voir_touche(void);
int     ft_shell_init(void);
int     ft_shell_mod(t_term term);
int		ft_popopo(int i);
void    ft_clear_screen(void);
void	ft_display(void);

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
