/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:05:35 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/18 21:34:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include "../libft/includes/libft.h"
# define t_term struct termios

int     voir_touche(void);
int     ft_shell_init(void);
int     ft_shell_mod(t_term term);
int		ft_popopo(int i);

#endif
