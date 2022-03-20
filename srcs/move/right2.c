/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:24:10 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 15:24:27 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_join_r(t_infos *infos)
{
	int	col;
	int	line;
	int	current_num;
	int	current_col;

	line = 0;
	while (line < infos->size)
	{
		col = infos->size - 1;
		current_num = infos->grid[line][col];
		current_col = col;
		while (col > 0)
		{
			if (infos->grid[line][col] != 0 || current_num == 0)
			{
				current_num = infos->grid[line][col];
				current_col = col;
			}
			if (infos->grid[line][col - 1] == current_num)
			{
				infos->score += current_num * 2;
				infos->grid[line][current_col] = current_num * 2;
				infos->grid[line][col - 1] = 0;
				current_num = 0;
			}
			col--;
		}
		line++;
	}
}

void	ft_move_r(t_infos *infos)
{
	int	col;
	int	line;
	int	i;

	ft_join_r(infos);
	line = 0;
	while (line < infos->size)
	{
		col = infos->size - 1;
		i = col;
		while (col >= 0)
		{
			if (infos->grid[line][col] != 0)
			{
				infos->grid[line][i] = infos->grid[line][col];
				i--;
			}
			col--;
		}
		while (i >= 0)
		{
			infos->grid[line][i] = 0;
			i--;
		}
		line++;
	}
}