/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:45:02 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 23:04:17 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H

# include <ncurses.h>

enum e_const
{
	WIN_VALUE = 32
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

int		move_down(t_infos *infos);
int		move_up(t_infos *infos);
int		move_left(t_infos *infos);
int		move_right(t_infos *infos);

int		check_gameover(t_infos *infos);


#endif
