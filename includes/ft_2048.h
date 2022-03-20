/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:45:02 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 17:07:04 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H

# include <ncurses.h>

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_infos
{
	int		size;
	int		(*grid)[5];
	int		score;
	WINDOW	*(*boxes)[5];
	int		box_height;
	int		box_width;
}				t_infos;

int		add_number(t_infos *infos);
int	ft_menu(t_infos *infos);
int		init_grid(t_infos *infos);
void	draw_numbers(t_infos *infos);
void	move_left(t_infos *infos);
void	move_right(t_infos *infos);
void	move_up(t_infos *infos);
void	move_down(t_infos *infos);
void	ft_move_d(t_infos *infos);
void	ft_move_u(t_infos *infos);
void	ft_move_r(t_infos *infos);
void	ft_move_l(t_infos *infos);

#endif
