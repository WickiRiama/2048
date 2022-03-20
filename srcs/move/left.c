/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:44 by dolee             #+#    #+#             */
/*   Updated: 2022/03/20 20:37:27 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int		move_left(t_infos *infos)
{
	int		i;
	int		j;
	int		temp_num;
	int		temp_pos;
	int		current_num;
	int		score;
	int		size;
	int		(*grid)[5];
	int		cannot_move;

	size = infos->size;
	grid = infos->grid;

	cannot_move = 1;
	i = 0;
	while (i < size)
	{
		temp_num = grid[i][0];
		if (temp_num)
			temp_pos = 1;
		else
			temp_pos = 0;

		j = 1;
		while (j < size)
		{
			current_num = grid[i][j];
			if (current_num)
			{
				if (current_num == temp_num)
				{
					score = temp_num * 2;
					grid[i][temp_pos - 1] = score;
					temp_num = 0;
					infos->score += score;
					grid[i][j] = 0;
					cannot_move = 0;
				}
				else
				{
					temp_num = current_num;
					if (temp_pos != j)
					{
						grid[i][temp_pos] = current_num;
						grid[i][j] = 0;
						cannot_move = 0;
					}
					temp_pos++;
				}
			}
			j++;
		}
		i++;
	}
	return (cannot_move);
}				
