/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:13:01 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 14:58:31 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_join_d(t_infos *infos)
{
	int	col;
	int	line;
	int	current_num;
	int	current_line;

	col = 0;
	while (col < infos->size)
	{
		line = infos->size - 1;
		current_num = infos->grid[line][col];
		current_line = line;
		while (line > 0)
		{
			if (infos->grid[line][col] != 0 || current_num == 0)
			{
				current_num = infos->grid[line][col];
				current_line = line;
			}
			if (infos->grid[line - 1][col] == current_num)
			{
				infos->score += current_num * 2;
				infos->grid[current_line][col] = current_num * 2;
				infos->grid[line - 1][col] = 0;
				current_num = 0;
			}
			line--;
		}
		col++;
	}
}

void	ft_move_d(t_infos *infos)
{
	int	col;
	int	line;
	int	i;

	ft_join_d(infos);
	col = 0;
	while (col < infos->size)
	{
		line = infos->size - 1;
		i = line;
		while (line >= 0)
		{
			if (infos->grid[line][col] != 0)
			{
				infos->grid[i][col] = infos->grid[line][col];
				i--;
			}
			line--;
		}
		while (i >= 0)
		{
			infos->grid[i][col] = 0;
			i--;
		}
		col++;
	}
}