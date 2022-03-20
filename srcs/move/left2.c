/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:34:37 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 15:36:41 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_join_l(t_infos *infos)
{
	int	col;
	int	line;
	int	current_num;
	int	current_col;

	line = 0;
	while (line < infos->size)
	{
		col = 0;
		current_num = infos->grid[line][col];
		current_col = col;
		while (col < infos->size - 1)
		{
			if (infos->grid[line][col] != 0 || current_num == 0)
			{
				current_num = infos->grid[line][col];
				current_col = col;
			}
			if (infos->grid[line][col + 1] == current_num)
			{
				infos->score += current_num * 2;
				infos->grid[line][current_col] = current_num * 2;
				infos->grid[line][col + 1] = 0;
				current_num = 0;
			}
			col++;
		}
		line++;
	}
}

void	ft_move_l(t_infos *infos)
{
	int	col;
	int	line;
	int	i;

	ft_join_l(infos);
	line = 0;
	while (line < infos->size)
	{
		col = 0;
		i = col;
		while (col < infos->size)
		{
			if (infos->grid[line][col] != 0)
			{
				infos->grid[line][i] = infos->grid[line][col];
				i++;
			}
			col++;
		}
		while (i < infos->size)
		{
			infos->grid[line][i] = 0;
			i++;
		}
		line++;
	}
}