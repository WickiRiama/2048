/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:45:02 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 16:48:38 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H

# include "ncurses.h"

enum e_const
{
	WIN_VALUE = 2048
};
int		ft_menu(int lines, int cols);
void	**ft_initgrid(int grid_size);

typedef struct	s_infos
{
	int		size;
	int		**grid;
	int		score;
}				t_infos;

#endif
