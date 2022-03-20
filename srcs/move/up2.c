/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:00:50 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 15:08:29 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_join_u(t_infos *infos)
{
	int	col;
	int	line;
	int	current_num;
	int	current_line;

	col = 0;
	while (col < infos->size)
	{
		line = 0;
		current_num = infos->grid[line][col];
		current_line = line;
		while (line < infos->size - 1)
		{
			if (infos->grid[line][col] != 0 || current_num == 0)
			{
				current_num = infos->grid[line][col];
				current_line = line;
			}
			if (infos->grid[line + 1][col] == current_num)
			{
				infos->score += current_num * 2;
				infos->grid[current_line][col] = current_num * 2;
				infos->grid[line + 1][col] = 0;
				current_num = 0;
			}
			line++;
		}
		col++;
	}
}

void	ft_move_u(t_infos *infos)
{
	int	col;
	int	line;
	int	i;

	ft_join_u(infos);
	col = 0;
	while (col < infos->size)
	{
		line = 0;
		i = line;
		while (line < infos->size)
		{
			if (infos->grid[line][col] != 0)
			{
				infos->grid[i][col] = infos->grid[line][col];
				i++;
			}
			line++;
		}
		while (i < infos->size)
		{
			infos->grid[i][col] = 0;
			i++;
		}
		col++;
	}
}