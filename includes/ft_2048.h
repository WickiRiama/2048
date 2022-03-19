/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:45:02 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 18:00:03 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H

# include "ncurses.h"

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_infos
{
	int		size;
	int		**grid;
	int		score;
}				t_infos;

int		ft_add_number(t_infos *infos);
int		ft_menu(int lines, int cols);
void	**ft_initgrid(t_infos infos);

#endif
