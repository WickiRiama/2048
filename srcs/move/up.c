/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:44 by dolee             #+#    #+#             */
/*   Updated: 2022/03/20 13:57:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void move_up(t_infos *infos)
{
	int		i;
	int		j;
	int		index;
	int		temp_num;
	int		temp_pos;
	int		current_num;
	int		score;
	int		size;
	int		(*grid)[5];

	size = infos->size;
	grid = infos->grid;

	i = 0;
	while (i < size)
	{
		temp_num = grid[size - 1][i];
		if (temp_num)
			temp_pos = size - 2;
		else
			temp_pos = size - 1;

		j = 1;
		while (j < size)
		{
			index = size - j - 1;
			current_num = grid[index][i];
			if (current_num)
			{
				if (current_num == temp_num)
				{
					score = temp_num * 2;
					grid[temp_pos + 1][i] = score;
					temp_num = 0;
					infos->score += score;
					grid[j][i] = 0;
				}
				else
				{
					temp_num = current_num;
					if (temp_pos != j)
					{
						grid[temp_pos][i] = current_num;
						grid[j][i] = 0;
					}
					temp_pos--;
				}
			}
			j++;
		}
		i++;
	}
}				
